/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_array","_dog","_dogHandle","_standing","_handle","_watchDog"];
_array = _this select 3;
_dog = _array select 0;
_dogHandle = _array select 1;
_standing = _dogHandle getFSMVariable "_standing";
_dogHandle setFSMVariable ["_command","stay"];
_watchDog = _dogHandle getFSMVariable "_watchDog";

_anim = animationState _dog;
if (_anim == "Dog_SitDown" and _watchDog) then {
	//[objNull, _dog, rSwitchMove,"Dog_SitUp"] call RE;
	//sleep 0.5;
	//[objNull, _dog, rSwitchMove,"Dog_LieDown"] call RE;
};

//Player Whistle
[player,"dog_whistleStay",0,false] call BP_fnc_objSpeak;

//Delay
sleep 1;

//Dog Bark
_dog playActionNow "GestureBark";
[_dog,"dog_bark",0,false] call BP_fnc_objSpeak;