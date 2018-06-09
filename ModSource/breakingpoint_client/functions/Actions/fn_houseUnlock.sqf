/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_building","_buildingType","_buildingConfig","_buildingLockable","_combo","_diag","_display","_control","_button","_attemptArray","_attemptCount","_exit"];
disableSerialization;
_building = _this select 3;
_buildingType = 	typeOf _building;

// Mission config file loot table override.
_buildingConfig = configFile >> "CfgBuildingLoot" >> _buildingType;
if (isClass (missionConfigFile >> "CfgBuildingLoot" >> _buildingType)) then
{
	_buildingConfig = missionConfigFile >> "CfgBuildingLoot" >> _buildingType;
};

_buildingLockable = (_buildingType in BP_Houses);
_buildingDoors = getNumber (configFile >> "CfgVehicles" >> _buildingType >> "numberOfDoors");
_combo = "";

//Remove Action to Prevent Spam
player removeAction s_player_lockHouse;
s_player_lockHouse = -1;
player removeAction s_player_unlockHouse;
s_player_unlockHouse = -1;

//Exit If Null Building
if (isNull _building) exitWith {};

//Get Lock Code
_exit = false;

//Close Any Active Windows
closeDialog 0;

//Show Safe Dialog
_diag = createDialog "RscDisplaySafe";
if (!_diag) exitWith {};

BP_SafeButton = nil;

_display = findDisplay 6918;
_control = _display displayCtrl 1201;

while {!isNull _display and dialog} do
{
	//Wait Until a Button Is Pressed
	if (!isNil "BP_SafeButton") then
	{
		//Process Button
		_button = BP_SafeButton;
		BP_SafeButton = nil;

		//Add Button Press to Total Combo
		_combo = _combo + _button;

		_attemptArray = toArray _combo;
		_attemptCount = count _attemptArray;

		//Update IEDs based on how many numbers have been entered
		switch (_attemptCount) do {
			case 0:
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4_off.jpg";
			};
			case 1:
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_1.jpg";
			};
			case 2:
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_2.jpg";
			};
			case 3:
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_3.jpg";
			};
			case 4:
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4.jpg";
			};
			default
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4_off.jpg";
			};
		};

		//4 Numbers have been entered, check the result
		if (_attemptCount == 4) then
		{
			BP_HavenUnlockResult = nil;

			[(netID _building),_combo,(netID player)] remoteExecCall ["BPServer_fnc_unlockHouse",2];

			waitUntil {!isNil "BP_HavenUnlockResult"};

			if (BP_HavenUnlockResult) then
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4.jpg";

				//_buildingLogic setVariable ['bis_disabled_Door',0,true];

				sleep 1;
				closeDialog 0;

				cutText ["Building Unlocked.", "PLAIN DOWN"];

				//Remove Action to Prevent Spam
				player removeAction s_player_lockHouse;
				s_player_lockHouse = -1;
				player removeAction s_player_unlockHouse;
				s_player_unlockHouse = -1;
			} else {
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4_red.jpg";
				sleep 2;
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4_off.jpg";
				sleep 0.5;
				BP_SafeButton = nil;
				_combo = "";
				_attemptArray = [];
				_attemptCount = 0;
				closeDialog 0;
			};
		};
	};
};
