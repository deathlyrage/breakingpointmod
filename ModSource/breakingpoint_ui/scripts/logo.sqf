disableSerialization;
private ["_display", "_control"];

_us_logo = "\A3\ui_f\data\logo_white_us_ca.paa";
_eu_logo = "\A3\ui_f\data\logo_white_eu_ca.paa";

_mode = _this select 1;
_arrayInput =  _this select 0;
 
if ( typeName(_arrayInput select 0) == "DISPLAY" ) then {
	_display = (_arrayInput select 0);
} else {
	_display = findDisplay 12;
};

_control = _display displayctrl (_this select 1);

if ( distributionRegion != 1 ) then {
	_control ctrlsettext _eu_logo; 
} else {
	_control ctrlsettext _us_logo;	
};
 	
