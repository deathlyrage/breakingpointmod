/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

//Slow compared to other database callback functions

[format [ "r:%1", "BreakingPointExt" callExtension format [ "s:%1", _this select 0 ] ], _this select 1] spawn
{
	waitUntil
	{
		_res = parseSimpleArray ("BreakingPointExt" callExtension (_this select 0));
		if (_res != "WAIT") exitWith { 
			_res call (_this select 1); 
			true
		}; 
		false
	};
};