disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with uinamespace do {
			private ["_display","_veh","_vehType","_uavPosition","_isPlayerInAV","_icon"];
			
			_display = _params select 0;
			_veh = vehicle player;
			_vehType = typeof _veh;
			_uavPosition = (uavControl (getConnectedUav player)) select 1;
			_isPlayerInAV = false;
			
			if((_uavPosition == "DRIVER") || (_uavPosition == "GUNNER")) then
			{
				_isPlayerInAV = true;
			};

			if !(isnil "RscUnitInfo_loop") then {terminate RscUnitInfo_loop;};

			if ((_veh != player) || _isPlayerInAV) then {
				//--- Radar icon
				_icon = gettext (configfile >> "cfgvehicles" >> _vehType >> "icon");
				
				if (_isPlayerInAV) then
				{
					_icon = gettext (configfile >> "cfgvehicles" >> (typeof (getConnectedUav player)) >> "icon");
				};
				
				(_display displayctrl 250) ctrlsettext _icon;

				//--- Stabilized
				_stabilized = _display displayctrl 1204;
				_stabilized ctrlshow false;

				RscUnitInfo_loop = [_display,_hitzones,_isPlayerInAV] spawn {
					disableserialization;
					_display = _this select 0;
					_isPlayerInAV = _this select 2;
					_stabilized = _display displayctrl 1204;

					while {!isnull _display} do {
						//--- Stabilized
						if(_isPlayerInAV) then
						{
							_stabilized ctrlshow (isAutoHoverOn (getConnectedUav player));
						}
						else
						{
							_stabilized ctrlshow (isAutoHoverOn vehicle player);
						};
						sleep .1;
					};
				};
			};
		};
	};
};