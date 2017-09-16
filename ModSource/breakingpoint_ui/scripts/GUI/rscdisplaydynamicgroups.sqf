// Do not serialize
disableSerialization;

// Includes
#include "\A3\ui_f\hpp\defineResincl.inc"
#include "\A3\ui_f\hpp\defineResinclDesign.inc"
#include "\A3\ui_f\hpp\defineCommonGrids.inc"

// Macros
#define CHECK(CONDITION) \
	if (CONDITION) exitWith {};

// Defines
#define SELF 				{ _this call (uiNamespace getVariable ["RscDisplayDynamicGroups_script", {}]); }
#define GROUPS 				{ _this call (missionNamespace getVariable ["BIS_fnc_dynamicGroups", {}]); }
#define SECTION_FADE_TIME 		0.2
#define UPDATE_RATE			2.0
#define TIME_GROUP_NAME_CHANGE		0.5
#define UNSORTED_GROUP_ID		localize "STR_A3_RscDisplayDynamicGroups_Ungrouped"
#define MAX_GROUP_NAME_SIZE		20
#define COLOR_SELF			[1.0, 0.6, 0.0, 1.0]
#define COLOR_LOCKED			[0.5, 0.5, 0.5, 1.0]
#define COLOR_DEAD			[0.5, 0.5, 0.5, 0.6]
#define COLOR_GROUP			[0.0, 0.5, 0.0, 1.0]
#define COLOR_INCAPACITATED		[0.5, 0.0, 0.0, 1.0]
#define ICON_KIA			"a3\Ui_F_Curator\Data\CfgMarkers\kia_ca.paa"
#define ICON_REVIVE			"a3\ui_f\data\revive\revive_ca.paa"
#define ICON_GENERAL			"a3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa"
#define VAR_SHOW_GROUPS			"BIS_dynamicGroups_showGroups"
#define VAR_LAST_PLAYER_GROUP		"BIS_dynamicGroups_lastPlayerGroup"
#define VAR_HAS_FOCUS			"BIS_dynamicGroups_hasFocus"
#define VAR_SELECTED_MEMBER		"BIS_dynamicGroups_selectedMember"
#define VAR_SELECTED_PLAYER		"BIS_dynamicGroups_selectedPlayer"
#define VAR_SELECTED_GROUPORPLAYER	"BIS_dynamicGroups_selectedGroupOrPlayer"
#define VAR_OLD_MEMBERS			"BIS_dynamicGroups_oldMembers"
#define VAR_OLD_PLAYERS			"BIS_dynamicGroups_oldPlayers"
#define VAR_OLD_GROUPS			"BIS_dynamicGroups_oldGroups"
#define VAR_OLD_GROUP			"BIS_dynamicGroups_oldGroup"
#define VAR_COLLAPSED_GROUPS		"BIS_dynamicGroups_collapsedGroups"
#define VAR_GROUP_REGISTERED		"BIS_dg_reg"
#define VAR_GROUP_CREATOR		"BIS_dg_cre"
#define VAR_GROUP_INSIGNIA		"BIS_dg_ins"
#define VAR_GROUP_PRIVATE		"BIS_dg_pri"
#define LOG_ENABLED			false

// Script parameters
private ["_mode", "_params"];
_mode 	= _this select 0;
_params = _this select 1;

