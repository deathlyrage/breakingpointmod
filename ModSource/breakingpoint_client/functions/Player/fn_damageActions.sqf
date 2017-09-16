/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_menClose","_isPlayer","_unit","_unconscious","_lowBlood","_injured","_inPain","_hasBandage","_hasMorphine","_hasMedBackpack","_hasSurgeryKit","_action1","_action2","_action","_vehClose","_hasVehicle","_vehicle","_inVehicle","_crew","_unconscious_crew","_patients"];
_menClose = cursorTarget;
_hasPatient = alive _menClose;
_isPlayer = isPlayer _menClose;
_vehicle = vehicle player;
_inVehicle = (_vehicle != player);
_isClose = ((player distance _menClose) < ((sizeOf typeOf _menClose) / 2));
_bag = unitBackpack player;
_classbag = typeOf _bag;

if (_hasPatient and !r_action and !_inVehicle and !r_player_unconscious and _isClose) then 
{
	_unit = 		cursorTarget;
	player reveal _unit;
	_vehClose = 	(getPosATL player) nearEntities [["Car","Tank","Helicopter","Plane","StaticWeapon","Ship"],5]; //nearestObjects [player, ["Car","Tank","Helicopter","Plane","StaticWeapon","Ship"], 5];
	_hasVehicle = 	({alive _x} count _vehClose > 0);
	_unconscious = 	_unit getVariable ["med_unconscious", false];
	_lowBlood = 	_unit getVariable ["med_lowBlood", false];
	_injured = 		_unit getVariable ["med_injured", false];
	_inPain = 		_unit getVariable ["med_inPain", false];
	_legsBroke = 	(_unit getHitPointDamage "HitLegs" >= 1);
	_armsBroke = 	(_unit getHitPointDamage "HitHands" >= 1);
	_hasBandage = 	"ItemBandage" in magazines player;
	_hasFieldBandage = 	"ItemFieldDressing" in magazines player;
	_hasMorphine = 	"ItemMorphine" in magazines player;
	_hasSurgeryKit = "ItemSurgeryKit" in assignedItems player;
	_hasToolbox = 	"ItemToolbox" in assignedItems player;
	_hasEtool = 	"ItemEtool" in weapons player;
	_hasWire = 		"ItemWire" in magazines player;
	_hasPainkillers = 	"ItemPainkiller" in magazines player;
	_hasMedBackpack = ("BP_Mpack" == (backpack player));
	_isPlayer = (isPlayer _menClose);

	if (_injured && {_hasBandage} && {_isPlayer}) then {
		r_action = true;
		_action = _unit addAction ["Apply Small Bandage", "\breakingpoint_code\medical\bandage.sqf",[_unit], 0, true, true, "", "'ItemBandage' in magazines player"];
		0 = r_player_actions pushBack _action;
	};

	if (_injured && {_hasFieldBandage} && {_isPlayer}) then {
		r_action = true;
		_action = _unit addAction ["Apply Field Dressing", "\breakingpoint_code\medical\fielddressing.sqf",[_unit], 0, true, true, "", "'ItemFieldDressing' in magazines player"];
		0 = r_player_actions pushBack _action;
	};

	//Allow player to give Morphine
	if !(isNil "_legsBroke") then {
		if ((_legsBroke or _armsBroke) && {_hasMorphine} && {_isPlayer}) then {
			r_action = true;
			_action = _unit addAction ["Inject Morphine", "\breakingpoint_code\medical\morphine.sqf",[_unit], 0, true, true, "", "'ItemMorphine' in magazines player"];
			0 = r_player_actions pushBack _action;
		};
	};
	//Allow player to give Painkillers
	if (_inPain && {_hasPainkillers} && {_isPlayer}) then {
		r_action = true;
		_action = _unit addAction ["Give Painkiller", "\breakingpoint_code\medical\painkiller.sqf",[_unit], 0, true, true, "", "'ItemPainkiller' in magazines player"];
		0 = r_player_actions pushBack _action;
	};

	//Allow player to operate using a Surgery Kit
	if (_lowBlood && {_hasSurgeryKit} && {_isPlayer}) then {
		r_action = true;
		_action = _unit addAction ["Perform Operation", "\breakingpoint_code\medical\surgerykit.sqf",[_unit], 0, true, true, "", "'ItemSurgeryKit' in assignedItems player"];
		0 = r_player_actions pushBack _action;
	};
	
	if (_hasMedBackpack && {_isPlayer} && {_isPlayer}) then {
		r_action = true;
		_action = _unit addAction ["Use Medpack (Other)", "\breakingpoint_code\medical\medpack.sqf",[_unit], 0, true, true, "", ""];
		0 = r_player_actions pushBack _action;
	};
	if (r_action) then { 0 = r_action_targets pushBack _unit; };
};

//Remove Actions
if ((!_isClose or !_hasPatient) && {r_action}) then {
	call BP_fnc_medicalRemoveMedicActions;
	r_action = false;
};
