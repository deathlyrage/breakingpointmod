disableSerialization;

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
	
		with uinamespace do {
		
			_display = _params select 0;
			_rainMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "RainConfig" >> "minCloudiness");
			_lightningsMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "LightningsConfig" >> "minCloudiness");
			
			//--- Register event handlers for CheckBoxes and Sliders
			(_display displayctrl 118) ctrladdeventhandler ["CheckBoxesSelChanged","with uinamespace do {['rain',_this,''] call RscDisplayIntel_script};"];
			(_display displayctrl 123) ctrladdeventhandler ["CheckBoxesSelChanged","with uinamespace do {['lightning',_this,''] call RscDisplayIntel_script};"];
			(_display displayctrl 128) ctrladdeventhandler ["CheckBoxesSelChanged","with uinamespace do {['waves',_this,''] call RscDisplayIntel_script};"];
			(_display displayctrl 133) ctrladdeventhandler ["CheckBoxesSelChanged","with uinamespace do {['wind',_this,''] call RscDisplayIntel_script};"];
			(_display displayctrl 108) ctrladdeventhandler ["SliderPosChanged","with uinamespace do {['overcastChanged',_this,''] call RscDisplayIntel_script};"];
			(_display displayctrl 110) ctrladdeventhandler ["SliderPosChanged","with uinamespace do {['forecastedOvercastChanged',_this,''] call RscDisplayIntel_script};"];
			
			//RAIN - enable/disable sliders according to button state and cloudiness (overcast) value
			_isRainAuto = ctrlChecked (_display displayctrl 118);
			_isCloudy = if( parseNumber(ctrlText (_display displayctrl 113)) >= (_rainMinCloudiness*100) ) then {true} else {false};
			(_display displayctrl 119) ctrlEnable (!(_isRainAuto) && _isCloudy);		//slider rain start
			(_display displayctrl 120) ctrlEnable !(_isRainAuto);				//text rain start
			(_display displayctrl 121) ctrlEnable !(_isRainAuto);				//slider rain forecasted
			(_display displayctrl 122) ctrlEnable !(_isRainAuto);				//text rain forecasted
			
			//LIGHTNING - enable/disable sliders according to button state
			_isLightningAuto = ctrlChecked (_display displayctrl 123);
			_isCloudy = if( parseNumber(ctrlText (_display displayctrl 113)) >= (_lightningsMinCloudiness*100) ) then {true} else {false};
			(_display displayctrl 124) ctrlEnable (!(_isLightningAuto) && _isCloudy);	//slider lightning start
			(_display displayctrl 125) ctrlEnable !(_isLightningAuto);			//text lightning start
			(_display displayctrl 126) ctrlEnable !(_isLightningAuto);			//slider lightning forecasted
			(_display displayctrl 127) ctrlEnable !(_isLightningAuto);			//text lightning forecasted
			
			//WAVES - enable/disable sliders according to button state
			_isWavesAuto = ctrlChecked (_display displayctrl 128);
			(_display displayctrl 129) ctrlEnable !(_isWavesAuto);				//slider waves start
			(_display displayctrl 130) ctrlEnable !(_isWavesAuto);				//text waves start
			(_display displayctrl 131) ctrlEnable !(_isWavesAuto);				//slider waves forecasted
			(_display displayctrl 132) ctrlEnable !(_isWavesAuto);				//text waves forecasted
			
			//WIND - enable/disable sliders according to button state
			_isWindAuto = ctrlChecked (_display displayctrl 133);
			(_display displayctrl 134) ctrlEnable !(_isWindAuto);
			(_display displayctrl 135) ctrlEnable !(_isWindAuto);
			(_display displayctrl 136) ctrlEnable !(_isWindAuto);
			(_display displayctrl 137) ctrlEnable !(_isWindAuto);
			(_display displayctrl 138) ctrlEnable !(_isWindAuto);
			(_display displayctrl 139) ctrlEnable !(_isWindAuto);
			(_display displayctrl 140) ctrlEnable !(_isWindAuto);
			(_display displayctrl 141) ctrlEnable !(_isWindAuto);
			(_display displayctrl 142) ctrlEnable !(_isWindAuto);
			(_display displayctrl 143) ctrlEnable !(_isWindAuto);
			(_display displayctrl 144) ctrlEnable !(_isWindAuto);
			(_display displayctrl 145) ctrlEnable !(_isWindAuto);
			
			//Set title text toUpper
			_control = _display displayctrl 1000;
			_control ctrlSetText (toUpper (ctrlText _control));
		};
	};
	
	//--- RAIN CheckBox
	case "rain": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		_checkBoxState = (_this select 1) select 2; 			//_this - array that comes from event handler

		//switching to manual
		if(_checkBoxState == 0) then
		{
			_checkBoxState = true;
			
			//Decide, whether to move the overcast and forecasted overcast bar to the threshold value
			_overcastValue = parseNumber(ctrlText (_display displayctrl 113));
			_forecastedOvercastValue = parseNumber(ctrlText (_display displayctrl 114));
			_rainMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "RainConfig" >> "minCloudiness");
			
			if( _overcastValue < (_rainMinCloudiness * 100) ) then
			{
				(_display displayctrl 113) ctrlSetText (str (100 * _rainMinCloudiness));		//text overcast start
			};
			
			if( _forecastedOvercastValue < (_rainMinCloudiness * 100) ) then
			{
				(_display displayctrl 114) ctrlSetText (str (100 * _rainMinCloudiness));		//text overcast forecasted
			};
		}
		else //switching to auto
		{
			_checkBoxState = false;
			
			(_display displayctrl 120) ctrlSetText "0";		//text rain start
			(_display displayctrl 122) ctrlSetText "0";		//text rain forecasted
		};
		
		(_display displayctrl 119) ctrlEnable _checkBoxState;		//slider rain start
		(_display displayctrl 120) ctrlEnable _checkBoxState;		//text rain start
		(_display displayctrl 121) ctrlEnable _checkBoxState;		//slider rain forecasted
		(_display displayctrl 122) ctrlEnable _checkBoxState;		//text rain forecasted	
	};
	
	//--- LIGHTNING CheckBox
	case "lightning": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		_checkBoxState = (_this select 1) select 2; 			//_this - array that comes from event handler
		
		if(_checkBoxState == 0) then
		{
			_checkBoxState = true;
			
			//Decide, whether to move the overcast and forecasted overcast bar to the threshold value
			_overcastValue = parseNumber(ctrlText (_display displayctrl 113));
			_forecastedOvercastValue = parseNumber(ctrlText (_display displayctrl 114));
			_lightningsMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "LightningsConfig" >> "minCloudiness");
			
			if( _overcastValue < (_lightningsMinCloudiness * 100) ) then
			{
				(_display displayctrl 113) ctrlSetText (str (100 * _lightningsMinCloudiness));		//text overcast start
			};
			
			if( _forecastedOvercastValue < (_lightningsMinCloudiness * 100) ) then
			{
				(_display displayctrl 114) ctrlSetText (str (100 * _lightningsMinCloudiness));		//text overcast forecasted
			};
		}
		else
		{
			_checkBoxState = false;
			
			(_display displayctrl 125) ctrlSetText "0";		//text rain start
			(_display displayctrl 127) ctrlSetText "0";		//text rain forecasted
		};

		(_display displayctrl 124) ctrlEnable _checkBoxState;		//slider lightning start
		(_display displayctrl 125) ctrlEnable _checkBoxState;		//text lightning start
		(_display displayctrl 126) ctrlEnable _checkBoxState;		//slider lightning forecasted
		(_display displayctrl 127) ctrlEnable _checkBoxState;		//text lightning forecasted
	};
	
	//--- WAVES CheckBox
	case "waves": {
	
		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		_checkBoxState = (_this select 1) select 2; 			//_this - array that comes from event handler
		
		if(_checkBoxState == 0) then
		{
			_checkBoxState = true;
		}
		else
		{
			_checkBoxState = false;
			
			(_display displayctrl 130) ctrlSetText "0";		//text rain start
			(_display displayctrl 132) ctrlSetText "0";		//text rain forecasted
		};

		(_display displayctrl 129) ctrlEnable _checkBoxState;		//slider waves start
		(_display displayctrl 130) ctrlEnable _checkBoxState;		//text waves start
		(_display displayctrl 131) ctrlEnable _checkBoxState;		//slider waves forecasted
		(_display displayctrl 132) ctrlEnable _checkBoxState;		//text waves forecasted
	};
	
	//--- WIND CheckBox
	case "wind": {
	
		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		_checkBoxState = (_this select 1) select 2; 			//_this - array that comes from event handler
		
		if(_checkBoxState == 0) then
		{
			_checkBoxState = true;
		}
		else
		{
			_checkBoxState = false;
			
			(_display displayctrl 135) ctrlSetText "0";		//text strength start
			(_display displayctrl 137) ctrlSetText "0";		//text strength forecasted
			(_display displayctrl 139) ctrlSetText "0";		//text gusts start
			(_display displayctrl 141) ctrlSetText "0";		//text gusts forecasted
			(_display displayctrl 143) ctrlSetText "0";		//text direction start
			(_display displayctrl 145) ctrlSetText "0";		//text direction forecasted

		};

		(_display displayctrl 134) ctrlEnable _checkBoxState;	
		(_display displayctrl 135) ctrlEnable _checkBoxState;
		(_display displayctrl 136) ctrlEnable _checkBoxState;
		(_display displayctrl 137) ctrlEnable _checkBoxState;
		(_display displayctrl 138) ctrlEnable _checkBoxState;
		(_display displayctrl 139) ctrlEnable _checkBoxState;
		(_display displayctrl 140) ctrlEnable _checkBoxState;
		(_display displayctrl 141) ctrlEnable _checkBoxState;
		(_display displayctrl 142) ctrlEnable _checkBoxState;
		(_display displayctrl 143) ctrlEnable _checkBoxState;
		(_display displayctrl 144) ctrlEnable _checkBoxState;
		(_display displayctrl 145) ctrlEnable _checkBoxState;
	};
	
	case "overcastChanged": {

		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		_overcastValue = ((_this select 1) select 1);
		
		
		//Enable/disable Rain controls
		_rainMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "RainConfig" >> "minCloudiness");
		_isCloudy = if( _overcastValue >= (_rainMinCloudiness) ) then {true} else {false};
		
		if (!ctrlChecked (_display displayctrl 118) && (!_isCloudy)) then
		{
			(_display displayctrl 119) ctrlEnable false;		//slider rain start
			(_display displayctrl 120) ctrlEnable false;		//text rain start
			(_display displayctrl 121) ctrlEnable false;		//slider rain forecasted
			(_display displayctrl 122) ctrlEnable false;		//text rain forecasted
		
			(_display displayctrl 118) ctrlSetChecked true;		//auto/manual checkbox
		};
		
		//Enable/disable Lightning controls
		_lightningsMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "LightningsConfig" >> "minCloudiness");
		_isCloudy = if( _overcastValue >= (_lightningsMinCloudiness) ) then {true} else {false};
		
		if (!ctrlChecked (_display displayctrl 123) && (!_isCloudy)) then
		{
			(_display displayctrl 124) ctrlEnable false;		//slider lightning start
			(_display displayctrl 125) ctrlEnable false;		//text lightning start
			(_display displayctrl 126) ctrlEnable false;		//slider lightning forecasted
			(_display displayctrl 127) ctrlEnable false;		//text lightning forecasted
			
			(_display displayctrl 123) ctrlSetChecked true;		//auto/manual checkbox
		};	
	};
	
	case "forecastedOvercastChanged": {
	
		_ctrl = _params select 0;
		_display = ctrlparent _ctrl;
		_overcastValue = ((_this select 1) select 1);
		
		//Enable/disable Rain controls
		_rainMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "RainConfig" >> "minCloudiness");
		_isCloudy = if( _overcastValue >= (_rainMinCloudiness) ) then {true} else {false};
		
		if (!ctrlChecked (_display displayctrl 118) && (!_isCloudy)) then
		{
			(_display displayctrl 119) ctrlEnable false;		//slider rain start
			(_display displayctrl 120) ctrlEnable false;		//text rain start
			(_display displayctrl 121) ctrlEnable false;		//slider rain forecasted
			(_display displayctrl 122) ctrlEnable false;		//text rain forecasted
		
			(_display displayctrl 118) ctrlSetChecked true;		//auto/manual checkbox
		};
		
		//Enable/disable Lightning controls
		_lightningsMinCloudiness = getNumber (configfile >> "cfgWorlds" >> "DefaultWorld" >> "Weather" >> "LightningsConfig" >> "minCloudiness");
		_isCloudy = if( _overcastValue >= (_lightningsMinCloudiness) ) then {true} else {false};

		if (!ctrlChecked (_display displayctrl 123) && (!_isCloudy)) then
		{
			(_display displayctrl 124) ctrlEnable false;		//slider lightning start
			(_display displayctrl 125) ctrlEnable false;		//text lightning start
			(_display displayctrl 126) ctrlEnable false;		//slider lightning forecasted
			(_display displayctrl 127) ctrlEnable false;		//text lightning forecasted
			
			(_display displayctrl 123) ctrlSetChecked true;		//auto/manual checkbox
		};
	};
	
	case "onUnload": {
	
		_display = (_this select 1) select 0;
		_exitCode = (_this select 1) select 1;
		_sliderPos = sliderPosition (_display displayctrl 108); //position of overcast slider
		
		//OK button clicked - set overcast toolbox in RscDisplayArcadeMap-------------------------------------------
		if(_exitCode == 1) then
		{	
			_overcastToolBox = ((findDisplay 26) displayctrl 2602); //overcast ToolBox in RscDisplayArcadeMap
		
			//set value in overcast ToolBox in RscDisplayArcadeMap	
			if (_sliderPos <= 0.2) then
			{
				//sun
				_overcastToolBox lbSetCurSel 0;
			}
			else
			{
				if ( (_sliderPos > 0.2) && (_sliderPos <= 0.4) ) then
				{
					//partly cloudy
					_overcastToolBox lbSetCurSel 1;
				}
				else
				{
					if ( (_sliderPos > 0.4) && (_sliderPos <= 0.6) ) then
					{
						//cloudy
						_overcastToolBox lbSetCurSel 2;
					}
					else
					{
						if ( (_sliderPos > 0.6) && (_sliderPos <= 0.8) ) then
						{
							//rainy
							_overcastToolBox lbSetCurSel 3;
						}
						else
						{
							//stormy (_selectedItem > 80)
							_overcastToolBox lbSetCurSel 4;
						};
					};	
				};	
			};

			//OK button clicked - set overcast toolbox in RscDisplayArcadeMap-------------------------------------------
		
		
			//Set time slider in RscDisplayArcadeMap-------------------------------------------
			_hoursComboBox = _display displayctrl 104;
			_minutesComboBox = _display displayctrl 105;
			
			_hours = parseNumber(_hoursComboBox lbText (lbCurSel _hoursComboBox)); //hours
			_minutes = parseNumber(_minutesComboBox lbText (lbCurSel _minutesComboBox)); //minutes

			((findDisplay 26) displayctrl 2601) sliderSetPosition ((60 * _hours) + _minutes);  //set time slider position in RscDisplayArcadeMap
			//set time slider position in RscDisplayArcadeMap-------------------------------------------
		};
		
		//return focus to Preview button
		ctrlSetFocus ((finddisplay 26) displayctrl 107);
	};
	
	default {};
};