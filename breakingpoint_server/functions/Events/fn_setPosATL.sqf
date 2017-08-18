_player = objectFromNetID (_this select 0);
if (isNull _player) exitWith {};
_player setPosATL (_this select 1);
[(getPlayerUID _player),(name _player),"Teleport"] call BPServer_fnc_adminlog;