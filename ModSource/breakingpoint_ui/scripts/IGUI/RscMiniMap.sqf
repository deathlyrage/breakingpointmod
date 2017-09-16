disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with uinamespace do {
			_display = _params select 0;

			if (getnumber (missionconfigfile >> "showGroupIndicator") > 0) then {

				//--- Initialize group indicator
				["Init",_params] call (uinamespace getvariable 'BIS_fnc_groupIndicator');

				_ctrlMinimap = _display displayctrl 13301;
				_ctrlMinimap ctrlsetfade 1;
				_ctrlMinimap ctrlcommit 0;

			} else {
				_ctrlGroupIndicator = _display displayctrl 13302;
				_ctrlGroupIndicator ctrlsetfade 1;
				_ctrlGroupIndicator ctrlcommit 0;

				_colorSelect = getarray (configfile >> "cfgIngameUi" >> "islandMap" >> "colorSelect");
				{
					_colorSelect set [_foreachindex,_x call bis_fnc_parsenumber];
				} foreach _colorSelect;

				RscMiniMap_refreshTime = -100;
				_ctrlMap = _display displayctrl 101;
				_ctrlMap ctrladdeventhandler [
					"draw",
					format [
						"
							with uinamespace do {
								_map = _this select 0;
								if (time > uinamespace getvariable ['RscMiniMap_refreshTime',0]) then {
									_display = ctrlparent _map;
									_ctrlGrid = _display displayctrl 1002;
									_ctrlGrid ctrlsettext (mapgridposition vehicle player);
	
									_ctrlTime = _display displayctrl 1003;
									_ctrlTime ctrlsettext ([daytime,'HH:MM'] call bis_fnc_timetostring);
	
									_ctrlHeading = _display displayctrl 1004;
									_ctrlHeading ctrlsettext str (floor direction vehicle player);
									RscMiniMap_refreshTime = time + 0.1;
								};
								{
									_map drawLine [position _x,position player,%1];
								} foreach groupSelectedUnits player;
							};
						",
						/* %1 */ _colorSelect					
					]
				];
			};
		};
	};
};