disableSerialization;
private ["_x","_data","_value","_island","_control","_dialog"];

//ensures that this script can be called by control and also by dialog
if ( typeName((_this select 0) select 0) == "DISPLAY" ) then { 
	_dialog = ((_this select 0) select 0);
	_control = (_dialog displayCtrl 101);	

} else {
	_control = ((_this select 0) select 0);
	_dialog = ctrlParent _control;
};

_ctrlPanoramaPic = _dialog displayCtrl 1005;

if (isNil "SI_defaultPic") then {
	SI_defaultPic = ctrlText  _ctrlPanoramaPic; 
};

_selectedIslandIndex = lbCurSel _control;
_data = _control lbData _selectedIslandIndex;
_value = _control lbValue _selectedIslandIndex;
_island = (configfile >> "cfgworlds" >> _data);

if (_island==_island) then {
	_x = getText(configFile >> "CfgWorlds" >> _data >> "pictureShot");

	SI_island = _x;	
	} else {
	_x = "";

};

if (_x == "") then {
	_ctrlPanoramaPic ctrlSetText SI_defaultPic;
} else {
	_ctrlPanoramaPic ctrlSetText _x;
};