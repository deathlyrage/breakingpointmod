#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		with uinamespace do
		{
			_display = _params select 0;
			
			//Set NO CONNECTION texts to upper
			_control = _display displayctrl 1024;
			_control ctrlSetText (toUpper (ctrlText _control));
			
			_control = _display displayctrl 1025;
			_control ctrlSetText (toUpper (ctrlText _control));

			//--- Hide hint
			_ctrlHintGroup = _display displayctrl IDC_RSCADVANCEDHINT_HINTGROUP;
			_ctrlHintGroup ctrlshow false;
			_ctrlHintGroup ctrlenable false;
			("RscAdvancedHint" call bis_fnc_rsclayer) cuttext ["","plain"];
			player setvariable ["BIS_fnc_advHint_HActiveF",""];
			player setvariable ["BIS_fnc_advHint_HActiveS",""];
		};
		
		//Switch to driver/gunner after click on PIP (picture doesn't have buttonClick event, using MouseButtonUp instead).
		_control = _display displayctrl IDC_IGUI_AVT_PIP1;
		_control ctrladdeventhandler ["MouseButtonUp","with uinamespace do {['pipClicked',_this,''] call RscDisplayAVTerminal_script};"];
		_control = _display displayctrl IDC_IGUI_AVT_PIP2;
		_control ctrladdeventhandler ["MouseButtonUp","with uinamespace do {['pipClicked',_this,''] call RscDisplayAVTerminal_script};"];
	};
	
	case "pipClicked":
	{
		_control = (_this select 1) select 0;
		_display = ctrlParent _control;
		
		switch (ctrlIDC _control) do
		{
			case 105:
			{
				ctrlActivate(_display displayctrl IDC_IGUI_AVT_TAKE_CONTROL_DRIVER);
			};
			
			case 106:
			{
				ctrlActivate(_display displayctrl IDC_IGUI_AVT_TAKE_CONTROL_GUNNER);
			};
		};
	};
};