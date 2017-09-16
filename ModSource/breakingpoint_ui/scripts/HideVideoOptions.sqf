disableSerialization;
private ["_control","_dialog","_action","_disp_ctrl","_OPT_advanced_array","_in_delay","_no_move","_hidden","_OPT_basic_array","_OPT_advanced_array"];
private ["_control","_disp_ctrl","_dialog"];
private ["_processIDCs","_fade","_ctrl_delay","_move_ctrl","_processIDCs","_x","_disp_ctrl","_posX","_posY","_move_ctrl"];
	
_in_delay = 0.7;
_out_delay = 0.25;
_no_move = [0,0]; 
_hidden = 1;
_delta = 0.31;

//_OPT_basic_array = [101,102,103,104,105,106,107,108,109,110,111,112,113,114,200,201,202,203,204,205,248,207,208,209,210,246,212,247,213,215,216,217,219,220,221,222,223,224,225,232,126,135,145,1220];

// Added aspect picture: 1202(background), 1203(foreground), removed 218(CA_PictureAspectRatio)
_OPT_basic_array = [126,232,213,1234,219,113,223,104,217,112,220,110,103,111,109,1236, 218,1104, 1202, 1203];
//MUF added 131(HDR), 257(HDR text), 140(Vsync), 258(Vsync text), 259(PIP text), 334(PIP)
_OPT_advanced_array = [131,139,140, 257, 258, 259, 334, 251,230,125,227, 228,1235,123,124,132,130,128,133,114,136,134,241,239,235,242,215,256,134,214,1105];
_OPT_array  = _OPT_basic_array + _OPT_advanced_array;

//Checks if IDC exists and if it is active, then it will put it to an array 
//required to properly handle focusung ability of control when hiding/showing them

//Could cause assertions if game is closed with this dialog opened - solved by using string conversion 
//
generate_active_controls_list = {

	CA_VO_active_controls = [];	
	
	for [{_x=0},{_x<=(350)},{_x=_x+1}] do 
	{
		_control = _x;
		_disp_ctrl = (_dialog displayCtrl _control); 

		if  (!isNull(_disp_ctrl)) then {
			if (ctrlEnabled _disp_ctrl) then { 
				//Using string insted of control to prevent assert due to not supported serialization of control variables
				CA_VO_active_controls = CA_VO_active_controls + [str(_disp_ctrl)];
			};
		};	  				
	};
	
};

//processIDCs is hiding, showing and moving controls
//array CA_VO_active_controls has to be present to ensure focus works properly
processIDCs = {	
	private ["_controlsBuffer","_x","_disp_ctrl","_controlsBufferSize"];
	_controlsBuffer = [];
	_processIDCs = _this select 0;
	_fade =  _this select 1;
	_ctrl_delay =  _this select 2;
	_move_ctrl =  _this select 3;
	
	for [{_x=0},{_x<=(count _processIDCs)},{_x=_x+1}] do 
	{
		_control = _processIDCs select _x;
		_disp_ctrl = (_dialog displayCtrl _control); 

		switch _fade do 
		{
			case true: 
			{
				_disp_ctrl ctrlSetFade 1;
			};
			case false: 
			{
				_disp_ctrl ctrlSetFade 0;
				//Restore focusability of the control 
				if (CA_VO_active_controls  find str(_disp_ctrl) != -1) then {
					_disp_ctrl ctrlEnable true; 
				};
			};
			
		};

		_posX = ((ctrlPosition _disp_ctrl) select 0)+ (_move_ctrl select 0); 
		_posY = ((ctrlPosition _disp_ctrl) select 1) +  (_move_ctrl select 1);
		if !(((_move_ctrl select 0) == 0) && ((_move_ctrl select 1) == 0) ) then {
			_disp_ctrl ctrlSetPosition [_posX, _posY];  
	  };	
		_controlsBuffer set [_x, _disp_ctrl];
		//_disp_ctrl ctrlCommit _ctrl_delay;
	};
	
		_controlsBufferSize = (count _controlsBuffer);
		if !(_action == "CA_VO_Init") then {

		};
		for [{_x=0},{_x<=_controlsBufferSize},{_x=_x+1}] do  {
			(_controlsBuffer select _x) ctrlCommit _ctrl_delay;
		};

		
		
		
		if !(_action == "CA_VO_Init") then {

		};
};

