/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_array","_dog","_dogHandle"];
_array = _this select 3;
_dog = _array select 0;
_dogHandle = _array select 1;

//Player Whistle
[player,"dog_whistleNon",0,false] call BP_fnc_objSpeak;

//Delay
sleep 1;

//Dog Bark
_dog playActionNow "GestureBark";
[_dog,"dog_bark",0,false] call BP_fnc_objSpeak;
