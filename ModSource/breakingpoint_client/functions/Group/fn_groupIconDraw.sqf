/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Called Every Frame Use DrawIcon3D

//Update Group Icon Positions / Members
call BP_fnc_groupIconUpdate;

//Check For Valid Player Object Ref
if (isNull player) exitWith {};

//Check Health / Update
if (r_player_blood <= 0) exitWith { [17] call BP_fnc_death; };

//if (BP_isUndead) then {
//	if (cameraView != "internal") then { cameraOn switchCamera "internal"; };
//} else {
	//Draw Group Icons
{ if (count _x > 3) then { drawIcon3D _x; }; } count r_group_membersIcons;
//};