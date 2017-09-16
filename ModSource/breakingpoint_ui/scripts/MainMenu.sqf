disableSerialization;
//if (cheatsEnabled) then {"resource" diag_enable true};
private ["_control", "_dialog","_x","_action", "_moveDirection", "_moveButton","_buttonVectors"];
private ["_MENU_mp_array, _MENU_editor_array, _MENU_single_array, _MENU_campaign_array,_moveDirection"];

_in_delay = 0.5;
_out_delay = 0.25;
_no_move = [0,0]; 
_hidden = 1;
_action = "CA_MM_Init";

//Upon main manu load, global variables are dropped which causes loss of this array 
//initialized from onload. To prevent it, array is hardcoded. 
CA_MM_active_controls = ["Control #1130","Control #1110","Control #104","Control #105","Control #106","Control #109","Control #115","Control #117","Control #101","Control #301","Control #302","Control #303","Control #304"];
// IDCs of buttons to animate
_MENU_mp_array = [105,1031,1032,1033,1034];
_MENU_editor_array = [115,1041,1042,1043,1044];
_MENU_single_array = [117,1011,1012,1013,1014];
_MENU_campaign_array = [101,1021,1022,1023,1024];
_MENU_tutorials_array = [1110,1111,1112,1113,1114];
_MENU_library_array = [1130,1131,1132,1133,1134];
_MENU_play_array = _MENU_campaign_array + _MENU_single_array + _MENU_library_array + _MENU_tutorials_array;
  
_MENU_video_array = [301,1071,1072,1073,1074];
_MENU_audio_array = [302,1081,1082,1083,1084];
_MENU_controls_array = [303,1091,1092,1093,1094];
_MENU_difficulty_array = [304,1101,1102,1103,1104];
_MENU_options_array = _MENU_audio_array + _MENU_video_array + _MENU_difficulty_array + _MENU_controls_array;

_MENU_play = 1050;
_MENU_options = 1060;

_MENU_options_buttons = [_MENU_video_array, _MENU_audio_array, _MENU_controls_array, _MENU_difficulty_array ];
_MENU_play_buttons = [_MENU_single_array, _MENU_campaign_array, _MENU_tutorials_array, _MENU_library_array ];

_buttonVectors = [[-0.135,-0.18],[0,-0.36],[0,-0.18],[0.135,-0.18]];

//control reference initialization
//ensures that this script can be called by control and also by dialog
if ( typeName(_this select 0) == "DISPLAY" ) then {
	_control = 0;
	_dialog = _this select 0;
} else {
	_control = _this select 0;
	_dialog = ctrlParent _control;
};

//processIDCs is hiding, showing and moving controls
//array CA_VO_active_controls has to be present to ensure focus works properly
_processIDCs = {
	private ["_processIDCs", "_ctrldelay", "_move_ctrl","_ctrl_delay","_fade","_control","_disp_ctrl","_posX","_posY"];
	
	//get input variables
	_processIDCs = _this select 0;
	_fade = _this select 1;
	_ctrl_delay = _this select 2;
	_move_ctrl = _this select 3;
	
	for [{_x=0},{_x<=(count _processIDCs)},{_x=_x+1}] do 
	{
		_control = _processIDCs select _x;
		_disp_ctrl = (_dialog displayCtrl _control); 

		switch _fade do 
		{
			case true: 
			{
				//Hide control
				_disp_ctrl ctrlSetFade 1;
				//Disable controls to disallow focusing them
				_disp_ctrl ctrlEnable false;
			};
			case false: 
			{
				_disp_ctrl ctrlSetFade 0;
				//Restore focusability of the control, if found in list of active IDCs 
				if (CA_MM_active_controls find str(_disp_ctrl) != -1) then {
					_disp_ctrl ctrlEnable true;
				};				
			};			
		};
		
		_posX = ((ctrlPosition _disp_ctrl) select 0)+ (_move_ctrl select 0); 
		_posY = ((ctrlPosition _disp_ctrl) select 1) + (_move_ctrl select 1);
		
		_disp_ctrl ctrlSetPosition [_posX, _posY]; 		
		_disp_ctrl ctrlCommit _ctrl_delay;
	};
};

