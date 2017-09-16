_logic = [_this,0,objnull,[objnull]] call bis_fnc_paramIn;
_logic setvariable ["bis_fnc_moduleInit_status",false];
_logicType = typeof _logic;
_logic hideobject true;

//--- Register module priority. Modules with lower priority gets executed first
_functionPriority = getnumber (configfile >> "cfgvehicles" >> _logicType >> "functionPriority");
_isGlobal = getnumber (configfile >> "cfgvehicles" >> _logicType >> "isGlobal") > 0;
_isPersistent = getnumber (configfile >> "cfgvehicles" >> _logicType >> "isPersistent") > 0 || getnumber (configfile >> "cfgvehicles" >> _logicType >> "isGlobal") > 1;
_logic setvariable ["bis_fnc_initModules_priroty",abs _functionPriority];
_logic setvariable ["bis_fnc_initModules_activate",false];

//--- Set name for curator
_logic spawn {_this setname "";};

//--- Terminate on client when the function is not global
if (!isserver && !_isGlobal) exitwith {_logic setvariable ["bis_fnc_moduleInit_status",true];};

//--- Execute (spawned, so sycnhronizations have time to initialize)
[_logic,_logicType] spawn {
	_fnc_scriptName = "Module Init";
	scriptname _fnc_scriptName;

	_logic = _this select 0;
	_logicType = _this select 1;
	_isCuratorPlaced = side group _logic != sidelogic || count units _logic > 1;
	_logic setvariable ["bis_fnc_moduleInit_isCuratorPlaced",_isCuratorPlaced];

	//--- Load config settings
	_function = gettext (configfile >> "cfgvehicles" >> _logicType >> "function");
	_isTriggerActivated = getnumber (configfile >> "cfgvehicles" >> _logicType >> "isTriggerActivated") > 0;
	_isGlobal = getnumber (configfile >> "cfgvehicles" >> _logicType >> "isGlobal") > 0;
	_isDisposable = getnumber (configfile >> "cfgvehicles" >> _logicType >> "isDisposable") > 0;
	_isPersistent = getnumber (configfile >> "cfgvehicles" >> _logicType >> "isPersistent") > 0 || getnumber (configfile >> "cfgvehicles" >> _logicType >> "isGlobal") > 1;

	//--- Force activation
	_triggerCount = count (_logic call bis_fnc_moduleTriggers);
	if (isserver) then {
		//--- Activate modules created on the fly
		if (time > 0) then {_logic setvariable ["bis_fnc_initModules_activate",true];};
	} else {
		//--- Wait until server is loaded, so we get info about module execution
		waituntil {getClientState != "MISSION RECEIVED" && getClientState != "GAME LOADED"};

		//--- Activate non-trigger modules and trigger modules without any triggers synced
		_logic setvariable ["bis_fnc_initModules_activate",!_isTriggerActivated || (_isTriggerActivated && _triggerCount == 0)];
	};

	//--- Activate curator modules
	if (_isCuratorPlaced) then {_logic setvariable ["bis_fnc_initModules_activate",true];};

	//--- Wait until module init is allowed
	waituntil {_logic getvariable ["bis_fnc_initModules_activate",true] || isnull _logic};
	if (isnull _logic) exitwith {};

	//--- Terminate on client when the module is trigger activated, but was not activated yet. Ignored for curator modules.
	if (!isserver && !(_logic getvariable ["bis_fnc_moduleExecute_activate",!_isTriggerActivated])) exitwith {_logic setvariable ["bis_fnc_moduleInit_status",true];};

	//--- Remove global settings when executed on client
	_isGlobal = _isGlobal && isserver;
	_isTriggerActivated = _isTriggerActivated && isserver;
	_isPersistent = _isPersistent && isserver;

	//--- Ignore when params are wrong
	_logicMain = missionnamespace getvariable ["bis_functions_mainscope",objnull];
	_canExecute = true;
	if (isnull _logicMain) then {_canExecute = false; "Functions logic 'BIS_functions_mainscope' is missing" call bis_fnc_error;};
	if (isnull _logic) then {_canExecute = false; "Module logic is missing" call bis_fnc_error;};
	if (_function == "") then {_canExecute = false; "Module function is missing" call bis_fnc_error;};

	//--- Execute function
	private ["_time"];
	_time = diag_ticktime;
	if (_canExecute) then {
		_moduleParams = [
			_logic,
			_function,
			[_isGlobal,_isTriggerActivated,_isDisposable,_isPersistent],
			true
		];

		if !(_isCuratorPlaced) then {
			if (_isTriggerActivated && _triggerCount > 0) then {

				//--- Add to module list
				_moduleParams set [3,false]; //--- Param used as activation indicator
				_modules = _logicMain getvariable ["bis_fnc_moduleInit_modules",[]];
				_modules set [count _modules,_moduleParams];
				_logicMain setvariable ["bis_fnc_moduleInit_modules",_modules,true];

				//--- Mark the module as registered
				_logic setvariable ["BIS_fnc_moduleInit_registered",true,true];

				//--- Execute global FSM
				if (isnil "bis_fnc_moduleInit_fsm") then {
					bis_fnc_moduleInit_fsm = [_logic] call bis_fnc_moduleHandle;
				};
			} else {
				_moduleParams call bis_fnc_moduleExecute;
			};
		} else {
			//--- The module is agent
			_moduleParams call bis_fnc_moduleExecute;
		};
	};

	//--- Group to functions module and delete the previous group (only for logics in logic side, to avoid overriding custom grouping)
	if (isserver && side group _logic == sidelogic) then {
		_category = gettext (configfile >> "cfgvehicles" >> _logicType >> "category");
		_groupOld = group _logic;
		_group = missionnamespace getvariable ["bis_fnc_initModules_" + _category,group _logicMain];
		_ownerID = owner _logic;
		[_logic] joinsilent _group;
		_logic setowner _ownerID;
		if (count units _groupOld == 0) then {deletegroup _groupOld;};
	};

	//--- Mark as initialized
	_logic setvariable ["bis_fnc_moduleInit_status",true];

	_fnc_scriptname = "module";
	["%1 (%2 ms)",_function,(diag_ticktime - _time) * 1000] call bis_fnc_logformat;
};