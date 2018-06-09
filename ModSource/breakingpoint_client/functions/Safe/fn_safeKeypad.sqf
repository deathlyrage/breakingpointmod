/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

disableSerialization;

params ["_unit","_safe"];

//Close Any Active Windows
closeDialog 0;

//Get Lock State and Combo
_locked = _safe getVariable ["lock",true];
_key = _safe getVariable ["key","0000"];
_combo = "";
_exit = false;

//Don't need to unlock a safe that's already unlocked.
if (!_locked) exitWith {};

//Show Safe Dialog
_diag = createDialog "RscDisplaySafe";
if (!_diag) exitWith {};

BP_SafeButton = nil;

_display = findDisplay 6918;
_control = _display displayCtrl 1201;

["safeKeypad: Started %1 %2",_display,_control] call BP_fnc_debugConsoleFormat;

while {!isNull _display and dialog} do
{
	//Wait Until a Button Is Pressed
	if (!isNil "BP_SafeButton") then
	{
		//Process Button
		_button = BP_SafeButton;
		BP_SafeButton = nil;
			
		//Debug
		["safeKeypad: onButtonPress() %1",_button] call BP_fnc_debugConsoleFormat;
		
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
			if (_combo == _key) then
			{
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4.jpg";
				[_safe] remoteExecCall ["BPServer_fnc_unlockObj",2];
				sleep 2;
				closeDialog 0;
				//player action ["Gear", _safe];
			} else {
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4_red.jpg";
				sleep 1;
				_control ctrlSetText "\breakingpoint_ui\safe\lights_4_off.jpg";
				sleep 0.1;
				BP_SafeButton = nil;
				_combo = "";
				_attemptArray = [];
				_attemptCount = 0;
				closeDialog 0;
			};
		};
	};
};

["safeKeypad: Thread Ended."] call BP_fnc_debugConsoleFormat;
