disableSerialization;
private ["_display", "_control"];

saveprofilenamespace;	

_display = (_this select 1) select 0;
_control = _display displayctrl 1105;

_control ctrlSetFade 1; 
_control ctrlCommit 0;

private ["_pos", "_posX", "_posY"];
_pos = ctrlPosition _control;
_posX = (_pos select 0) + 2;
_posY = (_pos select 1) + 2;
_control ctrlSetPosition [_posX, _posY]; 
_control ctrlCommit 0;

_control ctrlSetFade 0; 
_control ctrlCommit 0.5;

//Hide 'Skip' button
_control = _display displayctrl 1002;
_control ctrlenable false;
_control ctrlSetFade 1; 
_control ctrlCommit 0;

//If the mission defines an onPauseScript, then process that script.
private ["_script"];
_script = getText(missionConfigFile >> "onPauseScript");

if (_script != "") then 
{
	private ["_handle"];
	_handle = [_display] execVM _script;
} else {
	_scripts = getArray(missionConfigFile >> "onPauseScript");
	if (count _scripts > 0) then
	{
		{
			private ["_handle"];
			_handle = [_display] call (missionnamespace getvariable _x);
		} foreach _scripts;
	};
};

/*
switch (_this select 0) do {
	case "Init": 
	{
		_display = (_this select 1) select 0;
		
		_elements = ["a","b","c"];
		_control = _display displayctrl  1005;
		
		_controlTxt = _display displayctrl  1004;
		_controlTxt ctrlSettext "hello world";
		
		for [{_y=0},{_y<count _elements},{_y=_y+1}] do 
		{ 		
			_control lbAdd (_elements select _y);
		};
	};
	case "Cancel":
	{
			_display = ctrlParent (_this select 1);

	};

};
*/

true