/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_logic","_channel",["_msg","",[""]]];

["customChat: Logic: %1 | Channel: %2 | Msg: %3",_logic,_channel,_msg] call BP_fnc_debugConsoleFormat;

if (isNull _logic) exitWith {};

_logic setName ["SERVER","SERVER",""];
_logic customChat [_channel,_msg];
