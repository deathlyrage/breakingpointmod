_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {

	case "onLoad": {
		with uinamespace do {
			_display = _params select 0;

			//--- Mission listbox changed (also init)
			_ctrlName = _display displayctrl 101;
			_ctrlName ctrlenable false;
			_ctrlName ctrladdeventhandler [
				"lbselchanged",
				"
					with uinamespace do {
						_display = ctrlparent (_this select 0);
						_ctrlName = _display displayctrl 101;
						_ctrlNameScripted = _display displayctrl 1500;
						if (lbsize _ctrlNameScripted < 1) then {
							for '_i' from 0 to (lbsize _ctrlName - 1) do {
								_text = _ctrlName lbtext _i;
								_ctrlNameScripted lbadd _text;
							};

							_ctrlIsland = _display displayctrl 104;
							_curselArray = uinamespace getvariable ['RscDisplayTemplateLoad_cursel',[]];
							_curselArray resize (lbsize _ctrlIsland);
							_cursel = _curselArray select (lbcursel _ctrlIsland);
							if (isnil '_cursel') then {_cursel = 0;};
							_ctrlNameScripted lbsetcursel (_cursel);
						};
					};
				"
			];

			//--- Island listbox changed - clear fake mission list
			_ctrlIsland = _display displayctrl 104;
			_ctrlIsland ctrladdeventhandler [
				"lbselchanged",
				"
					_display = ctrlparent (_this select 0);
					_ctrlName = _display displayctrl 1500;
					lbclear _ctrlName;
				"
			];

			//--- Select real mission according to fake list
			_ctrlNameScripted = _display displayctrl 1500;
			_ctrlNameScripted ctrladdeventhandler [
				"lbselchanged",
				"
					_display = ctrlparent (_this select 0);
					_ctrlName = _display displayctrl 101;
					_ctrlName lbsetcursel (_this select 1);

					_ctrlIsland = _display displayctrl 104;
					_curselArray = uinamespace getvariable ['RscDisplayTemplateLoad_cursel',[]];
					_curselArray set [lbcursel _ctrlIsland,lbcursel _ctrlName];
					uinamespace setvariable ['RscDisplayTemplateLoad_cursel',_curselArray];
				"
			];

			//-- Double click on fake listbox
			_ctrlNameScripted ctrladdeventhandler [
				"lbdblclick",
				"
					ctrlactivate ((ctrlparent (_this select 0)) displayctrl 1)
				"
			];
			
			ctrlSetFocus _ctrlNameScripted;
		};
		
		
		
		//Sets all static texts toUpper---------------------------------------------------------------------------------------------
		_classInsideControls = configfile >> "RscDisplayTemplateLoad" >> "controls";
			
		for "_i" from 0 to (count _classInsideControls - 1) do {   //go to all subclasses
			_current = _classInsideControls select _i;
			if (isclass _current) then {
			
				//search inside main controls class
				_idc = getnumber (_current >> "idc");
				_control = _display displayctrl _idc;
				_control ctrlSetText (toUpper (ctrlText _control));	
			};
		};
		//Sets all static texts toUpper---------------------------------------------------------------------------------------------
	
	};
};