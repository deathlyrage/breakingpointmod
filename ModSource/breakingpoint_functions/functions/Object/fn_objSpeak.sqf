/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_source","_type","_chance","_distance","_num"];
_source = [_this, 0, objNull, [objNull]] call BIS_fnc_param;
_type = [_this, 1, "", [""]] call BIS_fnc_param;
_chance = [_this, 2, 0, [0]] call BIS_fnc_param;
_local = [_this, 3, false, [false]] call BIS_fnc_param;
_distance = [_this, 4, 0, [0]] call BIS_fnc_param;

//Exit If Source is Null
if (isNull _source) exitWith {};

//Exit If Invalid Sound Type
if (_type == "") exitWith {};

//Exit If Sounds are Disabled
if (!BP_ZombieSounds) exitWith {};

//Lookup Sound Random Counts
_num = switch (_type) do 
{
	default 					{0};
	//Player
	case "brokenleg":			{1};
	case "fieldbandage": 		{1};
	case "thirst": 			{2};
	case "hunger": 			{2};
	case "cough": 			{2};
	case "scream": 			{4};
	case "fracture":			{1};
	case "eat": 				{3};
	case "cook": 				{2};
	//Zombies
	case "chase": 			{8};
	case "spotted": 			{5};
	case "hit": 				{6};
	case "attack": 			{4};
	case "idle": 				{15};
	//Dog System
	case "dog_bark": 			{4};
	case "dog_bite":			{1};
	case "dog_confirm":		{1};
	case "dog_fail":			{1};
	case "dog_damage":		{1};
	case "dog_growl":			{1};
	case "dog_pain":			{1};
	case "dog_whistleFind":	{1};
	case "dog_whistleFollow":	{1};
	case "dog_whistleNon":		{1};
	case "dog_whistleStay":	{1};
};

//Force Global If Called on Server and Local
if (isServer) then { _local = false; };

//If Distance Is 0 then Lookup Distance
if (_distance == 0) then
{
	//Default Distance
	_distance = 35;
	
	//Define Override Distance
	if (_type in ["shout","hit","attack","scream","breath","spotted"]) then {
		_distance = 75;
	} else {
		_distance = 40;
	};
};

//Check Locality if Anyone is Nearby
if (!_local) then { _local = ({isPlayer _x} count (_source nearEntities ["AllVehicles",_distance]) < 2); };

//Women Zombie Sounds (Stub)
//_isWoman = getText(configFile >> "cfgVehicles" >> (typeOf _source) >> "TextPlural") == "Women";
//if (_isWoman and (_type in ["scream","panic"])) then { _type = _type + "_w"; };

if ((round(random _chance) == _chance) or (_chance == 0)) then 
{
	private ["_rnd","_sound","_isInside","_soundData","_soundCount","_soundVolume","_soundPath","_soundPitch"];
	_rnd = (round(random _num));
	_sound = "z_" + _type + "_" + str(_rnd);

	if (_local) then {
		_source say [_sound, _distance];
	} else {
		//Check If Player is Inside a Building
		_isInside = [_source] call BP_fnc_isInsideBuilding;
		
		//Set Default Sound Values
		_soundVolume = 1;
		_soundPitch = 1;
		
		//Get Sound Path / Name and Volume / Pitch
		_soundData = getArray (configFile >> "CfgSounds" >> _sound >> "sound");
		_soundCount = (count _soundData);
		if (_soundCount > 0) then { _soundPath = _soundData select 0; };
		if (_soundCount > 1) then { _soundVolume = _soundData select 1; };
		if (_soundCount > 2) then { _soundPitch = _soundData select 2; };
		
		["objSpeak: Sound: %1 Path: %2 Source: %3",_sound,_soundPath,_source] call BP_fnc_debugConsoleFormat;
		
		//Play Sound Globally Over The Network
		playSound3D [_soundPath, _source, _isInside, getPos _source, _soundVolume, _soundPitch, _distance];
	};
};