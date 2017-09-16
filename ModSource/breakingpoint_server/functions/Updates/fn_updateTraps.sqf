_changed = false;
{
	_x params ["_trapUID","_trap"];
	if (isNull _trap) then
	{
		_changed = true;
		BP_Traps deleteAt _forEachIndex;
		[_trapUID] call BPServer_fnc_deleteTrap;
	};
} forEach BP_Traps;

if (_changed) then { publicVariable "BP_Traps"; };