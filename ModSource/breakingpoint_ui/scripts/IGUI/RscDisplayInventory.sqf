#define CONTROL (_display displayctrl _idc)

disableserialization;
_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do {
	case "onLoad": {
		with uinamespace do {

			//--- Mission Name (ToDo: Handle by engine)
			//_idc = 112;
			//CONTROL ctrlsettext ctrltext ((finddisplay 12) displayctrl 112);

			//--- Player name (ToDo: Handle by engine)
			_idc = 111;
			CONTROL ctrlsettext (name player);
			[_display, 111] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');
			
			// CONTROL ctrlsettext format [
				// "%1. %2, %3",
				// localize ("STR_SHORT_" + rank player),
				// name player,
				// group player
			// ];

			//--- Rank (ToDo: Handle by engine)
			_idc = 1203;
			_rankTexture = [player,"texture"] call bis_fnc_rankParams;
			CONTROL ctrlsettext _rankTexture;
			//CONTROL ctrlSetTooltip (localize ("STR_" + rank player)); //Plug in as soon as sorting is fixed.
			
			//Set focus to GroundLoad to avoid closing inventory on Space or Enter key up.
			ctrlSetFocus (_display displayctrl 6307);
		};
	};
};