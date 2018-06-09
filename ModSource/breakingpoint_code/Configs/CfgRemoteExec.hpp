/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgRemoteExec
{        
	// List of script functions allowed to be sent from client via remoteExec
	class Functions
	{
		// State of remoteExec: 0-turned off, 1-turned on, taking whitelist into account, 2-turned on, however, ignoring whitelists (default because of backward compatibility)
		mode = 1;
		
		// Ability to send jip messages: 0-disabled, 1-enabled (default)
		jip = 0;
		
		// Global Things
		class BP_fnc_fireDelete { allowedTargets=0; };
		
		// Login / Setup
		class BPServer_fnc_checkLogin { allowedTargets=2; };		//BP_Login
		class BPServer_fnc_playerSetup { allowedTargets=2; };		//BP_PlayerSetup
		
		// Death / Respawn
		class BPServer_fnc_playerDeath { allowedTargets=2; };		//BP_Death
		class BPServer_fnc_playerDeathReg { allowedTargets=2; };
		class BPServer_fnc_playerRespawn { allowedTargets=2; };		//BP_Respawn
		
		// Interaction With Loot Containers
		class BPServer_fnc_containerOpened { allowedTargets=2; };	//BP_ContainerOpened
		class BPServer_fnc_containerClosed { allowedTargets=2; };	//BP_ContainerClosed
		class BPServer_fnc_containerSpawn { allowedTargets=2; };	//BP_ContainerSpawn
		class BPServer_fnc_containerTakeAll { allowedTargets=2; };	//BP_ContainerOpened
		
		// Loot Body / Dog Death
		class BPServer_fnc_playerLoot { allowedTargets=2; };		//BP_LootBody
		class BP_fnc_dogKilled { allowedTargets=2; };				//BP_DogDeath
		
		// Gear / Med Sync
		class BPServer_fnc_medSync { allowedTargets=2; };			//BP_MedSync
		class BPServer_fnc_updateObject { allowedTargets=2; };		//BP_ObjectSync
		class BPServer_fnc_updateObjectForce { allowedTargets=2; };	//BP_ObjectSyncForce
		
		// Havens
		class BPServer_fnc_lockHouse { allowedTargets=2; };			//BP_LockHouse
		class BPServer_fnc_unlockHouse { allowedTargets=2; };		//BP_UnlockHouse
		class BPServer_fnc_publishHouse { allowedTargets=2; };		//BP_PublishHouse
		class BPServer_fnc_deleteHouse { allowedTargets=2; };		//BP_DeleteHouse
		class BPServer_fnc_upgradeHouse { allowedTargets=2; };		//BP_UpgradeHouse
		
		// Publish / Delete Object
		class BPServer_fnc_publishObj { allowedTargets=2; };		//BP_PublishObj
		class BPServer_fnc_deleteObj { allowedTargets=2; };			//BP_DeleteObj
		class BPServer_fnc_lockObj { allowedTargets=2; };
		class BPServer_fnc_unlockObj { allowedTargets=2; };
		
		// Ignite Things
		class BPServer_fnc_igniteEntity { allowedTargets=2; };
		
		// Vehicles ( Spawn )
		class BP_fnc_vehicleRepair { allowedTargets=2; };			//BP_VehicleRepair
		class BP_fnc_vehicleRemove { allowedTargets=2; };			//BP_VehicleRemove
		class BP_fnc_vehicleFuel { allowedTargets=2; };				//BP_VehicleFuel
		
		// Vehicles ( Call)
		class BP_fnc_vehicleKilled { allowedTargets=2; };			//BP_VehicleKilled
		
		// Vehicles (Handle Repair Call)
		class BP_fnc_vehicleHandleFuel { allowedTargets=1; };
		class BP_fnc_vehicleHandleRepair { allowedTargets=1; };
		class BP_fnc_vehicleHandleRemove { allowedTargets=1; };
		
		// Medical / Traitor / Damage
		class BPServer_fnc_medicalUpdate { allowedTargets=2; };		//BP_MedicalEvent
		class BPServer_fnc_traitorFlag { allowedTargets=2; };		//BP_TraitorFlag
		class BPServer_fnc_eventKill { allowedTargets=2; };			//BP_EventKill
	
		// Damage Events
		class BP_fnc_damageEvent { allowedTargets=2; };				//BP_DamageEvent
		class BP_fnc_damageHandler { allowedTargets=2; };			//BP_HitV
		class BP_fnc_damageHandlerVehicle { allowedTargets=2; };	//BP_HitV
		
		// Misc
		class BPServer_fnc_hostageAdd { allowedTargets=2; };		//BP_HostageAdd
		class BPServer_fnc_hostageGive { allowedTargets=2; };		//BP_HostageGive
		class BPServer_fnc_groupInvite { allowedTargets=2; };		//BP_GroupInvite
		class BPServer_fnc_playerGive { allowedTargets=2; };		//BP_PlayerGive
		class BPServer_fnc_setLocalVar { allowedTargets=2; };		//BP_SetLocalVar
		class BPServer_fnc_simulationToggle { allowedTargets=2; };	//BP_Simulation
		class BPServer_fnc_groupLeaveTimer { allowedTargets=2; };	//BP_leaveGroupTimer
		
		// Traps
		class BPServer_fnc_publishTrap { allowedTargets=2; };		//BP_PublishTrap
		class BP_fnc_trapActivate { allowedTargets=2; };			//BP_TrapActivate
		class BP_fnc_trapDeactivate { allowedTargets=2; };			//BP_TrapDeactivate
		class BP_fnc_trapCollect { allowedTargets=2; };				//BP_TrapCollect
		
		/*your functions here*/
		//class YourFunction1
		//{
		//       allowedTargets=0; // can target anyone (default)
		//       jip = 0; // sending jip messages is disabled for this function (overrides settings in the Functions class)
		//};
		//class YourFunction2 { allowedTargets=1; }; // can target only clients
		//class YourFunction3 { allowedTargets=2; }; // can target only the server
	};  

	// List of script commands allowed to be sent from client via remoteExec
	class Commands
	{
		mode = 0;
		jip = 0;
		/*your commands here*/
		//class YourCommand1 { allowedTargets=0; jip=1; } // can target anyone, sending jip is turned off (overrides settings in the Commands class)
	};
};