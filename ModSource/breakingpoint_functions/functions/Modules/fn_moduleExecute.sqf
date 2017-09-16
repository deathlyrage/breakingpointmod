private ["_logic","_function","_params","_activate","_isGlobal","_isDisposable","_isPersistent","_spawn","_time"];

_logic = [_this,0,objnull,[objnull]] call bis_fnc_param;
_function = [_this,1,"",[""]] call bis_fnc_param;
_params = [_this,2,[],[[]]] call bis_fnc_param;
_activate = [_this,3,true,[true]] call bis_fnc_param;

_isGlobal = [_params,0,false,[false]] call bis_fnc_paramin;
_isDisposable = [_params,2,false,[false]] call bis_fnc_paramin;
_isPersistent = [_params,3,false,[false]] call bis_fnc_paramin;

_logic setvariable ["bis_fnc_moduleInit_status",false];
waituntil {_logic getvariable ["bis_fnc_initModules_activate",true] || isnull _logic};
if (isnull _logic) exitwith {false};

//--- Don't execute persistentely when the module was executed before (to avoid spamming the queue)
if (_isPersistent) then {
	_isPersistent = _isPersistent && (_logic getvariable ["bis_fnc_moduleExecute_first",true]);
	_logic setvariable ["bis_fnc_moduleExecute_first",false];
};

//--- Mark the module as activated for persistent execution
_logic setvariable ["bis_fnc_moduleExecute_activate",true,_activate && _isGlobal && _isPersistent];

//--- Execute the function (only if it's enabled)
_spawn = if (simulationenabled _logic) then {
	if (ismultiplayer && _isGlobal) then {

		//--- Global execution
		[
			[_logic,(_logic call bis_fnc_moduleUnits),_activate],
			_function,
			-2 //--- Not on server
		] spawn BIS_fnc_MP;
	};
	//--- Server execution
	[_logic,(_logic call bis_fnc_moduleUnits),_activate] spawn (missionnamespace getvariable _function);
} else {
	[] spawn {true};
};

//--- Show an error when the function contains errors
if (isnil "_spawn") then {["Cannot execute module, error found in '%1'",_function] call bis_fnc_error; _spawn = [] spawn {true};};

//--- Dispose
if (_isDisposable) then {
	private ["_logicMain","_modules"];
	_logicMain = missionnamespace getvariable ["bis_functions_mainscope",objnull];
	_modules = (_logicMain getvariable ["bis_fnc_moduleInit_modules",[]]);
	_modules set [_modules find _logic,-1];
	_logicMain setvariable ["bis_fnc_moduleInit_modules",_modules,true];
	//deletevehicle _logic;
};

//--- Wait until the function is done and then mark the module as initialized
_time = diag_ticktime + 1;
waituntil {scriptdone _spawn || diag_ticktime > _time};
//_logic setvariable ["bis_fnc_moduleInit_status",true]; //--- Status is now set in BIS_fnc_moduleExecute
true