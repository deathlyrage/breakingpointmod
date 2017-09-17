#include "\a3\Ui_f\hpp\defineResincl.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		_controlsGroup = _params select 0;
		_ctrlButtonOK = _controlsGroup controlsGroupCtrl IDC_OK;
		_ctrlButtonOK ctrladdeventhandler
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