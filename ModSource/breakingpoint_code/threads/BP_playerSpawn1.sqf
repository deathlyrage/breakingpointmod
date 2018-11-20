/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_playerSpawn1"; 

_lastPos = [0,0,0];
_lastSpawnCheck = diag_tickTime;

waitUntil 
{
	_camPos = positionCameraToWorld [0,0,0];
	
	if (((_lastPos distance _camPos) > 175) || {(diag_tickTime - _lastSpawnCheck) > 45}) then
	{
		_lastSpawnCheck = diag_tickTime;
		_lastPos = _camPos;
		
		//Loot / Zombies
		call BP_fnc_spawnCheck;
		
		//Animals
		call BP_fnc_animalCheck;
	};

	//Update Group Members
	BP_Group = call BP_fnc_groupGetMembers;
	
	//Update Zombie Counts
	call BP_fnc_updateVars;
	
	//Update Havens
	call BP_fnc_buildingUpdate;
	
	//Reset Anti Key-Spam
	BP_lastCheckBit = 0;
	
	//Reveal Nearby Units / Cars / Helicopters
	{ player reveal _x } forEach allUnits;
	{ player reveal _x } forEach entities "Car";
	{ player reveal _x } forEach entities "Helicopter";
	
	_class = player getVariable ["class",0];
	_factionName = _class call BP_fnc_getFactionName;
	_isHunter = (_factionName == "Hunter");
	_factionLevel = player call BP_fnc_getFactionLevel;
	if (_isHunter and _factionLevel > 2) then {
	player setAnimSpeedCoef 1.07;
	};
	//Inside Buildings
	//_building = nearestObject [player, "HouseBase"];
	//_buildingLogic = nearestObject [player,"BP_Haven"];
	//_buildingLogicResult = _buildingLogic getVariable ["building",objNull];
	//_validBuildingLogic = (_building == _buildingLogicResult); 
	//_buildingLocked = (_building getVariable ['bis_disabled_Door',0] == 1);
	//_inside = [player,_building] call BP_fnc_isInsideBuilding;
	//if (_inside) then
	//{
	//	if (_buildingLocked) then
	//	{
	//		//Option to Enter Passcode
	//		if (_validBuildingLogic) then
	//		{
	//			[nil,nil,nil,[_building,_buildingLogic]] spawn BP_fnc_houseUnlock;
	//		};
	//		
	//		//Teleport Out
	//		cutText ["You are not allowed to be inside locked havens","PLAIN DOWN"];
	//		BP_HavenGlitch = [(netID player),(netID _building),_lastSafePosition];
	//		publicVariableServer "BP_HavenGlitch";
	//	};
	//} else {
	//	_lastSafePosition = (getPosATL player);
	//};

	//Thread Delay
	sleep 12;
	
	r_player_dead
};
