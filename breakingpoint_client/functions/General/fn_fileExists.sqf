/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_ctrl", "_fileExists"];
disableSerialization; 
_ctrl = findDisplay 0 ctrlCreate ["RscHTML", -1];
_ctrl htmlLoad _this;
_fileExists = ctrlHTMLLoaded _ctrl;
ctrlDelete _ctrl;
_fileExists