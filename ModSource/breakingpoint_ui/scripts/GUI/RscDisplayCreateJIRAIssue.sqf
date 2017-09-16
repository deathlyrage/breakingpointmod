#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		_display = _params select 0;

		_ctrlTitle = _display displayctrl IDC_RSCDISPLAYCREATEJIRAISSUE_TITLE;
		_ctrlTitle ctrlsetstructuredtext parsetext format ["<img image='\a3\Ui_f\data\GUI\Rsc\RscDisplayCreateJIRAIssue\jira_ca.paa' />%1<a href='https://confluence.bistudio.com/display/ARMA3/In-game+Issue+Reporting' align='right'>?</a>",toupper ctrltext _ctrlTitle];

		_ctrlDescription = _display displayctrl IDC_RSCDISPLAYCREATEJIRAISSUE_DESCRIPTION;
		_ctrlDescription ctrlsetstructuredtext parsetext "Create JIRA issue based on a specific template. Screenshot of the current scene will be saved in the following path (can be absolute, or relative to Arma 3 root):";

		_ctrlScreenshotPath = _display displayctrl IDC_RSCDISPLAYCREATEJIRAISSUE_SCREENSHOTPATH;
		_ctrlScreenshotPath ctrlsettext (profilenamespace getvariable ["BIS_fnc_diagJIRAlink_path",""]);

		{
			_ctrl = _display displayctrl (_x select 0);
			[_x select 1,_ctrl] call bis_fnc_diagJIRAlink;
			_ctrl ctrladdeventhandler [
				"htmlLink",
				{
					_display = ctrlparent (_this select 0);
					_ctrlScreenshotPath = _display displayctrl IDC_RSCDISPLAYCREATEJIRAISSUE_SCREENSHOTPATH;
					profilenamespace setvariable ["BIS_fnc_diagJIRAlink_path",ctrltext _ctrlScreenshotPath];
					saveprofilenamespace;
					_display closedisplay 2;
				}
			];
		} foreach [
			[IDC_RSCDISPLAYCREATEJIRAISSUE_BUTTONEMPTY,""],
			[IDC_RSCDISPLAYCREATEJIRAISSUE_BUTTONMISSION,"mission"],
			[IDC_RSCDISPLAYCREATEJIRAISSUE_BUTTONMAP,"map"],
			[IDC_RSCDISPLAYCREATEJIRAISSUE_BUTTONOBJECT,"object"]
		];
	};
};