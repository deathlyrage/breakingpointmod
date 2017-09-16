#include "\a3\Ui_f\hpp\defineResinclDesign.inc"

private ["_display", "_params", "_class"];
_mode 	= _this select 0;
_params = _this select 1;
_class 	= _this select 2;

switch _mode do {
	case "onLoad": {
		private ["_display", "_background", "_text", "_progress"];
		_display 	= _params select 0;
		_text		= _display displayCtrl IDC_GROUNDSUPPORT_PROCEDUREVISUALIZATION_TEXT;
		_progress	= _display displayCtrl IDC_GROUNDSUPPORT_PROCEDUREVISUALIZATION_PROGRESS;
		
		// Store
		uiNamespace setVariable ["RscProcedureVisualization_Display", _display];
		uiNamespace setVariable ["RscProcedureVisualization_Text", _text];
		uiNamespace setVariable ["RscProcedureVisualization_Progress", _progress];
		uiNamespace setVariable ["RscProcedureVisualization_ProgressInitialWidth", (ctrlPosition _progress) select 2];
	};
	
	case "onUnload": {
		// Reset
		uiNamespace setVariable ["RscProcedureVisualization_Display", nil];
		uiNamespace setVariable ["RscProcedureVisualization_Text", nil];
		uiNamespace setVariable ["RscProcedureVisualization_Progress", nil];
		uiNamespace setVariable ["RscProcedureVisualization_ProgressInitialWidth", nil];
	};
};