_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		//Format and set welcome message
		private ["_shown","_display", "_colorHighlight", "_colorWarning", "_bullet", "_message", "_text1", "_text2", "_buttonSpoiler", "_textSpoiler",
			 "_positionText1", "_yText1", "_hText1", "_positionSpoilerButton","_hSpoilerButton","_positionSpoilerText"];
		_display = _params select 0;
		_colorHighlight = ["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet;
		_colorHighlight = _colorHighlight call BIS_fnc_colorRGBtoHTML;
		_colorWarning = ["IGUI", "WARNING_RGB"] call BIS_fnc_displayColorGet;
		_colorWarning = _colorWarning call BIS_fnc_colorRGBtoHTML;		
		
		_bullet = "<t size='0.5' color='" + _colorHighlight + "'><img image='A3\Ui_f\data\IGUI\RscIngameUI\RscHint\indent_square' /></t>";

		//Definitions of controls influenced by Spoiler button
		uiNamespace setVariable ["BIS_welcomeScreenShowSpoiler", false];
		_text1 = _display displayCtrl 1100;
		_buttonSpoiler = _display displayctrl 2400;
		_textSpoiler = _display displayctrl 1101;
		_text2 = _display displayCtrl 1102;

		//Show main Welcome Screen, Bootcamp, or trial?		
		if ((configName (configFile >> "CfgPatches" >> "A3_Missions_F_EPC")) != "") then 
		{
			_shown = profileNamespace getVariable ["BIS_welcomeScreenShown", 0];
		
			if (_shown <= 0) then 
			{
				//Main version
				//Register for the session.
				uiNamespace setVariable ["BIS_welcomeScreenShown", true];
			
				//Update how often this profile has seen the Welcome Screen
				_shown = _shown + 1;
				profileNamespace setVariable ["BIS_welcomeScreenShown", _shown];
				saveProfileNamespace;
			
				//Localized RC version
				_message = "";
				_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\ui_f\data\logos\arma3_expansion_ca' /></t><br />";
				_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARA2", _colorHighlight, "<img size='1' image='\A3\Ui_f\data\Logos\tm_ca' />"]) + "<br /><br />";
				
				_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Showcase_Arma_briefing_CA' /></t><br /><br />";
				
				_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_PARB_TITLE")) + "</t><br />";
				_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARB", _colorHighlight]) + "<br /><br />";
				_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST1") + "<br />";
				_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST2") + "<br />";
				_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST3") + "<br />";
				_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST4") + "<br /><br />";
				_message = _message + "<a href='http://www.arma3.com/' color='" + _colorWarning + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_FOOTER") + "</a><br /><br />";
				
				_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Faction_BLUFOR_briefing_CA' /></t><br /><br />";
				
				_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_PARC_TITLE")) + "</t><br />";
				_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARC", _colorHighlight, "<img size='1' image='\A3\Ui_f\data\Logos\tm_ca' />"]) + "<br /><br />";
				_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST1") + "<br />";
				_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST2") + "<br />";
				_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST3") + "<br />";
				_message = _message + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST4", "<img size='1' image='\A3\Ui_f\data\Logos\tm_ca' />"]) + "<br /><br />";
				_message = _message + "<a href='http://www.arma3.com/whatsnew/' color='" + _colorWarning + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_FOOTER") + "</a><br /><br />";
				
				_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Faction_OPFOR_briefing_CA' /></t><br /><br />";
				
				_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_PARE_TITLE")) + "</t><br />";
				_message = _message + (localize "STR_A3_RSCDISPLAYWELCOME_PARE") + "<br /><br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST1_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST1") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST2_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST2") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST6_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST6") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST4_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST4") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST5_TITLE") + "</t> - " + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST5", _colorWarning, "http://feedback.arma3.com/"]) + "<br /><br />";
				
				_message = _message + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_FOOTER1") + "<br />";
				
				_message = _message + "<t size='6' shadow='0'><img image='A3\Ui_f\data\Logos\bi_white_ca' /></t><br />";
				
				_message = _message + "- " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_FOOTER2") + "<br /><br />";
				
				
				//Fill only the first text
				_text1 ctrlSetStructuredText (parseText _message);

				//Resize StructuredText component to display the scrollbar if needed
				_positionText1 = ctrlPosition _text1;
				_yText1 = _positionText1 select 1;
				_hText1 = ctrlTextHeight _text1;
				_text1 ctrlSetPosition [_positionText1 select 0, _yText1, _positionText1 select 2, _hText1];
				_text1 ctrlcommit 0;
				
				//Hide second text, spoiler text and button
				_buttonSpoiler ctrlSetFade 1;
				_buttonSpoiler ctrlCommit 0;
				_buttonSpoiler ctrlEnable false;
				
				_textSpoiler ctrlSetFade 1;
				_textSpoiler ctrlCommit 0;
				
				_text2 ctrlSetFade 1;
				_text2 ctrlCommit 0;
			} 
			else 
			{
				//Bootcamp version
				//Register for the session.
				uiNamespace setVariable ["BIS_welcomeScreenBootcampShown", true];
			
				//Update how often this profile has seen the Welcome Screen
				_shown = profileNamespace getVariable ["BIS_welcomeScreenBootcampShown", 0];
				_shown = _shown + 1;
				profileNamespace setVariable ["BIS_welcomeScreenBootcampShown", _shown];
				saveProfileNamespace;
			
				_message = "";
				_message = _message + "<t align='center' size='8' shadow='0'><img image='A3\Ui_f\data\Logos\arma3_bootcamp_logo_ca' /></t><br />";
				_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARA", _colorHighlight]) + "<br /><br />";
				
				_message = _message + "<t align='center' size='8' shadow='0'><img image='A3\Data_F_Bootcamp\Data\FM_LEARN_Bootcamp1_ca' /></t><br /><br />";
				
				_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_TITLE")) + "</t><br />";			
				_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB", _colorHighlight]) + "<br /><br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST1_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST1") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST2_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST2") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST3_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST3") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST4_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST4") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST5_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARB_LIST5") + "<br /><br />";
				_message = _message + "<a href='http://www.arma3.com/bootcamp' color='" + _colorWarning + "'>www.arma3.com/bootcamp</a><br /><br />";
				
				_message = _message + "<t align='center' size='8' shadow='0'><img image='A3\Data_F_Bootcamp\Data\FM_LEARN_Bootcamp4_ca' /></t><br /><br />";
				
				_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC_TITLE")) + "</t><br />";
				_message = _message + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC") + "<br /><br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC_LIST1_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC_LIST1") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC_LIST2_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC_LIST2") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC_LIST3_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARC_LIST3") + "<br /><br />";
				
				_message = _message + "<t align='center' size='8' shadow='0'><img image='A3\Data_F_Bootcamp\Data\FM_LEARN_Bootcamp5_ca' /></t><br /><br />";
				
				_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARD_TITLE")) + "</t><br /><br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARD_LIST1_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARD_LIST1") + "<br />";
				_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARD_LIST2_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARD_LIST2") + "<br /><br />";
				
				_message = _message + "<a href='http://www.arma3.com/whatsnewbootcamp/' color='" + _colorWarning + "'>www.arma3.com/whatsnewbootcamp</a><br /><br />";
				
				_message = _message + (localize "STR_A3_RSCDISPLAYWELCOME_BOOT_PARD_FOOTER2") + "<br />";
				
				_message = _message + "<t size='6' shadow='0'><img image='A3\Ui_f\data\Logos\bi_white_ca' /></t><br />";
				
				_message = _message + "- " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_FOOTER2") + "<br /><br />";
				
				//Fill only the first text
				_text1 ctrlSetStructuredText (parseText _message);

				//Resize StructuredText component to display the scrollbar if needed
				_positionText1 = ctrlPosition _text1;
				_yText1 = _positionText1 select 1;
				_hText1 = ctrlTextHeight _text1;
				_text1 ctrlSetPosition [_positionText1 select 0, _yText1, _positionText1 select 2, _hText1];
				_text1 ctrlcommit 0;
				
				//Hide second text, spoiler text and button
				_buttonSpoiler ctrlSetFade 1;
				_buttonSpoiler ctrlCommit 0;
				_buttonSpoiler ctrlEnable false;
				
				_textSpoiler ctrlSetFade 1;
				_textSpoiler ctrlCommit 0;
				
				_text2 ctrlSetFade 1;
				_text2 ctrlCommit 0;
			};
		} 
		else 
		{
			//Trial version
			//Register for the session.
			uiNamespace setVariable ["BIS_welcomeScreenShown", true];
			
			_message = "";
			_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\ui_f\data\logos\arma3_expansion_ca' /> <img image='a3\ui_f\data\logos\steam_ca' /></t><br />";
			_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARA2_TRIAL", _colorHighlight, "<img size='1' image='\A3\Ui_f\data\Logos\tm_ca' />"]) + "<br /><br />";
			
			_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Showcase_Arma_briefing_CA' /></t><br /><br />";
			
			_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_PARB_TITLE")) + "</t><br />";
			_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARB", _colorHighlight]) + "<br /><br />";
			_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST1") + "<br />";
			_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST2") + "<br />";
			_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST3") + "<br />";
			_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_LIST4") + "<br /><br />";
			_message = _message + "<a href='http://www.arma3.com/' color='" + _colorWarning + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARB_FOOTER") + "</a><br /><br />";
			
			_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Faction_BLUFOR_briefing_CA' /></t><br /><br />";
			
			_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_PARC_TITLE")) + "</t><br />";
			_message = _message + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARC", _colorHighlight, "<img size='1' image='\A3\Ui_f\data\Logos\tm_ca' />"]) + "<br /><br />";
			_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST1") + "<br />";
			_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST2") + "<br />";
			_message = _message + _bullet + " " + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST3") + "<br />";
			_message = _message + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARC_LIST4", "<img size='1' image='\A3\Ui_f\data\Logos\tm_ca' />"]) + "<br /><br />";
			_message = _message + "<a href='http://www.arma3.com/whatsnew/' color='" + _colorWarning + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARC_FOOTER") + "</a><br /><br />";
			
			_message = _message + "<t align='center' size='8' shadow='0'><img image='a3\missions_f_gamma\data\img\Faction_OPFOR_briefing_CA' /></t><br /><br />";
			
			_message = _message + "<t color='" + _colorHighlight + "'>" + (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_PARE_TITLE")) + "</t><br />";
			_message = _message + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_TRIAL") + "<br /><br />";
			_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST1_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST1") + "<br />";
			_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST2_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST2") + "<br />";
			_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST6_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST6") + "<br />";
			_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST4_TITLE") + "</t> - " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST4_TRIAL") + "<br />";
			_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST5_TITLE") + "</t> - " + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST5", _colorWarning, "http://feedback.arma3.com/"]) + "<br />";
			_message = _message + _bullet + " <t color='" + _colorHighlight + "'>" + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST7_TITLE") + "</t> - " + (format [localize "STR_A3_RSCDISPLAYWELCOME_PARE_LIST7", _colorWarning, "http://makearmanotwar.com/"]) + "<br /><br />";
			
			_message = _message + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_FOOTER1") + "<br />";
			
			_message = _message + "<t size='6' shadow='0'><img image='A3\Ui_f\data\Logos\bi_white_ca' /></t><br />";
			
			_message = _message + "- " + (localize "STR_A3_RSCDISPLAYWELCOME_PARE_FOOTER2") + "<br /><br />";
			
			//Fill only the first text
			_text1 ctrlSetStructuredText (parseText _message);

			//Resize StructuredText component to display the scrollbar if needed
			_positionText1 = ctrlPosition _text1;
			_yText1 = _positionText1 select 1;
			_hText1 = ctrlTextHeight _text1;
			_text1 ctrlSetPosition [_positionText1 select 0, _yText1, _positionText1 select 2, _hText1];
			_text1 ctrlcommit 0;
			
			//Hide second text, spoiler text and button
			_buttonSpoiler ctrlSetFade 1;
			_buttonSpoiler ctrlCommit 0;
			_buttonSpoiler ctrlEnable false;
			
			_textSpoiler ctrlSetFade 1;
			_textSpoiler ctrlCommit 0;
			
			_text2 ctrlSetFade 1;
			_text2 ctrlCommit 0;
		};
	};
	
	case "spoilerButton":
	{
		private["_display","_buttonSpoiler","_spoilerText","_text2","_positionSpoilerText","_positionText2","_hSpoilerText"];

		_buttonSpoiler = _params select 0;
		_display = ctrlparent _buttonSpoiler;
		_spoilerText = _display displayCtrl 1101;
		_positionSpoilerText = ctrlPosition _spoilerText;
		_text2 = _display displayCtrl 1102;
			
		if(uiNamespace getVariable ["BIS_welcomeScreenShowSpoiler", true]) then
		{
			//TRUE - Hide spoiler (set its height to 0 and reposition all following UI elements)	
			_spoilerText ctrlSetPosition [_positionSpoilerText select 0, _positionSpoilerText select 1, _positionSpoilerText select 2, 0];
			_spoilerText ctrlcommit 0.2;
			
			//Reposition text under the Spoiler
			_positionText2 = ctrlPosition _text2;
			_text2 ctrlSetPosition [_positionText2 select 0, (_positionSpoilerText select 1) + 0, _positionText2 select 2, _positionText2 select 3];
			_text2 ctrlcommit 0.3;
			
			uiNamespace setVariable ["BIS_welcomeScreenShowSpoiler", false];
			_buttonSpoiler ctrlSetText (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_BUTTONSPOILER_SHOW"));	//"Show Spoiler";
		}
		else
		{
			//FALSE - Show spoiler
			private ["_colorHighlight", "_bullet", "_messageSpoiler"];
			_colorHighlight = ["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet;
			_colorHighlight = _colorHighlight call BIS_fnc_colorRGBtoHTML;
			
			_bullet = "<t size='0.5' color='" + _colorHighlight + "'><img image='A3\Ui_f\data\IGUI\RscIngameUI\RscHint\indent_square' /></t>";
			
			_messageSpoiler = "";

			//There are no spoilers currently
			/*
			_messageSpoiler = _messageSpoiler + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD2", _colorHighlight]) + "<br /><br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST1", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST2", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST3", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST4", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST5", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST6", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST7", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPB_PARD_LIST8", _colorHighlight]) + "<br /><br />";
			
			_messageSpoiler = _messageSpoiler + "<t align='center' size='8' shadow='0'><img image='A3\Missions_F_EPA\data\img\A_out_overview_CA' /></t><br /><br />";
			
			_messageSpoiler = _messageSpoiler + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC2", _colorHighlight]) + "<br /><br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST1", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST2", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST3", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST4", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST5", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST6", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST7", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST8", _colorHighlight]) + "<br />";
			_messageSpoiler = _messageSpoiler + _bullet + " " + (format [localize "STR_A3_RSCDISPLAYWELCOME_EPC_PARC_LIST9", _colorHighlight]) + "<br /><br />";
			
			_messageSpoiler = _messageSpoiler + "<t align='center' size='8' shadow='0'><img image='A3\Missions_F_EPB\data\img\B_out2_overview_CA' /></t><br />";
			*/
			
			_spoilerText ctrlSetStructuredText (parseText _messageSpoiler);
			_hSpoilerText = ctrlTextHeight _spoilerText;
			_spoilerText ctrlSetPosition [_positionSpoilerText select 0, _positionSpoilerText select 1, _positionSpoilerText select 2, _hSpoilerText];
			_spoilerText ctrlcommit 0.3;
			
			//Reposition text under the Spoiler
			_positionText2 = ctrlPosition _text2;
			_text2 ctrlSetPosition [_positionText2 select 0, (_positionSpoilerText select 1) + _hSpoilerText, _positionText2 select 2, _positionText2 select 3];
			_text2 ctrlcommit 0.2;
			
			uiNamespace setVariable ["BIS_welcomeScreenShowSpoiler", true];
			_buttonSpoiler ctrlSetText (toUpper (localize "STR_A3_RSCDISPLAYWELCOME_BUTTONSPOILER_HIDE"));	//"Hide Spoiler";
		};
	};	
};