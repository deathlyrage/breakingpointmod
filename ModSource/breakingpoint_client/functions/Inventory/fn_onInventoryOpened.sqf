/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//unit: Object - Object the event handler is assigned to
//container: Object - connected container or weaponholder
//return: return true to override default inventory functionality.

//Close Any Other Open Dialogs
//closeDialog 0;

//Undead Players Can't Access Inventory
//if (BP_isUndead) exitWith {true};

//Players who have Inventory Disallowed Can't Access Inventory
//if (!BP_AllowInventory) exitWith {true};

params ["_unit","_container"];

_return = false;
_restrictedInventory = false;

// Check Nearby Safes / House Storage Objects
//_safeObj = objNull;
//_nearHouse = false;
//_nearSafe = false;

//_objects = nearestObjects [getPosATL _unit, ["BP_Storage"], 8];
//{
//	if (_x isKindOf "BP_Safe") then { _nearSafe = true; _container = _x; };	
//	if (_x isKindOf "BP_HouseStorage") then { _nearHouse = true; _container = _x; };	
//} count _objects;

//Magazine Check
call BP_fnc_magazineCheck;

["onInventoryOpened: Unit: %1 | Container: %2",_unit,_container] call BP_fnc_debugConsoleFormat;

//Unconscious Players Can't Open Inventory
if (r_player_unconscious) exitWith {true};

//Check Nearby Players
//_nearbyPlayers = [(getPosATL _unit),5] call BP_fnc_nearbyPlayersList;
//_nearbyPlayers = _nearbyPlayers - [_unit];
//if (count _nearbyPlayers > 0) then { _restrictedInventory = true; };

//Valid Container / Weapon Holder
if !(isNull _container) then 
{
	if (_container isKindOf "CAManBase" && {!(_container isKindOf "Animal")} && {!(_container isKindOf "zZombie_Base")}) then {
		_restrictedInventory = true;
		cutText ["You need to use Loot Remains Action to access the inventory of this body.","PLAIN DOWN"];
	};

	//Check if AI Grave or Not
	//if (_container isKindOf "BP_DeadBodyAI") then
	//{
	//	if (BP_FactionStronghold > 0) then
	//	{
	//		//Check if Player is Friendly with AI not Not.
	//		if (side player == civilian) then {
	//			//FLag Player as Traitor
	//			player setVariable ["traitorFlag",true,true];
	//			
	//			//Check Strongholds
	//			call BP_fnc_strongholdCheck;
	//			
	//			//Check Faction Specific Clothing
	//			call BP_fnc_checkFactionClothing;
	//		};
	//	};
	//};
	
	//Check If Backpack in a Stronghold or Not
	//if (BP_FactionStronghold > 0) then
	//{
	//	if ((_container isKindOf "BP_Bag_Base") and (_container != backpackContainer _unit)) then 
	//	{
	//		//_return = true;
	//		_restrictedInventory = true;
	//		cutText ["Backpack access restricted within Faction Territory.","PLAIN DOWN"];
	//	};
	//};
	
	//Simulation Is Enabled
	//if (simulationEnabled _container) then 
	//{
	
	//Safe
	if (_container isKindOf "BP_Safe") then  // || _nearSafe
	{
		_locked = _container getVariable ["locked",false];
		if (_locked) then {
			[_unit,_container] spawn BP_fnc_safeKeypad;
			//_restrictedInventory = true;
			_return = true;
			//cutText ["This object is locked. Unlock the Safe to access it.","PLAIN DOWN"];
		} else {
			_return = false;
		};
	};
	
	//House Storage
	//if (_container isKindOf "BP_HouseStorage" || _nearHouse) then
	//{
	//	_building = nearestObject [_unit, "HouseBase"];
	//	if (!isNull _building) then
	//	{
	//		if ((_building distance _unit) < 30) then
	//		{
	//			_buildingLocked = (_building getVariable ['bis_disabled_Door_1',0] == 1);
	//			if (_buildingLocked) then 
	//			{
	//				cutText ["This object is locked. Unlock the Building to access it.","PLAIN DOWN"];
	//				_restrictedInventory = true;
	//			};
	//		};
	//	};
	//};

	//} else {
	//	[_unit,_container,_nearHouse,_nearSafe] spawn
	//	{
	//		//Fetch Container and Unit Data
	//		_unit = _this select 0;
	//		_container = _this select 1;
	//		_nearHouse = _this select 2;
	//		_nearSafe = _this select 3;
    //
	//		//RPC Call To Enable Simulation
	//		//BP_Simulation = [(netID _container),true];
	//		//publicVariableServer "BP_Simulation";
	//		
	//		//Wait Until the Server Toggles Simulation
	//		waitUntil {simulationEnabled _container};
	//		
	//		//Open Player Inventory on Object
	//		if (!_nearHouse && {!_nearSafe}) then { _unit action ["Gear", _container]; };
	//	};
	//	_return = true;
	//};
};

