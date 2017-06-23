/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_unit","_distance","_doSprint","_pos"];

{
	_global = (!local _x);
	_x setVariable ["myDest",_pos,_global];
	if (_doSprint) then {
		_x setVariable ["myDestSpeed",3,_global]; //Sprint
	} else {
		_x setVariable ["myDestSpeed",2,_global]; // Run
	};
} count (_pos nearEntities ["zZombie_Base",_distance]);
