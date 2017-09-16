disableSerialization;
scriptName "RscEGProgress";

#include "\a3\Ui_f\hpp\defineResinclDesign.inc"

#define SELF 			{ _this call (uiNamespace getVariable ["RscEGProgress_script", {}]); }
#define VAR_VISIBLE		"RscEGProgress_visible"
#define VAR_CONFLICT_VISIBLE	"RscEGProgress_conflictVisible"
#define VAR_PROGRESS_VISIBLE	"RscEGProgress_progressVisible"
#define VAR_SIDE_COLOR		"RscEGProgress_sideColor"
#define VAR_LETTER		"RscEGProgress_letter"
#define VAR_OBJECTS 		"BIS_progressVisualizer_objects"
#define VAR_DISPLAYS 		"BIS_progressVisualizer_displays"

private ["_mode", "_params"];
_mode 	= _this param [0, "", [""]];
_params = _this param [1, [], [[]]];

switch _mode do
{
	case "onLoad":
	{
		private _display = _params param [0, displayNull, [displayNull]];

		if (!isNull _display) then
		{
			// Add the display to the displays list
			private _displays = missionNamespace getVariable [VAR_DISPLAYS, []];
			_displays pushBack _display;
			missionNamespace setVariable [VAR_DISPLAYS, _displays];

			// Start hidden
			{
				(_display displayCtrl _x) ctrlSetFade 0;
				(_display displayCtrl _x) ctrlCommit 1;
			} forEach [IDC_RSCEGPROGRESS_OBJECTIVEBACKGROUND, IDC_RSCEGPROGRESS_OBJECTIVEBACKGROUNDCOLOURED, IDC_RSCEGPROGRESS_OBJECTIVELETTER];

			// Set default state
			["SetVisibility", [_display, _context, true]] call WIDGET;
			["SetProgressVisibility", [_display, _context, false, false]] call WIDGET;
			["SetConflictVisibility", [_display, _context, false]] call WIDGET;
		};
	};

	case "onUnload":
	{

	};

	case "UpdateContent" :
	{
		private ["_display", "_context", "_isUpload", "_progress", "_side", "_letter"];
		_display = _params select 0;
		_context = _params select 1;
		_isUpload = _params select 2;
		_progress = _params select 3;
		_side = _params select 4;
		_letter = _params param [5, _context getVariable [VAR_LETTER, "A"], [""]];

		private ["_title", "_progressBar", "_objLetter"];
		_title = _display displayCtrl IDC_RSCEGPROGRESS_TITLE;
		_progressBar = _display displayCtrl IDC_RSCEGPROGRESS_PROGRESSBAR;
		_objLetter = _display displayCtrl IDC_RSCEGPROGRESS_OBJECTIVELETTER;

		private ["_textSide", "_textTitle", "_text"];
		_textSide = switch (_side) do
		{
			case WEST: { localize "str_west"; };
			case EAST: { localize "str_east"; };
			case RESISTANCE: { localize "str_guerrila"; };
			default { localize "str_civilian"; };
		};
		_textTitle = if (_isUpload) then { localize "STR_A3_RscHvtPhase_Uploading" } else { localize "STR_A3_RscHvtPhase_Downloading" };
		_text = toUpper (_textSide + " " + _textTitle);

		_title ctrlSetText _text;
		_progressBar progressSetPosition _progress;
		_objLetter ctrlSetText _letter;
	};

	case "SetVisibility" :
	{
		private ["_display", "_bIsVisible"];
		_display = _params select 0;
		_context = _params select 1;
		_bIsVisible = _params select 2;

		private "_widget";
		_widget = _display displayCtrl IDC_RSCEGPROGRESS_DOWNLOAD;
		_widget ctrlShow _bIsVisible;

		_context setVariable [VAR_VISIBLE, _bIsVisible];
	};

	case "IsVisible" :
	{
		private ["_display", "_context"];
		_display = _params select 0;
		_context = _params select 1;

		_context getVariable [VAR_VISIBLE, false];
	};

	case "SetProgressVisibility" :
	{
		private ["_display", "_bIsVisible"];
		_display = _params select 0;
		_context = _params select 1;
		_bIsVisible = _params select 2;

		private "_widgets";
		_widgets =
		[
			_display displayCtrl IDC_RSCEGPROGRESS_DOWNLOADICON,
			_display displayCtrl IDC_RSCEGPROGRESS_DOWNLOADICONBACKGROUND,
			_display displayCtrl IDC_RSCEGPROGRESS_PROGRESSBAR,
			_display displayCtrl IDC_RSCEGPROGRESS_PROGRESSBARBACKGROUND,
			_display displayCtrl IDC_RSCEGPROGRESS_TITLE
		];

		if (_bIsVisible) then
		{
			{
				_x ctrlSetFade 0.0;
				_x ctrlCommit 0.15;
			} forEach _widgets;
		}
		else
		{
			{
				_x ctrlSetFade 1.0;
				_x ctrlCommit 0.15;
			} forEach _widgets;
		};

		_context setVariable [VAR_PROGRESS_VISIBLE, _bIsVisible];
	};

	case "IsProgressVisible" :
	{
		private ["_display", "_context"];
		_display = _params select 0;
		_context = _params select 1;

		_context getVariable [VAR_PROGRESS_VISIBLE, false];
	};

	case "SetConflictVisibility" :
	{
		private ["_display", "_context", "_bIsConflict"];
		_display = _params select 0;
		_context = _params select 1;
		_bIsConflict = _params select 2;

		private ["_background", "_picture"];
		_background = _display displayCtrl IDC_RSCEGPROGRESS_ACTIVITYBACKGROUND;
		_picture = _display displayCtrl IDC_RSCEGPROGRESS_ACTIVITY;

		if (_bIsConflict) then
		{
			_background ctrlSetFade 0.0;
			_background ctrlCommit 0.15;
			_picture ctrlSetFade 0.0;
			_picture ctrlCommit 0.15;
		}
		else
		{
			_background ctrlSetFade 1.0;
			_background ctrlCommit 0.15;
			_picture ctrlSetFade 1.0;
			_picture ctrlCommit 0.15;
		};

		_context setVariable [VAR_CONFLICT_VISIBLE, _bIsConflict];
	};

	case "IsConflictVisible" :
	{
		private ["_display", "_context"];
		_display = _params select 0;
		_context = _params select 1;

		_context getVariable [VAR_CONFLICT_VISIBLE, false];
	};

	case "SetSideColor" :
	{
		private ["_display", "_context", "_color"];
		_display = _params select 0;
		_context = _params select 1;
		_color = _params select 2;

		private _background = _display displayCtrl IDC_RSCEGPROGRESS_OBJECTIVEBACKGROUNDCOLOURED;
		_background ctrlSetTextColor _color;

		_context setVariable [VAR_SIDE_COLOR, _color];
	};

	case "GetSideColor" :
	{
		private ["_display", "_context"];
		_display = _params select 0;
		_context = _params select 1;

		_context getVariable [VAR_SIDE_COLOR, [0,0,0,0.75]];
	};

	case "SetLetter" :
	{
		private ["_display", "_context", "_letter"];
		_display = _params param [0, displayNull, [displayNull]];
		_context = _params param [1, objNull, [objNull]];
		_letter = _params param [2, "", [""]];

		private _text = _display displayCtrl IDC_RSCEGPROGRESS_OBJECTIVELETTER;
		_text ctrlSetText _letter;

		_context setVariable [VAR_LETTER, _letter];
	};

	case "GetLetter" :
	{
		private ["_display", "_context"];
		_display = _params select 0;
		_context = _params select 1;

		_context getVariable [VAR_LETTER, "A"];
	};

	case default
	{
		["Unknown mode: %1", _mode] call BIS_fnc_error;
	};
};