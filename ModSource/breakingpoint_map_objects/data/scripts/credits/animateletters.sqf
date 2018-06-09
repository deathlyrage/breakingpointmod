disableSerialization;

private ["_text", "_chars", "_mode", "_display", "_slot", "_stdPath"];
_text = _this select 0;
_chars = toArray _text;
_mode = "";
_display = findDisplay 998877;
_slot = 0;
_stdPath = "ca\data\scripts\credits\";
//"

switch (_this select 1) do 
{
	case 0: {_mode = (_stdPath + "animateLetter.sqf"); _slot = 0;};
	case 1: {_mode = (_stdPath + "animateLetter1.sqf"); _slot = 30;};
	case 2: {_mode = (_stdPath + "animateLetter2.sqf"); _slot = 60;};
	case 3: {_mode = (_stdPath + "animateLetter.sqf"); _slot = 90;};
	case 4: {_mode = (_stdPath + "animateLetter1.sqf"); _slot = 120;};
	case 5: {_mode = (_stdPath + "animateLetter2.sqf"); _slot = 150;};
	case 6: {_mode = (_stdPath + "animateLetter1.sqf"); _slot = 180;};
};

//Set up a pool of controls to use.
private ["_idcPool"];
_idcPool = 5000;

call (compile ("BIS_Credits_Pool" + (str _slot) + " = []"));

for "_i" from _slot to (_slot + 29) do 
{
	_ctrl = _display displayCtrl (_idcPool + _i);
	_ctrl ctrlSetFade 1;
	_ctrl ctrlCommit 0.5;
	call (compile ("BIS_Credits_Pool" + (str _slot) + " = BIS_Credits_Pool" + (str _slot) + " + [_ctrl]"));
};

sleep 0.8;

//Parse the array of characters.
for "_i" from 0 to ((count _chars) - 1) do 
{
	sleep 0.03;
	
	private ["_ctrl"];
	call (compile ("_ctrl = BIS_Credits_Pool" + (str _slot) + " select 0"));
	
	//Send character to the animation engine.
	if !(isNil "_ctrl") then 
	{
		[_ctrl, toString [_chars select _i], _i, _slot] execVM _mode;
	};
	
	sleep 0.03;
};

BIS_Credits_Counter = BIS_Credits_Counter + 1;

true