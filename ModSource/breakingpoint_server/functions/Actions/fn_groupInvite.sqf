/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_p1NetID","_p2NetID","_groupID"];
_p1 = objectFromNetID _p1NetID;
_p2 = objectFromNetID _p2NetID;

//Units Valid
if (isNull _p1) exitWith {};
if (isNull _p2) exitWith {};

//Units are Players
if (!isPlayer _p1) exitWith {};
if (!isPlayer _p2) exitWith {};

//Units are alive
if (!alive _p1) exitWith {};
if (!alive _p2) exitWith {};

//Tell Player 2 he has been invited.
BP_GroupInvite = [(netID _p1),_groupID];
(owner _p2) publicVariableClient "BP_GroupInvite";