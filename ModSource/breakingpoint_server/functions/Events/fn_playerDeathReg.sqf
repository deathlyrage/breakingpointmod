/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

// Fetch Input Params
params [["_characterID","0",[""]]];

// Ensure Valid Character ID is Sent 
if (_characterID == "0") exitWith {};

// Keep A Cache List Of All Dead People In Case Hive Extension is Failing
BP_DeadCharacters pushBack _characterID;