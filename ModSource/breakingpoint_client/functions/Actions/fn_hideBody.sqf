/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_body"];
_body = (_this select 3);

//Remove Action
player removeAction s_player_hidebody;
s_player_hidebody = -1;

//Ensure Body Isn't Null
if (isNull _body) exitWith {};

_fire = _body getVariable ["fire",objNull];
if !(isNull _fire) then
{
	[_body,_fire] remoteExecCall ["BP_fnc_fireDelete",0];
};

//Cleanup Body
deleteVehicle _body;