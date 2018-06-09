/*
	Breaking Point Mod: BP_fnc_medicalUnconscious;

	Description:
		None
	
	Parameter(s):
		None
	
	Returns:
		True
*/

if (isNull player) exitWith {};

if (r_player_dead) exitWith {};
if (r_player_handler1) exitWith {};

_inVehicle = (vehicle player != player);
_onLadder =	(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {
	player playActionNow "stop";
	sleep 0.5;
	player playActionNow "Die";
	sleep 0.5;
	player playActionNow "stop";
	r_player_unconscious = false;
};
	
// Drop Primary Weapon
if (r_player_unconsciousWeapon) then 
{
	private ["_currentWeapon","_primaryWeapon","_primaryWeaponMag","_primaryWeaponAmmo","_primaryWeaponItems","_handgunWeapon","_handgunWeaponMag","_handgunWeaponAmmo","_handgunWeaponItems","_launcherWeapon","_launcherWeaponMag","_launcherWeaponAmmo","_launcherWeaponItems"];
	_currentWeapon = currentWeapon player;
	_primaryWeapon = primaryWeapon player;
	_primaryWeaponMag = primaryWeaponMagazine player;
	_primaryWeaponAmmo = player ammo _primaryWeapon;
	_primaryWeaponItems = primaryWeaponItems player;
	_handgunWeapon = handgunWeapon player;
	_handgunWeaponMag = handgunMagazine player;
	_handgunWeaponAmmo = player ammo _handgunWeapon;
	_handgunWeaponItems = handgunItems player;
	_launcherWeapon = secondaryWeapon player;
	_launcherWeaponMag = secondaryWeaponMagazine player;
	_launcherWeaponAmmo = player ammo _launcherWeapon;
	_launcherWeaponItems = secondaryWeaponItems player;
	
	//Add Weapon Holder with Items
	private "_container";
	_container = createVehicle ["groundWeaponHolder", (getPosATL player), [], 4, "CAN_COLLIDE"];
	_container setVariable ["permaLoot",true,true];
	_container enableDynamicSimulation true;
	
	//Primary
	if (_primaryWeapon != "") then 
	{
		//Remove Weapon
		player removeWeapon _primaryWeapon;
		
		//Add Weapon Cargo
		_container addWeaponCargoGlobal [_primaryWeapon,1];
		_container addMagazineAmmoCargo [_primaryWeaponMag,1,_primaryWeaponAmmo];
		{ if (_x != "") then { _container addItemCargoGlobal [_x,1]; }; } count _primaryWeaponItems;
	};
	
	//Handgun
	if (_handgunWeapon != "") then 
	{
		//Remove Weapon
		player removeWeapon _handgunWeapon;
		
		//Add Weapon Cargo
		_container addWeaponCargoGlobal [_handgunWeapon,1];
		_container addMagazineAmmoCargo [_handgunWeaponMag,1,_handgunWeaponAmmo];
		{ if (_x != "") then { _container addItemCargoGlobal [_x,1]; }; } count _handgunWeaponItems;
	};
	
	//Launcher
	if (_launcherWeapon != "") then 
	{
		//Remove Weapon
		player removeWeapon _launcherWeapon;
		
		//Add Weapon Cargo
		_container addWeaponCargoGlobal [_launcherWeapon,1];
		_container addMagazineAmmoCargo [_launcherWeaponMag,1,_launcherWeaponAmmo];
		{ if (_x != "") then { _container addItemCargoGlobal [_x,1]; }; } count _launcherWeaponItems;
	};

	r_player_unconsciousWeapon = false;
};

r_player_timeout = 45;
r_player_unconscious = true;
r_player_handler1 = true;
player setVariable ["unconsciousTime", r_player_timeout, true];
	
if (!_inVehicle) then {
	_veh = (vehicle player);
	waitUntil{(((position _veh select 2 < 1) and (speed _veh < 1)) or (!r_player_unconscious))};
	sleep 1;
};
	
titleRsc ["BP_Unconscious","PLAIN",0];
player setVariable ["med_unconscious", true, true];
player playActionNow "Die";
	
while {r_player_timeout > 0} do {
	sleep 1;
	r_player_timeout = r_player_timeout - 1;
	if (r_player_dead) exitWith {};
};
	
call BP_fnc_medicalUnconsciousRecover;