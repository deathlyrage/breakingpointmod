/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

if (!BP_Debug) exitWith {};
_building = nearestObject [player, "Building"];
_relPos = _building worldToModel (getPosATL player);
_relPos params ["_x","_y","_z"];
_coords = format ["{%1,%2,%3}", _x , _y , _z];
_str = format ["%1 %2",typeOf _building,_coords];
"debug_console" callExtension _str;