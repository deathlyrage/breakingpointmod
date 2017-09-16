/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Update Group Data
_groupUID = player getVariable ["group","0"];
_playerDog = player getVariable ["dog",objNull];
if (_groupUID == "0" and isNull _playerDog) exitWith 
{
	r_group_members = [];
	r_group_membersIcons = [];
};

//Process Group Icons
_i = 1;
_groupMembers = [];
_groupMembersIcons = [];
_vehicleList = [];

{
	if ((!isNull _x) && {alive _x}) then 
	{
		_vehicle = (vehicle _x);
		if (_vehicle == _x) then
		{
			//Add Player to Group Members Array
			_groupMembers pushBack _x;
			
			//Make sure not to draw local player
			if (!local _x) then
			{
				//Process Player's DrawIcon Data
				_memberClass = _x getVariable ["class",0];
				_memberFactionName = _memberClass call BP_fnc_getFactionName;
				_memberIcon = getText (configFile >> "CfgFactions" >> _memberFactionName >> "icon");
				_memberName = (name _x);
				_memberDistance = _x distance player;
				_memberColour = r_group_colours select _i;
				_memberDist = _x distance positionCameraToWorld [0,0,0];
				_memberPosIcon = visiblePositionASL _x;
				_memberPosIcon set [2, ((_x modelToWorld [0,0,0]) select 2) + 2.0]; // Torso height
				_memberPosText = visiblePositionASL _x;
				_memberPosText set [2, ((_x modelToWorld [0,0,0]) select 2) + 1.8]; // Torso height
				
				if (_memberDistance < 2000) then 
				{
					//Member Icon
					0 = _groupMembersIcons pushBack [_memberIcon, [255, 255, 255, 1], _memberPosIcon,1,1,0];
					
					if (_memberDistance < 1500) then 
					{
						//Member Name
						if (!isStreamFriendlyUIEnabled) then { 0 = _groupMembersIcons pushBack ["", _memberColour, _memberPosText,0,0,0,_memberName,0,0.04,"PuristaMedium"]; };
					};						
				};
			};
		} else {
			if !(_vehicle in _vehicleList) then
			{
				0 = _vehicleList pushBack _vehicle;
				if ((_vehicle distance player) < 1500) then
				{
					_memberPosIcon = visiblePositionASL _vehicle;
					_memberPosIcon set [2, ((_x modelToWorld [0,0,0]) select 2) + 2.0];
					0 = _groupMembersIcons pushBack ["\breakingpoint_ui\icons\WheelIcon.paa", [255, 255, 255, 1], _memberPosIcon,1,1,0];
				};
			};
		};
		
		//Draw Member Dog Icon
		_dog = _x getVariable ["dog",objNull];
		if (!isNull _dog) then
		{
			if (alive _dog) then
			{
				//Process Player's DrawIcon Data
				_memberIcon = "\breakingpoint_ui\icons\DogIcon.paa";
				_memberName = _dog getVariable ["bodyName",(name _dog)];
				_memberDistance = _dog distance player;
				_memberColour = [255, 255, 255, 1];
				_memberDist = _dog distance positionCameraToWorld [0,0,0];
				_memberPosIcon = visiblePositionASL _dog;
				_memberPosIcon set [2, ((_dog modelToWorld [0,0,0]) select 2) + 1.35]; // Torso height
				_memberPosText = visiblePositionASL _dog;
				_memberPosText set [2, ((_dog modelToWorld [0,0,0]) select 2) + 1.20]; // Torso height
				
				if (_memberDistance < 2000) then {
					//Member Icon
					0 = _groupMembersIcons pushBack [_memberIcon, [255, 255, 255, 1], _memberPosIcon,0.8,0.8,0];
					
					//Member Name
					if (_memberDistance < 1500) then {
						0 = _groupMembersIcons pushBack ["", _memberColour, _memberPosText,0,0,0,_memberName,0,0.04,"PuristaMedium"];
					};
				};					
			};
		};

		//Increment Index
		_i = _i + 1;
	};
} count BP_Group;

r_group_members = _groupMembers;
r_group_membersIcons = _groupMembersIcons;