switch _mode do
{
	case "onLoad":
	{
		private ["_display"];
		_display = _params select 0;

		// Store
		uiNamespace setVariable ["BIS_dynamicGroups_display", _display];
		uiNamespace setVariable ["BIS_dynamicGroups_lastGroupNameChangeTime", 0];

		// Reset
		uiNamespace setVariable [VAR_SELECTED_MEMBER, nil];
		uiNamespace setVariable [VAR_SELECTED_PLAYER, nil];
		uiNamespace setVariable [VAR_SELECTED_GROUPORPLAYER, nil];

		// Sections
		private ["_sectionGroups", "_sectionManage"];
		_sectionGroups = _display displayCtrl IDC_DYNAMICGROUPS_SECTIONGROUPS;
		_sectionManage = _display displayCtrl IDC_DYNAMICGROUPS_SECTIONMANAGE;

		// List boxes
		private ["_groupsListbox", "_playersListbox", "_manageListbox"];
		_groupsListbox 	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXGROUPS;
		_playersListbox	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXPLAYERS;
		_manageListbox 	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXMANAGE;

		// Buttons
		private ["_createLeaveKickButton", "_promoteDisbandButton", "_joinButton", "_kickPlayerButton", "_invitePlayerButton", "_closeInterfaceButton", "_tabGroupsButton", "_tabPlayersButton"];
		_createLeaveKickButton = _display displayCtrl IDC_DYNAMICGROUPS_BUTTONCREATELEAVEKICK;
		_promoteDisbandButton = _display displayCtrl IDC_DYNAMICGROUPS_BUTTONPROMOTEDISBAND;
		_joinButton = _display displayCtrl IDC_DYNAMICGROUPS_BUTTONJOIN;
		_kickPlayerButton = _display displayCtrl IDC_DYNAMICGROUPS_BUTTONKICK;
		_invitePlayerButton = _display displayCtrl IDC_DYNAMICGROUPS_BUTTONINVITE;
		_closeInterfaceButton = _display displayCtrl IDC_DYNAMICGROUPS_CLOSEINTERFACE;
		_tabGroupsButton = _display displayCtrl IDC_DYNAMICGROUPS_TABBUTTONGROUPS;
		_tabPlayersButton = _display displayCtrl IDC_DYNAMICGROUPS_TABBUTTONPLAYERS;

		// Check boxes
		private ["_checkboxPrivate"];
		_checkboxPrivate = _display displayCtrl IDC_DYNAMICGROUPS_CHECKBOXPRIVATE;

		// Misc
		private ["_iconPicture", "_editGroupName"];
		_iconPicture = _display displayCtrl IDC_DYNAMICGROUPS_GROUPICON;
		_editGroupName = _display displayCtrl IDC_DYNAMICGROUPS_EDITGROUPNAME;

		// Add click events to list boxes
		_groupsListbox ctrlAddEventHandler ["treeSelChanged", { with uiNamespace do { ['OnGroupsTreeSelChanged', _this] call SELF; }; }];
		_playersListbox ctrlAddEventHandler ["LBSelChanged", { with uiNamespace do { ['OnPlayersLbSelChanged', _this] call SELF; }; }];
		_manageListbox ctrlAddEventHandler ["LBSelChanged", { with uiNamespace do { ["OnManageLbSelChanged", _this] call SELF; }; }];

		// Add double click events to list boxes
		_groupsListbox ctrlAddEventHandler ["TreeDblClick", { with uiNamespace do { ['OnTreeDoubleClick', _this] call SELF; }; }];
		_playersListbox ctrlAddEventHandler ["LBDblClick", { with uiNamespace do { ['OnListDoubleClick', _this] call SELF; }; }];
		_manageListbox ctrlAddEventHandler ["LBDblClick", { with uiNamespace do { ["OnListDoubleClick", _this] call SELF; }; }];

		// Add expanded/collapsed events for Tree
		_groupsListbox ctrlAddEventHandler ["TreeExpanded", { with uiNamespace do { ['OnGroupExpanded', _this] call SELF; }; }];
		_groupsListbox ctrlAddEventHandler ["TreeCollapsed", { with uiNamespace do { ['OnGroupCollapsed', _this] call SELF; }; }];

		// Add event handlers to buttons
		_createLeaveKickButton ctrlAddEventHandler ["ButtonClick", { with uiNamespace do { ["OnCreateLeaveKickButtonClick", _this] call SELF; }; }];
		_promoteDisbandButton ctrlAddEventHandler ["ButtonClick", { with uiNamespace do { ["OnPromoteDisbandButtonClick", _this] call SELF; }; }];
		_joinButton ctrlAddEventHandler ["ButtonClick", { with uiNamespace do { ["OnJoinButtonClick", _this] call SELF; }; }];
		_invitePlayerButton ctrlAddEventHandler ["ButtonClick", { with uiNamespace do { ["OnInvitePlayerButtonClick", _this] call SELF; }; }];
		_closeInterfaceButton ctrlAddEventHandler ["ButtonClick", { with uiNamespace do { ["CloseDisplay"] call SELF; }; }];
		_tabGroupsButton ctrlAddEventHandler ["ButtonClick", { with uiNamespace do { ["OnTabGroupsButtonClick", _this] call SELF; }; }];
		_tabPlayersButton ctrlAddEventHandler ["ButtonClick", { with uiNamespace do { ["OnTabPlayersButtonClick", _this] call SELF; }; }];

		// Add event handler to check box, detect when it's state changes
		_checkboxPrivate ctrlAddEventHandler ["CheckedChanged", { with uiNamespace do { ["OnPrivateStateChanged", _this] call SELF; }; }];

		// Add event handlers to group picture/icon
		_iconPicture ctrlAddEventHandler ["MouseEnter", { with uiNamespace do { ["OnGroupIconMouseEnter", _this] call SELF; }; }];
		_iconPicture ctrlAddEventHandler ["MouseExit", { with uiNamespace do { ["OnGroupIconMouseExit", _this] call SELF; }; }];

		// Add event handlers for editing the group name
		_editGroupName ctrlAddEventHandler ["KeyDown", { with uiNamespace do { ["OnGroupNameChanged", _this] call SELF; }; }];
		_editGroupName ctrlAddEventHandler ["SetFocus", { with uiNamespace do { ["OnGroupNameSetFocus", _this] call SELF; }; }];
		_editGroupName ctrlAddEventHandler ["KillFocus", { with uiNamespace do { ["OnGroupNameKillFocus", _this] call SELF; }; }];

		// Put Players list box right where groups list box is, both are never shown at the same time
		_playersListbox ctrlSetPosition (ctrlPosition _groupsListbox);
		_playersListbox ctrlCommit 0;
		_playersListbox ctrlShow false;

		// Make all sections invisible
		{ _x ctrlSetFade 1; _x ctrlShow false; _x ctrlCommit 0; } forEach [_sectionManage, _sectionGroups];

		// We always default to showing groups
		uiNamespace setVariable [VAR_SHOW_GROUPS, true];

		// Add key down event for our display
		["AddKeyEvents", [_display]] call GROUPS;

		// Hide hud and commanding menu
		showHud false;
		showCommandingMenu "";

		// Reset collapsed groups variable
		uiNamespace setVariable [VAR_COLLAPSED_GROUPS, []];

		// Initial update
		["Update", [true]] call SELF;

		// Log
		if (LOG_ENABLED) then
		{
			["onLoad: %1 / %2 / %3 / %4 / %5", _display, _sectionManage, _sectionGroups] call BIS_fnc_logFormat;
		};
	};

	case "onUnload":
	{
		terminate (uiNamespace getVariable "BIS_dynamicGroups_update");

		uiNamespace setVariable ["BIS_dynamicGroups_display", nil];
		uiNamespace setVariable ["BIS_dynamicGroups_lastGroupNameChangeTime", nil];
		uiNamespace setVariable [VAR_HAS_FOCUS, nil];

		// Show hud and commanding menu
		showHud true;

		// Log
		if (LOG_ENABLED) then
		{
			"onUnload" call BIS_fnc_log;
		};
	};

	case "GetDisplay" :
	{
		uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
	};

	case "CreateDisplay" :
	{
		([] call BIS_fnc_displayMission) createDisplay "RscDisplayDynamicGroups";
	};

	case "CloseDisplay" :
	{
		(uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull]) closeDisplay IDC_CANCEL;
	};

	case "Update" :
	{
		private ["_initialUpdate"];
		_initialUpdate = _params param [0, false, [true]];

		// Update groups section
		["UpdateGroupsSection", [_initialUpdate]] call SELF;

		// Update manage section
		["UpdateManageSection", [_initialUpdate]] call SELF;

		// Store last known player group
		uiNamespace setVariable [VAR_LAST_PLAYER_GROUP, group player];
	};

	case "UpdateManageSection" :
	{
		private ["_initialUpdate"];
		_initialUpdate = _params param [0, false, [true]];

		private "_display";
		_display = uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		CHECK(isNull _display)

		private
		[
			"_sectionManage", "_buttonPromoteDisband", "_buttonInvite", "_buttonCreateLeaveKick", "_editGroupName", "_textNumberOfPlayers",
			"_listBoxMembers", "_listBoxGroups", "_listBoxPlayers", "_checkboxPrivate", "_sidePicture", "_groupIcon", "_fillPlayerName",
			"_fillPlayerSide", "_fillPlayerScore"
		];
		_sectionManage 		= _display displayCtrl IDC_DYNAMICGROUPS_SECTIONMANAGE;
		_buttonPromoteDisband	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONPROMOTEDISBAND;
		_buttonInvite 		= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONINVITE;
		_buttonCreateLeaveKick	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONCREATELEAVEKICK;
		_editGroupName 		= _display displayCtrl IDC_DYNAMICGROUPS_EDITGROUPNAME;
		_textNumberOfPlayers 	= _display displayCtrl IDC_DYNAMICGROUPS_TEXTPLAYERCOUNT;
		_listBoxMembers		= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXMANAGE;
		_listBoxGroups 		= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXGROUPS;
		_listBoxPlayers		= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXPLAYERS;
		_checkboxPrivate 	= _display displayCtrl IDC_DYNAMICGROUPS_CHECKBOXPRIVATE;
		_sidePicture 		= _display displayCtrl IDC_DYNAMICGROUPS_PICTURESIDE;
		_groupIcon		= _display displayCtrl IDC_DYNAMICGROUPS_GROUPICON;
		_fillPlayerName		= _display displayCtrl IDC_DYNAMICGROUPS_TEXTPLAYERNAMEFILL;
		_fillPlayerSide		= _display displayCtrl IDC_DYNAMICGROUPS_TEXTPLAYERSIDEFILL;
		_fillPlayerScore	= _display displayCtrl IDC_DYNAMICGROUPS_TEXTPLAYERSCOREFILL;

		private ["_playerGroup", "_playerIsLeader", "_playerGroupRegistered"];
		_playerGroup 		= group player;
		_playerIsLeader		= player == leader _playerGroup;
		_playerGroupRegistered	= ["IsGroupRegistered", [_playerGroup]] call GROUPS;

		if (!_playerGroupRegistered) then
		{
			_sectionManage ctrlShow true;
			_sectionManage ctrlSetFade 0.5;
			_sectionManage ctrlCommit SECTION_FADE_TIME;

			_buttonCreateLeaveKick ctrlEnable true;
			_buttonCreateLeaveKick ctrlSetText (localize "STR_A3_RscDisplayDynamicGroups_Button_Create");
			_buttonCreateLeaveKick ctrlSetTooltip localize "STR_A3_DynamicGroups_Tooltip_CreateOwnGroup";

			_buttonPromoteDisband ctrlEnable false;
			_buttonInvite ctrlEnable false;

			_checkboxPrivate ctrlEnable false;
			_checkboxPrivate cbSetChecked false;

			_listBoxMembers ctrlEnable false;
			lbClear _listBoxMembers;

			_editGroupName ctrlEnable false;
			_editGroupName ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Hint";
			_editGroupName ctrlEnable false;

			_textNumberOfPlayers ctrlSetText "-";

			_fillPlayerName ctrlSetText "-";
			_fillPlayerSide ctrlSetText "-";
			_fillPlayerScore ctrlSetText "-";

			_sidePicture ctrlSetText "#(argb,8,8,3)color(0,0,0,0.5)";

			_groupIcon ctrlSetText "\A3\Ui_f\data\GUI\Cfg\UnitInsignia\bi_ca.paa";
		}
		else
		{
			private ["_groupName", "_groupPicture", "_groupInstance", "_groupLeader", "_groupPlayers", "_groupSide", "_groupIsPrivate"];
			_groupName 	= groupId _playerGroup;
			_groupPicture 	= _playerGroup getVariable [VAR_GROUP_INSIGNIA, ""];
			_groupIsPrivate = _playerGroup getVariable [VAR_GROUP_PRIVATE, false];
			_groupLeader 	= leader _playerGroup;
			_groupPlayers 	= units _playerGroup;
			_groupSide 	= side _playerGroup;

			_sectionManage ctrlShow true;
			_sectionManage ctrlSetFade 0;
			_sectionManage ctrlCommit SECTION_FADE_TIME;

			// Update members
			["FillPlayersListbox", [_listBoxMembers, _groupPlayers, true]] call SELF;
			uiNamespace setVariable [VAR_OLD_MEMBERS, _groupPlayers];
			uiNamespace setVariable [VAR_OLD_GROUP, _playerGroup];

			private ["_selectedMemberIndex", "_selectedMemberUid"];
			_selectedMemberIndex 	= lnbCurSelRow _listBoxMembers;
			_selectedMemberUid	= "";

			if (!isNull _listBoxMembers && !isNil { _selectedMemberIndex } && { _selectedMemberIndex != -1 }) then
			{
				_selectedMemberUid = _listBoxMembers lnbData [_selectedMemberIndex, 0];
			};

			_listBoxMembers ctrlEnable true;
			_checkboxPrivate ctrlEnable _playerIsLeader;
			_checkboxPrivate cbSetChecked _groupIsPrivate;
			_fillPlayerName ctrlSetText name player;
			_fillPlayerSide ctrlSetText (["GetSideFormattedString", [_groupSide]] call SELF);
			_fillPlayerScore ctrlSetText str score player;

			// Update edit box only if player is not leader (cannot edit)
			private "_lastPlayerGroup";
			_lastPlayerGroup = uiNamespace getVariable [VAR_LAST_PLAYER_GROUP, grpNull];

			if (!_playerIsLeader || _initialUpdate || _playerGroup != _lastPlayerGroup || ctrlText _editGroupName == localize "STR_A3_RscDisplayDynamicGroups_Hint") then
			{
				_editGroupName ctrlSetText _groupName;
			};

			// Enable edit box only for leader, because only leader can change group name
			if (_playerIsLeader) then
			{
				_editGroupName ctrlEnable true;
			}
			else
			{
				_editGroupName ctrlEnable false;
			};

			// Fill the number of players in the group
			_textNumberOfPlayers ctrlSetText str (count _groupPlayers);

			// Set the side color
			private ["_sideColor", "_sideColorString"];
			_sideColor = [_groupSide] call BIS_fnc_sideColor;
			_sideColorString = switch (_groupSide) do
			{
				case WEST : 		{ format["#(argb,8,8,3)color(%1,%2,%3,0.6)", _sideColor select 0, _sideColor select 1, _sideColor select 2] };
				case EAST : 		{ format["#(argb,8,8,3)color(%1,%2,%3,0.6)", _sideColor select 0, _sideColor select 1, _sideColor select 2] };
				case RESISTANCE : 	{ format["#(argb,8,8,3)color(%1,%2,%3,0.6)", _sideColor select 0, _sideColor select 1, _sideColor select 2] };
				case default 		{ "#(argb,8,8,3)color(0.9,0.9,0.9,0.6)" };
			};
			_sidePicture ctrlSetText _sideColorString;

			// Set the group icon
			private "_insigniaTexture";
			_insigniaTexture = ["GetInsigniaTexture", [_groupPicture]] call GROUPS;
			_groupIcon ctrlSetText _insigniaTexture;
		};
	};

	case "UpdateGroupsSection" :
	{
		private ["_initialUpdate"];
		_initialUpdate = _params param [0, false, [true]];

		private "_display";
		_display = uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		CHECK(isNull _display)

		private ["_sectionGroups", "_buttonJoin", "_playersListbox"];
		_sectionGroups 	= _display displayCtrl IDC_DYNAMICGROUPS_SECTIONGROUPS;
		_buttonJoin 	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONJOIN;
		_playersListbox	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXPLAYERS;

		// Show groups section
		_sectionGroups ctrlShow true;
		_sectionGroups ctrlSetFade 0;
		_sectionGroups ctrlCommit SECTION_FADE_TIME;

		// Disable the join button since groups section was just updated
		_buttonJoin ctrlEnable false;

		private "_friendlyGroups";
		_friendlyGroups = ["GetAllGroupsOfSide", [side group player]] call GROUPS;

		// Go through all players of same side and those which are not in the list are added to an "Unsorted Players" list
		private "_unsortedPlayers";
		_unsortedPlayers = [];

		{
			if (isPlayer _x && side group _x == side group player && !(["IsGroupRegistered", [group _x]] call GROUPS)) then
			{
				_unsortedPlayers pushBack _x;
			};
		} forEach playableUnits + switchableUnits + allDeadMen;

		private "_sidePlayers";
		_sidePlayers = [];

		{
			if (isPlayer _x && side group _x == side group player) then
			{
				_sidePlayers pushBack _x;
			};
		} forEach playableUnits + switchableUnits + allDeadMen;

		if (uiNamespace getVariable [VAR_SHOW_GROUPS, true]) then
		{
			["OnTabGroupsButtonClick"] call SELF;

			["FillPlayersListbox", [_playersListbox, _sidePlayers]] call SELF;
			uiNamespace setVariable [VAR_OLD_PLAYERS, _sidePlayers];

			["FillGroupsListbox", [_friendlyGroups, _unsortedPlayers]] call SELF;
			uiNamespace setVariable [VAR_OLD_GROUPS, [_friendlyGroups, _unsortedPlayers]];
		}
		else
		{
			["OnTabPlayersButtonClick"] call SELF;

			["FillGroupsListbox", [_friendlyGroups, _unsortedPlayers]] call SELF;
			uiNamespace setVariable [VAR_OLD_GROUPS, [_friendlyGroups, _unsortedPlayers]];

			["FillPlayersListbox", [_playersListbox, _sidePlayers]] call SELF;
			uiNamespace setVariable [VAR_OLD_PLAYERS, _sidePlayers];
		};
	};

	case "FillGroupsListbox" :
	{
		private ["_groupsList", "_unsortedPlayers"];
		_groupsList 		= _params param [0, [], [[]]];
		_unsortedPlayers	= _params param [1, [], [[]]];

		// The selected index, this is used to know if we should manually select a list element in case it was selected before this update
		private ["_selectedIndex", "_totalIndex"];
		_selectedIndex 	= [-1, -1];
		_totalIndex	= -1;

		private "_display";
		_display = uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		CHECK(isNull _display)

		private "_listbox";
		_listbox = _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXGROUPS;
		CHECK(isNull _listbox)

		// Clear the tree
		tvClear _listbox;

		// Add them to the list box
		{
			private "_index";
			_index = _forEachIndex;
			_totalIndex = _totalIndex + 1;

			private ["_groupName", "_groupPicture", "_groupIsPrivate", "_groupLeader", "_groupPlayers", "_wasKickedFrom"];
			_groupName 	= groupId _x;
			_groupPicture 	= _x getVariable [VAR_GROUP_INSIGNIA, ["LoadRandomInsignia"] call GROUPS];
			_groupIsPrivate = _x getVariable [VAR_GROUP_PRIVATE, false];
			_groupLeader 	= leader _x;
			_groupPlayers 	= units _x;
			_wasKickedFrom	= ["WasPlayerKickedFrom", [_x, player]] call GROUPS;

			// Selected group?
			if ((uiNamespace getVariable [VAR_SELECTED_GROUPORPLAYER, [grpNull, objNull]]) select 0 == _x) then
			{
				_selectedIndex = [_index, -1];
			};

			private "_texture";
			_texture = if ((_groupIsPrivate || _wasKickedFrom) && !(player in _groupPlayers) && !(["HasInvite", [_x, player]] call GROUPS)) then
			{
				"a3\Ui_f\data\GUI\Rsc\RscDisplayDynamicGroups\Lock.paa";
			}
			else
			{
				["GetInsigniaTexture", [_groupPicture]] call GROUPS;
			};

			private "_parent";
			_parent = _listbox tvAdd [[], _groupName];
			_listbox tvSetData [[_parent], _groupName];
			_listbox tvSort [[_parent], true];
			_listbox tvSetPicture [[_parent], _texture];

			if (_x in (uiNamespace getVariable [VAR_COLLAPSED_GROUPS, []])) then
			{
				_listbox tvCollapse [_parent];
			}
			else
			{
				_listbox tvExpand [_parent];
			};

			if (_groupIsPrivate) then
			{
				_listbox tvSetPictureColor [[_parent], COLOR_LOCKED];
			};

			{
				private ["_groupPlayerName", "_isLeader", "_sameGroup", "_groupPlayerIcon", "_isDead", "_isIncapacitated"];
				_groupPlayerName 	= name _x;
				_isLeader		= _x == _groupLeader;
				_sameGroup		= group player == group _x;
				_groupPlayerIcon	= if (!_isLeader) then { ["GetPlayerIcon", [_x]] call SELF; } else { ICON_GENERAL; };
				_isDead			= !alive _x;
				_isIncapacitated	= alive _x && _x getVariable ["BIS_revive_incapacitated", false];

				// Selected player?
				if ((uiNamespace getVariable [VAR_SELECTED_GROUPORPLAYER, [grpNull, objNull]]) select 1 == _x) then
				{
					_selectedIndex = [_index, _forEachIndex];
				};

				if (_isDead) then
				{
					_groupPlayerName = localize "STR_A3_rscdisplaydynamicgroups_deadplayer";
					_groupPlayerIcon = ICON_KIA;
				}
				else
				{
					if (_isIncapacitated) then
					{
						_groupPlayerIcon = ICON_REVIVE;
					};
				};

				private "_child";
				_child = _listbox tvAdd [[_parent], _groupPlayerName];
				_listbox tvSetData [[_parent, _child], getPlayerUid _x];
				_listbox tvSort [[_parent, _child], true];
				_listbox tvSetPicture [[_parent, _child], _groupPlayerIcon];

				switch (true) do
				{
					case (_isDead) : 		{ _listbox tvSetPictureColor [[_parent, _child], COLOR_DEAD]; };
					case (_isIncapacitated) : 	{ _listbox tvSetPictureColor [[_parent, _child], COLOR_INCAPACITATED]; };
					case (player == _x) : 		{ _listbox tvSetPictureColor [[_parent, _child], COLOR_SELF]; };
					case (_sameGroup) : 		{ _listbox tvSetPictureColor [[_parent, _child], COLOR_GROUP]; };
				};
			}
			forEach _groupPlayers;
		}
		forEach _groupsList;

		if (count _unsortedPlayers > 0) then
		{
			// Add unsorted players to the list
			private "_parent";
			_parent = _listbox tvAdd [[], UNSORTED_GROUP_ID];
			_listbox tvSetData [[_parent], UNSORTED_GROUP_ID];
			_listbox tvSort [[_parent], true];
			_listbox tvExpand [_parent];

			_totalIndex = _totalIndex + 1;

			// Selected group?
			if (isNull ((uiNamespace getVariable [VAR_SELECTED_GROUPORPLAYER, [grpNull, objNull]]) select 0)) then
			{
				_selectedIndex = [count _groupsList, -1];
			};

			{
				private ["_unsortedPlayerName", "_unsortedPlayerIcon"];
				_unsortedPlayerName 	= name _x;
				_unsortedPlayerIcon	= ["GetPlayerIcon", [_x]] call SELF;
				_isDead			= !alive _x;
				_isIncapacitated	= alive _x && _x getVariable ["BIS_revive_incapacitated", false];

				// Selected player?
				if ((uiNamespace getVariable [VAR_SELECTED_GROUPORPLAYER, [grpNull, objNull]]) select 1 == _x) then
				{
					_selectedIndex = [_totalIndex, _forEachIndex];
				};

				if (_isDead) then
				{
					_unsortedPlayerName = localize "STR_A3_rscdisplaydynamicgroups_deadplayer";
					_unsortedPlayerIcon = ICON_KIA;
				}
				else
				{
					if (_isIncapacitated) then
					{
						_unsortedPlayerIcon = ICON_REVIVE;
					};
				};

				private "_child";
				_child = _listbox tvAdd [[_parent], _unsortedPlayerName];
				_listbox tvSetData [[_parent, _child], getPlayerUid _x];
				_listbox tvSort [[_parent, _child], true];
				_listbox tvSetPicture [[_parent, _child], _unsortedPlayerIcon];

				if (UNSORTED_GROUP_ID in (uiNamespace getVariable [VAR_COLLAPSED_GROUPS, []])) then
				{
					_listbox tvCollapse [_parent];
				}
				else
				{
					_listbox tvExpand [_parent];
				};

				switch (true) do
				{
					case (_isDead) : 		{ _listbox tvSetPictureColor [[_parent, _child], COLOR_DEAD]; };
					case (_isIncapacitated) : 	{ _listbox tvSetPictureColor [[_parent, _child], COLOR_INCAPACITATED]; };
					case (player == _x) : 		{ _listbox tvSetPictureColor [[_parent, _child], COLOR_SELF]; };
				};
			}
			forEach _unsortedPlayers;
		};

		// If we had a previously selected element, try to re-set it if it still exists
		if (_selectedIndex select 0 != -1) then
		{
			if (_selectedIndex select 1 != -1) then
			{
				_listbox tvSetCurSel _selectedIndex;
			}
			else
			{
				_listbox tvSetCurSel [_selectedIndex select 0];
			};
		};
	};

	case "FillPlayersListbox" :
	{
		private ["_listbox", "_playerList", "_isManageSection"];
		_listbox		= _params param [0, controlNull, [controlNull]];
		_playerList 		= _params param [1, [], [[]]];
		_isManageSection	= _params param [2, false, [true]];

		// The selected index, this is used to know if we should manually select a list element in case it was selected before this update
		private ["_selectedIndex", "_selfIndex", "_targetVar"];
		_selectedIndex 	= -1;
		_selfIndex	= -1;
		_targetVar	= if (_isManageSection) then { VAR_SELECTED_MEMBER } else { VAR_SELECTED_PLAYER };

		// Clear listbox
		lnbClear _listbox;

		// Fill listbox
		{
			private ["_name", "_textureIcon", "_textureRank", "_isGroupLeader", "_texture", "_sameGroup", "_isDead", "_isIncapacitated"];
			_name 			= name _x;
			_textureIcon		= ["GetPlayerIcon", [_x]] call SELF;
			_textureRank		= "a3\Ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
			_isGroupLeader		= _x == leader group _x;
			_texture 		= if (_isGroupLeader && ["IsGroupRegistered", [group _x]] call GROUPS) then { _textureRank } else { _textureIcon };
			_sameGroup		= group player == group _x;
			_isDead			= !alive _x;
			_isIncapacitated	= alive _x && _x getVariable ["BIS_revive_incapacitated", false];

			if (_isDead) then
			{
				_name = localize "STR_A3_rscdisplaydynamicgroups_deadplayer";
				_texture = ICON_KIA;
			}
			else
			{
				if (_isIncapacitated) then
				{
					_texture = ICON_REVIVE;
				};
			};

			_listbox lnbAddRow [""];
			_listbox lnbSetData [[_forEachIndex, 0], getPlayerUid _x];
			_listbox lnbSetPicture [[_forEachIndex, 0], _texture];
			_listbox lnbSetText [[_forEachIndex, 1], _name];

			if (_x == uiNamespace getVariable [_targetVar, objNull]) then
			{
				_selectedIndex = _forEachIndex;
			};

			_listbox lnbSetColor [[_forEachIndex, 1], [1,1,1,1]];

			if (player == _x) then
			{
				_selfIndex = _forEachIndex;
			};

			switch (true) do
			{
				case (_isDead) : 		{ _listbox lnbSetPictureColor [[_forEachIndex, 0], COLOR_DEAD]; _listbox lnbSetPictureColorSelected [[_forEachIndex, 0], COLOR_DEAD]; };
				case (_isIncapacitated) : 	{ _listbox lnbSetPictureColor [[_forEachIndex, 0], COLOR_INCAPACITATED]; _listbox lnbSetPictureColorSelected [[_forEachIndex, 0], COLOR_INCAPACITATED]; };
				case (player == _x) : 		{ _listbox lnbSetPictureColor [[_forEachIndex, 0], COLOR_SELF]; _listbox lnbSetPictureColorSelected [[_forEachIndex, 0], COLOR_SELF]; };
				case (_sameGroup) : 		{ _listbox lnbSetPictureColor [[_forEachIndex, 0], COLOR_GROUP]; _listbox lnbSetPictureColorSelected [[_forEachIndex, 0], COLOR_GROUP]; };
			};
		} forEach _playerList;

		// If we had a previously selected element, try to re-set it if it still exists
		if (_selectedIndex != -1) then
		{
			_listbox lnbSetCurSelRow _selectedIndex;
		}
		else
		{
			if (_selfIndex != -1) then
			{
				_listbox lnbSetCurSelRow _selfIndex;
			};
		};
	};

	case "OnGroupsTreeSelChanged" :
	{
		private ["_listbox", "_index"];
		_listbox 	= _params select 0;
		_index 		= tvCurSel _listbox;

		// Exit if index is invalid
		if (count _index < 1 || { _index select 0 < 0 }) exitWith {};

		private ["_display", "_inviteButton", "_joinButton"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_inviteButton 	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONINVITE;
		_joinButton 	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONJOIN;

		_joinButton ctrlEnable false;
		_inviteButton ctrlEnable false;

		private "_data";
		_data = _listbox tvData _index;

		// If we are dealing with the unsorted group we exit
		if (_data == UNSORTED_GROUP_ID) exitWith
		{
			uiNamespace setVariable [VAR_SELECTED_GROUPORPLAYER, [grpNull, objNull]];
		};

		// The group
		private ["_group", "_player"];
		_group  = ["GetGroupByName", [_data, side group player]] call GROUPS;
		_player = [_data] call BIS_fnc_getUnitByUid;

		// Validate group or player
		if (isNull _group && isNull _player) exitWith
		{
			["OnGroupsTreeSelChanged: Group (%1) or player (%1) not found", _data] call BIS_fnc_error;
		};

		// Did the user just clicked a group or a player
		if (!isNull _group) then
		{
			// A group was selected
			private ["_groupIsPrivate", "_wasKickedFrom", "_isInGroup", "_hasInvite"];
			_groupIsPrivate 	= _group getVariable [VAR_GROUP_PRIVATE, false];
			_wasKickedFrom		= ["WasPlayerKickedFrom", [_group, player]] call GROUPS;
			_isInGroup		= _group == group player;
			_hasInvite 		= ["HasInvite", [_group, player]] call GROUPS;

			// Store the newly selected group
			uiNamespace setVariable [VAR_SELECTED_GROUPORPLAYER, [_group, objNull]];

			if (_isInGroup) then
			{
				_joinButton ctrlEnable false;
			}
			else
			{
				if (!_hasInvite && (_groupIsPrivate || _wasKickedFrom)) then
				{
					_joinButton ctrlEnable false;
				}
				else
				{
					_joinButton ctrlEnable true;
				};
			};
		}
		else
		{
			// A player was selected
			private ["_playerName", "_weAreLeader", "_hasInvite", "_sameGroup", "_noGroup"];
			_playerName 	= name _player;
			_weAreLeader 	= player == leader group player;
			_hasInvite 	= ["HasInvite", [group player, _player]] call GROUPS;
			_sameGroup	= group player == group _player;
			_noGroup	= !(["PlayerHasGroup", [player]] call GROUPS);

			// Store the newly selected player
			uiNamespace setVariable [VAR_SELECTED_GROUPORPLAYER, [group _player, _player]];

			switch (true) do
			{
				case (_hasInvite) :
				{
					_inviteButton ctrlSetText localize "STR_A3_rscdisplaydynamicgroups_button_invited";
					_inviteButton ctrlSetTooltip localize "STR_A3_rscdisplaydynamicgroups_tooltip_invited";
					_inviteButton ctrlSetBackgroundColor [0.5, 0.5, 0.5, 1.0];
					_inviteButton ctrlSetTextColor [1.0, 1.0, 1.0, 1.0];
					_inviteButton ctrlEnable false;
					_joinButton ctrlEnable false;
				};

				case (!_weAreLeader || player == _player || _sameGroup || _noGroup) :
				{
					_inviteButton ctrlSetText localize "STR_A3_rscdisplaydynamicgroups_button_invite";
					_inviteButton ctrlSetTooltip "";
					_inviteButton ctrlEnable false;
					_joinButton ctrlEnable false;
				};

				default
				{
					_inviteButton ctrlSetText localize "STR_A3_rscdisplaydynamicgroups_button_invite";
					_inviteButton ctrlSetTooltip "";
					_inviteButton ctrlEnable true;
					_joinButton ctrlEnable false;
				};
			};
		};
	};

	case "OnPlayersLbSelChanged" :
	{
		private ["_listbox", "_index"];
		_listbox = _params select 0;
		_index = _params select 1;

		private ["_display", "_inviteButton", "_joinButton"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_inviteButton 	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONINVITE;
		_joinButton 	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONJOIN;

		_joinButton ctrlEnable false;
		_inviteButton ctrlEnable false;

		// Make sure we have a group, otherwise there is nothing for us to do here
		if !(["PlayerHasGroup", [player]] call GROUPS) exitWith {};

		// The clicked player
		private "_clickedUid";
		_clickedUid = _listbox lnbData [_index, 0];

		// The player to which the uid belongs to
		private ["_clickedPlayer", "_hasInvite", "_inSameGroup", "_weAreLeader"];
		_clickedPlayer 	= [_clickedUid] call BIS_fnc_getUnitByUid;
		_hasInvite 	= ["HasInvite", [group player, _clickedPlayer]] call GROUPS;
		_inSameGroup 	= group player == group _clickedPlayer;
		_weAreLeader 	= player == leader group player;

		// Store the newly selected player
		uiNamespace setVariable [VAR_SELECTED_PLAYER, _clickedPlayer];

		if (getPlayerUid player != _clickedUid && !_hasInvite && !_inSameGroup && _weAreLeader) then
		{
			_inviteButton ctrlEnable true;
		};
	};

	case "OnManageLbSelChanged" :
	{
		private ["_listbox", "_index"];
		_listbox 	= _params select 0;
		_index 		= _params select 1;

		// The clicked player uid
		private "_clickedUid";
		_clickedUid = _listbox lnbData [_index, 0];

		// The player to which the uid belongs to
		private ["_clickedPlayer", "_currentPlayerIsLeader"];
		_clickedPlayer 		= [_clickedUid] call BIS_fnc_getUnitByUid;
		_currentPlayerIsLeader 	= player == leader group player;

		// Store the newly selected member
		uiNamespace setVariable [VAR_SELECTED_MEMBER, _clickedPlayer];

		private ["_display", "_buttonCreateLeaveKick", "_buttonPromoteDisband"];
		_display 		= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_buttonCreateLeaveKick 	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONCREATELEAVEKICK;
		_buttonPromoteDisband	= _display displayCtrl IDC_DYNAMICGROUPS_BUTTONPROMOTEDISBAND;

		_buttonCreateLeaveKick ctrlEnable false;
		_buttonPromoteDisband ctrlEnable false;

		// Did we click ourselves?
		if (_clickedPlayer == player) then
		{
			if (count units group player < 2) then
			{
				_buttonCreateLeaveKick ctrlEnable true;
				_buttonCreateLeaveKick ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Button_Leave";
				_buttonCreateLeaveKick ctrlSetTooltip localize "STR_A3_RscDisplayDynamicGroups_Tooltip_LeaveGroup";

				_buttonPromoteDisband ctrlEnable false;
				_buttonPromoteDisband ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Button_Disband";
				_buttonPromoteDisband ctrlSetTooltip localize "STR_A3_RscDisplayDynamicGroups_Tooltip_KickAll";
			}
			else
			{
				_buttonCreateLeaveKick ctrlEnable true;
				_buttonCreateLeaveKick ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Button_Leave";
				_buttonCreateLeaveKick ctrlSetTooltip localize "STR_A3_RscDisplayDynamicGroups_Tooltip_LeaveGroup";

				if (_currentPlayerIsLeader) then
				{
					_buttonPromoteDisband ctrlEnable true;
					_buttonPromoteDisband ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Button_Disband";
					_buttonPromoteDisband ctrlSetTooltip localize "STR_A3_RscDisplayDynamicGroups_Tooltip_KickAll";
				};
			};
		}
		else
		{
			if (_currentPlayerIsLeader) then
			{
				_buttonCreateLeaveKick ctrlEnable true;
				_buttonCreateLeaveKick ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Button_KickBan";
				_buttonCreateLeaveKick ctrlSetTooltip localize "STR_A3_RscDisplayDynamicGroups_Tooltip_KickPlayer";

				_buttonPromoteDisband ctrlEnable true;
				_buttonPromoteDisband ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Button_Promote";
				_buttonPromoteDisband ctrlSetTooltip localize "STR_A3_RscDisplayDynamicGroups_Tooltip_PromotePlayer";
			}
			else
			{
				_buttonCreateLeaveKick ctrlEnable true;
				_buttonCreateLeaveKick ctrlSetText localize "STR_A3_RscDisplayDynamicGroups_Button_Leave";
				_buttonCreateLeaveKick ctrlSetTooltip localize "STR_A3_RscDisplayDynamicGroups_Tooltip_LeaveGroup";
			};
		};
	};

	case "OnCreateLeaveKickButtonClick" :
	{
		private ["_button"];
		_button = _params select 0;

		_button ctrlEnable false;
		["SetDefaultFocus"] call SELF:

		private ["_display", "_listbox", "_listBoxIndex", "_selectedUid"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_listbox 	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXMANAGE;
		_listBoxIndex	= lnbCurSelRow _listbox;
		_selectedUid	= _listbox lnbData [_listBoxIndex, 0];

		private ["_hasGroup", "_isLeader", "_isSelfSelected"];
		_hasGroup 	= ["PlayerHasGroup", [player]] call GROUPS;
		_isLeader 	= _hasGroup && player == leader group player;
		_isSelfSelected	= _selectedUid == getPlayeruid player;

		switch (true) do
		{
			case (_hasGroup && _isLeader && _isSelfSelected) : 	{ ["OnLeaveGroupButtonClick"] call SELF; };
			case (_hasGroup && _isLeader && !_isSelfSelected) : 	{ ["OnKickPlayerButtonClick", [_selectedUid]] call SELF; };
			case (_hasGroup && !_isLeader) :			{ ["OnLeaveGroupButtonClick"] call SELF; };
			case default 						{ ["OnCreateGroupButtonClick"] call SELF; };
		};
	};

	case "OnCreateGroupButtonClick" :
	{
		// Request group for player
		if (player == leader group player) then
		{
			["SendClientMessage", ["RegisterGroup", [group player, player]]] call GROUPS;
		}
		else
		{
			["SendClientMessage", ["CreateGroupAndRegister", [player]]] call GROUPS;
		};

		// Log
		if (LOG_ENABLED) then
		{
			["OnCreateGroupButtonClick: %1 / %2", group player, player] call BIS_fnc_logFormat;
		};
	};

	case "OnLeaveGroupButtonClick" :
	{
		// Request server to make player leave the current group
		["SendClientMessage", ["RemoveGroupMember", [group player, player]]] call GROUPS;

		// Event
		["OnGroupLeave", [group player, leader group player, player]] call GROUPS;

		// Log
		if (LOG_ENABLED) then
		{
			["OnLeaveGroupButtonClick: %1 / %2", group player, player] call BIS_fnc_logFormat;
		};
	};

	case "OnKickPlayerButtonClick" :
	{
		private ["_uid"];
		_uid = _params param [0, "", [""]];

		private ["_group", "_groupLeader", "_kickedPlayer"];
		_group 		= group player;
		_groupLeader	= leader _group;
		_kickedPlayer	= [_uid] call BIS_fnc_getUnitByUid;

		if (!isNull _group && !isNull _groupLeader && _groupLeader == player && !isNull _kickedPlayer) then
		{
			// Request server to make player leave the current group
			["SendClientMessage", ["KickPlayer", [_group, _groupLeader, _kickedPlayer]]] call GROUPS;

			// Event
			["OnKicked", [_group, _kickedPlayer, _groupLeader]] call GROUPS;
		};

		// Log
		if (LOG_ENABLED) then
		{
			["OnKickPlayerButtonClick: %1", _group, _groupLeader, _kickedPlayer] call BIS_fnc_logFormat;
		};
	};

	case "OnPromoteDisbandButtonClick" :
	{
		private ["_button"];
		_button = _params select 0;

		_button ctrlEnable false;
		["SetDefaultFocus"] call SELF:

		private ["_hasGroup", "_hasEnoughPlayers"];
		_hasGroup 		= ["PlayerHasGroup", [player]] call GROUPS;
		_hasEnoughPlayers	= count units group player > 1;

		// Make sure player has a group, group has at least another player and that player is actually leader
		if (!_hasGroup && !_hasEnoughPlayers && player == leader group player) exitWith {};

		private ["_display", "_listbox", "_listBoxIndex", "_selectedUid"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_listbox 	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXMANAGE;
		_listBoxIndex	= lnbCurSelRow _listbox;
		_selectedUid	= _listbox lnbData [_listBoxIndex, 0];

		private ["_isSelfSelected"];
		_isSelfSelected	= _selectedUid == getPlayerUid player;

		// If we have ourselves selected in the listbox, we Disband group, otherwise we will Promote to leader
		if (_isSelfSelected) then
		{
			["OnDisbandGroupButtonClick"] call SELF;
		}
		else
		{
			["OnPromotePlayerButtonClick", [_selectedUid]] call SELF;
		};

		// Log
		if (LOG_ENABLED) then
		{
			["OnPromoteDisbandButtonClick: %1", _isSelfSelected] call BIS_fnc_logFormat;
		};
	};

	case "OnDisbandGroupButtonClick" :
	{
		private ["_group", "_group", "_groupPlayers", "_groupLeader"];
		_group	 	= group player;
		_groupPlayers	= units _group;
		_groupLeader	= leader _group;

		{
			["OnGroupDisbanded", [_group, _x, _groupLeader]] call GROUPS;
		} forEach _groupPlayers - [_groupLeader];

		{
			[_x] joinSilent grpNull;
		} forEach _groupPlayers;

		// Request server to make player leave the current group
		["SendClientMessage", ["UnregisterGroup", [_group]]] call GROUPS;

		// Log
		if (LOG_ENABLED) then
		{
			["OnDisbandGroupButtonClick: %1", _group, _groupPlayers, _groupLeader] call BIS_fnc_logFormat;
		};
	};

	case "OnPromotePlayerButtonClick" :
	{
		private ["_uid"];
		_uid = _params param [0, "", [""]];

		private ["_group", "_groupLeader", "_newLeader"];
		_group 			= group player;
		_groupLeader		= leader _group;
		_newLeader		= [_uid] call BIS_fnc_getUnitByUid;

		// Request server to switch leader
		["SendClientMessage", ["SwitchLeader", [_group, _newLeader]]] call GROUPS;

		// Event
		["OnPromotedToLeader", [_group, _newLeader, _groupLeader]] call GROUPS;

		// Log
		if (LOG_ENABLED) then
		{
			["OnPromotePlayerButtonClick: %1 / %2 / %3", _group, _groupLeader, _newLeader] call BIS_fnc_logFormat;
		};
	};

	case "OnJoinButtonClick" :
	{
		private ["_button"];
		_button = _params select 0;

		_button ctrlEnable false;
		["SetDefaultFocus"] call SELF:

		private ["_display", "_listboxGroups", "_index", "_groupId"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_listboxGroups 	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXGROUPS;
		_index 		= tvCurSel _listboxGroups;
		_groupName 	= _listboxGroups tvData _index;

		private "_group";
		_group = ["GetGroupByName", [_groupName, side group player]] call GROUPS;

		if (!isNull _group) then
		{
			private ["_groupLeader", "_groupIsPrivate", "_hasInvite"];
			_groupLeader		= leader _group;
			_groupIsPrivate 	= _group getVariable [VAR_GROUP_PRIVATE, false];
			_hasInvite		= ["HasInvite", [_group, player]] call GROUPS;

			if (!_groupIsPrivate || _hasInvite) then
			{
				if !(["PlayerHasGroup", [player]] call GROUPS) then
				{
					["SendClientMessage", ["AddGroupMember", [_group, player]]] call GROUPS;
				}
				else
				{
					["SendClientMessage", ["SwitchGroup", [_group, player]]] call GROUPS;
				};

				if (_hasInvite) then
				{
					["RemoveInvite", [_group, player]] call GROUPS;
				};

				// Event
				["OnGroupJoin", [_group, _groupLeader, player]] call GROUPS;
			};
		};

		// Log
		if (LOG_ENABLED) then
		{
			["OnJoinButtonClick: %1", _button] call BIS_fnc_logFormat;
		};
	};

	case "OnInvitePlayerButtonClick" :
	{
		private ["_button"];
		_button = _params select 0;

		_button ctrlEnable false;
		["SetDefaultFocus"] call SELF:

		private ["_display", "_isTree", "_listbox", "_listboxIndex"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_isTree		= uiNamespace getVariable [VAR_SHOW_GROUPS, true];
		_listbox 	= if (_isTree) then { _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXGROUPS; } else { _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXPLAYERS; };
		_listboxIndex	= if (_isTree) then { tvCurSel _listbox; } else { lnbCurSelRow _listbox; };

		// Validate selected player in list box
		if (_listboxIndex isEqualTo []) exitWith
		{
			"OnInvitePlayerButtonClick: No player selected within the Tree/listNbox resource" call BIS_fnc_error;
		};

		// The local player group
		private "_group";
		_group = group player;

		// The clicked player uid
		private ["_clickedUid", "_clickedPlayer"];
		_clickedUid = if (_isTree) then { _listbox tvData _listboxIndex; } else { _listbox lnbData [_listboxIndex, 0]; };
		_clickedPlayer = [_clickedUid] call BIS_fnc_getUnitByUid;

		// Validate player object
		if (isNull _clickedPlayer) exitWith
		{
			["OnInvitePlayerButtonClick: Player with uid (%1) not found", _clickedUid] call BIS_fnc_error;
		};

		// Add invite
		if !(["HasInvite", [_group, _clickedPlayer]] call GROUPS) then
		{
			["AddInvite", [_group, player, _clickedPlayer]] call GROUPS;
		};

		// Log
		if (LOG_ENABLED) then
		{
			["OnInvitePlayerButtonClick: %1 / %2 / %3", _group, player, _clickedPlayer] call BIS_fnc_logFormat;
		};
	};

	case "OnTabGroupsButtonClick" :
	{
		private ["_display", "_listGroups", "_listPlayers", "_buttonGroups", "_buttonPlayers"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_listGroups	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXGROUPS;
		_listPlayers	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXPLAYERS;
		_buttonGroups	= _display displayCtrl IDC_DYNAMICGROUPS_TABBUTTONGROUPS;
		_buttonPlayers	= _display displayCtrl IDC_DYNAMICGROUPS_TABBUTTONPLAYERS;

		_listGroups ctrlShow true;
		_buttonGroups ctrlSetTextColor [1,1,1,1];
		_buttonGroups ctrlSetBackgroundColor [1,1,1,0.6];
		_buttonGroups ctrlSetActiveColor [1,1,1,0.6];

		_listPlayers ctrlShow false;
		_buttonPlayers ctrlSetTextColor [1,1,1,0.4];
		_buttonPlayers ctrlSetBackgroundColor [0,0,0,0.6];
		_buttonPlayers ctrlSetActiveColor [0,0,0,0.6];

		uiNamespace setVariable [VAR_SHOW_GROUPS, true];
	};

	case "OnTabPlayersButtonClick" :
	{
		private ["_display", "_listGroups", "_listPlayers"];
		_display 	= uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_listGroups	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXGROUPS;
		_listPlayers	= _display displayCtrl IDC_DYNAMICGROUPS_LISTBOXPLAYERS;
		_buttonGroups	= _display displayCtrl IDC_DYNAMICGROUPS_TABBUTTONGROUPS;
		_buttonPlayers	= _display displayCtrl IDC_DYNAMICGROUPS_TABBUTTONPLAYERS;

		_listPlayers ctrlShow true;
		_buttonPlayers ctrlSetTextColor [1,1,1,1];
		_buttonPlayers ctrlSetBackgroundColor [1,1,1,0.6];
		_buttonPlayers ctrlSetActiveColor [1,1,1,0.6];

		_listGroups ctrlShow false;
		_buttonGroups ctrlSetTextColor [1,1,1,0.4];
		_buttonGroups ctrlSetBackgroundColor [0,0,0,0.6];
		_buttonGroups ctrlSetActiveColor [0,0,0,0.6];

		uiNamespace setVariable [VAR_SHOW_GROUPS, false];
	};

	case "OnGroupIconMouseEnter" :
	{

	};

	case "OnGroupIconMouseExit" :
	{

	};

	case "OnPrivateStateChanged" :
	{
		private ["_checkboxPrivate", "_isChecked"];
		_checkboxPrivate = _params select 0;
		_isChecked = (_params select 1) == 1;

		["SendClientMessage", ["SetPrivateState", [group player, _isChecked]]] call GROUPS;

		// Log
		if (LOG_ENABLED) then
		{
			["OnPrivateStateChanged: %1", _isChecked] call BIS_fnc_logFormat;
		};
	};

	case "OnTreeDoubleClick" :
	{
		private "_tree";
		_tree = _params select 0;

		private "_index";
		_index = tvCurSel _tree;

		if (count _index > 1) then
		{
			private "_clickedUid";
			_clickedUid = _tree tvData _index;

			// The player to which the uid belongs to
			private "_clickedPlayer";
			_clickedPlayer = [_clickedUid] call BIS_fnc_getUnitByUid;

			// Player was clicked
			if (player != _clickedPlayer) then
			{
				["OnPlayerDoubleClick", [_clickedPlayer]] call SELF;
			};
		}
		else
		{
			private ["_clickedName", "_clickedGroup"];
			_clickedName 	= _tree tvData _index;
			_clickedGroup	= ["GetGroupByName", [_clickedName, side group player]] call GROUPS;

			// Group was clicked
			if (!isNull _clickedGroup) then
			{
				["OnGroupDoubleClick", [_clickedGroup]] call SELF;
			};
		};
	};

	case "OnListDoubleClick" :
	{
		private ["_listbox", "_index"];
		_listbox 	= _params select 0;
		_index 		= _params select 1;

		// The clicked player uid
		private "_clickedUid";
		_clickedUid = _listbox lnbData [_index, 0];

		// The player to which the uid belongs to
		private "_clickedPlayer";
		_clickedPlayer = [_clickedUid] call BIS_fnc_getUnitByUid;

		// Player was clicked
		if (player != _clickedPlayer) then
		{
			["OnPlayerDoubleClick", [_clickedPlayer]] call SELF;
		};
	};

	case "OnGroupDoubleClick" :
	{
		private ["_group"];
		_group = _params select 0;

		private ["_groupPrivate", "_wasKickedFrom", "_hasInvite"];
		_groupPrivate 	= _group getVariable [VAR_GROUP_PRIVATE, false];
		_wasKickedFrom	= ["WasPlayerKickedFrom", [_group, player]] call GROUPS;
		_hasInvite	= ["HasInvite", [_group, player]] call GROUPS;

		// Make sure that group is not private and player is not kicked from it, or player as invite
		if ((!_groupPrivate && !_wasKickedFrom) || _hasInvite) then
		{
			if (["PlayerHasGroup", [player]] call GROUPS) then
			{
				["SendClientMessage", ["AddGroupMember", [_group, player]]] call GROUPS;
			}
			else
			{
				["SendClientMessage", ["SwitchGroup", [_group, player]]] call GROUPS;
			};

			if (_hasInvite) then
			{
				["RemoveInvite", [_group, player]] call GROUPS;
			};
		};
	};

	case "OnPlayerDoubleClick" :
	{
		private ["_clickedPlayer"];
		_clickedPlayer 	= _params select 0;

		// Did we clicked ourselves
		if (_clickedPlayer != player) then
		{
			private ["_selfInGroup", "_otherInGroup", "_hasInvite", "_wasKicked", "_groupIsLocked"];
			_selfInGroup 	= ["PlayerHasGroup", [player]] call GROUPS;
			_otherInGroup	= ["PlayerHasGroup", [_clickedPlayer]] call GROUPS;
			_hasInvite	= ["HasInvite", [group player, _clickedPlayer]] call GROUPS;
			_wasKicked	= ["WasPlayerKickedFrom", [group _clickedPlayer, player]] call GROUPS;
			_groupIsLocked	= (group _clickedPlayer) getVariable [VAR_GROUP_PRIVATE, false];

			switch (true) do
			{
				// Invite player
				case (_selfInGroup && !_hasInvite && group player != group _clickedPlayer) :
				{
					["AddInvite", [group player, player, _clickedPlayer]] call GROUPS;
				};

				// Join other player's group
				case (!_selfInGroup && _otherInGroup && !_wasKicked && !_groupIsLocked) :
				{
					["SendClientMessage", ["AddGroupMember", [group _clickedPlayer, player]]] call GROUPS;

					if (_hasInvite) then
					{
						["RemoveInvite", [group _clickedPlayer, player]] call GROUPS;
					};
				};
			};
		};
	};

	case "OnGroupNameChanged" :
	{
		private ["_editGroupName", "_key"];
		_editGroupName 	= _params select 0;
		_key		= _params param [1, -1, [0]];

		if (time < (uiNamespace getVariable "BIS_dynamicGroups_lastGroupNameChangeTime") + TIME_GROUP_NAME_CHANGE) exitWith {};

		// Store current change time
		uiNamespace setVariable ["BIS_dynamicGroups_lastGroupNameChangeTime", time];

		if (_key == 28 || _key == 156 || _key == -1) then
		{
			private ["_wasUpdated", "_groupName", "_groupNameSize", "_oldGroupName"];
			_wasUpdated 	= false;
			_groupName 	= ctrlText _editGroupName;
			_groupNameSize	= count (toArray _groupName);
			_oldGroupName 	= groupid (group player);

			private ["_clampedGroupName", "_groupNameWasClamped"];
			_clampedGroupName 	= ["ClampString", [_groupName]] call SELF;
			_groupNameWasClamped	= _groupNameSize > count (toArray _clampedGroupName);

			private ["_groupsOfSide", "_nameTaken"];
			_groupsOfSide 	= ["GetAllGroupsOfSide", [side group player]] call GROUPS;
			_nameTaken 	= false;

			{
				if (groupId _x isEqualTo _clampedGroupName) then
				{
					_nameTaken = true;
				};
			}
			forEach _groupsOfSide;

			if (typeName _clampedGroupName == typeName "" && { _clampedGroupName != _oldGroupName } && { _clampedGroupName != "" } && { !_nameTaken }) then
			{
				["SendClientMessage", ["SetName", [group player, _clampedGroupName]]] call GROUPS;
				_wasUpdated = true;
			};

			// Animate
			private ["_backgroundGroupName", "_color"];
			_backgroundGroupName = (uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull]) displayCtrl IDC_DYNAMICGROUPS_BACKGROUNDGROUPNAME;
			_color = switch (true) do
			{
				case (_wasUpdated && !_groupNameWasClamped) : 	{ [RESISTANCE] call BIS_fnc_sideColor };
				case (_wasUpdated && _groupNameWasClamped) :  	{ [CIVILIAN] call BIS_fnc_sideColor };
				case default 					{ [EAST] call BIS_fnc_sideColor };
			};
			_backgroundGroupName ctrlSetBackgroundColor _color;
			_editGroupName ctrlSetTextColor _color;

			[_backgroundGroupName, _editGroupName, if (_wasUpdated) then { _clampedGroupName } else { _oldGroupName }] spawn
			{
				scriptName "RscDisplayDynamicGroups RscEdit animation";

				disableSerialization;

				sleep 0.3;
				(_this select 0) ctrlSetBackgroundColor [0, 0, 0, 1];
				(_this select 1) ctrlEnable true;
				(_this select 1) ctrlSetText (_this select 2);
				(_this select 1) ctrlSetTextColor [1, 1, 1, 1];
			};

			// Lose focus
			ctrlSetFocus ((uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull]) displayCtrl IDC_DYNAMICGROUPS_LISTBOXMANAGE);

			// Log
			if (LOG_ENABLED) then
			{
				["OnGroupNameChanged: %1 / %2", _this, _clampedGroupName] call BIS_fnc_logFormat;
			};
		};
	};

	case "OnGroupExpanded" :
	{
		private ["_tree", "_index"];
		_tree = _params select 0;
		_index = _params select 1;

		private ["_data", "_collapsedGroups"];
		_data 			= _tree tvData _index;
		_collapsedGroups 	= uiNamespace getVariable [VAR_COLLAPSED_GROUPS, []];
		_group			= ["GetGroupByName", [_data, side group player]] call GROUPS;

		if (!isNull _group) then
		{
			if (_group in _collapsedGroups) then
			{
				_collapsedGroups deleteAt (_collapsedGroups find _group);
				uiNamespace setVariable [VAR_COLLAPSED_GROUPS, _collapsedGroups];
			};
		};
	};

	case "OnGroupCollapsed" :
	{
		private ["_tree", "_index"];
		_tree 	= _params select 0;
		_index 	= _params select 1;

		private ["_data", "_collapsedGroups", "_group"];
		_data 			= _tree tvData _index;
		_collapsedGroups 	= uiNamespace getVariable [VAR_COLLAPSED_GROUPS, []];
		_group			= ["GetGroupByName", [_data, side group player]] call GROUPS;

		if (!isNull _group) then
		{
			if !(_group in _collapsedGroups) then
			{
				_collapsedGroups pushBack _group;
				uiNamespace setVariable [VAR_COLLAPSED_GROUPS, _collapsedGroups];
			};
		};
	};

	case "SetDefaultFocus" :
	{
		private ["_display", "_control"];
		_display = uiNamespace getVariable ["BIS_dynamicGroups_display", displayNull];
		_control = _display displayCtrl IDC_CANCEL;

		ctrlSetFocus _control;
	};

	case "OnGroupNameSetFocus" :
	{
		private ["_editGroupName"];
		_editGroupName = _params select 0;

		// Flag
		uiNamespace setVariable [VAR_HAS_FOCUS, true];

		// Log
		if (LOG_ENABLED) then
		{
			["OnGroupNameFocus: Group Name has focus (%1)", _editGroupName] call BIS_fnc_log;
		};
	};

	case "OnGroupNameKillFocus" :
	{
		private ["_editGroupName"];
		_editGroupName = _params select 0;

		// Flag
		uiNamespace setVariable [VAR_HAS_FOCUS, nil];

		// Log
		if (LOG_ENABLED) then
		{
			["OnGroupNameFocus: Group Name lost focus (%1)", _editGroupName] call BIS_fnc_log;
		};
	};

	case "GetFactionPicture" :
	{
		private ["_leader"];
		_leader = _params param [0, objNull, [objNull]];

		private "_picture";
		_picture = getText (configFile >> "CfgFactionClasses" >> faction _leader >> "flag");

		if (_picture != "") then
		{
			_picture;
		}
		else
		{
			["GetSideColor", [side group _leader]] call SELF;
		};
	};

	case "GetSideColor" :
	{
		private ["_side"];
		_side = _params param [0, SIDEUNKNOWN, [SIDEUNKNOWN]];

		private "_color";
		_color = switch (_side) do
		{
			case WEST : 		{ "#(argb,8,8,3)color(0,0,1,0.6)" };
			case EAST : 		{ "#(argb,8,8,3)color(1,0,0,0.6)" };
			case RESISTANCE : 	{ "#(argb,8,8,3)color(0,1,0,0.6)" };
			case CIVILIAN : 	{ "#(argb,8,8,3)color(0.5,0.5,0.5,0.6)" };
			case default 		{ "#(argb,8,8,3)color(0,0,0,0.6)" };
		};

		_color;
	};

	case "GetPlayerIcon" :
	{
		private "_player";
		_player = _params param [0, objNull, [objNull, ""]];

		if (typeName _player == typeName "") then
		{
			_player = [_player] call BIS_fnc_getUnitByUid;
		};

		if (isNull _player) exitWith { ""; };

		private ["_icon", "_texture"];
		_icon 		= getText (configfile >> "CfgVehicles" >> typeOf _player >> "icon");
		_texture	= getText (configfile >> "CfgVehicleIcons" >> _icon);

		_texture;
	};

	case "GetSideFormattedString" :
	{
		private ["_side"];
		_side = _params param [0, sideUnknown, [sideUnknown]];

		private "_string";
		_string = switch (_side) do
		{
			case WEST : 		{ localize "STR_A3_texturesources_blu0" };
			case EAST : 		{ localize "STR_A3_truck_02_transport_base_f_texturesources_opfor0" };
			case RESISTANCE : 	{ localize "STR_A3_cfggroups_indep0" };
			case default 		{ localize "STR_A3_cfgvehicles_c_man_10" };
		};

		_string;
	};

	case "ClampString" :
	{
		private ["_inString", "_maxSize"];
		_inString 	= _params param [0, "", [""]];
		_maxSize 	= _params param [1, MAX_GROUP_NAME_SIZE, [0]];

		private ["_outString", "_groupNameArray"];
		_outString = "";
		_groupNameArray = toArray _inString;

		if (count _groupNameArray > _maxSize) then
		{
			_groupNameArray resize _maxSize;
			_outString = toString _groupNameArray;
		}
		else
		{
			_outString = _inString;
		};

		_outString;
	};

	case default
	{
		["Unknown mode: %1", _mode] call BIS_fnc_error;
	};
};