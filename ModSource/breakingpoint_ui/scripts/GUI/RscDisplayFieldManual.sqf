_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		private ["_display", "_control", "_ListBoxTopic", "_ListBoxHint", "_cfgHints", "_cfgHintsMission", "_i", "_topicSelectedData"];
		_display = _params select 0;
		
		//--- set player's name
		(_display displayctrl 8434) ctrlSetText profileName;
		[_display, 8434] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
		
		//toUpper title
		_control = (_display displayctrl 1000);
		_control ctrlSetText (toUpper (ctrlText _control));
		//toUpper Back button
		_control = (_display displayctrl 2);
		_control ctrlSetText (toUpper (ctrlText _control));


		//Register event handlers
		_ListBoxTopic = (_display displayctrl 1500);
		_ListBoxHint = (_display displayctrl 1501);
		_ListBoxTopic ctrladdeventhandler ["LBSelChanged","with uinamespace do {['listTopic_LBSelChanged',_this,''] call RscDisplayFieldManual_script};"];
		//should be here to fill the description as soon as hint is selected in _ListBoxHint by this init
		_ListBoxHint ctrladdeventhandler ["LBSelChanged","with uinamespace do {['listHint_LBSelChanged',_this,''] call RscDisplayFieldManual_script};"];

	
		//Fill Topic ListBox
		_cfgHints = configfile >> "CfgHints";
		_cfgHintsMission = missionConfigFile >> "cfgHints";
		_i = 0;
		_topicSelectedData = "";
		
		if( (str(_cfgHintsMission)) != "" ) then
		{
			_currentTopic = _cfgHintsMission select _i;
			if (isclass _currentTopic) then
			{
				//Check whether the topic is non-empty (should contain at least one sub-class)
				_isTopicEmpty = true;
				if !((getNumber (_currentTopic >> "dlc")) < 0) then 
				{
					for "_k" from 0 to (count _currentTopic - 1) do
					{
						if(isClass(_currentTopic select _k)) then
						{
							_isTopicEmpty = false;
						};
					};
				};

				if (!_isTopicEmpty) then
				{
					_index = _ListBoxTopic lbAdd (localize "STR_A3_RscDisplayFieldManual_TextMission"); //"<Mission>"
					_ListBoxTopic lbSetValue [_index, _i]; //add metadata - number that represents order in config
					_i = _i + 1;	
				};	
			};
		};
		
		while {_i <= (count _cfgHints - 1)} do
		{
			_currentTopic = _cfgHints select _i;
			if (isclass _currentTopic) then
			{
				//Check whether the topic is non-empty (should contain at least one sub-class)
				_isTopicEmpty = true;
				if !((getNumber (_currentTopic >> "dlc")) < 0) then 
				{
					for "_k" from 0 to (count _currentTopic - 1) do
					{
						if(isClass(_currentTopic select _k)) then
						{
							_isTopicEmpty = false;
						};
					};
				};
					
				if (!_isTopicEmpty) then
				{
					//Read displayName including arguments. Needed for reading displayName from locDB bis_fnc_advHintArg.
					//Arguments are not needed for ListBox, but are applied for hint title which uses displayName too.
					_displayName = getText(_currentTopic >> "displayName");
					//Get arguments.
					_arguments = getArray(_currentTopic >> "arguments");
					_keyColor = (["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet) call BIS_fnc_colorRGBtoHTML;
					_elementColor = (["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet) call BIS_fnc_colorRGBtoHTML;
					//Shift of the reguments according to the string variables shift and color them when needed.
					_arguments = [_arguments, _keyColor, _elementColor] call bis_fnc_advHintArg;
					_displayName = format([_displayName]+_arguments);
					
					_index = _ListBoxTopic lbAdd _displayName;
					_ListBoxTopic lbSetValue [_index, _i]; //add metadata - number that represents order in config
					//add metadata
					_topicID = "GlobalTopic_"+(configName _currentTopic);
					_ListBoxTopic lbSetData [_index, _topicID];
					
					//Mark topic shown as hint in the mission
					if(_topicID in (missionNamespace getVariable ['BIS_fnc_advHint_FMMark', []]) ) then
					{
						_ListBoxTopic lbSetPicture [_index, "\A3\Ui_f\data\Map\Markers\Military\warning_CA.paa"];
					};

					//Check if topic was selected when Field Manual was last time opened.
					//Take DLC topics into account (Field Manual was invoked by click on DLC logo in Main Menu).
					_topicStr = "";
					_dlcTopic = (getFieldManualStartPage _display) select 0;
					
					if(_dlcTopic != "") then
					{
						_topicStr = "GlobalTopic_" + _dlcTopic;
					}
					else
					{
						_topicStr = uiNamespace getVariable ['RscDisplayFieldManual_Topic', ""];
					};
					
					if( (_topicStr != "") && ((_ListBoxTopic lbData _index) == _topicStr) ) then
					{
						_topicSelectedData = _ListBoxTopic lbData _index;
					};
				};
				
				_i = _i + 1;
			};
		};
		
		lbSort _ListBoxTopic;
		
		//Find topic that was selected while closing Field Manual last time
		scopeName "onLoadScope";
		for "_k" from 0 to ((lbSize _ListBoxTopic) - 1) do
		{
			if((_ListBoxTopic lbData _k) == _topicSelectedData) then
			{
				_ListBoxTopic lbSetCurSel _k;
				breakTo "onLoadScope";
			};
		};
		
		//Ensure that on first opening of Field Manual after game restart first item will be selected
		if(_topicSelectedData == "") then
		{
			_ListBoxTopic lbSetCurSel 0;
		};


		//Find hint that was selected while closing Field Manual last time.
		//Take DLC hints into account (Field Manual was invoked by click on DLC logo in Main Menu).
		_hintStr = "";
		_dlcHint = (getFieldManualStartPage _display) select 1;
		_topicClassName = [_ListBoxTopic lbData (lbCurSel _ListBoxTopic), 12] call bis_fnc_trimString;
		
		if(_dlcHint != "") then
		{
			_hintStr = _topicClassName + "_" + _dlcHint;
		}
		else
		{
			_hintStr = uiNamespace getVariable ['RscDisplayFieldManual_Hint', ""];
		};
		
		if(_hintStr != "") then
		{
			for "_k" from 0 to ((lbSize _ListBoxHint) - 1) do
			{
				if( ((_ListBoxTopic lbText _k) != "<Mission>") && ((_ListBoxHint lbData _k) == _hintStr) ) then
				{
					_ListBoxHint lbSetCurSel _k;
					breakTo "onLoadScope";
				};
			};
		};
	};
	
	
	case "listTopic_LBSelChanged": {
	
		//Reads hints for the selected topic
		private ["_ListBoxTopic", "_display", "_ListBoxHint", "_topicSelectedNum", "_cfgHintsMission", "_currentTopic"];
		_ListBoxTopic = (_this select 1) select 0;
		_display = ctrlparent _ListBoxTopic;
		_ListBoxHint = (_display displayctrl 1501);
		_topicSelectedNum = _ListBoxTopic lbValue ((_this select 1) select 1);
		_cfgHintsMission = missionConfigFile >> "cfgHints";
		_currentTopic = "";
		
		//Check if mission specific hints are defined in description.ext and selected in Topic ListBox
		if( ((str _cfgHintsMission) != "") && (_topicSelectedNum == 0)) then
		{
			_currentTopic = _cfgHintsMission select _topicSelectedNum;
		}
		else
		{
			_currentTopic = (configfile >> "CfgHints") select _topicSelectedNum;
		};
		
		lbClear _ListBoxHint;
		(_display displayctrl 1100) ctrlSetStructuredText parseText "";
		
		if (isclass _currentTopic) then
		{
			//Fill second ListBox with the hints of selected topic
			for "_i" from 0 to (count _currentTopic - 1) do
			{
				_currentHint = _currentTopic select _i;
				if ((isclass _currentHint) && {!((getNumber (_currentHint >> "dlc")) < 0)}) then
				{
					//Read displayName including arguments. Needed for reading displayName from locDB bis_fnc_advHintArg.
					//Arguments are not needed for ListBox, but are applied for hint title which uses displayName too.
					_displayName = getText(_currentHint >> "displayName");	
					//Get arguments.
					_arguments = getArray(_currentHint >> "arguments");
					_keyColor = (["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet) call BIS_fnc_colorRGBtoHTML;
					_elementColor = (["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet) call BIS_fnc_colorRGBtoHTML;
					//Shift of the reguments according to the string variables shift and color them when needed.
					_arguments = [_arguments, _keyColor, _elementColor] call bis_fnc_advHintArg;	
					_displayName = format([_displayName]+_arguments);

					_index = _ListBoxHint lbAdd _displayName;
					_ListBoxHint lbSetValue [_index, _i]; //add metadata - number that represents order in config
					//_ListBoxHint lbSetPicture [_index, "#(argb,8,8,3)color(0.5,0,0,0.5)"]; //for indicating unread hints
					
					//add metadata for remembering selected item
					_hintID = (configName _currentTopic)+"_"+(configName _currentHint);
					_ListBoxHint lbSetData [_index, _hintID];
					
					//Mark hint shown in the mission
					if(_hintID in (missionNamespace getVariable ['BIS_fnc_advHint_FMMark', []])) then
					{
						_ListBoxHint lbSetPicture [_index, "\A3\Ui_f\data\Map\Markers\Military\warning_CA.paa"];
					};	
				};
			};
		};
		lbSort _ListBoxHint;
		_ListBoxHint lbSetCurSel 0; //during init (after dialogue is opened and ListBoxHint first filled) is overwritten
	};
	
	case "listHint_LBSelChanged": {
	
		//Displays text of the selected hint
		private ["_ListBoxHint", "_display", "_ListBoxTopic", "_topicSelectedNum", "_cfgHintsMission", "_currentTopic", "_hintControl", "_position"];
		_ListBoxHint = (_this select 1) select 0;
		_display = ctrlparent _ListBoxHint;
		_ListBoxTopic = (_display displayctrl 1500);
		_topicSelectedNum = (_ListBoxTopic lbValue (lbCurSel _ListBoxTopic));
		_cfgHintsMission = missionConfigFile >> "cfgHints";
		_currentTopic = "";
		
		//Check if mission specific hints are defined in description.ext and selected in Topic ListBox
		if( ((str _cfgHintsMission) != "") && (_topicSelectedNum == 0)) then
		{
			_currentTopic = _cfgHintsMission select _topicSelectedNum;
		}
		else
		{
			_currentTopic = (configfile >> "CfgHints") select _topicSelectedNum;
		};

		if(count _currentTopic > 0) then
		{
			_selectedHint = _currentTopic select (_ListBoxHint lbValue ((_this select 1) select 1));
		
			if (isclass _selectedHint) then
			{
				//Colors
				_keyColor = (["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet) call BIS_fnc_colorRGBtoHTML;
				_elementColor = (["GUI", "BCG_RGB"] call BIS_fnc_displayColorGet) call BIS_fnc_colorRGBtoHTML;
				_shadowColor = "#999999";
				
				//Text sizes
				_textSizeSmall = 0.8;		// computed from size parameter set in config: configSize*_textSizeSmall = final size
				_textSizeNormal = 1.0;		// e.g. configSize = 1 (parameter size), 1*0.8=0.8 or 1*1=1;
				
				//Load strings
				_displayName = getText(_selectedHint >> "displayName");
				_displayNameShort = getText(_selectedHint >> "displayNameShort");
				_image = getText(_selectedHint >> "image");
				_description = getText(_selectedHint >> "description");
				_tip = getText(_selectedHint >> "tip");
				_arguments = getArray(_selectedHint >> "arguments");
				
				//DLC check
				_dlcNo = getNumber (_selectedHint >> "dlc");
				if !((_dlcNo == 0) || {_dlcNo in (getDlcs 1)}) then 
				{
					_displayName = getText(configFile >> "CfgHints" >> "DlcMessage" >> ("Dlc" + (str _dlcNo) + "FM") >> "displayName");
					_image = getText(configFile >> "CfgHints" >> "DlcMessage" >> ("Dlc" + (str _dlcNo) + "FM") >> "image");
					_description = getText(configFile >> "CfgHints" >> "DlcMessage" >> ("Dlc" + (str _dlcNo) + "FM") >> "description");
					_tip = getText(configFile >> "CfgHints" >> "DlcMessage" >> ("Dlc" + (str _dlcNo) + "FM") >> "tip");
					_arguments = getArray(configFile >> "CfgHints" >> "DlcMessage" >> ("Dlc" + (str _dlcNo) + "FM") >> "arguments");
				};
				
				//shift of the reguments according to the string variables shift and color them when needed
				_arguments = [_arguments, _keyColor, _elementColor] call bis_fnc_advHintArg;
				
				_displayName = toUpper(format([_displayName]+_arguments));
				
				//shift of string variables (e.g. %1 to %5 etc.)
				//_description = [_description] call bis_fnc_advHintInfo;
				
				//concatenate and format string with arguments (replacement of variables in the string with proper arguments)
				_description = [_description] + _arguments;
				_description = format _description;
				
				//_displayNameShort is optional, check if it is present and non-empty
				_startPartString = "";
				if (_displayNameShort == "") then {
					_startPartString = format ["<t align='left' size = '%2' color = '%3'>%1</t>", _displayName, _textSizeNormal, _keyColor];
				} else {
					_startPartString = format ["<t align='left' size = '%3' color = '%4'>%1</t><br/><t size = '%3' align='left' color = '%5'>""%2""</t>", _displayName, _displayNameShort, _textSizeNormal, _keyColor, _shadowColor];
				};
				
				//Title
				_titleControl = (_display displayctrl 1101);
				_titleControl ctrlSetStructuredText parseText (_startPartString);
				
				//image
				if (_image == "") then
				{
					//NO ICON image - TODO: add icon here as soon as it is ready
					(_display displayctrl 1200) ctrlSetText "#(argb,8,8,3)color(1,1,1,0.1)";
				}
				else
				{						
					(_display displayctrl 1200) ctrlSetText _image;
				};
				
				_middlePartString = format ["<t align='left' size='%2'>%1</t><br/>", _description, _textSizeNormal];	// from image to tip
				_hintControl = (_display displayctrl 1100);
				
				if (_tip == "") then
				{
					_hintControl ctrlSetStructuredText parseText (_middlePartString);	
				}
				else
				{
					//shift of string variables (e.g. %1 to %5 etc.)
					//_tip = [_tip] call bis_fnc_advHintInfo;
					//concatenate and format string with arguments (replacement of variables in the string with proper arguments)
					_tip = [_tip] + _arguments;
					_tip = format _tip;
					_tip = format ["<t align='left' size='%2' color='%3'>%1</t><br/>", _tip, _textSizeNormal, _shadowColor];
					_hintControl ctrlSetStructuredText (parseText (format ["%1<br/>%2", _middlePartString, _tip]));
				};
				
				//Resize StructuredText component to display the scrollbar if needed
				_position = ctrlPosition _hintControl;
				_hintControl ctrlSetPosition [_position select 0, _position select 1, _position select 2, ctrlTextHeight _hintControl];
				_hintControl ctrlcommit 0;
			};
		};
	};
	
	case "onUnload": {
	
		private ["_display", "_ListBoxTopic", "_ListBoxHint"];
		_display = _params select 0;
		_ListBoxTopic = _display displayctrl 1500;
		_ListBoxHint = _display displayctrl 1501;
		
		//Remember the selected topic
		uinamespace setvariable ["RscDisplayFieldManual_Topic", _ListBoxTopic lbData (lbCurSel _ListBoxTopic)];
		uinamespace setvariable ["RscDisplayFieldManual_Hint", _ListBoxHint lbData (lbCurSel _ListBoxHint)];
	};
};
