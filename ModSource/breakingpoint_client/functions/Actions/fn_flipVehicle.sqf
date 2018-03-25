/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_object","_position"];
_object = _this select 3;

player removeAction s_player_flipveh;
s_player_flipveh = -1;

//_position = [position _object,0,0,0,0,0,0,position player] call BIS_fnc_findSafePos;
player playMove "amovpknlmstpslowwrfldnon_amovpercmstpsraswrfldnon";
[player,"repair",0,true] call BP_fnc_objSpeak;
waitUntil { animationState player != "amovpknlmstpslowwrfldnon_amovpercmstpsraswrfldnon"};
_position = getPosATL _object;
sleep 2;
_object setVectorUp [0,0,1];
_object setPosATL [_position select 0,_position select 1,0];
_handle = [player,20,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
[_handle] call BP_fnc_addThreadHandle;
sleep 3;