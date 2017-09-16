/*
	Author: Karel Moricky

	Description:
	Return object category and type. Recognized types are:

		Soldier
			AT
			Civilian
			Diver
			Infantry
			Medic
			MG
			Officer
			Pilot
			Sniper
			SpecialForces
			UAVPilot
		Vehicle / VehicleAutonomous
			Car
			Helicopter
			Motorcycle
			Plane
			Ship
			StaticWeapon
			Submarine
			TrackedAPC
			Tank
			WheeledAPC
		Logic
			Logic
			Module
		Object
			Ammobox
			Animal
			Backpack
			Camera
			Church
			Effect
			Fire
			Flag
			Helipad
			House
			Marker
			Mine
			Parachute
			Seagull
			Sound
			Target
			Thing
			Trigger
			UnknownObject
			VASI
			Wreck

	Parameter(s):
		0: STRING - item class

	Returns:
	ARRAY in format [category,type]
*/

private ["_object"];
_object = [_this,0,"",["",objnull]] call bis_fnc_param;
if (typename _object == typename objnull) then {_object = typeof _object;};

switch (true) do {
	case (isclass (configfile >> "cfgvehicles" >> _object)): {
		private ["_cfgObject","_simulation","_namesound","_objectCategory","_objectType"];
		_cfgObject = configfile >> "cfgvehicles" >> _object;
		_simulation = tolower gettext (_cfgObject >> "simulation");
		_namesound = gettext (_cfgObject >> "namesound");
		_objectCategory = "Object";

		_objectType = switch _simulation do {
			case "airplane";
			case "airplanex": {
				_objectCategory = "Vehicle";
				"Plane"

			};
			case "animal": {
				"Animal"
			};
			case "artillerymarker";
			case "lasertarget";
			case "nvmarker": {
				"Marker"
			};
			case "car";
			case "carx": {
				_objectCategory = "Vehicle";
				switch (true) do {

					case (_namesound == "veh_vehicle_apc_s"): {"WheeledAPC"};
					default {"Car"};
				};

			};
			case "church": {
				"Church"
			};
			case "fire": {
				"Fire"
			};
			case "flagcarrier": {
				"Flag"
			};
			case "helicopter";
			case "helicopterx": {
				_objectCategory = "Vehicle";
				"Helicopter"
			};
			case "house";
			case "thing";
			case "thingx": {
				switch (true) do {

					case (getnumber (_cfgObject >> "isbackpack") > 0): {"Backpack"};
					case (_object iskindof "ReammoBox");
					case (_object iskindof "ReammoBox_F"): {"AmmoBox"};
					case (_object iskindof "Wreck");
					case (_object iskindof "Wreck_Base"): {"Wreck"};
					case (_object iskindof "TargetBase"): {"Target"};
					case (_object iskindof "HeliH"): {"Helipad"};
					case (_simulation == "house"): {"House"};
					default {"Thing"};
				};
			};
			case "curator";
			case "invisible": {
				_objectCategory = "Logic";
				if (gettext (_cfgObject >> "vehicleclass") == "Modules") then {"Module"} else {"Logic"};

			};
			case "motorcycle": {
				_objectCategory = "Vehicle";
				"Motorcycle"
			};
			case "parachute";
			case "paraglide": {
				"Parachute"
			};
			case "ship";
			case "shipx": {
				_objectCategory = "Vehicle";
				"Ship"
			};
			case "soldier": {
				_objectCategory = "Soldier";
				switch (_namesound) do {
					case "veh_infantry_diver_s": {"Diver"};
					case "veh_infantry_sniper": {"Sniper"};
					case "veh_infantry_SF_s": {"SpecialForces"};
					case "veh_infantry_medic_s": {"Medic"};
					case "veh_infantry_AT_s": {"AT"};
					case "veh_infantry_MG_s": {"MG"};
					case "veh_infantry_officer_s": {"Officer"};
					case "veh_infantry_pilot_s": {"Pilot"};
					case "veh_infantry_civilian_s": {"Civilian"};
					default {"Infantry"};
				};
			};
			case "submarinex": {
				_objectCategory = "Vehicle";
				"Submarine"
			};
			case "tank";
			case "tankx": {
				_objectCategory = "Vehicle";
				switch (true) do {

					case (_namesound == "veh_vehicle_apc_s"): {"TrackedAPC"};
					case (_object iskindof "StaticWeapon"): {"StaticWeapon"};
					default {"Tank"};
				};
			};
			case "thingeffect": {
				"Effect"
			};
			case "uavpilot": {
				_objectCategory = "Soldier";
				"UAVpilot"
			};
			case "vasi": {
				"VASI"
			};
			default {
				switch (true) do {
					case (_object iskindof "MineBase"): {"Mine"};
					case (gettext (_cfgObject >> "vehicleclass") == "Sounds"): {"Sound"};
					default {"UnknownObject"};
				};
			};
		};
		if (getnumber (_cfgObject >> "isUAV") > 0) then {_objectCategory = "VehicleAutonomous";};
		if (getnumber (_cfgObject >> "hasdriver") == 0 && count (_cfgObject >> "turrets") == 0) then {_objectCategory = "Object"};
		[_objectCategory,_objectType]
	};
	case (isclass (configfile >> "cfgnonaivehicles" >> _object)): {
		private ["_cfgObject","_simulation","_objectCategory","_objectType"];
		_cfgObject = configfile >> "cfgvehicles" >> _object;
		_simulation = tolower gettext (_cfgObject >> "simulation");

		_objectCategory = "Object";
		_objectType = switch _simulation do {
			case "camconstruct";
			case "camcurator";
			case "camera": {
				"Camera"
			};
			case "detector": {
				"Trigger"
			};
			case "seagull": {
				"Seagull"
			};
			default {"UnknownObject"};
		};
		[_objectCategory,_objectType]
	};
	default {["",""]};
};