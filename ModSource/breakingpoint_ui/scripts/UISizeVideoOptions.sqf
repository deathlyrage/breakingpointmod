disableSerialization;
private ["_control","_dialog","_deltaY","_y"];

_action = _this select 1;



//ensures that this script can be called by control and also by dialog
if ( typeName((_this select 0) select 0) == "DISPLAY" ) then {
	_control = 0;
	_dialog = ((_this select 0) select 0);
} else {
	_control = ((_this select 0) select 0);

	_dialog = ctrlParent _control;
};

if (isNil("CA_VO_SafeZoneH_old") || _action == "onMouseButtonDown" ) then {
	CA_VO_SafeZoneH_old  = SafeZoneH; 
	CA_VO_SafeZoneY_old = SafeZoneY;
};
     

if ( _action == "onLBSelChanged" ) then {

		_control = (_dialog displayCtrl 1025);																													
		_y = (ctrlPosition _control) select 1;																													
		_deltaY = CA_VO_SafeZoneY_old - SafeZoneY;																													
		_control ctrlSetPosition [0, (_y + _deltaY)];																													
		_control ctrlCommit 0;																													
																															
																															
																															
		_control = (_dialog displayCtrl 1024);																													
		_y = (ctrlPosition _control) select 1;																													
		_deltaY = CA_VO_SafeZoneY_old - SafeZoneY;																													
		_control ctrlSetPosition [0, (_y + _deltaY)];																													
		_control ctrlCommit 0;																													
		CA_VO_SafeZoneH_old  = SafeZoneH;																															
		CA_VO_SafeZoneY_old = SafeZoneY;																															
																															
																												
};

true;