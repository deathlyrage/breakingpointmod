/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Check Stronghold
_factionID = [player] call BP_fnc_strongholdNearby;
_factionName = _factionID call BP_fnc_getFactionName;
_playerClass = player getVariable ["class",0];
_playerFactionName = _playerClass call BP_fnc_getFactionName;

//Entering / Leaving a Stronghold
if (BP_FactionStronghold != _factionID) then
{
	//Entering Stronghold
	if (_factionID != 0 and BP_FactionStronghold == 0) then 
	{
		//Handle Event
		[player,_factionID] call BP_fnc_strongholdEnter; 
		BP_FactionStronghold = _factionID;
	};
	
	//Leaving Stronghold
	if (_factionID == 0 and BP_FactionStronghold != 0) then 
	{
		//Handle Event
		[player,BP_FactionStronghold] call BP_fnc_strongholdLeave; 
		BP_FactionStronghold = 0;
	};
};

//Stronghold Points Update
if (BP_FactionStronghold > 0) then 
{
	//Set Rating
	_pointsChange = 0;
	
	_traitorFlag = player getVariable ["traitorFlag",false];
	if (_traitorFlag) then
	{
		_pointsChange = 50;
	} else {
		if (uniform player in BP_TraitorClothing) then {
			_pointsChange = 50;
		} else {
			_pointsChange = getNumber (configFile >> "CfgFactions" >> _factionName >> "Points" >> "Kill" >> _playerFactionName >> "Level_1");
		};
	};

	if (_pointsChange > -1) then
	{
		//Player
		if (side player != west) then
		{
			_group = createGroup west;
			[player] joinSilent _group;
		};
		
		//_vehicle = (vehicle player);
		//if (_vehicle != player) then
		//{
		//	if (side _vehicle != west) then 
		//	{
		//		{
		//			if (side _x != west) then
		//			{
		//			};
		//		} count crew _vehicle;
		//		{
		//			_class = _x getVariable ["class",0];
		//			_factionName = _class call BP_fnc_getFactionName;
		//			_factionLevel = _x call BP_fnc_getFactionLevel;
		//			
		//			if (_factionLevel != 0 && {_factionName != "Hunter"}) then
		//			{
		//				_flag = _x getVariable ["traitorFlag",false];
		//				if (!_flag) then { _x setVariable ["traitorFlag",true,true]; };
		//			};
		//		} count crew _vehicle;
		//	};
		//};
	} else {
		//Player
		if (side player != civilian) then
		{
			_group = createGroup civilian;
			[player] joinSilent _group;
		};
	};
};