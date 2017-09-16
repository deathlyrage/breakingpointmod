#include "\a3\Ui_f\hpp\defineResinclDesign.inc"

#define SELF				{ _this call (uiNamespace getVariable ["RscHvtPhase_script", {}]); }
#define VAR_DISPLAY 			"RscHvtPhase_display"
#define VAR_TOOLTIP_OPEN	 	"RscHvtPhase_tooltipOpen"
#define VAR_TOOLTIP_WIDTH	 	"RscHvtPhase_tooltipWidth"
#define VAR_PROGRESS_WIDTH	 	"RscHvtPhase_progressWidth"
#define VAR_PROGRESS		 	"RscHvtPhase_progress"
#define VAR_RANGE			"RscHvtPhase_range"
#define VAR_MULTIPLIER			"RscHvtPhase_multiplier"
#define VAR_DOWNLOAD_VISIBLE		"RscHvtPhase_downloadVisible"
#define VAR_TIMER_VISIBLE		"RscHvtPhase_timerVisible"
#define VAR_CARRIER_VISIBLE		"RscHvtPhase_carrierVisible"
#define VAR_TITLE			"RscHvtPhase_title"
#define VAR_PROGRESS_TEXT		"RscHvtPhase_progressText"
#define VAR_PROGRESS_COLOR		"RscHvtPhase_progressColor"
#define VAR_INITIAL_CONTENT_POSITION	"RscHvtPhase_initialContentPosition"
#define STRING_ESTABLISH_FOB		localize "STR_A3_RscHvtPhase_PhaseOne"
#define STRING_DOWNLOAD_INTEL		localize "STR_A3_RscHvtPhase_PhaseTwo"
#define STRING_SECURE_SCHEMATICS	localize "STR_A3_RscHvtPhase_PhaseThree"
#define STRING_STAGE_1			"I"
#define STRING_STAGE_2			"II"
#define STRING_STAGE_3			"III"
#define TEXT_DOWNLOAD			localize "STR_A3_RscHvtPhase_Downloading"
#define TEXT_UPLOADING			localize "STR_A3_RscHvtPhase_Uploading"
#define TEXT_LOSING			localize "STR_A3_rschvtphase_loosingconnection"
#define TEXT_PAUSED			localize "STR_A3_RscHvtPhase_paused"
#define TEXT_TB				localize "STR_A3_RscHvtPhase_TeraBytes"
#define TOOLTIP_ANIMATE_IN_TIME		0.6
#define TOOLTIP_ANIMATE_OUT_TIME	0.3
#define TOOLTIP_STAGE_DISPLAY_TIME	10.0
#define RANGE_COLOR_ACTIVE		[0.8,0.5,0,1]
#define RANGE_COLOR_INACTIVE		[0.5,0.5,0.5,1]
#define PROGRESS_COLOR_ACTIVE		[0.8,0.5,0,1]
#define PROGRESS_COLOR_PAUSED		[1.0,0.3,0.0,1]
#define PICTURE_RANGE			"a3\Ui_f\data\IGUI\RscTitles\RscHvtPhase\"
#define PICTURE_RANGE_0			(PICTURE_RANGE + "JAC_A3_Signal_0_ca.paa")
#define PICTURE_RANGE_1			(PICTURE_RANGE + "JAC_A3_Signal_1_ca.paa")
#define PICTURE_RANGE_2			(PICTURE_RANGE + "JAC_A3_Signal_2_ca.paa")
#define PICTURE_RANGE_3			(PICTURE_RANGE + "JAC_A3_Signal_3_ca.paa")
#define PICTURE_RANGE_4			(PICTURE_RANGE + "JAC_A3_Signal_4_ca.paa")
#define PICTURE_CARRIER_SEEN		"a3\Ui_F_Curator\Data\Displays\RscDisplayMultiplayerSetup\flag_logic_ca.paa"

private ["_display", "_params"];
_mode 	= _this select 0;
_params = _this select 1;

