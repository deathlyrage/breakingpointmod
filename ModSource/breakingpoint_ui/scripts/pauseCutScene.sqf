disableSerialization;
private ["_event","_data","_display","_control"];
_event = _this select 1;
_data = _this select 0;


debugLog format ["WF_SKIP_ pauseCutScene.sqf %1", _this];

debuglog _data;
if(typeName(_data select 0) == "DISPLAY")then {  
  _display = (_data select 0);
};

if(typeName(_data select 0) == "CONTROL")then
{
  _control = (_data select 0);
  _display = ctrlParent _control;
};
debuglog "custcene pause";

private["_toggleButton", "_eventHandled"];
_eventHandled = false;

_toggleButton = 
{
	private ["_button", "_action", "_buttonID"];
	_button = _this select 0;
	_action = _this select 1;
	_buttonID = 0;
	switch(_button) do
	{
		case "save":{_buttonID = 103};
		case "restart":{_buttonID = 119};
		case "skip":{_buttonID = 1002};
		case "again":{_buttonID = 1003};
	};
	_control = (_display displayCtrl _buttonID); 
	if(_action == "enable") then
	{
		//DEBUGLOG format["pauseCutScene: enabling button: %1", _buttonID];
		_control ctrlEnable true; 
		_control ctrlSetFade 0;
		_control ctrlCommit 0;		
	}
	else
	{
		//DEBUGLOG format["pauseCutScene: disabling button: %1", _buttonID];
		_control ctrlEnable false; 
		_control ctrlSetFade 1;
		_control ctrlCommit 0;	
	};
};


if (isNil("BIS_sceneState")) then {BIS_sceneState=false;};
if (isNil("BIS_sceneJumpable")) then {BIS_sceneJumpable=true;};
if (isNil("BIS_sceneLoadable")) then {BIS_sceneLoadable=true;};

if (isNil "BIS_WF_FastTravelInProgress") then {BIS_WF_FastTravelInProgress = false;};

if (BIS_sceneState) then 
{
	["save", "disable"] call _toggleButton;
	if(!BIS_sceneJumpable) then
	{
		["skip", "disable"] call _toggleButton;	
	};
	if(!BIS_sceneLoadable) then
	{
		["restart", "enable"] call _toggleButton;
		["again", "disable"] call _toggleButton;
	}
	else
	{
		["restart", "disable"] call _toggleButton;	
	};
} 
else 
{
  if (BIS_WF_FastTravelInProgress) then
  {//FT in Warfare - we need skip button only
    ["save", "disable"] call _toggleButton;
    //["restart", "disable"] call _toggleButton;
	  ["again", "disable"] call _toggleButton;
	  
	  if (BIS_WF_FastTravelSkip) then {["skip", "disable"] call _toggleButton;};
	  
  }
  else
  {        
	["skip", "disable"] call _toggleButton;
	["again", "disable"] call _toggleButton;
  };
};

switch _event do {
  case "skip": 
  {
  	if(!isnil "BIS_scenesController") then
  	{
  		DEBUGLOG "pauseCutScene: Skipping scene";
	 	BIS_scenesController setFSMVariable ["sceneToStop", BIS_scenesController getFSMVariable "currentrunningscene"];
	 	//_eventHandled = true;
	 	BIS_sceneEventHandled = true;
	}
	else
	{
		if(BIS_debugModules) then {DEBUGLOG "pauseCutScene: not possible to skip scene - scenes controller is not running"};
		
		if (BIS_WF_FastTravelInProgress) then 
		{
		  BIS_WF_FastTravelSkip = true;
		  hint (localize "strwffasttravel" + " " + localize "str_cfg_markers_end"); 
		};
	};
  };
  case "again": 
  {
  	//LoadAutosavedGame
  	loadGame;
  };
  case "onload": {};
  case "unload": 
  {
	if(BIS_sceneState) then
	{
		if(isNil "BIS_sceneEventHandled") then
		{
		  	if(BIS_sceneLoadable) then
		  	{
		  		DEBUGLOG format["pauseCutScene: Loading scene._eventHandled = %1", _eventHandled];
				loadGame;		  	
			};
		};
	};
	BIS_sceneEventHandled = nil;
  };
};