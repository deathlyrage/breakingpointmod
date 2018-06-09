/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_objectNetID","_anim"];
_object = objectFromNetID _objectNetID;
if (isNull _object) exitWith {};
if (_anim == "") exitWith {};
_object switchMove _anim;