switch _mode do
{
	case "onLoad":
	{
		private ["_display", "_icon", "_tooltip", "_downloadGroup", "_progressBar", "_timer", "_carrier"];
		_display 	= _params select 0;
		_icon 		= _display displayCtrl IDC_RSCHVTPHASE_PERSISTENT;
		_tooltip 	= _display displayCtrl IDC_RSCHVTPHASE_DYNAMIC;
		_downloadGroup	= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOAD;
		_progressBar	= _display displayCtrl IDC_RSCHVTPHASE_PROGRESSBAR;
		_timer		= _display displayCtrl IDC_RSCHVTPHASE_TIMER;
		_carrier	= _display displayCtrl IDC_RSCHVTPHASE_CARRIERPICTURE;

		uiNamespace setVariable [VAR_DISPLAY, _display];
		uiNamespace setVariable [VAR_TOOLTIP_OPEN, false];
		uiNamespace setVariable [VAR_TOOLTIP_WIDTH, (ctrlPosition _tooltip) select 2];
		uiNamespace setVariable [VAR_PROGRESS_WIDTH, (ctrlPosition _progressBar) select 2];

		_icon ctrlSetText "-";
		_icon ctrlSetBackgroundColor [0, 0, 0, 0.7];
		_icon ctrlSetTextColor [1, 1, 1, 1];

		private "_initialTootipPosition";
		_initialTootipPosition = ctrlPosition _tooltip;
		uiNamespace setVariable [VAR_INITIAL_CONTENT_POSITION, _initialTootipPosition];

		_tooltip ctrlSetText "";
		_tooltip ctrlSetPosition [_initialTootipPosition select 0, _initialTootipPosition select 1, 0, _initialTootipPosition select 3];
		_tooltip ctrlSetFade 1;
		_tooltip ctrlCommit 0;

		_downloadGroup ctrlShow false;
		_downloadGroup ctrlSetPosition [_initialTootipPosition select 0, _initialTootipPosition select 1, (ctrlPosition _downloadGroup) select 2, (ctrlPosition _downloadGroup) select 3];
		_downloadGroup ctrlCommit 0;
		uiNamespace setVariable [VAR_DOWNLOAD_VISIBLE, false];

		_timer ctrlShow false;
		_timer ctrlSetPosition [_initialTootipPosition select 0, _initialTootipPosition select 1, (ctrlPosition _timer) select 2, (ctrlPosition _timer) select 3];
		_timer ctrlCommit 0;
		uiNamespace setVariable [VAR_TIMER_VISIBLE, false];

		_carrier ctrlShow false;
		uiNamespace setVariable [VAR_CARRIER_VISIBLE, false];

		["OnLoad: %1 / %2 / %3", _display, _icon, _tooltip] call BIS_fnc_logFormat;
	};

	case "onUnload":
	{
		uiNamespace setVariable [VAR_DISPLAY, displayNull];

		if (!isNil { RscHvtPhase_timerThread }) then
		{
			terminate RscHvtPhase_timerThread;
			RscHvtPhase_timerThread = nil;
		};

		["OnUnload: %1 / %2 / %3", _display, _icon, _tooltip] call BIS_fnc_logFormat;
	};

	case "GetDisplay":
	{
		uiNamespace getVariable [VAR_DISPLAY, displayNull];
	};

	case "GetTooltipWidth":
	{
		uiNamespace getVariable [VAR_TOOLTIP_WIDTH, 0];
	};

	case "GetProgressWidth":
	{
		uiNamespace getVariable [VAR_PROGRESS_WIDTH, 0];
	};

	case "SetStage":
	{
		private ["_stage"];
		_stage = _params param [0, 0, [0]];

		private "_display";
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];

		if (isNull _display) exitWith {};

		private ["_icon", "_tooltip"];
		_icon		= _display displayCtrl IDC_RSCHVTPHASE_PERSISTENT;
		_tooltip	= _display displayCtrl IDC_RSCHVTPHASE_DYNAMIC;

		if (isNull _icon || isNull _tooltip) exitWith {};

		switch (_stage) do
		{
		    case 0:
		    {
		    	_icon ctrlSetText STRING_STAGE_1;
		    	_tooltip ctrlSetText STRING_ESTABLISH_FOB;
		    };

		    case 1:
		    {
		    	_icon ctrlSetText STRING_STAGE_2;
		    	_tooltip ctrlSetText STRING_DOWNLOAD_INTEL;
		    };

		    default
		    {
		    	_icon ctrlSetText STRING_STAGE_3;
		    	_tooltip ctrlSetText STRING_SECURE_SCHEMATICS;
		    };
		};

		["OnStageChanged", [_stage]] call SELF;
	};

	case "OnStageChanged":
	{
		uiNamespace setVariable ["BIS_hvtPhase_changing", true];

		_params spawn
		{
			disableSerialization;

			private ["_stage"];
			_stage = _this param [0, 0, [0]];

			["SetIconState", [0]] call SELF;
			["AnimateTooltipIn"] call SELF;

			sleep TOOLTIP_STAGE_DISPLAY_TIME;

			["AnimateTooltipOut"] call SELF;
			["SetIconState", [1, TOOLTIP_ANIMATE_OUT_TIME]] call SELF;

			sleep TOOLTIP_ANIMATE_OUT_TIME;

			if (_stage >= 2 && missionNamespace getVariable ["BIS_hvtPhase_showTimer", true]) then
			{
				// Show timer
				["ShowTimer"] call SELF;
			};

			uiNamespace setVariable ["BIS_hvtPhase_changing", false];
		};
	};

	case "AnimateTooltipIn":
	{
		disableSerialization;

		private ["_display", "_tooltip"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_tooltip	= _display displayCtrl IDC_RSCHVTPHASE_DYNAMIC;

		_tooltip ctrlSetPosition [ctrlPosition _tooltip select 0, ctrlPosition _tooltip select 1, ["GetTooltipWidth"] call SELF, ctrlPosition _tooltip select 3];
		_tooltip ctrlSetFade 0;
		_tooltip ctrlCommit TOOLTIP_ANIMATE_IN_TIME;

		// Sfx
		playSound "Beep_Target";
	};

	case "AnimateTooltipOut":
	{
		disableSerialization;

		private ["_display", "_tooltip"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_tooltip	= _display displayCtrl IDC_RSCHVTPHASE_DYNAMIC;

		_tooltip ctrlSetPosition [ctrlPosition _tooltip select 0, ctrlPosition _tooltip select 1, 0, ctrlPosition _tooltip select 3];
		_tooltip ctrlSetFade 1;
		_tooltip ctrlCommit TOOLTIP_ANIMATE_OUT_TIME;

		// Sfx
		playSound "ZoomOut";
	};

	case "SetIconState":
	{
		private ["_state", "_delay"];
		_state = _params param [0, 0, [0]];
		_delay = _params param [1, 0, [0]];

		private ["_display", "_icon"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_icon		= _display displayCtrl IDC_RSCHVTPHASE_PERSISTENT;

		if (_delay > 0) then
		{
			sleep _delay;
		};

		switch (_state) do
		{
		    case 0:
		    {
		    	_icon ctrlSetBackgroundColor [1, 1, 1, 0.7];
		    	_icon ctrlSetTextColor [0, 0, 0, 1];
		    };

		    default
		    {
		    	_icon ctrlSetBackgroundColor [0, 0, 0, 0.7];
		    	_icon ctrlSetTextColor [1, 1, 1, 1];
		    };
		};
	};

	case "IsDownloadProgressShown" :
	{
		uiNamespace getVariable [VAR_DOWNLOAD_VISIBLE, false];
	};

	case "ShowDownloadProgress" :
	{
		if !(["IsDownloadProgressShown"] call SELF) then
		{
			private ["_isUpload", "_initialProgress", "_initialRange", "_initialMultiplier"];
			_isUpload		= _params param [0, false, [true]];
			_initialProgress	= _params param [1, 0, [0]];
			_initialRange		= _params param [2, 4, [0]];
			_initialMultiplier	= _params param [3, 1, [0]];

			private ["_display", "_downloadGroup", "_progressBar", "_multiplier", "_title"];
			_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
			_downloadGroup	= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOAD;
			_progressBar	= _display displayCtrl IDC_RSCHVTPHASE_PROGRESSBAR;
			_multiplier	= _display displayCtrl IDC_RSCHVTPHASE_MULTIPLIER;
			_title		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADTITLE;

			private "_titleText";
			_titleText = if (_isUpload) then { TEXT_UPLOADING } else { TEXT_DOWNLOAD };

			["SetTitle", [_titleText]] call SELF;
			["SetProgress", [_initialProgress]] call SELF;
			["SetRange", [_initialRange]] call SELF;
			["SetMultiplier", [_initialMultiplier]] call SELF;

			uiNamespace setVariable [VAR_DOWNLOAD_VISIBLE, true];
			["AnimateDownloadIn"] call SELF;
		};
	};

	case "HideDownloadProgress" :
	{
		disableSerialization;

		if (["IsDownloadProgressShown"] call SELF) then
		{
			uiNamespace setVariable [VAR_DOWNLOAD_VISIBLE, false];
			["AnimateDownloadOut"] call SELF;
		};
	};

	case "GetProgress" :
	{
		uiNamespace getVariable [VAR_PROGRESS, 0];
	};

	case "SetProgress" :
	{
		private ["_inProgress"];
		_inProgress = _params param [0, 0, [0]];

		private ["_display", "_progressBar"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_progressBar	= _display displayCtrl IDC_RSCHVTPHASE_PROGRESSBAR;

		_progressBar progressSetPosition _inProgress;
		uiNamespace setVariable [VAR_PROGRESS, _inProgress];

		["SetProgressText", [_inProgress]] call SELF;
	};

	case "GetMultiplier" :
	{
		uiNamespace getVariable [VAR_MULTIPLIER, 0];
	};

	case "SetMultiplier" :
	{
		private ["_inMultiplier"];
		_inMultiplier = _params param [0, 0, [0, ""]];

		private "_display";
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];

		private "_multiplier";
		_multiplier = _display displayCtrl IDC_RSCHVTPHASE_MULTIPLIER;

		_multiplier ctrlSetText format["%1", _inMultiplier];
		uiNamespace setVariable [VAR_MULTIPLIER, _inMultiplier];
	};

	case "GetRange" :
	{
		uiNamespace getVariable [VAR_RANGE, 0];
	};

	case "SetRange" :
	{
		private ["_inRange"];
		_inRange = _params param [0, 0, [0]];

		// Clamp ranges
		if (_inRange > 4) then
		{
			_inRange = 4;
		};
		if (_inRange < 0) then
		{
			_inRange = 0;
		};

		private ["_display", "_range"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_range		= _display displayCtrl IDC_RSCHVTPHASE_RANGE;

		switch (_inRange) do
		{
			case 1 :
			{
				_range ctrlSetText PICTURE_RANGE_1;
			};

			case 2 :
			{
				_range ctrlSetText PICTURE_RANGE_2;
			};

			case 3 :
			{
				_range ctrlSetText PICTURE_RANGE_3;
			};

			case 4 :
			{
				_range ctrlSetText PICTURE_RANGE_4;
			};

			case default
			{
				_range ctrlSetText PICTURE_RANGE_0;
			};
		};

		uiNamespace setVariable [VAR_RANGE, _inRange];
	};

	case "GetTitle" :
	{
		uiNamespace getVariable [VAR_TITLE, TEXT_DOWNLOAD];
	};

	case "SetTitle" :
	{
		private ["_text"];
		_text = toUpper (_params param [0, "", [""]]);

		private ["_display", "_title"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_title		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADTITLE;

		_title ctrlSetText _text;
		uiNamespace setVariable [VAR_TITLE, _text];
	};

	case "GetProgressText" :
	{
		uiNamespace getVariable [VAR_PROGRESS_TEXT, "0.0 / 0.0 TB"];
	};

	case "SetProgressText" :
	{
		private ["_progress", "_paused"];
		_progress 	= _params param [0, 0, [0]];
		_paused 	= _params param [1, false, [false]];

		private ["_display", "_downloadSpeed"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_downloadSpeed	= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADSPEED;

		private "_text";
		_text = if (!_paused) then
		{
			toUpper (format ["%1 / %2 TB", [_progress, 2] call bis_fnc_cutDecimals, [1.00, 2] call bis_fnc_cutDecimals]);
		}
		else
		{
			toUpper TEXT_LOSING;
		};

		_downloadSpeed ctrlSetText _text;
		uiNamespace setVariable [VAR_PROGRESS_TEXT, _text];
	};

	case "GetProgressColor" :
	{
		uiNamespace getVariable [VAR_PROGRESS_COLOR, [1,1,1,1]];
	};

	case "SetProgressColor" :
	{
		private ["_state"];
		_state = _params param [0, 0, [0]];

		private "_color";
		_color = switch (_state) do
		{
			case 0 : 	{ PROGRESS_COLOR_ACTIVE };
			case default 	{ PROGRESS_COLOR_PAUSED };
		};

		private ["_display", "_progress"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_progress	= _display displayCtrl IDC_RSCHVTPHASE_PROGRESSBAR;

		_progress ctrlSetTextColor _color;
		uiNamespace setVariable [VAR_PROGRESS_COLOR, _color];
	};

	case "AnimateDownloadIn" :
	{
		private ["_display", "_ctrlGroup", "_ctrlContent", "_ctrlTitle", "_ctrlMultiplier", "_ctrlRangeBackground", "_ctrlRange", "_ctrlProgressText", "_ctrlProgressBar"];
		_display 		= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_ctrlGroup		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOAD;
		_ctrlContent		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADCONTENT;
		_ctrlTitle 		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADTITLE;
		_ctrlMultiplier		= _display displayCtrl IDC_RSCHVTPHASE_MULTIPLIER;
		_ctrlRangeBackground	= _display displayCtrl IDC_RSCHVTPHASE_RANGEBACKGROUND;
		_ctrlRange		= _display displayCtrl IDC_RSCHVTPHASE_RANGE;
		_ctrlProgressText	= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADSPEED;
		_ctrlProgressBar	= _display displayCtrl IDC_RSCHVTPHASE_PROGRESSBAR;

		private ["_ctrlContentPosition", "_ctrlTitlePosition", "_ctrlTitleText"];
		_ctrlContentPosition	= [0,0,0,0];
		_ctrlTitlePosition 	= [0,0,0,0];
		_ctrlTitleText		= "";

		// Store positions the first time we show download progress
		if (isNil { uiNamespace getVariable "BIS_rscHvtPhase_properties" }) then
		{
			_ctrlContentPosition	= ctrlPosition _ctrlContent;
			_ctrlTitlePosition 	= ctrlPosition _ctrlTitle;
			_ctrlTitleText		= ctrlText _ctrlTitle;

			uiNamespace setVariable ["BIS_rscHvtPhase_properties", [_ctrlContentPosition, _ctrlTitlePosition, _ctrlTitleText]];
		}
		else
		{
			private "_properties";
			_properties = uiNamespace getVariable ["BIS_rscHvtPhase_properties", [[0,0,0,0], [0,0,0,0], ""]];

			_ctrlContentPosition	= _properties select 0;
			_ctrlTitlePosition 	= _properties select 1;
			_ctrlTitleText		= _properties select 2;
		};

		// Show download group
		_ctrlGroup ctrlShow true;

		// Hide controls
		_ctrlMultiplier ctrlShow false;
		_ctrlRangeBackground ctrlShow false;
		_ctrlRange ctrlShow false;
		_ctrlProgressText ctrlShow false;
		_ctrlProgressBar ctrlShow false;

		// The initial state
		_ctrlContent ctrlSetPosition [_ctrlContentPosition select 0, _ctrlContentPosition select 1, _ctrlContentPosition select 2, 0];
		_ctrlContent ctrlCommit 0;
		_ctrlTitle ctrlSetPosition [_ctrlTitlePosition select 0, _ctrlTitlePosition select 1, 0, _ctrlTitlePosition select 3];
		_ctrlTitle ctrlSetText "";
		_ctrlTitle ctrlCommit 0;

		playSound "Beep_Target";

		// Thread
		[_ctrlTitle, _ctrlTitlePosition, _ctrlTitleText, _ctrlContent, _ctrlContentPosition, [_ctrlMultiplier, _ctrlRangeBackground, _ctrlRange, _ctrlProgressText, _ctrlProgressBar]] spawn
		{
			disableSerialization;
			scriptName "RscHvtPhase_Script: AnimateDownloadIn";

			private ["_ctrlTitle", "_ctrlTitlePosition", "_ctrlTitleText", "_ctrlContent", "_ctrlContentPosition", "_showCtrls"];
			_ctrlTitle 		= _this select 0;
			_ctrlTitlePosition	= _this select 1;
			_ctrlTitleText		= _this select 2;
			_ctrlContent		= _this select 3;
			_ctrlContentPosition	= _this select 4;
			_showCtrls		= _this select 5;

			// If timer is show, put it in correct position
			if (["IsTimerShown"] call SELF) then
			{
				private ["_display", "_timer", "_initialPosition"];
				_display		= uiNamespace getVariable [VAR_DISPLAY, displayNull];
				_timer			= _display displayCtrl IDC_RSCHVTPHASE_TIMER;
				_initialPosition	= uiNamespace getVariable [VAR_INITIAL_CONTENT_POSITION, [0,0,0,0]];

				private "_YOffset";
				_YOffset = (ctrlPosition _timer) select 3;
				_YOffset = _YOffset + (_YOffset / 100);

				_timer ctrlSetPosition [_initialPosition select 0, (_initialPosition select 1) + _YOffset, (ctrlPosition _timer) select 2, (ctrlPosition _timer) select 3];
				_timer ctrlCommit 0.4;
			};

			// Extent title
			_ctrlTitle ctrlSetPosition _ctrlTitlePosition;
			_ctrlTitle ctrlCommit 0.4;

			waituntil { ctrlCommitted _ctrlTitle };

			_ctrlTitle ctrlSetText _ctrlTitleText;

			// Extend content
			_ctrlContent ctrlSetPosition _ctrlContentPosition;
			_ctrlContent ctrlCommit 0.4;

			waituntil { ctrlCommitted _ctrlContent };

			{
				_x ctrlShow true;
			} forEach _showCtrls;

			// Sfx
			playSound "ReadoutClick";
		};
	};

	case "AnimateDownloadOut" :
	{
		private ["_display", "_ctrlGroup", "_ctrlContent", "_ctrlTitle", "_ctrlMultiplier", "_ctrlRangeBackground", "_ctrlRange", "_ctrlProgressText", "_ctrlProgressBar"];
		_display 		= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_ctrlGroup		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOAD;
		_ctrlContent		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADCONTENT;
		_ctrlTitle 		= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADTITLE;
		_ctrlMultiplier		= _display displayCtrl IDC_RSCHVTPHASE_MULTIPLIER;
		_ctrlRangeBackground	= _display displayCtrl IDC_RSCHVTPHASE_RANGEBACKGROUND;
		_ctrlRange		= _display displayCtrl IDC_RSCHVTPHASE_RANGE;
		_ctrlProgressText	= _display displayCtrl IDC_RSCHVTPHASE_DOWNLOADSPEED;
		_ctrlProgressBar	= _display displayCtrl IDC_RSCHVTPHASE_PROGRESSBAR;

		// Hide all lower controls, leave just background
		_ctrlMultiplier ctrlShow false;
		_ctrlRangeBackground ctrlShow false;
		_ctrlRange ctrlShow false;
		_ctrlProgressText ctrlShow false;
		_ctrlProgressBar ctrlShow false;

		// Sfx
		playSound "ZoomOut";

		// Thread
		[_ctrlGroup, _ctrlContent, _ctrlTitle] spawn
		{
			disableSerialization;
			scriptName "RscHvtPhase_Script: AnimateDownloadOut";

			private ["_ctrlGroup", "_ctrlContent", "_ctrlTitle"];
			_ctrlGroup 	= _this select 0;
			_ctrlContent	= _this select 1;
			_ctrlTitle	= _this select 2;

			// Shorten content
			private ["_ctrlContentPositionOld", "_ctrlContentPosition"];
			_ctrlContentPositionOld = ctrlPosition _ctrlContent;
			_ctrlContentPosition = _ctrlContentPositionOld;
			_ctrlContentPosition set [2, 0];
			_ctrlContentPosition set [3, 0];

			_ctrlContent ctrlSetPosition _ctrlContentPosition;
			_ctrlContent ctrlCommit 0.2;

			waituntil { ctrlCommitted _ctrlContent };

			// Shorten title
			private ["_ctrlTitlePositionOld", "_ctrlTitlePosition"];
			_ctrlTitlePositionOld = ctrlPosition _ctrlTitle;
			_ctrlTitlePosition = _ctrlTitlePositionOld;
			_ctrlTitlePosition set [2, 0];
			_ctrlTitlePosition set [3, 0];

			_ctrlTitle ctrlSetText "";
			_ctrlTitle ctrlSetPosition _ctrlTitlePosition;
			_ctrlTitle ctrlCommit 0.2;

			waituntil { ctrlCommitted _ctrlTitle };

			// Hide download group
			_ctrlGroup ctrlShow false;

			// If timer is show, put it in correct position
			if (["IsTimerShown"] call SELF) then
			{
				private ["_display", "_timer", "_initialPosition"];
				_display		= uiNamespace getVariable [VAR_DISPLAY, displayNull];
				_timer			= _display displayCtrl IDC_RSCHVTPHASE_TIMER;
				_initialPosition	= uiNamespace getVariable [VAR_INITIAL_CONTENT_POSITION, [0,0,0,0]];

				_timer ctrlSetPosition [_initialPosition select 0, _initialPosition select 1, (ctrlPosition _timer) select 2, _initialPosition select 3];
				_timer ctrlCommit 0.4;
			};
		};
	};

	case "IsTimerShown" :
	{
		uiNamespace getVariable [VAR_TIMER_VISIBLE, false];
	};

	case "ShowTimer" :
	{
		if !(["IsTimerShown"] call SELF) then
		{
			private ["_display", "_timer", "_initialPosition"];
			_display 		= uiNamespace getVariable [VAR_DISPLAY, displayNull];
			_timer			= _display displayCtrl IDC_RSCHVTPHASE_TIMER;
			_initialPosition 	= uiNamespace getVariable [VAR_INITIAL_CONTENT_POSITION, [0,0,0,0]];

			_timer ctrlSetPosition [_initialPosition select 0, _initialPosition select 1, (ctrlPosition _timer) select 2, _initialPosition select 3];
			_timer ctrlCommit 0;

			// If download is being shown already, timer shows bellow
			if (["IsDownloadProgressShown"] call SELF) then
			{
				private "_YOffset";
				_YOffset = (ctrlPosition _timer) select 3;
				_YOffset = _YOffset + (_YOffset / 100);

				_timer ctrlSetPosition [(ctrlPosition _timer) select 0, ((ctrlPosition _timer) select 1) + _YOffset, (ctrlPosition _timer) select 2, (ctrlPosition _timer) select 3];
				_timer ctrlCommit 0;
			};

			_timer ctrlShow true;
			uiNamespace setVariable [VAR_TIMER_VISIBLE, true];

			if (isNil { missionNamespace getVariable "RscHvtPhase_timerThread" }) then
			{
				missionNamespace setVariable ["RscHvtPhase_timerThread", [] spawn
				{
					scriptName "RscHvtPhase: Update Timer Thread";
					disableSerialization;

					["SetTimerTimeout", [0]] call SELF;

					while { true } do
					{
						private ["_targetTime", "_timeout"];
						_targetTime 	= missionNamespace getVariable ["BIS_hvt_timeoutTarget", time];
						_timeout	= _targetTime - time;

						["SetTimerTimeout", [_timeout]] call SELF;

						sleep 1;
					};
				}];
			};
		};
	};

	case "HideTimer" :
	{
		if (["IsTimerShown"] call SELF) then
		{
			private ["_display", "_timer"];
			_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
			_timer		= _display displayCtrl IDC_RSCHVTPHASE_TIMER;

			_timer ctrlShow false;
			uiNamespace setVariable [VAR_TIMER_VISIBLE, false];

			if (!isNil { RscHvtPhase_timerThread }) then
			{
				terminate RscHvtPhase_timerThread;
				RscHvtPhase_timerThread = nil;
			};
		};
	};

	case "SetTimerTimeout" :
	{
		private ["_timeout"];
		_timeout = _params param [0, 0, [0]];

		private ["_display", "_timer"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_timer		= _display displayCtrl IDC_RSCHVTPHASE_TIMER;

		if (_timeout >= 0) then
		{
			private ["_minutes", "_seconds", "_zero"];
			_minutes = floor (_timeout / 60);
			_seconds = floor (_timeout % 60);
			_zero	 = if (_seconds < 10) then { "0" } else { "" };

			_timer ctrlSetText format ["%1:%2%3", _minutes, _zero, _seconds];
		}
		else
		{
			_timer ctrlSetText "0:00";
		};
	};

	case "IsCarrierIconVisible" :
	{
		uiNamespace getVariable [VAR_CARRIER_VISIBLE, false];
	};

	case "ShowCarrierIcon" :
	{
		private ["_show"];
		_show  = _params param [0, true, [true]];

		private ["_display", "_control"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_control	= _display displayCtrl IDC_RSCHVTPHASE_CARRIERPICTURE;

		if (!isNull _display && !isNull _control) then
		{
			if (_show) then
			{
				uiNamespace setVariable [VAR_CARRIER_VISIBLE, true];
				_control ctrlSetFade 0;
				_control ctrlShow true;
				_control ctrlSetText PICTURE_CARRIER_SEEN;
				_control ctrlCommit 0.5;
			}
			else
			{
				uiNamespace setVariable [VAR_CARRIER_VISIBLE, false];
				_control ctrlSetFade 1;
				_control ctrlCommit 0.5;
				[_control] spawn
				{
					scriptName "RscHvtPhase: Hide carrier icon delay";
					disableSerialization;
					sleep 0.5;

					private "_control";
					_control = _this select 0;
					_control ctrlShow false;
				};
			};
		};
	};

	case default
	{
		["Unknown mode: %1", _mode] call BIS_fnc_error;
	};
};