disableSerialization;
private  ["_test","_data","_action","_display","_control","_lbUsersControl","_selectedUserIndex","_selectedUser","_selectedUserData","_selectedName","_isAdmin"];
private ["_isAdminInt","_x","_selectedMission","_lbMissionsControl","_selectedMissionIndex","_close","_delayControl","_uiSleep","_dummy"];
private ["_votingAllowed","_votingAllowedInt","_x"];
private ["_userIDCs","_voteIDCs","_voteGroupIDC","_userGroupIDC","_adminGroupIDC","_adminIDCs"];

_serverConnnected = true;


_data = _this select 0;
_action = _this select 1;
debuglog _action;
if(typeName(_data select 0) == "DISPLAY")then 
{
	_display = (_data select 0);
};

if(typeName(_data select 0) == "CONTROL")then 
{
	_control = (_data select 0);
	_display = ctrlParent _control;
};


if (serverCommandAvailable "#vote") then {  
  _votingAllowed = true;
  _votingAllowedInt = 0;
};

//||(_action == "logout"))

if (serverCommandAvailable "#logout") then {
  _isAdmin = true;
	_isAdminInt = 1;
	_votingAllowed = false;
  _votingAllowedInt = 1;

	} else {
  _isAdmin = false;
	_isAdminInt = 0;
};

_delay = 0.5;
if (_action=="onload") then {
	_delay = 0;
};


_userIDCs = [1211,1113,1122];
_voteIDCs = [1116,1118,1229,1222,1156,1119];
_adminIDCs = [1252,1216,1217,1221,1120,1127,1149,1145,1111];
//admin 1026
//user 1025
for [{_x=0},{_x < count(_adminIDCs)},{_x=_x+1}] do {
  _adminGroupIDC = _display displayCtrl (_adminIDCs select _x);
  _adminGroupIDC ctrlEnable _isAdmin;
  _adminGroupIDC  ctrlSetFade (1 - _isAdminInt);
  _adminGroupIDC  ctrlCommit _delay;
};
_editPwdBackground = _display displayCtrl 1123;
_editPwdBackground ctrlEnable false;

for [{_x=0},{_x < count(_userIDCs)},{_x=_x+1}] do {

  _userGroupIDC = _display displayCtrl (_userIDCs select _x);
  _userGroupIDC ctrlEnable !(_isAdmin);
  _userGroupIDC ctrlSetFade _isAdminInt;
  _userGroupIDC ctrlCommit _delay;
};

for [{_x=0},{_x < count(_voteIDCs)},{_x=_x+1}] do {
  _voteGroupIDC = _display displayCtrl (_voteIDCs select _x);
  _voteGroupIDC ctrlEnable (_votingAllowed);
  if (_isAdmin) then {_voteGroupIDC  ctrlSetFade 1};
  _voteGroupIDC  ctrlCommit _delay;
};

//set user rating in the listbox
_lbUsersControl = _display displayCtrl 101;
_lbUsersSize = lbSize _lbUsersControl;

for [{_x=0},{_x < _lbUsersSize},{_x=_x+1}] do {
	_selectedUserData = _lbUsersControl lbData _x;		
	
	for [{_y=0},{_y < count(playableUnits)},{_y=_y+1}] do {
	
		_playerName = name(playableUnits select _y);		

		if (_selectedUserData == _playername) then {

				_rating = -1*rating(playableUnits select _y);
				_lbUsersControl lbSetValue [_x, _rating];
				if (_rating > 0) then {
					    _lbUsersControl lbSetColor [_x, [1,0,0,1]];
				};
		};
	};		
};

//lbSortByValue _lbUsersControl; 



//selected user
_lbUsersControl = _display displayCtrl 101;
_selectedUserIndex = lbCurSel _lbUsersControl;
_selectedUser = _lbUsersControl lbValue _selectedUserIndex;
_selectedUserData = _lbUsersControl lbData _selectedUserIndex;
_selectedUserText = _lbUsersControl lbText _selectedUserIndex;
_selectedName = _selectedUserData;


//selected mission
_lbMissionsControl = _display displayCtrl 102;
_selectedMissionIndex = lbCurSel _lbMissionsControl;
_selectedMission = _lbMissionsControl lbValue _selectedMissionIndex;
_selectedMissionData = _lbMissionsControl lbData _selectedMissionIndex;
_selectedMissionText = _lbMissionsControl lbText _selectedMissionIndex;
_selectedMission = _selectedMissionData;


//don't kick/ban yourself


//password
_editPassControl = _display displayCtrl 1113;
_password = ctrlText _editPassControl;
_close = false;

switch _action do {
 case "Kick": { 
 		debuglog "kick execute";
 		serverCommand ("#kick " + _selectedName); 
 		debuglog ("#kick " + _selectedName); 
 };
 case "ban": { 
 		debuglog "ban execute";
 		serverCommand ("#ban " + _selectedName); 
 		debuglog ("#ban " + _selectedName); 
 }; 	
 case "vote_kick": {  	serverCommand ("#vote kick " + _selectedName);   };
 case "vote_admin": {  	serverCommand ("#vote admin " + _selectedName);   };
 case "login": { serverCommand ("#login " + _password);};
 	
 case "logout": { serverCommand "#logout";  		_close = true;};
 
 case "shutdown": { 
 		serverCommand "#shutdown"; 
 		_close = true;
 	}; 
 	
 case "mission": { 
 		serverCommand ("#mission " + _selectedMission); 
 		_close = true;
 	}; 
 
 case "vote_mission": { 
 			serverCommand ("#vote mission " + _selectedMission);  			
 };  	
 	 
 case "missions": { 
 		serverCommand "#missions"; 
 		_close = true;
 }; 
 
 case "vote_missions": { serverCommand "#vote missions"; }; 
 	
 case "reassign": { 
 	serverCommand "#reassign"; 
 	_close = true;
 };
 	
 case "vote_reassign": { 
 	serverCommand "#vote reassign"; 
 }; 	
 	
 case "restart": { 
 		serverCommand "#restart"; 
 		_close = true;
 	}; 
 	
 case "vote_restart": {serverCommand "#vote restart"; };			
};

_cancel = _display displayCtrl 2;
if (_close) then {
		ctrlActivate _cancel;
};
if !((serverCommandAvailable "#login") || (serverCommandAvailable "#logout")) then {
		ctrlActivate _cancel;
};

//server shutdown
if ((serverCommandAvailable "#login") && (serverCommandAvailable "#logout")) then {
		//ctrlActivate _cancel;
};


//1352


_uiSleep = {
		_delayControl =_display displayCtrl 1352;
		_pos = 1 - ((ctrlPosition _delayControl) select 1);
		_delayControl ctrlSetPosition [0, _pos];
		_delayControl ctrlCommit _this;
		while {!(ctrlCommitted _delayControl)} do {};
		true;
};




if ((_action == "login") or (_action == "logout") or (_action == "kick") or (_action == "vote_admin")) then  {
		_dummy = 0.8 call _uiSleep;
		_test = [_data,"reload"] execVM "\A3\ui_f\scripts\dedicatedServerInterface.sqf";
};

