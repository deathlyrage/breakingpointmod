/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_vehicle = _this select 3;

player removeAction s_player_pushBoat;
s_player_pushBoat = -1;

//_isWater = surfaceIsWater position player; 

//if (_isWater) exitwith {titleText ["You can't push from in the water","PLAIN DOWN",1];};

if (player in _vehicle) exitwith {titleText ["You can't push from inside the vehicle","PLAIN DOWN",1];};

if (!local _vehicle) exitwith {titleText ["Get in driver seat first!","PLAIN DOWN",1];};

player playMove "AmovPercMstpSnonWnonDnon_AinvPercMstpSnonWnonDnon_Putdown";

if (currentWeapon player == "") then {sleep 1;} else {sleep 2;};

_vehicle setVelocity [(sin(direction player))*3, (cos(direction player))*3, 0];  
