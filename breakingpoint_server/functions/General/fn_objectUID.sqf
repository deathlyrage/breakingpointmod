/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params [["_dir",0,[0]],["_position",[],[[]]],["_key","",[""]]];
{
	_x = _x * 10;
	if ( _x < 0 ) then { _x = _x * -10 };
	_key = _key + str(round(_x));
} count _position;
_key = _key + str(round(_dir));
_key