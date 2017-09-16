/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_entity = _this select 3;

if (isNull _entity) exitWith {};

player removeAction s_player_destroyVehicle;
s_player_destroyVehicle = -1;
player removeAction s_player_destroySafe;
s_player_destroySafe = -1;

_leaveReturn = ["Are you sure you would like to destroy this object? It will detonate in several seconds. ","Destroy Object",nil,true] call BIS_fnc_guiMessage;
if (!_leaveReturn) exitWith {};

_hasIED = "BP_IED1_Mag" in magazines player;
if (!_hasIED) exitWith {};

player removeMagazine "BP_IED1_Mag";

[_entity] spawn
{
	sleep 7;
	[BP_characterID,(netID (_this select 0)),"Explode",(netID player)] remoteExecCall ["BPServer_fnc_deleteObj",2];
};
