/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_array","_dog","_dogHandle","_whistle"];
_array = _this select 3;
_dog = _array select 0;
_dogHandle = _array select 1;
_whistle = _array select 2;

if (_whistle) then { [player,"dog_whistleFollow",0,false] call BP_fnc_objSpeak; };

if (_dog distance player <= 900) then { _dogHandle setFSMVariable ["_command","return"]; };

