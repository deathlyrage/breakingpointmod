disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		_display = _params select 0;

		//Sets all static texts toUpper
		["RscDisplayPublishMissionSelectTags",["RscText","RscTitle"]] call bis_fnc_toUpperDisplayTexts;
	};	
};
