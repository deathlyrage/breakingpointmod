/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_object","_position"];
_object = _this select 3;
_position = [position _object,0,0,0,0,0,0,position player] call BIS_fnc_findSafePos;
player playMove "amovpknlmstpslowwrfldnon_amovpercmstpsraswrfldnon";
waitUntil { animationState player != "amovpknlmstpslowwrfldnon_amovpercmstpsraswrfldnon"};
sleep 2;
_object setVectorUp [0,0,1];
[player,"scream",0,true] call BP_fnc_objSpeak;
_handle = [player,20,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
[_handle] call BP_fnc_addThreadHandle;
sleep 3;