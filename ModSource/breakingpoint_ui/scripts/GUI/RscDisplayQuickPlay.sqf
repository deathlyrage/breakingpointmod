#include "\a3\Ui_f\hpp\defineResincl.inc"
#include "\a3\Ui_f\hpp\defineResinclDesign.inc"

_mode = _this select 0;
_params = _this select 1;
_class = _this select 2;

switch _mode do
{
	case "onLoad":
	{
		_display = _params select 0;

		//--- Set player's name
		(_display displayctrl IDC_RSCDISPLAYQUICKPLAY_PLAYERSNAME) ctrlSetText profileName;
		[_display, IDC_RSCDISPLAYQUICKPLAY_PLAYERSNAME] call (uinamespace getvariable 'BIS_fnc_setIDCStreamFriendly');

		//--- Show mod notification
		if !(productversion select 5) then {
			{[0,_x] call bis_fnc_log;
				(_display displayctrl _x) ctrlshow false;
			} foreach [
				IDC_RSCDISPLAYQUICKPLAY_MODBACKGROUND,
				IDC_RSCDISPLAYQUICKPLAY_MODTEXT,
				IDC_RSCDISPLAYQUICKPLAY_MODICON
			];
		};

		_ctrlGameTypes = _display displayctrl IDC_MP_QUICK_GAME_TYPE;
		_ctrlGameTypes ctrladdeventhandler ["lbselchanged",{with uinamespace do {["lbSelChanged",_this,""] call RscDisplayQuickPlay_script}}];

		//--- Init game modes list (have to be done after short delay)
		if !(missionNamespace getVariable ["cheat1",false]) then {
			[_display] spawn {
				disableserialization;
				_display = _this select 0;
				_ctrlGameTypes = _display displayctrl IDC_MP_QUICK_GAME_TYPE;
				_colorFeatured = ["GUI","BCG_RGB"] call bis_fnc_displayColorGet;
				_colorFeatured set [3,1];

				for "_i" from 0 to (lbsize _ctrlGameTypes - 1) do {
					_cfgGameType = configfile >> "CfgMPGameTypes" >> (_ctrlGameTypes lbdata _i);

					//--- Featured modes - change color and move on top
					if (getnumber (_cfgGameType >> "featured") > 0) then {
						_ctrlGameTypes lbsetcolor [_i,_colorFeatured];
						_ctrlGameTypes lbsetvalue [_i,-1];
					};

					//--- Set mod icon
					_mods = configSourceModList _cfgGameType;
					_mod = if (count _mods > 0) then {_mods select 0} else {gettext (_cfgGameType >> "dlc")};
					_modParams = modparams [_mod,["logosmall"]];
					if (count _modParams > 0) then {_ctrlGameTypes lbsetpictureright [_i,_modParams select 0];};
				};

				//--- Sort by value (first "Any", the featured modes and then the remaining modes
				_ctrlGameTypes lbsetvalue [0,-2]; //--- Make "Any" the topmost item
				lbsortbyvalue _ctrlGameTypes;
			};
		};
		

		//Sets title and button texts toUpper
		//["RscDisplayQuickPlay",["RscText","RscTitle"],["PlayersName","TextLongSearchDisclaimer","TextQuickPlayTip","TextFriendsIngame"]] call bis_fnc_toUpperDisplayTexts;
	};
	case "lbSelChanged": {
		_ctrlGameTypes = _params select 0;
		_cursel = _params select 1;

		_display = ctrlparent _ctrlGameTypes;
		_ctrlGameTypeTitle = _display displayctrl IDC_RSCDISPLAYQUICKPLAY_GAMETYPETITLE;
		_ctrlGameTypeOverview = _display displayctrl IDC_RSCDISPLAYQUICKPLAY_GAMETYPEOVERVIEW;
		_ctrlGameTypeDescription = _display displayctrl IDC_RSCDISPLAYQUICKPLAY_GAMETYPEDESCRIPTION;
		_ctrlGameTypeBackground = _display displayctrl IDC_RSCDISPLAYQUICKPLAY_GAMETYPEDESCRIPTIONBACKGROUND;

		_cfgGameType = configfile >> "CfgMPGameTypes" >> (_ctrlGameTypes lbdata _cursel);
		_picture = gettext (_cfgGameType >> "picture");
		if (_picture == "") then {_picture = gettext (configfile >> "CfgMPGameTypes" >> "Unknown" >> "picture");};

		_ctrlGameTypeTitle ctrlsettext toupper (_ctrlGameTypes lbtext _cursel);//gettext (_cfgGameType >> "name");
		_ctrlGameTypeOverview ctrlsettext _picture;
		_ctrlGameTypeDescription ctrlsettext gettext (_cfgGameType >> "description");
		_ctrlGameTypeBackground ctrlshow (ctrltext _ctrlGameTypeDescription != "");
	};
};