#include "\a3\Ui_f\hpp\defineResincl.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		_display = _params select 0;
		_buttonOK = _display displayCtrl IDC_OK;

		_buttonOK ctrladdeventhandler [
				"ButtonClick",
				"with uinamespace do {['yesButtonClicked', _this, 'RscDisplayKeyMapMsgBox'] call RscDisplayKeyMapMsgBox_script};"
		];
	};

	case "yesButtonClicked":
	{
		//Open Select Keyboard Preset display.
		[] spawn
		{
			ctrlActivate ((findDisplay IDD_MAIN) displayCtrl IDC_OPTIONS_CONFIGURE);
			waituntil {!isnull (findDisplay IDD_CONFIGURE)};
			ctrlActivate ((findDisplay IDD_CONFIGURE) displayCtrl IDC_CONFIG_KEY_PRESETS);
			waituntil {!isnull (findDisplay IDD_CONTROLS_SCHEME)};
		};
	};
};