//Decides about action based on IDC calling this script
switch _control do
{
	case (_dialog displayctrl _MENU_play): 
	{
		_action = "CA_MM_TogglePlay";
	};
	case (_dialog displayctrl _MENU_options): 
	{
		_action = "CA_MM_ToggleOptions";
	};
};

//Main global variables are rather initialized based on the position of the buttons
//due to possible loss of global variables when intro animation is restarted 
_playButtonsDelta = (abs(((ctrlPosition (_dialog displayCtrl 117)) select 1) - ((ctrlPosition (_dialog displayCtrl 101)) select 1)));
_optionsButtonsDelta = (abs(((ctrlPosition (_dialog displayCtrl 302)) select 1) - ((ctrlPosition (_dialog displayCtrl 304)) select 1)));

if (_action == "CA_MM_Init") then {
	CA_MM_Play_visible = false; 
	CA_MM_Options_visible = false;
} else {
	CA_MM_Play_visible = (_playButtonsDelta > 0.01); 
	CA_MM_Options_visible = (_optionsButtonsDelta > 0.01);
};
//If button are still animated, wait
//Input during animation would cause faulty behaviour
if ( !(ctrlCommitted (_dialog displayCtrl 117)) || !(ctrlCommitted (_dialog displayCtrl 301)) ) then {
	_action = "CA_MM_Wait";
}; 

switch _action do 
{
	//Button position and status initialization, everything is hiden
	case "CA_MM_Init":
	{
		private ["_i"];		
		for [{_i = 0},{_i < 5},{_i = _i +1}] do {	
			[(_MENU_play_buttons select _i), !(CA_MM_Play_visible), 0, [( -1) * ( (_buttonVectors select _i) select 0), ( -1) * ( (_buttonVectors select _i) select 1)]] call _processIDCs;
			[(_MENU_options_buttons select _i), !(CA_MM_Options_visible), 0, [( -1) * ( (_buttonVectors select _i) select 0), ( -1) * ( (_buttonVectors select _i) select 1)]] call _processIDCs;
		};	
	};	
	case "CA_MM_TogglePlay": 
	{
		_moveButton = if (CA_MM_Options_visible) then { 1; } else { 0; };
		_moveDirection = if (CA_MM_Play_visible) then { -1; } else { 1; };
		
		//change status
		CA_MM_Play_visible = !(CA_MM_Play_visible);
		CA_MM_Options_visible = false;	 
		
		//different speed for opening and closing
		_delay = if (CA_MM_Play_visible) then { _in_delay; } else { _out_delay; };
				
		private ["_i"];
		for [{_i = 0},{_i < 5},{_i = _i +1}] do {	
			[(_MENU_play_buttons select _i), !(CA_MM_Play_visible), _delay, [_moveDirection * ( (_buttonVectors select _i) select 0), _moveDirection * ((_buttonVectors select _i ) select 1)]] call _processIDCs;					
			[(_MENU_options_buttons select _i), !(CA_MM_Options_visible), _out_delay, [ (_moveDirection * -1) * _moveButton * ( (_buttonVectors select _i) select 0), (_moveDirection * -1) * _moveButton * ( (_buttonVectors select _i) select 1)]] call _processIDCs;			
		};
	}; 

	case "CA_MM_ToggleOptions":
	{				
		_moveButton = if (CA_MM_Play_visible) then { 1; } else { 0; };
		_moveDirection = if (CA_MM_Options_visible) then { -1; } else { 1; };	
		
		CA_MM_Options_visible = !(CA_MM_Options_visible);
		CA_MM_Play_visible = false;
		
		_delay = if (CA_MM_Options_visible) then { _in_delay; } else { _out_delay; };
		
		private ["_i"];
		for [{_i = 0},{_i < 5},{_i = _i +1}] do {	
			[(_MENU_options_buttons select _i), !(CA_MM_Options_visible), _delay, [_moveDirection * ( (_buttonVectors select _i) select 0), _moveDirection * ((_buttonVectors select _i ) select 1)]] call _processIDCs;
			[(_MENU_play_buttons select _i), !(CA_MM_Play_visible), _out_delay, [ (_moveDirection * -1) * _moveButton * ( (_buttonVectors select _i) select 0), (_moveDirection * -1) * _moveButton * ( (_buttonVectors select _i) select 1)]] call _processIDCs;
		};
	};
	case "CA_MM_Wait":
	{
		//please click later, controls are busy :)		
	};
};
