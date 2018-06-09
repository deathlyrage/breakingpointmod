private ["_display","_script"];

_display = _this select 0;
_script = getText(missionConfigFile >> "onMinimapScript");

if (_script != "") then 
{
	private ["_handle"];
	_handle = [_display] call _script;
} else {
	_scripts = getArray(missionConfigFile >> "onMinimapScript");
	if (count _scripts > 0) then
	{
		{
			private ["_handle"];
			_handle = [_display] call (missionnamespace getvariable _x);
		} foreach _scripts;
	};
};