//Set text of switching button accordingly to dialog state
setTextOfButton_Advanced = {

	if (CA_VO_Advanced_visible) then {
		(_dialog displayCtrl 345) ctrlsettext (localize "STR_CA_ADV_HIDE");
	} else {
		(_dialog displayCtrl 345) ctrlsettext (localize "STR_CA_ADV_SHOW");
	};
};				

setTextOfButton_All = {
	if ( CA_VO_All_visible) then {
		(_dialog displayCtrl 344) ctrlsettext (localize "STR_CA_HIDE");
	} else {
		(_dialog displayCtrl 344) ctrlsettext (localize "STR_CA_SHOW");
	};
	(_dialog displayCtrl 345)  ctrlEnable (CA_VO_All_visible);
};				

//control reference initialization
//ensures that this script can be called by control and also by dialog
if ( typeName((_this select 0) select 0) == "DISPLAY" ) then {
	_control = 0;
	_dialog = ((_this select 0) select 0);
} else {
	_control = ((_this select 0) select 0);
	_dialog = ctrlParent _control;
};

//input parameter to perform certain action
_action = _this select 1;



//is launched for first time
if (isNil("CA_VO_Advanced_visible")) then {
	CA_VO_Advanced_visible = false;
	CA_VO_All_visible = true;
	call generate_active_controls_list; 
}; 


//prevents from changes if controls are still animated
_disp_ctrl = (_dialog displayCtrl 126);
if !(ctrlCommitted _disp_ctrl) then {
	_action = "CA_VO_Wait";
}; 

switch _action do 
{
	case "CA_VO_Init":
	{
		[_OPT_advanced_array, !(CA_VO_Advanced_visible AND CA_VO_All_visible), 0, _no_move] call processIDCs;		

		if (CA_VO_Advanced_visible) then {
			[_OPT_basic_array, false, 0, [0,-1*_delta]] call processIDCs;
		} else {
			[_OPT_advanced_array, true, 0, [0,_delta]] call processIDCs;		
	 };

		[_OPT_basic_array, (!CA_VO_All_visible), 0, _no_move] call processIDCs;
		call setTextOfButton_Advanced;
		call setTextOfButton_All;
	};
	
	case "CA_VO_ToggleAdvanced": 
	{
		//CA_VO_All_visible
		CA_VO_Advanced_visible = !(CA_VO_Advanced_visible);	
		
		if CA_VO_Advanced_visible then {
		//		[_OPT_advanced_array, false, _in_delay, [0,-0.31]] call processIDCs;
		//		[_OPT_basic_array, false, _in_delay, [0,-0.31]] call processIDCs;
				[_OPT_array, false, _in_delay, [0,-1*_delta]] call processIDCs;
		} else {
				[_OPT_array, true, _in_delay, [0,_delta]] call processIDCs;
				[_OPT_basic_array, false, 0, _no_move] call processIDCs;
				

		};

		call setTextOfButton_Advanced;						
	};
	
	case "CA_VO_AspectChanged": 
	{
		//CA_VO_All_visible
		CA_VO_Advanced_visible = !(CA_VO_Advanced_visible);	
		
		if CA_VO_Advanced_visible then {
				[_OPT_array, false, _in_delay, [0,-1*_delta]] call processIDCs;
		} else {
				[_OPT_array, true, _in_delay, [0,_delta]] call processIDCs;
				[_OPT_basic_array, false, 0, _no_move] call processIDCs;
		};

		call setTextOfButton_Advanced;						
	};	
	case "CA_VO_ToggleAll":
	{			
		CA_VO_All_visible =  !(CA_VO_All_visible);
		
		if CA_VO_Advanced_visible then {
			[_OPT_array, !(CA_VO_All_visible), _in_delay, _no_move] call processIDCs;
			} else {
			[_OPT_basic_array, !(CA_VO_All_visible), _in_delay, _no_move] call processIDCs;
		};
		
		call setTextOfButton_All;		
	};
};