_isAlive = (alive _container);
_isMan = (_container isKindOf "zZombie_Base");
_isZombie = (_container isKindOf "Man");

if (_isMan && {!_isZombie} && {!_isAlive}) then { _return = false; };

//player removeAllEventHandlers "InventoryOpened";
//_box = "Box_NATO_Ammo_F" createVehicle [0,0,0];
//_box setPos (player modelToWorld [0,1.5,0.5]);
//player action ["Gear", _box];
//true //<-- inventory override

//Play Inventory Open Sounds
if (!_return) then 
{
	//Inform the Server of Container Opening
	[(netID _container)] remoteExecCall ["BPServer_fnc_containerOpened",2];
	
	//BP_ContainerOpened = [(netID _container),(netID _unit)];
	//
	//if (!BP_WaitingForContainer && {_container isKindOf "BP_LootBox"}) exitWith
	//{
	//	_return = true;
	//	BP_ContainerOpened = [(netID _container)];
	//	publicVariableServer "BP_ContainerOpened";	
	//	[_unit,_container] spawn {
	//		sleep 1;
	//		BP_WaitingForContainer = true;
	//		(_this select 0) action ["Gear", (_this select 1)];
	//	};
	//};
	//
	//if !(_container isKindOf "BP_LootBox") then {
	//	BP_ContainerOpened = [(netID _container)];
	//	publicVariableServer "BP_ContainerOpened";	
	//};
	//
	//BP_WaitingForContainer = false;
	
	//Play Backpack Sounds Of Opening Things
	if (_container isKindOf "BP_Bag_Base") then {
		_isInside = [_unit] call BP_fnc_isInsideBuilding;
		playSound3D ["a3\sounds_f\characters\stances\concrete_adjust_prone_left.wss", _unit, _isInside, getPosASL _unit,1,1,20];
	};
	
	//BP_AllowInventory = false;
	BP_CurrentContainer = _container;
	
	if (!isNull BP_InventoryThread) then
	{
		terminate BP_InventoryThread;
		BP_InventoryThread = scriptNull;
	};
	
	//Check for reverse pickpocket grenades
	_hasLiveGrenade = ("HandGrenadeLive" in magazines _unit);
	_myBackpack = (unitBackpack _unit);
	if (_hasLiveGrenade and (!isNull _myBackpack)) then
	{
		//Count How Many Live Grenades Added
		_grenadeCount = 0;
		{
			if (_x == "HandGrenadeLive") then
			{
				_unit removeMagazine "HandGrenadeLive";
				_grenadeCount = _grenadeCount + 1;
			};
		} count magazines _unit;
		
		//RIP
		[_grenadeCount,_myBackpack,_unit] spawn
		{
			params ["_grenadeCount","_container","_unit"];
			_spawnedGrenades = 0;
			while {_spawnedGrenades < _grenadeCount} do
			{
				_spawnedGrenades = _spawnedGrenades + 1;
				_gnade = "GrenadeHand" createVehicle (getPosATL _unit);
				_gnade attachTo [_container];
			};
		};
	};
	
	//Add Inventory Event Handlers
	BP_InventoryThread = [_restrictedInventory] spawn 
	{
		disableSerialization;
		private ["_controlUniform","_controlVest","_controlBackpack", "_controlHealthHuman", "_controlHealthDog", "_healthCurrentMath", "_dogObject", "_dogHealthCurrent", "_dogObjectID", "_dogHealthFull"];
		while {isNull (findDisplay 602)} do {};
		
		_restrictedInventory = _this select 0;
		_inventoryWindow = (findDisplay 602);
		
		if (_restrictedInventory) then
		{
			_hideCtrls = [1001,1239,6320,6400,6321,6307,632,6401,640];
			{
				_ctrl = (_inventoryWindow displayCtrl _x);
				_ctrl ctrlShow false;
				_ctrl ctrlSetPosition [0,0,0,0];
				_ctrl ctrlSetScale 0;
				_ctrl ctrlCommit 0;
			} count _hideCtrls;
		};
		
		//Custom Inventory Skin Selection
		_controlInventoryBG = (_inventoryWindow displayCtrl 1000);
		_controlGroundBG = (_inventoryWindow displayCtrl 1001);
		_inventorySkin = BP_InventorySkins select BP_CurrentInventorySkin;
		_controlInventoryBG ctrlSetText (_inventorySkin select 0);
		_controlInventoryBG ctrlCommit 0;
		_controlGroundBG ctrlSetText (_inventorySkin select 1);
		_controlGroundBG ctrlCommit 0;
		
		//Inventory Skin Selection Button
		_controlSkin = (_inventoryWindow displayCtrl 1231);
		_controlSkin ctrlSetEventHandler ["MouseButtonClick", "_this call BP_fnc_inventoryChangeSkin"];
		_controlSkin ctrlShow true;
		_controlSkin ctrlCommit 0;
		
		//Take All Button
		_controlTakeAll = (_inventoryWindow displayCtrl 1239);
		_controlTakeAll ctrlSetEventHandler ["MouseButtonClick", "_this call BP_fnc_inventoryTakeAll"];
		_controlTakeAll ctrlShow true;
		_controlTakeAll ctrlCommit 0;
		
		//Uni / Vest / Backpack Events
		_controlUniform = (_inventoryWindow displayCtrl 633);
		_controlUniform ctrlSetEventHandler ["LBDblClick", "[0,'LBDblClick',_this] call BP_fnc_inventorySelectItem"];
		_controlVest = (_inventoryWindow displayCtrl 638);
		_controlVest ctrlSetEventHandler ["LBDblClick", "[1,'LBDblClick',_this] call BP_fnc_inventorySelectItem"];
		_controlBackpack = (_inventoryWindow displayCtrl 619);
		_controlBackpack ctrlSetEventHandler ["LBDblClick", "[2,'LBDblClick',_this] call BP_fnc_inventorySelectItem"];
		
		_controlGround = (_inventoryWindow displayCtrl 632);
		_controlCrate = (_inventoryWindow displayCtrl 640);
		
		if (!_restrictedInventory) then 
		{
			//_controlGround ctrlSetEventHandler ["LBDblClick", "[3,'LBDblClick',_this] call BP_fnc_InventorySelectItem"];
			_controlGround ctrlSetEventHandler ["LBSelChanged", "[3,'LBSelChanged',_this] call BP_fnc_inventorySelectItem"];
			_controlCrate ctrlSetEventHandler ["LBDblClick", "[4,'LBDblClick',_this] call BP_fnc_inventorySelectItem"];
			_controlCrate ctrlSetEventHandler ["LBSelChanged", "[4,'LBSelChanged',_this] call BP_fnc_inventorySelectItem"];
		};
		
		_controlGroundIndex = -1;
		_controlCrateIndex = -1;
		
		_controlPreview = (_inventoryWindow displayCtrl 9999);
		_controlPreview ctrlShow false;

		_controlHealthHuman = (_inventoryWindow displayCtrl 1229);
		_controlHealthDog = (_inventoryWindow displayCtrl 1230);
		
		_controlPlayerFood = (_inventoryWindow displayCtrl 1233);
		_controlPlayerWater = (_inventoryWindow displayCtrl 1237);
		_controlDogFood = (_inventoryWindow displayCtrl 1235);
		_controlDogWater = (_inventoryWindow displayCtrl 1236);
		
		//Set Crate and Ground Tab Texture Images
		_controlCrateTab = (_inventoryWindow displayCtrl 6401);
		_controlGroundImg = (_inventoryWindow displayCtrl 6320);
		_controlCrateImg = (_inventoryWindow displayCtrl 6400);
		_controlCrateImg ctrlShow (ctrlShown _controlCrateTab);
		_controlCrateImg ctrlCommit 0;
		
		(findDisplay 602) displayAddEventHandler ["KeyDown", {_this call BP_fnc_spaceInterruptInv}];
		
		waitUntil
		{
			// Dog Updates
			_dogObject = player getVariable ["dog", objNull];
			if (!isNull _dogObject) then 
			{
				//Get Dog Information
				_dogHealthFull = 8000;
				_dogObjectID = player getVariable ["dogID", 0];
				_dogHealthCurrent = _dogObjectID getFSMVariable "_blood";
				
				//Health
				_controlHealthDog ctrlSetFade ((_dogHealthFull - _dogHealthCurrent) / _dogHealthFull);
				_controlHealthDog ctrlSetText "\breakingpoint_ui\inventory\health_dog.paa";
				_controlHealthDog ctrlCommit 0;
				
				//Food
				_controlDogFood ctrlShow false;
				_controlDogFood ctrlCommit 0;
				
				//Water
				_controlDogWater ctrlShow false;
				_controlDogWater ctrlCommit 0;
			} else {
				//Health
				_controlHealthDog ctrlSetFade 0;
				_controlHealthDog ctrlSetText "\breakingpoint_ui\inventory\health_no_dog.paa";
				_controlHealthDog ctrlCommit 0;
				
				//Food
				_controlDogFood ctrlShow false;
				_controlDogFood ctrlCommit 0;
				
				//Water
				_controlDogWater ctrlShow false;
				_controlDogWater ctrlCommit 0;
			};

			// Player Updates
			if (!isNull player) then 
			{
				//Health
				_controlHealthHuman ctrlSetFade ((r_player_bloodTotal - r_player_blood) / r_player_bloodTotal);
				_controlHealthHuman ctrlCommit 0;

				//Water
				_thirstVal = 	1 - (BP_thirst / SleepWater);
				if (_thirstVal < 0.3) then {
					_controlPlayerWater ctrlShow true;
				} else {
					_controlPlayerWater ctrlShow false;
				};

				//Food
				_foodVal = 1 - (BP_hunger / SleepFood);
				if (_foodVal < 0.3) then {
					_controlPlayerFood ctrlShow true;
				} else {
					_controlPlayerFood ctrlShow false;
				};
			};
			
			if (!_restrictedInventory) then 
			{
				//Update Selected Ground Item
				if (_controlGroundIndex != (lbCurSel _controlGround)) then {
					_controlGroundIndex = (lbCurSel _controlGround);
					if (lbCurSel _controlGround > -1) then {
						[3,'LBSelChanged',[_controlGround,(lbCurSel _controlGround)]] call BP_fnc_InventorySelectItem;
					} else {
						_controlPreview ctrlShow false;
					};
				};
				
				//Update Selected Crate Item
				if (_controlCrateIndex != (lbCurSel _controlCrate)) then {
					_controlCrateIndex = (lbCurSel _controlCrate);
					if (lbCurSel _controlCrate > -1) then {
						[3,'LBSelChanged',[_controlCrate,(lbCurSel _controlCrate)]] call BP_fnc_InventorySelectItem;
					} else {
						_controlPreview ctrlShow false;
					};
				};
			};
			
			(!dialog)
		};
	};
	[BP_InventoryThread] call BP_fnc_addThreadHandle;
};

_return
