/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

disableSerialization;

params ["_container","_eventName","_eventData"];

_eventData params ["_control","_index"];

_data = _control lbData _index;
_displayName = _control lbText _index;

if (_eventName == "LBSelChanged") then
{
	//Check All CfgWeapons
	if (_data == "") then
	{
		private ["_exit","_cfgWeapons"];
		_exit = false;
		_cfgWeapons = (configFile >> "CfgWeapons");
		for "_c" from 0 to (count _cfgWeapons - 1) do 
		{
			private ["_currentWeapon","_weaponName"];
			_currentWeapon = _cfgWeapons select _c;
			_weaponName = configName _currentWeapon;
			if (isClass _currentWeapon) then {
				if (_displayName == getText (_cfgWeapons >> _weaponName >> "displayName")) exitWith {
					_data = _weaponName;
				};			
			};
			if (_exit) exitWith {};
		};
	};
	
	//Check All CfgVehicles
	if (_data == "") then
	{
		private ["_exit","_cfgVehicles"];
		_exit = false;
		_cfgVehicles = (configFile >> "CfgVehicles");
		for "_c" from 0 to (count _cfgVehicles - 1) do 
		{
			private ["_currentVehicle","_vehicleName"];
			_currentVehicle = _cfgVehicles select _c;
			_vehicleName = configName _currentVehicle;
			if (isClass _currentVehicle) then {
				if (_displayName == getText (_cfgVehicles >> _vehicleName >> "displayName")) exitWith {
					_data = _vehicleName;
				};			
			};
			if (_exit) exitWith {};
		};
	};

	private ["_isWeapon","_isMagazine","_isVehicle","_config","_model"];
	_isWeapon = isClass(configFile >> "CfgWeapons" >> _data);
	_isMagazine = isClass(configFile >> "CfgMagazines" >> _data);
	_isVehicle = isClass(configFile >> "CfgVehicles" >> _data);
	_config = configFile;
	_controlPreview = ((findDisplay 602) displayCtrl 9999);

	if (_isWeapon) then { _config = (configFile >> "CfgWeapons" >> _data); };
	if (_isMagazine) then { _config = (configFile >> "CfgMagazines" >> _data); };
	if (_isVehicle) then { _config = (configFile >> "CfgVehicles" >> _data); };
	
	if (!_isWeapon and !_isMagazine and !_isVehicle) exitWith { _controlPreview ctrlShow false; };

	_model = getText (_config >> "model");
	_newModel = ctrlModel _controlPreview;
	
	if (_model != "") then 
	{
		private ["_dir","_up","_scale"];
		_controlPreview ctrlShow true;
		_controlPreview ctrlSetModel _model;
		_dir = [0, -0.35, -0.65]; // _dir = [0, -0.35, -0.65];
		_up = [0, 0.65, -0.35]; // _up = [0, 0.65, -0.35];
		_scale = 1;
		if (isClass (_config >> "InventoryPreview")) then {
			_dir = getArray (_config >> "InventoryPreview" >> "direction");
			_up = getArray (_config >> "InventoryPreview" >> "up");
			_scale = getNumber (_config >> "InventoryPreview" >> "scale");
		};
		_controlPreview ctrlSetModelDirAndUp [_dir,_up];
		_controlPreview ctrlSetModelScale _scale;
	} else {
		_controlPreview ctrlShow false;
	};
};

if (_eventName == "LBDblClick") then
{
	if (_data == "WaterbotEmpty") exitWith { [_data] spawn BP_fnc_waterFill; };
	if (_data == "ItemMatchbox") exitWith { [_data] spawn BP_fnc_fireMake; };	
	if (_data in BP_FuelEmpty) exitWith { [_data] spawn BP_fnc_fuelFill; };
	if (_data in BP_TrapBuildables) exitWith { [_data] spawn BP_fnc_constructTrap; };
	if (_data in BP_Blueprints) exitWith {[_data] spawn BP_fnc_constructStorage;};
	if (_data in AllMedical) exitWith {[_data] spawn BP_fnc_useMeds;};
	if (_data in AllFood) exitWith {[_data] spawn BP_fnc_eat;};
	if (_data in meatcooked) exitWith {[_data] spawn BP_fnc_eat;};
	if (_data in AllDrinks) exitWith {[_data] spawn BP_fnc_drink;};
	if (_data in BP_SprayCans) exitWith {[_data] spawn BP_fnc_sprayCan;};
			
	["Inventory: Attempted to Active Undefined Item: %1",_data] call BP_fnc_debugConsoleFormat;
};