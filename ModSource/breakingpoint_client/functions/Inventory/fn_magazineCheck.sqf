/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_fnc_magazineCheck";

_currentWep = currentWeapon player;

//Waypoints Can Only If You have a GPS
if ("ItemGPS" in assignedItems player) then { 
	onMapSingleClick ""; 
	//if (BP_GPSWindID == -1 and !isStreamFriendlyUIEnabled) then {
	//	BP_GPSWindID = findDisplay 12 displayCtrl 51 ctrlAddEventHandler ["Draw", "_this select 0 drawIcon [  '\A3\ui_f\data\map\Markers\Military\arrow2_ca.paa',  [1,0,0,1],  getPos player,  40,  40,  windDir,  '',  1,  0.03,  'TahomaB',  'right']"];
	//};
} else {
	onMapSingleClick {_shift};
	//if (BP_GPSWindID != -1) then {
	//	findDisplay 12 displayCtrl 51 ctrlRemoveEventHandler ["Draw", BP_GPSWindID];
	//};
};

//Faction Clothing Check
call BP_fnc_checkFactionClothing;

//Bayonet
_bayonetMag = "BP_Bayonet_Stab";
_hasBayonetMag = (_bayonetMag in magazines player);
_isBayonet = isClass (configFile >> "CfgWeapons" >> _currentWep >> "Bayonet");
if (_isBayonet) then {
	if (!_hasBayonetMag) then { player addMagazine _bayonetMag; };
} else {
	if (_hasBayonetMag) then { player removeMagazine _bayonetMag; };
};

//Rifle Butt
_buttMag = "BP_Rifle_Butt";
_hasButtMag = (_buttMag in magazines player);
_isButt = isClass (configFile >> "CfgWeapons" >> _currentWep >> "Butt");
if (_isButt) then {
	if (!_hasButtMag) then { player addMagazine _buttMag; };
} else {
	if (_hasButtMag) then { player removeMagazine _buttMag; };
};

//Melee Ammo
if (_currentWep in BP_MeleeWeapons) then 
{
	_wpnType = _currentWep;
	_magType = ([] + getArray (configFile >> "CfgWeapons" >> _wpnType >> "magazines")) select 0;

	if (isNil "_magType") exitWith {};
	
	if (player hasWeapon _wpnType) then 
	{
		_array = secondaryWeaponMagazine player;
		_currentMag = "";
		if (count _array > 0) then { _currentMag = _array select 0; };
		_meleeNum = ({_x == _magType} count magazines player);
		if (_currentMag == _magType) then
		{
			if (_meleeNum > 0) then {
				while {_meleeNum > 0} do {
					player removeMagazine _magType;
					_meleeNum = _meleeNum - 1;
				};
			};
		} else {
			if (_meleeNum < 1) then {
				player addMagazine _magType;
			};
		};
	};
};
