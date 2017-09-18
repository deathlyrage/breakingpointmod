#include "\a3\Ui_f\hpp\defineResincl.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		#define __COLORTEXT(STRING) "<t color='"+ _color + "'>" + STRING + "</t>"
		private _controlsGroup = _params select 0;
		private _color = (["IGUI", "WARNING_RGB"] call BIS_fnc_displayColorGet) call BIS_fnc_colorRGBtoHTML;
		private _text = format
		[
			localize "str_a3_rscmsgboxkeyspresetcustominfopanel_text",
			__COLORTEXT(actionName "ListRightVehicleDisplay"),
			__COLORTEXT(actionName "NextModeRightVehicleDisplay"),
			__COLORTEXT(localize "str_a3_useractiongroups_common_0")
		];
		(_controlsGroup controlsGroupCtrl 1001) ctrlSetStructuredText (parseText _text);
		private _presetCustomInfoPanel_count = profilenamespace getvariable ["RscMsgBoxKeysPresetCustomInfoPanel_shown",0];
		private _presetCustomInfoPanel_count = profilenamespace getvariable ["RscMsgBoxKeysPresetCustomInfoPanel_shown",0];
		(_controlsGroup controlsGroupCtrl IDC_OK) ctrladdeventhandler
		[
			"buttonclick",
			{
				_this spawn
				{
					//--- Open controls menu
					ctrlActivate ((finddisplay IDD_MAIN) displayctrl IDC_OPTIONS_CONFIGURE);
					waituntil {!isnull (finddisplay IDD_CONFIGURE)};
				};
			}
		];
	};
};