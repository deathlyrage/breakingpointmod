/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_unit = _this;
_myGroupID = player getVariable ["group","0"];
_groupMembers = [];

if (_myGroupID != "0") then {
	//Loop Though all players and find those who are in your group
	{
		if (!isNull _x) then {
			_groupUID = _x getVariable ["group","0"];
			if (_groupUID == _myGroupID) then 
			{ 
				0 = _groupMembers pushBack _x;
				//_dog = _x getVariable ["dog",objNull];
				//if (!isNull _dog) then {
				//	0 = _groupMembers pushBack _x;
				//};
			};
		};
	} count allPlayers;
};

if (_groupMembers isEqualTo []) then { 0 = _groupMembers pushBack player; };

_groupMembers