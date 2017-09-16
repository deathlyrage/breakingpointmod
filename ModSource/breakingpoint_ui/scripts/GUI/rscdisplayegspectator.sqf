/*
	Author:
	Nelson Duarte

	Description:
	Handles spectator display

	Returns:
	Multiple values / none

	Event Handlers:
	RscDisplayEGSpectator_OnCursorObjectFocused
	RscDisplayEGSpectator_OnFocusChanged
	RscDisplayEGSpectator_OnUiVisibilityChanged
	RscDisplayEGSpectator_MapStateChanged

	Notes:
	Not to be used directly
*/
// Do not serialize this script
disableSerialization;

// Name this script
scriptName "RscDisplayEGSpectator";

// Common spectator defines
#include "\A3\Functions_F_Exp_A\EGSpectatorCommonDefines.inc"

// Params
private ["_mode", "_params"];
_mode 	= _this param [0, "", [""]];
_params = _this param [1, [], [[]]];

switch _mode do
{
	/**
	 * Display initiated
	 */
	case "onLoad":
	{
		scriptName "RscDisplayEGSpectator: onLoad";

		private _display = _params select 0;

		// Store our display
		uiNamespace setVariable [VAR_DISPLAY, _display];

		// Create our loop
		uiNamespace setVariable [VAR_LOOP, [] spawn
		{
			scriptName "RscDisplayEGSpectator: Loop";
			disableSerialization;

			while { true } do
			{
				if (uiNamespace getVariable [VAR_INTERFACE_VISIBLE, true]) then
				{
					["Update_GameTime"] call DISPLAY;
					sleep LOOP_RATE;
					["Update_FocusInfoWidget"] call DISPLAY;
				};

				sleep LOOP_RATE;
			};

			uiNamespace setVariable [VAR_LOOP, nil];
		}];

		// Start ticking
		uiNamespace setVariable [VAR_TICK, addMissionEventHandler ["Draw3D",
		{
			// Update cursor object
			["UpdateCursorObject"] call DISPLAY;

			// Update list
			if (time >= (missionNamespace getVariable [VAR_LAST_TICK_TIME, 0.0]) + LIST_UPDATE_RATE) then
			{
				missionNamespace setVariable [VAR_LAST_TICK_TIME, time];

				if (uiNamespace getVariable [VAR_LIST_TYPE, ""] == LIST_ENTITIES) then
				{
					["Update_PlayerList"] call DISPLAY;
				}
				else
				{
					["Update_LocationList"] call DISPLAY;
				};
			};
		}]];

		// Add events for input handling
		uiNamespace setVariable [VAR_KEY_DOWN, _display displayaddeventhandler ["KeyDown", { ["KeyDown", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_KEY_UP, _display displayaddeventhandler ["KeyUp", { ["KeyUp", _this] call DISPLAY; }]];

		// Mouse input handling
		uiNamespace setVariable [VAR_MOUSE_BUTTON_DOWN, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlAddEventHandler ["MouseButtonDown", { ["MouseButtonDown", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_MOUSE_BUTTON_UP, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlAddEventHandler ["MouseButtonUp", { ["MouseButtonUp", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_MOUSE_DBL_BUTTON_DOWN, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlAddEventHandler ["MouseButtonDblClick", { ["MouseButtonDblClick", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_MOUSE_Z_CHANGED, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlAddEventHandler ["MouseZChanged", { ["MouseZChanged", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_MOUSE_MOVING, _display displayAddEventHandler ["MouseMoving", { ["MouseMoving", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_IS_HOLDING_RIGHT_M_BUTTON, false];

		// Add event for children being destroyed
		uiNamespace setVariable [VAR_CHILD_DESTROYED, _display displayaddeventhandler ["ChildDestroyed", { ["ChildDestroyed", _this] call DISPLAY; }]];

		// The tree list event handlers
		uiNamespace setVariable [VAR_TREE_MOUSE_ENTER, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlAddEventHandler ["MouseEnter", { ["ShowList", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_TREE_MOUSE_EXIT, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlAddEventHandler ["MouseExit", { ["HideList", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_TREE_PLAYER_CLICKED, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlAddEventHandler ["TreeSelChanged", { ["TreeClicked", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_TREE_PLAYER_DBL_CLICKED, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlAddEventHandler ["TreeDblClick", { ["TreeDblClicked", _this] call DISPLAY; }]];

		// The camera buttons event handlers
		{
			uiNamespace setVariable [VAR_CAM_BUTTON_CLICKED, (_display displayCtrl _x) ctrlAddEventHandler ["ButtonClick", { ["CamButtonClicked", _this] call DISPLAY; }]];
		} forEach [IDC_RSCDISPLAYEGSPECTATOR_FREE, IDC_RSCDISPLAYEGSPECTATOR_FOLLOW, IDC_RSCDISPLAYEGSPECTATOR_FPS];

		// Initial visibility mode of the ui
		uiNamespace setVariable [VAR_INTERFACE_VISIBLE, true];

		// Selected camera type button
		["ResetCameraButtonsState"] call DISPLAY;
		//(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FREE) ctrlSetText CAM_ICON_FREE_SELECTED;

		// If the free camera is disabled find focus (it will automatically assign correct mode, but focus is mandatory)
		if !(missionNamespace getVariable [VAR_ALLOW_FREE_CAMERA, true]) then
		{
			private _initialFocus = ["FindFocus"] call DISPLAY;

			if (!isNull _initialFocus) then
			{
				["SetFocus", [_initialFocus]] call DISPLAY;
				["SetCameraMode", [MODE_FOLLOW]] call CAM;
			}
			else
			{
				"RscDisplayEGSpectator: Unable to assign initial focus and free camera is disabled" call BIS_fnc_error;
			};

			// Set free camera button to fully disabled state
			(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FREE) ctrlSetTextColor [1,1,1,0.2];
			(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FREE) ctrlSetTooltip "";
		};

		// Camera mode changes event handler
		uiNamespace setVariable [VAR_CAMERA_MODE_CHANGED, [missionNamespace, "EGSpectator_OnCameraModeChanged", { ["SpectatorCameraModeChanged", _this] call DISPLAY; }] call BIS_fnc_addScriptedEventHandler];

		// Tabs event handlers
		uiNamespace setVariable [VAR_TABS_CLICKED, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS) ctrlAddEventHandler ["ToolBoxSelChanged", { ["OnTabSelected", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_TABS_MOUSE_ENTER, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS) ctrlAddEventHandler ["MouseEnter", { ["ShowList", _this] call DISPLAY; }]];
		uiNamespace setVariable [VAR_TABS_MOUSE_EXIT, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS) ctrlAddEventHandler ["MouseExit", { ["HideList", _this] call DISPLAY; }]];

		// Game phase
		uiNamespace setvariable [VAR_GAME_PHASE, ""];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMEPHASETEXT) ctrlSetFade 1.0;
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMEPHASETEXT) ctrlCommit 0.0;
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMEPHASE) ctrlSetFade 1.0;
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMEPHASE) ctrlCommit 0.0;

		// Hide map
		uiNamespace setVariable [VAR_MAP_VISIBLE, false];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAPGROUP) ctrlShow false;

		// Map highlighted object
		uiNamespace setVariable [VAR_MAP_HIGHLIGHTED_OBJECT, objNull];

		// Default view distance
		setViewDistance DEFAULT_VIEW_DISTANCE;

		// Head to head visualization
		["SetHeadToHeadVisibility", [false]] call DISPLAY;

		// List related
		uiNamespace setVariable [VAR_LIST_TYPE, LIST_ENTITIES];
		uiNamespace setVariable [VAR_ENTITIES_LIST_OLD, nil];
		uiNamespace setVariable [VAR_LOCATIONS_LIST_OLD, nil];
		["HideList"] call DISPLAY;

		// Update controls help status
		uiNamespace setVariable [VAR_DEFAULT_HELP_Y, (ctrlPosition (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELP)) select 1];
		uiNamespace setVariable [VAR_DEFAULT_HELP_H, (ctrlPosition (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELP)) select 3];
		["SetControlsHelpVisibility", [true]] call DISPLAY;

		// Focus info widget
		["ShowFocusInfoWidget", [false]] call DISPLAY;
	};

	/**
	 * Display terminated
	 */
	case "onUnload":
	{
		scriptName "RscDisplayEGSpectator: onUnload";

		private _display = ["GetDisplay"] call DISPLAY;

		// Stop our loop
		terminate (uiNamespace getVariable [VAR_LOOP, scriptNull]);
		uiNamespace setVariable [VAR_LOOP, nil];

		// Stop ticking
		removeMissionEventHandler ["Draw3D", uiNamespace getVariable [VAR_TICK, -1]];

		// Remove input handling
		if (!isNil { uiNamespace getVariable VAR_KEY_DOWN } && !isNil { uiNamespace getVariable VAR_DISPLAY } && { !isNull (uiNamespace getVariable VAR_DISPLAY) }) then
		{
			(uiNamespace setVariable [VAR_DISPLAY, displayNull]) displayRemoveEventHandler ["KeyDown", uiNamespace getVariable [VAR_KEY_DOWN, -1]];
		};

		if (!isNil { uiNamespace getVariable VAR_KEY_UP } && !isNil { uiNamespace getVariable VAR_DISPLAY } && { !isNull (uiNamespace getVariable VAR_DISPLAY) }) then
		{
			(uiNamespace setVariable [VAR_DISPLAY, displayNull]) displayRemoveEventHandler ["KeyUp", uiNamespace getVariable [VAR_KEY_UP, -1]];
		};

		// Reset variables
		uiNamespace setVariable [VAR_DISPLAY, nil];
		uiNamespace setVariable [VAR_KEY_DOWN, nil];
		uiNamespace setVariable [VAR_KEY_UP, nil];

		// Remove mouse handler events
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlRemoveEventHandler ["MouseButtonDown", uiNamespace getVariable [VAR_MOUSE_BUTTON_DOWN, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlRemoveEventHandler ["MouseButtonUp", uiNamespace getVariable [VAR_MOUSE_BUTTON_UP, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlRemoveEventHandler ["MouseButtonDblClick", uiNamespace getVariable [VAR_MOUSE_DBL_BUTTON_DOWN, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER) ctrlRemoveEventHandler ["MouseZChanged", uiNamespace getVariable [VAR_MOUSE_Z_CHANGED, -1]];
		_display displayRemoveEventHandler ["MouseMoving", uiNamespace getVariable [VAR_MOUSE_MOVING, -1]];
		uiNamespace setVariable [VAR_MOUSE_BUTTON_DOWN, nil];
		uiNamespace setVariable [VAR_MOUSE_BUTTON_UP, nil];
		uiNamespace setVariable [VAR_MOUSE_DBL_BUTTON_DOWN, nil];
		uiNamespace setVariable [VAR_MOUSE_Z_CHANGED, nil];
		uiNamespace setVariable [VAR_MOUSE_MOVING, nil];
		uiNamespace setVariable [VAR_IS_HOLDING_RIGHT_M_BUTTON, nil];

		// Reset cursor object and focus
		uiNamespace setVariable [VAR_CURSOR_OBJECT, nil];
		uiNamespace setVariable [VAR_FOCUS, nil];

		// Remove tree events
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlRemoveEventHandler ["MouseEnter", uiNamespace getVariable [VAR_TREE_MOUSE_ENTER, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlRemoveEventHandler ["MouseExit", uiNamespace getVariable [VAR_TREE_MOUSE_EXIT, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlRemoveEventHandler ["TreeSelChanged", uiNamespace getVariable [VAR_TREE_PLAYER_CLICKED, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST) ctrlRemoveEventHandler ["TreeDblClick", uiNamespace getVariable [VAR_TREE_PLAYER_DBL_CLICKED, -1]];
		uiNamespace getVariable [VAR_TREE_MOUSE_ENTER, nil];
		uiNamespace getVariable [VAR_TREE_MOUSE_EXIT, nil];
		uiNamespace getVariable [VAR_TREE_PLAYER_CLICKED, nil];
		uiNamespace getVariable [VAR_TREE_PLAYER_DBL_CLICKED, nil];

		// The camera buttons event handlers
		{
			(_display displayCtrl _x) ctrlRemoveEventHandler ["MouseButtonDown", uiNamespace getVariable [VAR_CAM_BUTTON_CLICKED, -1]];
		} forEach [IDC_RSCDISPLAYEGSPECTATOR_FREE, IDC_RSCDISPLAYEGSPECTATOR_FOLLOW, IDC_RSCDISPLAYEGSPECTATOR_FPS];
		uiNamespace setVariable [VAR_CAM_BUTTON_CLICKED, nil];

		// Initial visibility mode of the ui
		uiNamespace setVariable [VAR_INTERFACE_VISIBLE, nil];

		// Camera mode changes event handler
		[missionNamespace, "EGSpectator_OnCameraModeChanged", uiNamespace getVariable [VAR_CAMERA_MODE_CHANGED, -1]] call BIS_fnc_removeScriptedEventHandler;

		// The current list mode - Players or locations
		uiNamespace setVariable [VAR_LIST_TYPE, nil];

		// Remove event handlers from tabs
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS) ctrlRemoveEventHandler ["ToolBoxSelChanged", uiNamespace getVariable [VAR_TABS_CLICKED, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS) ctrlRemoveEventHandler ["MouseEnter", uiNamespace getVariable [VAR_TABS_MOUSE_ENTER, -1]];
		(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS) ctrlRemoveEventHandler ["MouseExit", uiNamespace getVariable [VAR_TABS_MOUSE_EXIT, -1]];
		uiNamespace setVariable [VAR_TABS_CLICKED, nil];
		uiNamespace setVariable [VAR_TABS_MOUSE_ENTER, nil];
		uiNamespace setVariable [VAR_TABS_MOUSE_EXIT, nil];

		// Game phase
		uiNamespace setvariable [VAR_GAME_PHASE, nil];

		// Map
		uiNamespace setVariable [VAR_MAP_VISIBLE, nil];

		// Map highlighted object
		uiNamespace setVariable [VAR_MAP_HIGHLIGHTED_OBJECT, nil];

		// List related
		uiNamespace setVariable [VAR_LIST_TYPE, nil];
		uiNamespace setVariable [VAR_ENTITIES_LIST_OLD, nil];
		uiNamespace setVariable [VAR_LOCATIONS_LIST_OLD, nil];

		// Focus info widget
		uiNamespace setVariable [VAR_FOCUS_WIDGET_VISIBLE, nil];

		// Stored insignias
		uiNamespace setVariable [VAR_AVAILABLE_INSIGNIAS, nil];

		// Controls visibility
		uiNamespace setVariable [VAR_CONTROLS_HELP_VISIBLE, nil];

		// Show chat
		showChat true;
	};

	case "GetDisplay" :
	{
		uiNamespace getVariable [VAR_DISPLAY, displayNull];
	};

	/**
	 * Updates the game time control
	 */
	case "Update_GameTime" :
	{
		scriptName "RscDisplayEGSpectator: Update_GameTime";

		private "_display";
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];

		if (!isNull _display) then
		{
			private "_ctrlGameTime";
			_ctrlGameTime = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMETIMETEXT;

			private "_timeLeft";
			_timeLeft = -1;

			if (!isNil { missionNamespace getVariable "BIS_hvt_timeoutTarget" }) then
			{
				_timeLeft = (time - (missionNamespace getVariable "BIS_hvt_timeoutTarget")) * -1 / 3600;

				_ctrlGameTime ctrlSetText ("-" + ([_timeLeft] call BIS_fnc_timeToString));
			};

			if (_timeLeft < 0) then
			{
				_ctrlGameTime ctrlSetText ("+" + ([time / 3600] call BIS_fnc_timeToString));
			};
		};
	};

	/**
	 * Updates player list
	 */
	case "Update_PlayerList" :
	{
		scriptName "RscDisplayEGSpectator: Update_PlayerList";

		private _display	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		private _ctrl 		= _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

		private _oldList	= [] + (uiNamespace getVariable [VAR_ENTITIES_LIST_OLD, []]);
		private _groups		= [] + (["GetTargetGroups"] call SPEC);

		private ["_west", "_east", "_indep", "_civ"];
		_west		= [];
		_east		= [];
		_indep		= [];
		_civ		= [];

		{
			private _group = _x;
			private _units = units _x;
			private _showAiGroups = missionNamespace getVariable [VAR_SHOW_AI_GROUPS, true];
			private _groupTexture = ["GetGroupTexture", [_group]] call BIS_fnc_dynamicGroups;
			private _groupInfo = [_group, side _group, _groupTexture];
			private _unitsInfo = [];

			{
				if (simulationEnabled _x && {!isObjectHidden _x} && {simulationEnabled vehicle _x} && {!isObjectHidden vehicle _x} && {isPlayer _x || {_showAiGroups}} && !(_x isKindOf SPECTATOR_CLASS)) then
				{
					_unitsInfo pushBack [_x, alive _x, alive _x && { _x getVariable [VAR_INCAPACITATED, false] }, [_x, nil, NAME_MAX_CHARACTERS] call BIS_fnc_getName, groupId _group];
				};
			} forEach _units;

			if (count _unitsInfo > 0) then
			{
				private _result = [_groupInfo, _unitsInfo];

				switch (side _group) do
				{
					case WEST: 		{ _west pushBack _result; };
					case EAST: 		{ _east pushBack _result; };
					case RESISTANCE: 	{ _indep pushBack _result; };
					default 		{ _civ pushBack _result; };
				};
			};
		} forEach _groups;

		private _newList = [_west, _east, _indep, _civ];
		private _needsUpdate = !(_oldList isEqualTo _newList);

		if (_needsUpdate) then
		{
			private _allElements = ["TreeGetAllElements"] call DISPLAY;
			private _sideElements = _allElements select 0;
			private _groupElements = _allElements select 1;
			private _unitElements = _allElements select 2;

			{
				private ["_sideType", "_sideColor", "_sideString", "_sideIndex"];
				_sideType = switch (_forEachIndex) do
				{
					case 0: { "WEST"; };
					case 1: { "EAST"; };
					case 2: { "RESISTANCE"; };
					default { "CIVILIAN"; };
				};
				_sideColor = switch (_forEachIndex) do
				{
					case 0: { [WEST] call BIS_fnc_sideColor; };
					case 1: { [EAST] call BIS_fnc_sideColor; };
					case 2: { [RESISTANCE] call BIS_fnc_sideColor; };
					default { [CIVILIAN] call BIS_fnc_sideColor; };
				};
				_sideString = switch (_forEachIndex) do
				{
					case 0: { localize "str_west"; };
					case 1: { localize "str_east"; };
					case 2: { localize "str_guerrila"; };
					default { localize "str_civilian"; };
				};
				_sideIndex = _forEachIndex;

				_sideElements = _sideElements - [_sideType];

				if (_ctrl tvCount [] == _forEachIndex) then
				{
					_ctrl tvAdd [[], _sideString];
					_ctrl tvSetData [[_forEachIndex], _sideType];
				};

				{
					private _groupInfo = _x select 0;
					private _unitsInfo = _x select 1;
					private _group = _groupInfo select 0;
					private _groupIndex = _forEachIndex;

					_groupElements = _groupElements - [str _group];

					if (["TreeGetDataIndex", [str _group]] call DISPLAY isEqualTo []) then
					{
						_ctrl tvAdd [[_sideIndex], groupId _group];
						_ctrl tvSetData [[_sideIndex, _forEachIndex], str _group];
						_ctrl tvSetPicture [[_sideIndex, _forEachIndex], _groupInfo select 2];
						_ctrl tvSetPictureColor [[_sideIndex, _forEachIndex], [1, 1, 1, 0.5]];
						_ctrl tvSetTooltip [[_sideIndex, _forEachIndex], groupId _group];
						_ctrl tvExpand [_sideIndex];
						_ctrl tvSort [[_sideIndex], false];
					}
					else
					{
						["TreeUpdateElement", [str _group, groupId _group, _groupInfo select 2, [1, 1, 1, 0.5], groupId _group]] call DISPLAY;
					};

					{
						private ["_unit", "_isAlive", "_isIncapacitated", "_name", "_groupId"];
						_unit 			= _x select 0;
						_isAlive 		= _x select 1;
						_isIncapacitated 	= _x select 2;
						_name 			= _x select 3;
						_groupId 		= _x select 4;

						private "_texture";
						_texture = switch (true) do
						{
							case (!_isAlive) : 		{ ICON_DEAD };
							case (_isIncapacitated) : 	{ ICON_INCAPACITATED };
							default 			{ getText (configfile >> "CfgVehicleIcons" >> getText (configfile >> "CfgVehicles" >> typeOf _unit >> "icon")) };
						};

						private _text = if (isPlayer _unit) then { _name } else { format ["%1: %2", localize "str_player_ai", _name] };
						private _tooltip = if (isPlayer _unit) then { format ["%1 - %2", _name, _groupId] } else { format ["%1: %2 - %3", localize "str_player_ai", _name, _groupId] };

						_unitElements = _unitElements - [[_unit] call BIS_fnc_objectVar];

						if (["TreeGetDataIndex", [[_unit] call BIS_fnc_objectVar]] call DISPLAY isEqualTo []) then
						{
							_ctrl tvAdd [[_sideIndex, _groupIndex], _text];
							_ctrl tvSetData [[_sideIndex, _groupIndex, _forEachIndex], [_unit] call BIS_fnc_objectVar];
							_ctrl tvSetPicture [[_sideIndex, _groupIndex, _forEachIndex], _texture];
							_ctrl tvSetPictureColor [[_sideIndex, _groupIndex, _forEachIndex], _sideColor];
							_ctrl tvSetTooltip [[_sideIndex, _groupIndex, _forEachIndex], _tooltip];
							_ctrl tvExpand [_sideIndex, _groupIndex];
							_ctrl tvSort [[_sideIndex, _groupIndex], false];
						}
						else
						{
							["TreeUpdateElement", [[_unit] call BIS_fnc_objectVar, _text, _texture, _sideColor, _tooltip]] call DISPLAY;
						};
					} forEach _unitsInfo;
				} forEach _x;
			} forEach _newList;

			// Delete all elements that are now gone
			{ ["TreeDeleteItem", [_x]] call DISPLAY; } forEach _sideElements;
			{ ["TreeDeleteGroup", [_x]] call DISPLAY; } forEach _groupElements;
			{ ["TreeDeleteUnit", [_x]] call DISPLAY; } forEach _unitElements;

			uiNamespace setVariable [VAR_ENTITIES_LIST_OLD, _newList];
		};
	};

	/**
	 * Updates location list
	 */
	case "Update_LocationList" :
	{
		scriptName "RscDisplayEGSpectator: Update_LocationList";

		private _display	= uiNamespace getVariable [VAR_DISPLAY, displayNull];
		private _ctrl 		= _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

		private _oldList	= [] + (uiNamespace getVariable [VAR_LOCATIONS_LIST_OLD, []]);
		private _newList	= [] + (missionNamespace getVariable [VAR_LOCATIONS, []]);

		if !(_oldList isEqualTo _newList) then
		{
			private _allLocations = [];

			for "_i" from 0 to ((_ctrl tvCount []) - 1) do
			{
				_allLocations pushBack (_ctrl tvData [_i]);
			};

			{
				private ["_id", "_object", "_name", "_description", "_texture", "_cameraOffset"];
				_id 		= _x select 0;
				_name 		= _x select 1;
				_description 	= _x select 2;
				_texture	= _x select 3;
				_cameraOffset 	= _x select 4;

				_allLocations = _allLocations - [_id];

				if (["TreeGetDataIndex", [_id]] call DISPLAY isEqualTo []) then
				{
					_ctrl tvAdd [[], _name];
					_ctrl tvSetData [[_forEachIndex], _id];
					_ctrl tvSetPicture [[_forEachIndex], _texture];
					_ctrl tvSetPictureColor [[_forEachIndex], [1,1,1,1]];
					_ctrl tvSetTooltip [[_forEachIndex], _name];
				}
				else
				{
					["TreeUpdateElement", [_id, _name, _texture, [1,1,1,1], _name]] call DISPLAY;
				};
			} forEach _newList;

			// Delete all elements that are now gone
			{ ["TreeDeleteItem", [_x]] call DISPLAY; } forEach _allLocations;

			uiNamespace setVariable [VAR_LOCATIONS_LIST_OLD, _newList];
		};
	};

	case "ShowFocusInfoWidget" :
	{
		private _bShow = _params param [0, true, [true]];
		private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		private _widget = if (!isNull _display) then { _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FOCUSINFO } else { controlNull };

		if (!isNull _widget) then
		{
			// Widget may be forced off
			if !(missionNamespace getVariable [VAR_SHOW_FOCUS_INFO, true]) then
			{
				_widget ctrlShow false;
				uiNamespace setVariable [VAR_FOCUS_WIDGET_VISIBLE, false];
			}
			else
			{
				_widget ctrlShow _bShow;
				uiNamespace setVariable [VAR_FOCUS_WIDGET_VISIBLE, _bShow];
			};
		};
	};

	case "IsFocusInfoWidgetVisible" :
	{
		uiNamespace setVariable [VAR_FOCUS_WIDGET_VISIBLE, false];
	};

	/**
	 * Updates focus info widget
	 */
	case "Update_FocusInfoWidget" :
	{
		private _focus = uiNamespace getVariable [VAR_FOCUS, objNull];

		if (!isNull _focus && {missionNamespace getVariable [VAR_SHOW_FOCUS_INFO, true]} && {uiNamespace getVariable [VAR_FOCUS_WIDGET_VISIBLE, false]}) then
		{
			private _newFocusInfo = getPlayerScores _focus;
			private _oldFocusInfo = uiNamespace getVariable [VAR_OLD_FOCUS_INFO, [-1]];

			private ["_name", "_unitTypePicture", "_weapon", "_insigniaTexture"];
			_name = if (isPlayer _focus) then { [_focus, nil, NAME_MAX_CHARACTERS] call BIS_fnc_getName; } else { format ["%1: %2", localize "str_player_ai", [_focus, nil, NAME_MAX_CHARACTERS] call BIS_fnc_getName]; };
			_unitTypePicture = getText (configfile >> "CfgVehicleIcons" >> getText (configfile >> "CfgVehicles" >> typeOf _focus >> "icon"));
			_vehicleTypePicture = getText (configFile >> "CfgVehicles" >> typeOf vehicle _focus >> "Picture");
			_weapon = currentWeapon _focus;
			_insigniaTexture = ["GetGroupTexture", [group _focus]] call BIS_fnc_dynamicGroups;

			private _weaponPicture = if (_weapon != "") then
			{
				getText (configFile >> "CfgWeapons" >> _weapon >> "Picture");
			}
			else
			{
				switch (true) do
				{
					case (commander vehicle _focus == _focus) : 	{ "a3\Ui_f\data\IGUI\Cfg\CommandBar\imageCommander_ca.paa" };
					case (driver vehicle _focus == _focus) : 	{ "a3\Ui_f\data\IGUI\Cfg\CommandBar\imageDriver_ca.paa" };
					case (gunner vehicle _focus == _focus) : 	{ "a3\Ui_f\data\IGUI\Cfg\CommandBar\imageGunner_ca.paa" };
					default 					{ "a3\Ui_f\data\IGUI\Cfg\CommandBar\imageCargo_ca.paa" };
				};
			};

			private ["_kills", "_softKills", "_armoredKills", "_airKills", "_deaths", "_total"];
			_kills = _newFocusInfo param [0, 0, [0]];
			_softKills = _newFocusInfo param [1, 0, [0]];
			_armoredKills = _newFocusInfo param [2, 0, [0]];
			_airKills = _newFocusInfo param [3, 0, [0]];
			_deaths = _newFocusInfo param [4, 0, [0]];
			_total = _newFocusInfo param [5, 0, [0]];

			private ["_display", "_ctrlAvatar", "_ctrlName", "_ctrlUnitType", "_ctrlWeaponPicture", "_ctrlWeaponBackground", "_ctrlKills", "_ctrlSoftKills", "_ctrlArmoredKills", "_ctrlAirKills", "_ctrlDeaths", "_ctrlTotal"];
			_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			_ctrlAvatar = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_AVATAR;
			_ctrlname = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_NAME;
			_ctrlUnitType = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_UNITTYPE;
			_ctrlVehicleType = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_VEHICLETYPE;
			_ctrlWeaponPicture = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_WEAPONPICTURE;
			_ctrlWeaponBackground = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LOWERLEFTBACKGROUND;
			_ctrlKills = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_KILLS_COUNT;
			_ctrlSoftKills = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LANDKILLS_COUNT;
			_ctrlArmoredKills = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_ARMOREDKILLS_COUNT;
			_ctrlAirKills = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_AIRKILLS_COUNT;
			_ctrlDeaths = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_DEATHS_COUNT;
			_ctrlTotal = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TOTAL_COUNT;

			_ctrlAvatar ctrlSetText _insigniaTexture;
			_ctrlname ctrlSetText _name;
			_ctrlWeaponPicture ctrlSettext _weaponPicture;
			_ctrlKills ctrlSettext str _kills;
			_ctrlSoftKills ctrlSettext str _softKills;
			_ctrlArmoredKills ctrlSettext str _armoredKills;
			_ctrlAirKills ctrlSettext str _airKills;
			_ctrlDeaths ctrlSettext str _deaths;
			_ctrlTotal ctrlSettext str _total;

			if (vehicle _focus == _focus) then { _ctrlUnitType ctrlSetText _unitTypePicture; } else { _ctrlUnitType ctrlSetText ""; };
			_ctrlUnitType ctrlShow (vehicle _focus == _focus);
			if (vehicle _focus != _focus) then { _ctrlVehicleType ctrlSetText _vehicleTypePicture; } else { _ctrlVehicleType ctrlSetText ""; };
			_ctrlVehicleType ctrlShow (vehicle _focus != _focus);

			_ctrlWeaponPicture ctrlShow (_weaponPicture != "");
			_ctrlWeaponBackground ctrlShow (_weaponPicture != "");
		};
	};

	case "UpdateCursorObject" :
	{
		private ["_focus", "_oldCursorObject", "_cursorObject", "_whitelist", "_allowAi"];
		_focus			= uiNamespace getVariable [VAR_FOCUS, objNull];
		_oldCursorObject 	= uiNamespace getVariable [VAR_CURSOR_OBJECT, objNull];
		_cursorObject 		= objNull;
		_whitelist		= missionNamespace getVariable [VAR_WHITELISTED_SIDES, []];
		_allowAi		= missionNamespace getVariable [VAR_ALLOW_AI_SWITCH, false];

		private "_intersections";
		_intersections = [getMousePosition select 0, getMousePosition select 1, _focus, vehicle _focus] call BIS_fnc_getIntersectionsUnderCursor;

		if (count _intersections > 0) then
		{
			_cursorObject = (_intersections select 0) select 3;
		};

		if !(_cursorObject isKindOf "Man") then
		{
			if (count crew _cursorObject > 0) then
			{
				_cursorObject = (crew _cursorObject) select 0;
			}
			else
			{
				_cursorObject = objNull;
			};
		};

		if ((_whitelist isEqualTo [] || {side group _cursorObject in _whitelist}) && {_allowAi || {isPlayer _cursorObject}} && {isNil {_cursorObject getVariable VAR_EXCLUDED_UNIT}}) then
		{
			uiNamespace setVariable [VAR_CURSOR_OBJECT, _cursorObject];
		}
		else
		{
			uiNamespace setVariable [VAR_CURSOR_OBJECT, objNull];
		};

		// Focus new object if needed
		if (!isNull _cursorObject && {_oldCursorObject != _cursorObject} && {_whitelist isEqualTo [] || {side group _cursorObject in _whitelist}}) then
		{
			["OnCursorObjectFocused", [_cursorObject]] call DISPLAY;
		};

		// Unfocus old object if needed
		if (!isNull _oldCursorObject && {!alive _cursorObject || {_oldCursorObject != _cursorObject}}) then
		{
			["OnCursorObjectUnfocused", [_oldCursorObject]] call DISPLAY;
		};
	};

	case "GetCursorObject" :
	{
		uiNamespace getVariable [VAR_CURSOR_OBJECT, objNull];
	};

	case "OnCursorObjectFocused" :
	{
		private "_object";
		_object = _params select 0;

		[missionNamespace, "RscDisplayEGSpectator_OnCursorObjectFocused", [_object]] call BIS_fnc_callScriptedEventHandler;
	};

	case "OnCursorObjectUnfocused" :
	{
		private "_object";
		_object = _params select 0;

		[missionNamespace, "RscDisplayEGSpectator_OnCursorObjectUnfocused", [_object]] call BIS_fnc_callScriptedEventHandler;
	};

	case "FindFocus" :
	{
		private _newFocus = objNull;
		private _entities = ["GetTargetEntities"] call SPEC;

		if (count _entities > 0) then
		{
			_newFocus = _entities select 0;
		};

		_newFocus;
	};

	case "GetFocus" :
	{
		uiNamespace getVariable [VAR_FOCUS, objNull];
	};

	case "GetFocusOld" :
	{
		uiNamespace getVariable [VAR_OLD_FOCUS, objNull];
	};

	case "SetFocus" :
	{
		private _newFocus = _params select 0;
		private _oldFocus = ["GetFocus"] call DISPLAY;

		if (_newFocus != _oldFocus && { !isNull _newFocus || { !isNull _oldFocus } }) then
		{
			// Make sure we can be without focus
			if (!isNull _newFocus) then
			{
				uiNamespace setvariable [VAR_FOCUS, _newFocus];
				uiNamespace setvariable [VAR_OLD_FOCUS, _oldFocus];
				["OnFocusChanged", [_newFocus]] call DISPLAY;
			};
		};
	};

	case "OnFocusChanged" :
	{
		private "_newFocus";
		_newFocus = _params param [0, objNull, [objNull]];

		private ["_camera", "_mode"];
		_camera = ["GetCamera"] call CAM;
		_mode = ["GetCameraMode"] call CAM;

		switch (_mode) do
		{
			case MODE_FPS:
			{
				if (isNull _newFocus) then
				{
					["SetCameraMode", [MODE_FREE]] call CAM;
				}
				else
				{
					["SetCameraMode", [_mode]] call CAM;
				};
			};

			case MODE_FOLLOW:
			{
				if (isNull _newFocus) then
				{
					["SetCameraMode", [MODE_FREE]] call CAM;
				}
				else
				{
					["SetCameraMode", [_mode]] call CAM;
				};
			};

			case MODE_FREE:
			{
				if (isNull _newFocus) then
				{
					[] call CAM_RESET_TARGET;
				}
				else
				{
					["SetCameraMode", [_mode]] call CAM;
				};
			};
		};

		// Trigger event
		[missionNamespace, "RscDisplayEGSpectator_OnFocusChanged", [_newFocus]] call BIS_fnc_callScriptedEventHandler;

		// Update controls help status
		["UpdateControlsHelp"] call DISPLAY;

		// Update focus info widget
		if (!isNull _newFocus) then
		{
			["ShowFocusInfoWidget", [true]] call DISPLAY;
			["Update_FocusInfoWidget"] call DISPLAY;
		}
		else
		{
			["TreeUnselect"] call DISPLAY;
			["ShowFocusInfoWidget", [false]] call DISPLAY;
		};
	};

	case "ToggleUiVisibility" :
	{
		scriptName "RscDisplayEGSpectator: ToggleUiVisibility";

		private "_bVisible";
		_bVisible = if (uiNamespace getVariable [VAR_INTERFACE_VISIBLE, true]) then { false } else { true };

		private ["_display", "_controls"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, _display];
		_controls 	= ["GetAllDisplayControls"] call DISPLAY;

		{
			private "_fade";
			_fade = if (_bVisible) then { getNumber (configFile >> "RscDisplayEGSpectator" >> "Controls" >> ctrlClassName _x >> "fade"); } else { 1.0 };

			_x ctrlSetFade _fade;
			_x ctrlCommit 0.25;
		} forEach _controls;

		uiNamespace setVariable [VAR_INTERFACE_VISIBLE, _bVisible];

		if (_bVisible) then
		{
			showChat true;
			playsound "HintCollapse";
		}
		else
		{
			showChat false;
			playsound "HintExpand";
		};

		[missionNamespace, "RscDisplayEGSpectator_OnUiVisibilityChanged", [_bVisible]] call BIS_fnc_callScriptedEventHandler;
	};

	case "IsUiVisible" :
	{
		uiNamespace getVariable [VAR_INTERFACE_VISIBLE, false];
	};

	case "GetAllDisplayControls" :
	{
		scriptName "RscDisplayEGSpectator: GetAllDisplayControls";

		private ["_display", "_controls"];
		_display 	= uiNamespace getVariable [VAR_DISPLAY, _display];
		_controls 	=
		[
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMETIME,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMETIMETEXT,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_CAMERATYPESGROUP,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_SIDEAPROGRESSGROUP,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_SIDEBPROGRESSGROUP,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELP,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELPBACKGROUND,
			_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FOCUSINFO
		];

		if (["GetGamePhase"] call DISPLAY != "") then
		{
			_controls pushBack (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMEPHASE);
			_controls pushBack (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMEPHASETEXT);
		};

		_controls;
	};

	case "KeyDown":
	{
		scriptName "RscDisplayEGSpectator: KeyDown";
		disableSerialization;

		private ["_display", "_key"];
		_display	= _params select 0;
		_key 		= _params select 1;

		switch true do
		{
			case (_key == DIK_ESCAPE): 	{ ["Interrupt"] call DISPLAY; true; };
			case (_key == DIK_M): 		{ ["ToggleMap"] call DISPLAY; true; };
			case (_key == DIK_BACKSPACE): 	{ ["ToggleUiVisibility"] call DISPLAY; true; };
			case (_key == DIK_F1): 		{ ["ToggleControlsHelp"] call DISPLAY; true; };
			case (_key == DIK_PGUP):	{ ["AddViewDistanceInput", [250.0]] call DISPLAY; true; };
			case (_key == DIK_PGDN): 	{ ["AddViewDistanceInput", [-250.0]] call DISPLAY; true; };

			case (_key == DIK_N): 		{ ["ToggleVisionMode"] call CAM; true; };
			case (_key == DIK_SPACE): 	{ ["ToggleCameraMode"] call CAM; true; };
			case (_key == DIK_L): 		{ ["ToggleCameraLights"] call CAM; true; };
			case (_key == DIK_LALT): 	{ ["ToggleVeryFastSpeed", [true]] call CAM; true; };

			default 			{ false; };
		};
	};

	case "KeyUp":
	{
		scriptName "RscDisplayEGSpectator: KeyUp";
		disableSerialization;

		private ["_display", "_key"];
		_display	= _params select 0;
		_key 		= _params select 1;

		switch true do
		{
			case (_key == DIK_LALT): 	{ ["ToggleVeryFastSpeed", [false]] call CAM; true; };

			default 			{ false; };
		};
	};

	case "Interrupt" :
	{
		if (["IsMapVisible"] call DISPLAY) then
		{
			["ToggleMap"] call DISPLAY;
		}
		else
		{
			private _displayType = if (isMultiplayer) then { "RscDisplayMPInterrupt" } else { "RscDisplayInterrupt" };
			private _interrupt = _display createDisplay _displayType;
		};
	};

	case "ToggleControlsHelp" :
	{
		private _current = uiNamespace getVariable [VAR_CONTROLS_HELP_VISIBLE, true];
		["SetControlsHelpVisibility", [!_current]] call DISPLAY;
	};

	case "IsMapVisible" :
	{
		uiNamespace getVariable [VAR_MAP_VISIBLE, false];
	};

	case "ToggleMap" :
	{
		private "_display";
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];

		if (!isNull _display) then
		{
			if !(["IsMapVisible"] call DISPLAY) then
			{
				uiNamespace setVariable [VAR_MAP_VISIBLE, true];
				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAPGROUP) ctrlShow true;

				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAPTITLE) ctrlSetText briefingName;
				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_SPECTATORSCOUNT) ctrlSetText str (["CountSpectators"] call SPEC);

				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAP) ctrlMapAnimAdd [0, 0.05, ["GetCameraPosition"] call CAM];
				ctrlMapAnimCommit (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAP);

				uiNamespace setVariable [VAR_MAP_CLICKED, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAP) ctrlAddEventHandler ["MouseButtonClick", { ["OnMapClicked", _this] call DISPLAY; }]];
				uiNamespace setVariable [VAR_MAP_DRAW, (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAP) ctrlAddEventHandler ["Draw", { _this call SPEC_DRAW2D; ["DrawMap", _this] call DISPLAY; }]];
			}
			else
			{
				uiNamespace setVariable [VAR_MAP_VISIBLE, false];
				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAPGROUP) ctrlShow false;

				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAP) ctrlRemoveEventHandler ["MouseButtonClick", uiNamespace getVariable [VAR_MAP_CLICKED, -1]];
				uiNamespace setVariable [VAR_MAP_CLICKED, nil];

				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAP) ctrlRemoveEventHandler ["Draw", uiNamespace getVariable [VAR_MAP_DRAW, -1]];
				uiNamespace setVariable [VAR_MAP_DRAW, nil];

				ctrlSetFocus (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST);
			};

			// Reset highlighted object
			uiNamespace setVariable [VAR_MAP_HIGHLIGHTED_OBJECT, objNull];

			// Trigger scripted event handler
			[missionNamespace, "RscDisplayEGSpectator_MapStateChanged", [["IsMapVisible"] call DISPLAY]] call BIS_fnc_callScriptedEventHandler;
		};
	};

	case "DrawMap" :
	{
		private "_map";
		_map = _params select 0;

		if (!isNull _map) then
		{
			private ["_display", "_camera"];
			_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			_camera = missionNamespace getVariable [VAR_CAMERA, objNull];

			if (!isNull _display && !isNull _camera) then
			{
				private ["_loc", "_entities", "_nearestEntity", "_text", "_minDist"];
				_loc = _map ctrlMapScreenToWorld getMousePosition;
				_entities = [];
				_nearestEntity = objNull;
				_text = "";
				_minDist = 999999;

				{
					private "_dist";
					_dist = _x distance2D _loc;

					if (_dist < _minDist && { alive _x } && { _dist < MAP_MIN_ENTITY_DISTANCE } && { simulationEnabled _x } && { !(isObjectHidden _x) }) then
					{
						_minDist = _dist;
						_nearestEntity = _x;
					};
				} forEach allUnits;

				if (!isNull _nearestEntity) then
				{
					if (isPlayer _nearestEntity) then
					{
						_text = format ["%1 [%2 m]", [_nearestEntity, nil, NAME_MAX_CHARACTERS] call BIS_fnc_getName, round (_nearestEntity distance _camera)];
					}
					else
					{
						_text = format ["%1: %2 [%3 m]", localize "str_player_ai", [_nearestEntity, nil, NAME_MAX_CHARACTERS] call BIS_fnc_getName, round (_nearestEntity distance _camera)];
					};

					uiNamespace setVariable [VAR_MAP_HIGHLIGHTED_OBJECT, _nearestEntity];
				}
				else
				{
					uiNamespace setVariable [VAR_MAP_HIGHLIGHTED_OBJECT, objNull];
				};

				(_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MAPFOOTER) ctrlSetText _text;
			};
		};
	};

	case "OnMapClicked" :
	{
		scriptName "RscDisplayEGSpectator: OnMapClicked";

		private ["_map", "_button", "_x", "_y"];
		_map = _params select 0;
		_button = _params select 1;
		_x = _params select 2;
		_y = _params select 3;

		private ["_camera", "_highlightedObject"];
		_camera = ["GetCamera"] call CAM;
		_highlightedObject = uiNamespace getVariable [VAR_MAP_HIGHLIGHTED_OBJECT, objNull];

		if (!isNull _camera) then
		{
			if (!isNull _highlightedObject) then
			{
				["TreeSelectFromData", [[_highlightedObject] call BIS_fnc_objectVar]] call DISPLAY;
				[_highlightedObject] call CAM_PREPARE_TARGET;
				playsound "ReadoutClick";
			}
			else
			{
				if (!isNull (["GetFocus"] call DISPLAY)) then
				{
					playsound "ReadoutHideClick1";
				};

				["SetFocus", [objNull]] call DISPLAY;

				private _pos = _map ctrlMapScreenToWorld [_x - 0.1, _y - 0.04];
				_pos set [2, (getPosASLVisual _camera) select 2];

				_camera setPosASL _pos;
			};
		};
	};

	case "MouseButtonDown" :
	{
		scriptName "RscDisplayEGSpectator: MouseButtonDown";
		disableSerialization;

		private ["_control", "_key"];
		_control	= _params select 0;
		_key 		= _params select 1;

		switch (_key) do
		{
			// Left mouse button
			case 0 :
			{
				private "_cursorObject";
				_cursorObject = ["GetCursorObject"] call DISPLAY;

				if (!isNull _cursorObject) then
				{
					["TreeSelectFromData", [[_cursorObject] call BIS_fnc_objectVar]] call DISPLAY;
					playsound "ReadoutClick";
					setMousePosition [0.5, 0.5];
				}
				else
				{
					if (!isNull (["GetFocus"] call DISPLAY)) then
					{
						playsound "ReadoutHideClick1";
					};

					["SetFocus", [objNull]] call DISPLAY;
				};
			};

			// Right mouse button
			case 1 :
			{
				private ["_cameraMode", "_dummy", "_focus"];
				_cameraMode = ["GetCameraMode"] call CAM;
				_dummy = ["GetDummyTarget"] call CAM;
				_focus = ["GetFocus"] call DISPLAY;

				if (_cameraMode == MODE_FREE && { !isNull _focus } && { !isNull (attachedTo _dummy) }) then
				{
					[] call CAM_RESET_TARGET;
				};
			};
		};

		if (_key == 1) then
		{
			uiNamespace setVariable [VAR_IS_HOLDING_RIGHT_M_BUTTON, true];
		};
	};

	case "MouseButtonUp" :
	{
		scriptName "RscDisplayEGSpectator: MouseButtonUp";
		disableSerialization;

		private ["_control", "_key"];
		_control	= _params select 0;
		_key 		= _params select 1;

		if (_key == 1) then
		{
			uiNamespace setVariable [VAR_IS_HOLDING_RIGHT_M_BUTTON, false];
		};
	};

	case "MouseButtonDblClick" :
	{
		scriptName "RscDisplayEGSpectator: MouseButtonDblClick";
		disableSerialization;

		private ["_control", "_key"];
		_control	= _params select 0;
		_key 		= _params select 1;

		if (_key == 0) then
		{
			private "_cursorObject";
			_cursorObject = ["GetCursorObject"] call DISPLAY;

			if (!isNull _cursorObject) then
			{
				[_cursorObject] call CAM_PREPARE_TARGET;
			};
		};
	};

	case "MouseZChanged" :
	{
		private ["_control", "_change"];
		_control = _params select 0;
		_up = (_params select 1) > 0;

		private "_cameraMode";
		_cameraMode = ["GetCameraMode"] call CAM;

		if (_cameraMode == MODE_FOLLOW) then
		{
			if (_up) then
			{
				["AddZoomInput", [-1.0]] call CAM;
			}
			else
			{
				["AddZoomInput", [1.0]] call CAM;
			};
		};
	};

	case "MouseMoving" :
	{
		if (["GetCameraMode"] call CAM == MODE_FOLLOW && { uiNamespace getVariable [VAR_IS_HOLDING_RIGHT_M_BUTTON, false] }) then
		{
			private ["_display", "_deltaX", "_deltaY"];
			_display = _params select 0;
			_deltaX = _params select 1;
			_deltaY = _params select 2;

			private _deltaTime = missionNamespace getVariable [VAR_CAMERA_DELTA_TIME, 1.0];

			if (_deltaX != 0.0) then
			{
				["AddYawInput", [_deltaX * 100 * _deltaTime]] call CAM;
			};

			if (_deltaY != 0.0) then
			{
				["AddPitchInput", [_deltaY * 100 * _deltaTime]] call CAM;
			};
		};
	};

	case "ChildDestroyed":
	{
		scriptName "RscDisplayEGSpectator: ChildDestroyed";
		disableSerialization;

		private ["_display", "_child", "_exitCode"];
		_display	= _params select 0;
		_child 		= _params select 1;
		_exitCode	= _params select 2;

		if (_exitCode == 104) then
		{
			_display closeDisplay 2;
			(findDisplay 46) closeDisplay 2;
		};
	};

	case "ShowList" :
	{
		if (uiNamespace getVariable [VAR_INTERFACE_VISIBLE, true]) then
		{
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _list = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;
			private _tabs = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS;

			_list ctrlSetBackgroundColor [0,0,0,0.75];
			_list ctrlSetFade 0.0;
			_list ctrlCommit 0.2;

			_tabs ctrlSetBackgroundColor [0,0,0,0.25];
			_tabs ctrlSetFade 0.0;
			_tabs ctrlCommit 0.2;

			showChat false;
		};
	};

	case "HideList" :
	{
		if (uiNamespace getVariable [VAR_INTERFACE_VISIBLE, true]) then
		{
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _mouseHandler = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_MOUSEHANDLER;
			private _list = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;
			private _tabs = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_TABS;

			_list ctrlSetBackgroundColor [0,0,0,0];
			_list ctrlSetFade 0.8;
			_list ctrlCommit 0.2;

			_tabs ctrlSetBackgroundColor [0,0,0,0];
			_tabs ctrlSetFade 0.5;
			_tabs ctrlCommit 0.2;

			showChat true;
		};
	};

	case "TreeClicked" :
	{
		private _doubleClickTime = missionNamespace getVariable [VAR_DOUBLE_CLICK_TIME, 0];

		if (time > _doubleClickTime + DOUBLE_CLICK_DELAY) then
		{
			private ["_ctrl", "_index"];
			_ctrl = _params select 0;
			_index = _params select 1;

			private ["_data", "_object", "_location", "_cameraMode"];
			_data = _ctrl tvData _index;
			_object	= missionNamespace getVariable [_data, objNull];
			_location = ["GetLocationById", [_data]] call SPEC;
			_cameraMode = ["GetCameraMode"] call CAM;

			// Entity
			if (!isNull _object) then
			{
				if (_cameraMode == MODE_FREE) then
				{
					["SetFocus", [_object]] call DISPLAY;
					playsound "ReadoutClick";
				}
				else
				{
					["SetFocus", [_object]] call DISPLAY;
					[_object] call CAM_PREPARE_TARGET;
					playsound "ReadoutClick";
				};
			}
			// Location
			else
			{
				private "_camera";
				_camera = missionNamespace getVariable ["BIS_EGSpectator_camera", objNull];

				if (!isNull _camera && count _location > 0) then
				{
					private ["_id", "_description", "_texture", "_cameraTransform", "_dirOverride"];
					_id 			= _location param [0, "", [""]];
					_name 			= _location param [1, "", [""]];
					_description 		= _location param [2, "", [""]];
					_texture		= _location param [3, "", [""]];
					_cameraTransform 	= _location param [4, [[], [], [], []], [[]]];

					// Set camera target
					[] call CAM_RESET_TARGET;

					// Reset focus
					["SetFocus", [objNull]] call DISPLAY;

					private "_dummy";
					_dummy = ["GetDummyTarget"] call CAM;
					detach _dummy;
					_dummy setPosASL (_cameraTransform select 0);

					// Set new target
					[_dummy] call CAM_SET_TARGET;
				};
			};
		};
	};

	case "TreeDblClicked" :
	{
		private ["_ctrl", "_index"];
		_ctrl = _params select 0;
		_index = _params select 1;

		private ["_data", "_object", "_location"];
		_data = _ctrl tvData _index;
		_object	= missionNamespace getVariable [_data, objNull];
		_location = ["GetLocationById", [_data]] call SPEC;

		// Entity
		if (!isNull _object) then
		{
			["SetFocus", [_object]] call DISPLAY;
			[_object] call CAM_PREPARE_TARGET;
			playsound "ReadoutClick";
		}
		// Location
		else
		{
			if (count _location > 0) then
			{
				private ["_id", "_description", "_texture", "_cameraTransform", "_dirOverride"];
				_id 			= _location param [0, "", [""]];
				_name 			= _location param [1, "", [""]];
				_description 		= _location param [2, "", [""]];
				_texture		= _location param [3, "", [""]];
				_cameraTransform 	= _location param [4, [[], [], [], []], [[]]];

				// Reset focus
				["SetFocus", [objNull]] call DISPLAY;

				// Set camera transformation defined by selected location
				["SetCameraTransform", _cameraTransform] call CAM;

				// Location info text
				[parseText format [ "<t align='right' size='1.2'><t font='PuristaBold' size='1.6'>""%1""</t><br/>%2</t>", _name, _description], true, nil, 7, 0.7, 0] spawn BIS_fnc_textTiles;

				// Store last double click time
				// This is used to not allow click if double click just happened
				missionNamespace setVariable [VAR_DOUBLE_CLICK_TIME, time];
			};
		};
	};

	case "GetTreeSelectedPlayer" :
	{
		private ["_display", "_ctrl", "_index", "_data", "_object"];
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_ctrl = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;
		_index = tvCurSel _ctrl;
		_data = _ctrl tvData _index;
		_object = missionNamespace getVariable [_data, objNull];

		_object;
	};

	case "GetTreeSelectedLocation" :
	{
		private ["_display", "_ctrl", "_index", "_data", "_location"];
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_ctrl = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;
		_index = tvCurSel _ctrl;
		_data = _ctrl tvData _index;
		_location = ["GetLocationById", [_data]] call SPEC;

		_location;
	};

	case "TreeSelectFromData" :
	{
		private _data = _params param [0, "", [""]];

		// Make sure data is not empty
		if (_data != "") then
		{
			// Get the list box control
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

			if (!isNull _control) then
			{
				private _index = ["TreeGetDataIndex", [_data]] call DISPLAY;

				// Make sure we have a valid index
				if !(_index isEqualTo []) then
				{
					_control tvSetCurSel _index;
				};
			};
		};
	};

	case "TreeUnselect" :
	{
		private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

		if (!isNull _control) then
		{
			_control tvSetCurSel [-1];
		};
	};

	case "TreeClear" :
	{
		private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

		if (!isNull _control) then
		{
			tvClear _control;
		};
	};

	case "TreeUpdateElement" :
	{
		_params params
		[
			["_data", "", [""]],
			["_text", "", [""]],
			["_picture", "", [""]],
			["_pictureColor", [0,0,0,0], [[]]],
			["_tooltip", "", [""]]
		];

		// Make sure data is not empty
		if (_data != "") then
		{
			// Get the list box control
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

			if (!isNull _control) then
			{
				private _index = ["TreeGetDataIndex", [_data]] call DISPLAY;

				if !(_index isEqualTo []) then
				{
					_control tvSetText [_index, _text];
					_control tvSetPicture [_index, _picture];
					_control tvSetPictureColor [_index, _pictureColor];
					_control tvSetTooltip [_index, _tooltip];
				};
			};
		};
	};

	case "TreeDeleteItem" :
	{
		private _data = _params param [0, "", [""]];

		// Make sure data is not empty
		if (_data != "") then
		{
			// Get the list box control
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

			if (!isNull _control) then
			{
				for "_i" from 0 to ((_control tvCount []) - 1) do
				{
					if (_control tvData [_i] == _data) exitWith
					{
						_control tvDelete [_i];
					};
				};
			};
		};
	};

	case "TreeDeleteGroup" :
	{
		private _data = _params param [0, "", [""]];

		// Make sure data is not empty
		if (_data != "") then
		{
			// Get the list box control
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

			if (!isNull _control) then
			{
				for "_i" from 0 to ((_control tvCount []) - 1) do
				{
					for "_a" from 0 to ((_control tvCount [_i]) - 1) do
					{
						if (_control tvData [_i, _a] == _data) exitWith
						{
							_control tvDelete [_i, _a];
						};
					};
				};
			};
		};
	};

	case "TreeDeleteUnit" :
	{
		private _data = _params param [0, "", [""]];

		// Make sure data is not empty
		if (_data != "") then
		{
			// Get the list box control
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

			if (!isNull _control) then
			{
				for "_i" from 0 to ((_control tvCount []) - 1) do
				{
					for "_a" from 0 to ((_control tvCount [_i]) - 1) do
					{
						for "_b" from 0 to ((_control tvCount [_i, _a]) - 1) do
						{
							if (_control tvData [_i, _a, _b] == _data) exitWith
							{
								_control tvDelete [_i, _a, _b];
							};
						};
					};
				};
			};
		};
	};

	case "TreeGetDataIndex" :
	{
		private _data = _params param [0, "", [""]];

		// Our resulting index
		private _index = [];

		// Make sure data is not empty
		if (_data != "") then
		{
			// Get the list box control
			private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
			private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

			if (!isNull _control) then
			{
				// Sides
				for "_i" from 0 to ((_control tvCount []) - 1) do
				{
					if (_control tvData [_i] == _data) exitWith {_index = [_i]};

					// Groups
					for "_a" from 0 to ((_control tvCount [_i]) - 1) do
					{
						if (_control tvData [_i, _a] == _data) exitWith {_index = [_i, _a]};

						// Units
						for "_b" from 0 to ((_control tvCount [_i, _a]) - 1) do
						{
							if (_control tvData [_i, _a, _b] == _data) exitWith {_index = [_i, _a, _b]};
						};
					};
				};
			};
		};

		_index;
	};

	case "TreeGetAllElements" :
	{
		private _elements = [[], [], []];

		private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

		if (!isNull _control) then
		{
			// Sides
			for "_i" from 0 to ((_control tvCount []) - 1) do
			{
				(_elements select 0) pushBack (_control tvData [_i]);

				// Groups
				for "_a" from 0 to ((_control tvCount [_i]) - 1) do
				{
					(_elements select 1) pushBack (_control tvData [_i, _a]);

					// Units
					for "_b" from 0 to ((_control tvCount [_i, _a]) - 1) do
					{
						(_elements select 2) pushBack (_control tvData [_i, _a, _b]);
					};
				};
			};
		};

		_elements;
	};

	case "TreeLog" :
	{
		// Get the list box control
		private _display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		private _control = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_LIST;

		if (!isNull _control) then
		{
			// Sides
			for "_i" from 0 to ((_control tvCount []) - 1) do
			{
				["%1 (%2)", _control tvText [_i], _control tvData [_i]] call BIS_fnc_logFormat;

				// Groups
				for "_a" from 0 to ((_control tvCount [_i]) - 1) do
				{
					["  %1 (%2)", _control tvText [_i, _a], _control tvData [_i, _a]] call BIS_fnc_logFormat;

					// Units
					for "_b" from 0 to ((_control tvCount [_i, _a]) - 1) do
					{
						["    %1 (%2)", _control tvText [_i, _a, _b], _control tvData [_i, _a, _b]] call BIS_fnc_logFormat;
					};
				};
			};
		};
	};

	case "CamButtonClicked" :
	{
		private "_ctrl";
		_ctrl = _params select 0;

		private "_display";
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];

		switch (_ctrl) do
		{
			case (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FREE) : { ["SetCameraMode", [MODE_FREE]] call CAM; };
			case (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FOLLOW) : { ["SetCameraMode", [MODE_FOLLOW]] call CAM; };
			case (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FPS) : { ["SetCameraMode", [MODE_FPS]] call CAM; };
		};
	};

	case "SpectatorCameraModeChanged" :
	{
		private "_newMode";
		_newMode = _params select 0;

		private "_display";
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];

		["ResetCameraButtonsState"] call DISPLAY;

		switch (_newMode) do
		{
			case MODE_FREE : { (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FREE) ctrlSetText CAM_ICON_FREE_SELECTED; };
			case MODE_FOLLOW : { (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FOLLOW) ctrlSetText CAM_ICON_FOLLOW_SELECTED; };
			case MODE_FPS : { (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FPS) ctrlSetText CAM_ICON_FPS_SELECTED; };
		};

		// Update controls help status
		["UpdateControlsHelp"] call DISPLAY;
	};

	case "ResetCameraButtonsState" :
	{
		private "_display";
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];

		{
			private "_control";
			_control = _display displayCtrl _x;

			switch (_control) do
			{
				case (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FREE) : { _control ctrlSetText CAM_ICON_FREE; };
				case (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FOLLOW) : { _control ctrlSetText CAM_ICON_FOLLOW; };
				case (_display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_FPS) : { _control ctrlSetText CAM_ICON_FPS; };
			};
		} forEach [IDC_RSCDISPLAYEGSPECTATOR_FREE, IDC_RSCDISPLAYEGSPECTATOR_FOLLOW, IDC_RSCDISPLAYEGSPECTATOR_FPS];
	};

	/**
	 * A tab was selected
	 * Could mean Entities or locations selected
	 */
	case "OnTabSelected" :
	{
		private ["_ctrl", "_index"];
		_ctrl = _params select 0;
		_index = _params select 1;

		if (_index == 0) then
		{
			uiNamespace setVariable [VAR_LIST_TYPE, LIST_ENTITIES];
			uiNamespace setVariable [VAR_ENTITIES_LIST_OLD, nil];

			// Clear list
			["TreeClear"] call DISPLAY;

			// Force initial update
			["Update_PlayerList"] call DISPLAY;
		}
		else
		{
			uiNamespace setVariable [VAR_LIST_TYPE, LIST_LOCATIONS];
			uiNamespace setVariable [VAR_LOCATIONS_LIST_OLD, nil];

			// Clear list
			["TreeClear"] call DISPLAY;

			// Force initial update
			["Update_LocationList"] call DISPLAY;
		};
	};

	/**
	 * Set's the desired game phase, shown on UI
	 */
	case "SetGamePhase" :
	{
		private "_phase";
		_phase = _params select 0;

		if (_phase != uiNamespace getVariable [VAR_GAME_PHASE, ""]) then
		{
			uiNamespace setVariable [VAR_GAME_PHASE, _phase];
			["OnGamePhaseChanged", [_phase]] call DISPLAY;
		};
	};

	/**
	 * Get's the game phase, shown on UI
	 */
	case "GetGamePhase" :
	{
		uiNamespace getVariable [VAR_GAME_PHASE, ""];
	};

	/**
	 * On game phase changed
	 */
	case "OnGamePhaseChanged" :
	{
		private "_phase";
		_phase = _params select 0;

		private "_bUiVisible";
		_bUiVisible = uiNamespace getVariable [VAR_INTERFACE_VISIBLE, true];

		private ["_display", "_text"];
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_text = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_GAMEPHASETEXT;

		if (!isNull _display) then
		{
			if (_phase == "" || !_bUiVisible) then
			{
				_text ctrlSetFade 1.0;
				_text ctrlSetText _phase;
				_text ctrlSetFade 1.0;
				_text ctrlCommit 0.25;
			}
			else
			{
				private ["_fadeBackground", "_fadeText"];
				_fadeBackground = getNumber (configFile >> "RscDisplayEGSpectator" >> "Controls" >> ctrlClassName _text >> "fade");
				_fadeText = getNumber (configFile >> "RscDisplayEGSpectator" >> "Controls" >> ctrlClassName _text >> "fade");

				_text ctrlSetFade _fadeBackground;
				_text ctrlSetText _phase;
				_text ctrlSetFade _fadeText;
				_text ctrlCommit 0.25;
			};
		};
	};

	case "AddViewDistanceInput" :
	{
		private _amount = _params param [0, 0, [0]];
		private _viewDistance = viewDistance + _amount;

		if (_viewDistance > MAX_VIEW_DISTANCE) then
		{
			_viewDistance = MAX_VIEW_DISTANCE;
		};

		if (_viewDistance < MIN_VIEW_DISTANCE) then
		{
			_viewDistance = MIN_VIEW_DISTANCE;
		};

		setViewDistance _viewDistance;
	};

	case "SetHeadToHeadVisibility" :
	{
		private _visible = _params param [0, false, [false]];

		private ["_display", "_a", "_b"];
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_a = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_SIDEAPROGRESSGROUP;
		_b = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_SIDEBPROGRESSGROUP;

		_a ctrlShow _visible;
		_b ctrlShow _visible;

		uiNamespace setVariable [VAR_HEAD_TO_HEAD_SHOWN, _visible];
	};

	case "SetSideTask" :
	{
		private ["_side", "_task"];
		_side = _params param [0, 0, [0]];
		_task = _params param [1, "", [""]];

		private ["_display", "_control"];
		_display = uiNamespace getVariable [VAR_DISPLAY, displayNull];
		_control = _display displayCtrl (if (_side == 0) then { IDC_RSCDISPLAYEGSPECTATOR_SIDEATASK } else { IDC_RSCDISPLAYEGSPECTATOR_SIDEBTASK });

		_control ctrlSetText _task;

		if (_side == 0) then
		{
			uiNamespace setVariable [VAR_SIDE_A_TASK, _task];
		}
		else
		{
			uiNamespace setVariable [VAR_SIDE_B_TASK, _task];
		};

		["FlashSideTask", [_side]] call DISPLAY;
	};

	case "FlashSideTask" :
	{
		private _side = _params param [0, 0, [0]];
		private _var = if (_side == 0) then { VAR_SIDE_A_FLASHING; } else { VAR_SIDE_B_FLASHING; };

		if (!isNil { uiNamespace getVariable _var }) then
		{
			terminate (uiNamespace getVariable _var);
			uiNamespace setVariable [_var, nil];
		};

		uiNamespace setVariable [_var, ["FlashSideTaskThread", [_side, _var]] spawn DISPLAY];
	};

	case "FlashSideTaskThread" :
	{
		disableSerialization;
		scriptName "RscDisplayEGSpectator: FlashSideTaskThread";

		private _side = _params param [0, 0, [0]];
		private _var = _params param [1, "", [""]];

		private _idcBackground = if (_side == 0) then { IDC_RSCDISPLAYEGSPECTATOR_SIDEABACKGROUND } else { IDC_RSCDISPLAYEGSPECTATOR_SIDEBBACKGROUND };
		private _idcText = if (_side == 0) then { IDC_RSCDISPLAYEGSPECTATOR_SIDEATASK } else { IDC_RSCDISPLAYEGSPECTATOR_SIDEBTASK };

		private _display = ["GetDisplay"] call DISPLAY;
		private _ctrlBackground = _display displayCtrl _idcBackground;
		private _ctrlText = _display displayCtrl _idcText;

		private _min = 0.0;
		private _max = 1.0;
		private _alpha = _max;
		private _goingDown = true;

		private _colorDefault = [0.0, 0.0, 0.0];
		private _colorTarget = [1.0, 1.0, 1.0];

		private _maxIterations = 3;
		private _iterations = 1;

		while { true } do
		{
			if (!_goingDown && _alpha < _max) then
			{
				_alpha = _alpha + 0.025;

				if (_alpha > _max) then
				{
					_alpha = _max;
				};
			};

			if (_goingDown && _alpha > _min) then
			{
				_alpha = _alpha - 0.025;

				if (_alpha <= _min) then
				{
					_alpha = _min;
					_goingDown = false;
				};
			};

			private _colorBackground = _colorDefault vectorAdd ((_colorTarget vectorDiff _colorDefault) vectorMultiply _alpha);
			private _colorText = _colorDefault vectorAdd ((_colorTarget vectorDiff _colorDefault) vectorMultiply (1.0 - _alpha));

			_colorBackground pushBack 0.5;
			_colorText pushBack 1.0;

			_ctrlBackground ctrlSetBackgroundColor _colorBackground;
			_ctrlText ctrlSetTextColor _colorText;

			if (!_goingDown && _alpha == _max && _iterations < _maxIterations) then
			{
				_goingDown = true;
				_iterations = _iterations + 1;
			};

			if (!_goingDown && _alpha == _max && _iterations >= _maxIterations) exitWith {};

			sleep 0.01;
		};

		_ctrlBackground ctrlSetBackgroundColor [0,0,0,0.5];
		_ctrlText ctrlSetTextColor [1,1,1,1];
		uiNamespace setVariable [_var, nil];
	};

	case "SetControlsHelpVisibility" :
	{
		private _bVisible = _params param [0, true, [true]];

		private _display = ["GetDisplay"] call DISPLAY;
		private _background = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELPBACKGROUND;
		private _help = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELP;

		uiNamespace setVariable [VAR_CONTROLS_HELP_VISIBLE, _bVisible];

		if (_bVisible) then
		{
			_background ctrlShow true;
			_help ctrlShow true;
			["UpdateControlsHelp"] call DISPLAY;
		}
		else
		{
			_background ctrlShow false;
			_help ctrlShow false;
		};
	};

	case "UpdateControlsHelp" :
	{
		private _display = ["GetDisplay"] call DISPLAY;
		private _background = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELPBACKGROUND;
		private _help = _display displayCtrl IDC_RSCDISPLAYEGSPECTATOR_HELP;
		private _hasFocus = !isNull (["GetFocus"] call DISPLAY);
		private _cameraMode = ["GetCameraMode"] call CAM;
		private _allowFreeCamera = missionNamespace getVariable [VAR_ALLOW_FREE_CAMERA, true];
		private _x = uiNamespace getVariable [VAR_DEFAULT_HELP_X, (ctrlPosition _help) select 0];
		private _y = uiNamespace getVariable [VAR_DEFAULT_HELP_Y, (ctrlPosition _help) select 1];
		private _w = uiNamespace getVariable [VAR_DEFAULT_HELP_W, (ctrlPosition _help) select 2];
		private _h = uiNamespace getVariable [VAR_DEFAULT_HELP_H, (ctrlPosition _help) select 3];
		private _amount = _h / MAX_CONTROLS_HELP_ENTRIES;

		private _count = 0;
		private _controls = [];

		if (_cameraMode != MODE_FPS && {_cameraMode != MODE_FREE || {_allowFreeCamera}}) then
		{
			_controls pushback ["[RMB]", "Camera Rotation"];	// TODO: Localize
		};

		if (_hasFocus) then
		{
			_controls pushBack ["[LMB]", "Unfocus"];		// TODO: Localize
			_controls pushBack ["[SPACE]", "Camera Mode"];		// TODO: Localize
		}
		else
		{
			_controls pushBack ["[LMB]", "Focus"];			// TODO: Localize
		};

		if (_cameraMode == MODE_FREE && {_allowFreeCamera}) then
		{
			_controls pushback ["[W/S]", "Movement"];		// TODO: Localize
			_controls pushback ["[A/D]", "Strafing"];		// TODO: Localize
			_controls pushback ["[Q/Z]", "Height"];			// TODO: Localize
		};

		_controls pushback ["[BACK]", "Interface"];			// TODO: Localize
		_controls pushback ["[F1]", "Controls"];			// TODO: Localize

		if (count _controls > MAX_CONTROLS_HELP_ENTRIES) then
		{
			_controls resize MAX_CONTROLS_HELP_ENTRIES;
		};

		_help ctrlEnable false;
		_help lnbSetColumnsPos [0, 0.3];
		lnbClear _help;

		{
			_help lnbAddRow [_x select 0, _x select 1];
			_help lnbSetColor [[_forEachIndex, 0], [0.75,0.6,0,1]];
		} forEach _controls;

		private _newH = _amount * count _controls;
		private _newY = safezoneY + safezoneH - _newH;
		private _newW = _w;
		private _newX = safezoneX + safezoneW - _newW;

		{
			_x ctrlSetPosition [_newX, _newY, _newW, _newH];
			_x ctrlCommit 0.15;
		} forEach [_background, _help];
	};

	/**
	 * Unknown mode
	 */
	default
	{
		scriptName "RscDisplayEGSpectator: Default";

		["Unknown mode: %1", _mode] call BIS_fnc_error;
	};
};