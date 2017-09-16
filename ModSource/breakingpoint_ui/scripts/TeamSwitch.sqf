disableSerialization;

private ["_display", "_control","_select_index","_arrayInput","_mode"];

_mode = _this select 1;
_arrayInput =  _this select 0;
 
_display = findDisplay 632;

_PauseTimeAcc = 0.1;


//In the case of all units are killed during window opened
if (count switchableunits == 1 && alive player && _mode != "CA_TS_Resume") then {_mode = "CA_TS_Close"};
 
//Function with defined marker parameters, input is array with position
setMarkerProcedure = 
{ 			
	deleteMarker "Marker_teamSwitch"; 
	marker = createMarker ["Marker_teamSwitch", _this]; 
	marker setMarkerText ""; 
	marker setMarkerType "Select";
	marker setMarkerColor "ColorGreen";
	marker setMarkerSize [0.5, 0.5];  
};

switch _mode do 
{
	case "CA_TS_Pause":
	{
		//temporary hack to have selection in the list on the playable uinit, not on the player
		//removeSwitchableUnit player;
		//addSwitchableUnit player;

		//Detect if player is dead, if so, remove blackout made by camera script
		if (!(alive player)) then { titleCut["","BLACK IN",0]; };

		//Indicates that dialog was freshly opened, necessary for View  Unit logic
		TSW_externalCamera = false;
		
		//Slow down game and remember original time acceleration value
		TSW_oldAccTime = AccTime;
		setAccTime _PauseTimeAcc;

		//Clear teamswitch selected unit marker
		deleteMarker "Marker_teamSwitch";
				
		//Assigning action to map double click
		//onMapSingleClick "_dummy =[_pos, ""CA_TS_MapClick""] call compile preprocessFile ""\A3\ui\scripts\TeamSwitch.sqf"" ";

/*		//Select player within list box
		_player_index = switchableUnits find player;
 		_control = _display displayctrl 101;
		_control lbSetCurSel _player_index;
*/


		//Hide Map if it's disabled	 for player	
		_mapControls = [555,556,557,558,559,560,561,562];
		private ["_x"];	
	     for [{_x=(count _mapControls) - 1},{_x>=0},{_x=_x-1}] do 
		{ 
			_control = _mapControls select _x; 
			_control = _display displayctrl (_mapControls select _x);
			_control ctrlShow difficultyEnabled "Map";			
		};
		//Disable view unit button in veteran mode
		_control = _display displayctrl 32;
		_control ctrlEnable difficultyEnabled "Map";
		_control ctrlShow difficultyEnabled "Map";			
		
		//Hide or show map according to last user-selected status
		if (!TSW_mapDisplayed) then 
		{
			_dummy = [_pos, "CA_TS_ShowMap"]  call compile preprocessFile  "\A3\ui_f\scripts\TeamSwitch.sqf";
			TSW_mapDisplayed = false;			
		};
		
		TSW_OldSelectedUnit = objNull;
		if (isnil ("TSW_MapScale")) then 
		{
			 
			TSW_MapScale = 0.2 + 0.005 * abs( speed vehicle player);
		};	
	};

	case "CA_TS_Resume":
	{
		setAccTime TSW_oldAccTime;

		if (count switchableunits == 1 && alive player) exitwith {_display closedisplay 2;};

		//return back camera
		switchcam CameraEffect ["Terminate","Back"];
		CamDestroy switchcam;
		deleteMarker "Marker_teamSwitch";
		cuttext ["","black in"];
	};
	

	case "CA_TS_UnitSelected":
	{	

		private ["_mapAnimDelay"];
		_selectedUnitNumber =  (_arrayInput select 1) ;
		
		if (_selectedUnitNumber < (0)) then 
		{
			_selectedUnitNumber = 0;
		};
		
		// checks if some unit died during selection, if so, last unit from list is selected
		if (_selectedUnitNumber > (count switchableUnits)) then 
		{
			_next_alive_unit = count switchableUnits;
	 		_control = _display displayctrl 101;

			_control lbSetCurSel _next_alive_unit;
			_selectedUnitNumber = _next_alive_unit;
		};

			
		_selectedUnit = switchableUnits select _selectedUnitNumber;
		_vehicleOfSelectedUnit = typeOf (vehicle _selectedUnit);
		//Who controls selected Unit? - AI or Player
		_playerObject = player;
		
		private ["_controledBy"]; 
		if (_selectedUnit == player) then 
		{
			_controledBy = (localize "STR_TEAM_SWITCH_PLAYER");
		}
		else {
			_controledBy = (localize "STR_TEAM_SWITCH_AI");
		};	

		_control = _display displayctrl 501;
		_control ctrlsettext  _controledBy;

 		_control = _display displayctrl 101;		
		_unit_icon = _control lbPicture _selectedUnitNumber;

		if (_unit_icon != "") then {
			_control = _display displayctrl 493;
			_control ctrlsettext _unit_icon;
		};

		//Is another unit selected?
		if ( _selectedUnit != TSW_OldSelectedUnit) then
		{
			if (isNull(TSW_OldSelectedUnit)) then {
				_mapAnimDelay = 0;
			} else {
				_mapAnimDelay = 0.5;
			};

			TSW_OldSelectedUnit = _selectedUnit;
			//Set marker as selection
			_UnitPos = position _selectedUnit;			
			_UnitPos call setMarkerProcedure;  		
			
			// Move map to selected (unit) position;
			_mapCtrl = _display displayctrl 561;
			ctrlMapAnimClear _mapCtrl;
			_mapCtrl ctrlMapAnimAdd [_mapAnimDelay, TSW_mapScale, _UnitPos];
			ctrlMapAnimCommit _mapCtrl;
			//Now play with camera
			TSW_camTargetUnit = _selectedUnit;			
			} else {
			
    		"Marker_teamSwitch" setMarkerPos position _selectedUnit;
		};	
		
		//store map scale into temporary global variable
		_control = _display displayctrl 561;
		
		if !(isnull _control) then {
			TSW_mapscale =  ctrlMapScale _control;
		};
	};
		
	case "CA_TS_MapClick":
	{
		private ["_x", "_closest_unit","_closest_unit_index","_closest_unit_distance","_closest_vehicle"];
		private ["_playableUnit_position","_playableUnit_distance","_cursor_range","_closest_unit_position"];
		//_pos3D = _map ctrlMapScreenToWorld _pos2D 
			
		_mapCtrl = _display displayctrl 561;
		_pos = _mapCtrl ctrlMapScreenToWorld [ _arrayInput select 2, _arrayInput select 3];
		_distance = 60;

		_posX = _pos select 0;
		_posY = _pos select 1; 
			
		_closest_unit_distance = 100000; //No unit should be more distant, dull but works;
		
		deleteMarker "Marker_teamSwitch";
			
		for [{_x=(count switchableUnits) - 1},{_x>=0},{_x=_x-1}] do 
		{
		  _playableUnit_position = position  (switchableUnits select _x);
		  _playableUnit_distance = sqrt ( ((_playableUnit_position select 0) - (_posX) )^2 + ((_playableUnit_position select 1) -  (_posY) ) ^2);
		
		  if (_playableUnit_distance < _closest_unit_distance) then
		  {
			_closest_unit_index = _x;
			_closest_unit_distance = _playableUnit_distance;	  	
		  };
		};			
		  _closest_unit = switchableUnits select _closest_unit_index;
		  _closest_vehicle = typeOf (vehicle _closest_unit);
		  		  
		  //Change selection of unit if it is within cursor range
		  _cursor_range = 150; //Calculation of cursor range based on the map zoom
		  _closest_unit_position = position _closest_unit;

		  if (_closest_unit_distance < _cursor_range) then 
		  {			
			_closest_unit_position call setMarkerProcedure;  
			
	 		_control = _display displayctrl 101;
			_control lbSetCurSel _closest_unit_index;
		  };
	};
	
	case "CA_TS_ShowMap":
	{
		//Show or hide map control with corensponding controls
		//Show or hide 		
		_control = _display displayctrl 556;
		_control ctrlShow not(ctrlShown _control);
		_control = _display displayctrl 561;
		_control ctrlShow not(ctrlShown _control);
		
		//_arrowDown = "\A3\ui_f\data\ui_map_arrow_close_ca.paa";
		//_arrowUp = "\A3\ui_f\data\ui_map_arrow_open_ca.paa";
		_arrowDown = "#(argb,8,8,3)color(1,0,1,1)";
		_arrowUp = "#(argb,8,8,3)color(1,0,1,1)";
		//Change icon
		_control = _display displayctrl 561;
		TSW_mapDisplayed = ctrlShown _control;
		
		
		if (TSW_mapDisplayed) then 
		{
			 _control = _display displayctrl 560;
			 _control ctrlsettext _arrowUp;
		} else {
			_control = _display displayctrl 560;
			_control ctrlsettext _arrowDown;
		};		
	}; 
	
	case "CA_TS_ViewUnit":
	{
		//View unit button pressed for first time;
		if (!TSW_externalCamera) then 
		{
			TSW_oldcamTargetUnit = player;
			TSW_externalCamera = true; 	
		};
		
		switchcam = "camera" CamCreate getpos TSW_oldcamTargetUnit;			
		switchcam CameraEffect ["internal","back"];
		(vehicle TSW_oldcamTargetUnit) switchCamera "EXTERNAL";
		showCinemaBorder false;
		
		_p1pos = getPos TSW_oldcamTargetUnit;
		_p2pos = getPos TSW_camTargetUnit;
			
		switchcam camSetTarget vehicle TSW_oldcamTargetUnit;
		switchcam camSetRelPos [0, -8, (_p1pos select 2) + 20];
		switchcam camSetFOV 0.5;
		switchcam camCommit 0;	
		waitUntil {camCommitted switchcam};

		_px1 = _p1pos select 0;
		_pz1 = _p1pos select 1;
		_px2 = _p2pos select 0;
		_pz2 = _p2pos select 1;			
		
		_Dist = TSW_camTargetUnit distance switchcam;
		switchcam camSetTarget getPos vehicle TSW_camTargetUnit;			//Zameri kameru na 2.jednotku
		switchcam camSetPos [_px1, _pz1 - 8, (_p1pos select 2) + 20 + _Dist/400];	// Vystoupání kamery nad hrace
		switchcam camCommit 3*(_PauseTimeAcc+0.001);
		waitUntil {camCommitted switchcam};
		_CamSpeed = 3;
		if ((TSW_camTargetUnit distance switchcam) > 37) then
		{
			while {((TSW_camTargetUnit distance switchcam)) > 37} do
			{
				switchcam camCommit (_camspeed * 33); // puvodne 100	
				sleep (0.05 * _PauseTimeAcc);
				_Retarder = ((TSW_camTargetUnit distance switchcam) * (((180 / (_Dist / 100)) / 100)));
				_Retarder = ((_Dist/200) - (sin(_retarder)* (_Dist/200)-2));
				_CamSpeed = ((TSW_camTargetUnit distance switchcam) * (((_retarder / (_Dist / 100)) / 100)));
				switchcam camSetPos [_px2, _pz2 - 20,(_p2pos select 2) + 20 + (TSW_camTargetUnit distance switchcam)/5];
				switchcam camCommit _CamSpeed*(_PauseTimeAcc);
			};
		};
		
		switchcam camSetPos [_px2, _pz2 - 20.5,(_p2pos select 2) + 25.5];
		switchcam camCommit _CamSpeed*(_PauseTimeAcc+0.001);
		waitUntil {camCommitted switchcam};
		
		TSW_oldcamTargetUnit = TSW_camTargetUnit;
	};
	//script executed by onTeamSwitch.sqf after unit is switched 
	case "CA_TS_onTeamSwitch":
	{
	};	
	case "CA_TS_ListDoubleClick":
	{
		_control = _display displayctrl 1;
		ctrlActivate _control;
	};

	case "CA_TS_Close":
	{
		_control = _display displayctrl 2;
		ctrlActivate _control;
	};
	

};
