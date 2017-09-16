/*
	Author: Karel Moricky

	Description:
	Wait until all modules using module framework are initialized
	
	Parameter(s): 
		0: ARRAY of OBJECTs - modules to be activated
	
	Returns:
	BOOL
*/

//--- Create groups for module categories
_sideLogic = sidelogic call bis_fnc_sideID;
{
	_category = configname _x;
	_side = getnumber (_x >> "side");
	if (_side == _sideLogic) then {
		_groupVar = "bis_fnc_initModules_" + _category;
		_group = grpnull;
		if (isserver) then {
			_group = creategroup sidelogic;
			missionnamespace setvariable [_groupVar,_group];
			publicvariable _groupVar;
		} else {
			_group = missionnamespace getvariable [_groupVar,grpnull]
		};
		_group setgroupid [gettext (configfile >> "cfgfactionclasses" >> _category >> "displayname")];
	};
} foreach ((configfile >> "cfgfactionclasses") call bis_fnc_returnchildren);

//--- Sort modules by priorities. Modules with lower number gets executed first
private ["_modules","_modulesSorted"];
_modules = if (count _this > 0) then {_this} else {entities "Module_F"};
_modulesSorted = [[]];
{
	private ["_priority","_priorityModules"];
	_priority = _x getvariable ["bis_fnc_initModules_priroty",-1];
	if (_priority >= 0) then { //--- Register only modules using the framework
		_modulesSorted resize ((_priority + 1) max (count _modulesSorted));
		_priorityModules = _modulesSorted select _priority;
		if (isnil {_priorityModules}) then {
			_modulesSorted set [_priority,[]];
			_priorityModules = _modulesSorted select _priority;
		};
		_priorityModules set [count _priorityModules,_x];
	};
} foreach _modules;

//--- Wait until modules are initialized
private ["_time"];
waituntil {

	//--- Activate modules
	private ["_priorityModules"];
	_priorityModules = _modulesSorted select 0;
	if !(isnil {_priorityModules}) then {
		{_x setvariable ["bis_fnc_initModules_activate",true];} foreach _priorityModules;

		//--- Wait until they are initialized
		_time = diag_ticktime + 2;
		waituntil {
			{!(_x getvariable ["bis_fnc_moduleInit_status",false])} count _priorityModules == 0 || diag_ticktime > _time
		};
	};

	//--- Remove modules of the current priority
	_modulesSorted set [0,-1];
	_modulesSorted = _modulesSorted - [-1];
	count _modulesSorted == 0
};
true