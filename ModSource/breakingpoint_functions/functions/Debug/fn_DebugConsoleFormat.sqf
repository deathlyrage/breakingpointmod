/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_text","_debug"];
_text = format _this;
if (BP_Debug or isServer) then {
	_debug = "debug_console" callExtension _text;
};
diag_log (_text);