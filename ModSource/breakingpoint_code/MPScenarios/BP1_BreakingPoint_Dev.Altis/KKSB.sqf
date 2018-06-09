//[SB_CALLER, {}] call SB_CALLBACK;
//[SB_CALLER, compile format ["hint str [time, %1]", time]] call SB_CALLBACK;
//[SB_CALLER, compile format ["hint str [str isDedicated, %1]", str str isDedicated]] call SB_CALLBACK;
//[SB_CALLER, compile format ["hint str [str isDedicated, str isServer, %1, %2]", str str isDedicated, str str isServer]] call SB_CALLBACK;
SBServerExec = [];
SBClientExec = [];
if (isDedicated) then {
	SB_CALLBACK = {
		SBClientExec = [_this select 0, _this select 1, if (count _this > 2) then [{format ["%1", call (_this select 1)]},{nil}]];
		(owner (_this select 0)) publicVariableClient "SBClientExec";
	};
	"SBServerExec" addPublicVariableEventHandler {
		SB_CALLER = _this select 1 select 0;
		SB_CODE = _this select 1 select 1;
		call compile SB_CODE;
	};
} else {
	SB_CALL = {
		SBServerExec = [_this select 0, _this select 1];
		publicVariableServer "SBServerExec";
	};
	SB_EXEC = {
		private ["_code","_codeArr"];
		switch (_this) do {
			case 1 : {
				_code = ctrlText ((findDisplay 10000) displayCtrl 9999);
				call compile _code;
			};
			case 2 : {
				_code = ctrlText ((findDisplay 10000) displayCtrl 9998);
				[player, _code] call SB_CALL;
			};
			case 3 : {
				_code = ctrlText ((findDisplay 10000) displayCtrl 9997);
				[player, "[SB_CALLER, {" + _code + "}, true] call SB_CALLBACK"] call SB_CALL;
			};
		};
		_codeArr = toArray _code;
		_codeArr = _codeArr - [32];
		if (count _codeArr > 0 && {_codeArr select (count _codeArr - 1) == 59}) then {closeDialog 0};
	};
	"SBClientExec" addpublicVariableEventHandler {
		SB_CALLBACK_CALLER = _this select 1 select 0;
		SB_CALLBACK_CODE = _this select 1 select 1;
		SB_CALLBACK_RESULT = _this select 1 select 2;
		if (!isNil "SB_CALLBACK_RESULT") then {
			hint format ["- SERVER SIDE HINT -\n\n%1", SB_CALLBACK_RESULT];
		} else {
			call SB_CALLBACK_CODE;
		};
	};
	/*
	if_Zeus = {
		if (inputAction "CuratorInterface" > 0) then {
			0 = 0 spawn {
				waitUntil {!isNull findDisplay 312 && !isNull curatorCamera};
				sleep 0.5;
				curatorCamera attachTo [vehicle player, [0,-5,5]];
				curatorCamera setVectorUp [0,0.4,0.6];
				sleep 0.1;
				detach curatorCamera;
			};
		};
		false
	};
	*/
	0 = 0 spawn {
		waitUntil {!isNull findDisplay 46};
		findDisplay 46 displayAddEventHandler ["KeyDown", {
			if (_this select 1 in actionKeys "IngamePause") then {
				0 = 0 spawn {
					waitUntil {!isNull findDisplay 49};
					waitUntil {isNull findDisplay 49};
					createDialog 'sandbox';
				};
			};
			false
		}];
	};
};

/*
//Zeus interface
if (isDedicated) then {
	curatorObj = objNull;
	curatorAddonsArr = [];
	_cfg = configFile >> "CfgPatches";
	for "_i" from 0 to count _cfg - 1 do {
		curatorAddonsArr set [_i, configName (_cfg select _i)];
	};
	"playerServer" addPublicVariableEventHandler {
		0 = 0 spawn {
			if (!isNull curatorObj) then {
				unassignCurator curatorObj;
				deleteVehicle curatorObj;
			};
			curatorObj = createGroup sideLogic createUnit [
				"ModuleCurator_F",
				[0,0,0], 
				[], 
				0,
				"NONE"
			];
			waitUntil {
				_arr = toArray str curatorObj;
				_arr resize 6;
				_arr isEqualTo [76,32,90,101,117,115] //L Zeus
			};
			playerServer assignCurator curatorObj;
			curatorObj addCuratorAddons curatorAddonsArr;
		};
	};
} else {
	0 = 0 spawn {
		waitUntil {!isNull player};
		waitUntil {time > 0};
		playerServer = player;
		publicVariableServer "playerServer";
		player removeAllEventHandlers "Respawn";
		player addEventHandler ["Respawn", {
			playerServer = player;
			publicVariableServer "playerServer";
		}];
	};
};
*/