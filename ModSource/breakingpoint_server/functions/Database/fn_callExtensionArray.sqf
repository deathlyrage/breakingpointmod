params ["_data","_key","_status"];

//Removed Direct calls cause the freeze arma for long amounts of time
//_result = _key call BPServer_fnc_callExtensionDirect;

_ticket = _key call BPServer_fnc_callExtensionTicket;
_result = _ticket call BPServer_fnc_callExtensionResult;

["callExtensionArray: %1",_result] call BP_fnc_debugConsoleFormat;

if ((_result select 0) == _status) then {
	for "_i" from 1 to (_result select 1) do {
		0 = _data pushBack (_key call BPServer_fnc_callExtensionDirect);
	};
};