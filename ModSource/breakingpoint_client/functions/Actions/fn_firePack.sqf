/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_obj"];

_obj = _this select 3;

player playActionNow "Medic";

sleep 6;

if (BP_hasFire == _obj) then {
	BP_hasFire = objNull;
};

deleteVehicle _obj;

cutText ["You have removed the fireplace.", "PLAIN DOWN"];

player removeAction s_player_fireout;
s_player_fireout = -1;