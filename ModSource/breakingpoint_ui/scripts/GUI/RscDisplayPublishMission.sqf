disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 1010) ctrlSetText profileName;
		[_display, 1010] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//Sets all static texts toUpper
		["RscDisplayPublishMission",["RscText","RscTitle"],["PlayersName","TextSteamQuota","TextLicence"]] call bis_fnc_toUpperDisplayTexts;
	};
		
		
		// //--- Publish button
		// _control = _display displayctrl 118;
		// _control ctrladdeventhandler ["buttonclick","with uinamespace do {['publish',_this,''] call RscDisplayPublishMission_script};"];
		// //--- Set focus to GENERAL button
		// ctrlSetFocus _control;
		
		// //--- Update button
		// _control = _display displayctrl 105;
		// _control ctrladdeventhandler ["buttonclick","with uinamespace do {['update',_this,''] call RscDisplayPublishMission_script};"];
		// // TODO: put it in the group!
		// _MissionSizeText = _display displayctrl 1011;				//Scenario size text
		// _UpdateBtn = _display displayctrl 108;				//UPDATE button		
		// _DeleteBtn = _display displayctrl 117;				//DELETE button		
		// _UpdateChangeNoteText = _display displayctrl 1005;  //UPDATE changenote text
		// _UpdateChangeNote = _display displayctrl 110;		//UPDATE changenote 

		// //--- Disable Update group
		// _UpdateGroup = _display displayctrl 2301;
		// _UpdateGroup ctrlenable false;
		// _UpdateGroup ctrlshow false;
		// _MissionSizeText ctrlshow false;
		// _UpdateBtn ctrlshow false;
		// _DeleteBtn ctrlshow false;
		// _UpdateChangeNoteText ctrlshow false;
		// _UpdateChangeNote ctrlshow false;
	// };
	
	// //--- Publish button
	// case "publish": {

		// _ctrl = _params select 0;
		// _display = ctrlparent _ctrl;

		// _UpdateGroup = _display displayctrl 2301;
		// _PublishBtn = _display displayctrl 107;		//PUBLISH button
		// _ctrlPublish = _display displayctrl 118;	//PUBLISH tab
		// // TODO: put it in the group!
		// _MissionSizeText = _display displayctrl 1011;	//Scenario size text
		// _UpdateBtn = _display displayctrl 108;		//UPDATE button
		// _DeleteBtn = _display displayctrl 117;		//DELETE button
		// _UpdateChangeNoteText = _display displayctrl 1005;  //UPDATE changenote text
		// _UpdateChangeNote = _display displayctrl 110;		//UPDATE changenote 

		// //--- Enable Publish
		// _PublishBtn ctrlshow true;
		
		// //--- Disable Update
		// _UpdateGroup ctrlenable false;
		// _UpdateGroup ctrlshow false;
		// _MissionSizeText ctrlshow false;
		// _UpdateBtn ctrlshow false;
		// _DeleteBtn ctrlshow false;
		// _UpdateChangeNoteText ctrlshow false;
		// _UpdateChangeNote ctrlshow false;
		
		// //--- Set focus to PUBLISH button
		// ctrlSetFocus _ctrlPublish;
	// };
	
	// //--- Update button
	// case "update": {

		// _ctrl = _params select 0;
		// _display = ctrlparent _ctrl;

		// _UpdateGroup = _display displayctrl 2301;
		// _PublishBtn = _display displayctrl 107;	//PUBLISH button
		// _ctrlUpdate = _display displayctrl 105;	//UPDATE tab
		// // TODO: put it in the group!
		// _MissionSizeText = _display displayctrl 1011;	//Scenario size text
		// _UpdateBtn = _display displayctrl 108;	//UPDATE button
		// _DeleteBtn = _display displayctrl 117;	//DELETE button
		// _UpdateChangeNoteText = _display displayctrl 1005;  //UPDATE changenote text
		// _UpdateChangeNote = _display displayctrl 110;		//UPDATE changenote 

		// //--- Enable Update
		// _UpdateGroup ctrlenable true;
		// _UpdateGroup ctrlshow true;
		// _MissionSizeText ctrlshow true;
		// _UpdateBtn ctrlshow true;
		// _DeleteBtn ctrlshow true;
		// _UpdateChangeNoteText ctrlshow true;
		// _UpdateChangeNote ctrlshow true;
		
		// //--- Disable Publish
		// _PublishBtn ctrlshow false;
		
		// //--- Set focus to UPDATE button
		// ctrlSetFocus _ctrlUpdate;
	// };
	
};