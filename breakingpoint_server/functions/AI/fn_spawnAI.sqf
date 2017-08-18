/*
	Breaking Point Arma 3 Public-Alpha Build
	Created By Deathlyrage, Valtiel and Nohrt

	More Detailed Credits Listed Here:
		http://thezombieinfection.com/wiki/index.php?title=Credits

	Copyright © 2013-2015, The Zombie Infection (thezombieinfection.com)
	All rights reserved.
*/

params ["_group","_classname","_position","_faction"];

//["spawnAI: %1",_this] call BP_fnc_debugConsoleFormat;

if (isNull _group) then { _group = createGroup east; };

_groupID = groupID _group;

_unit = _group createUnit [_classname, _position, [], 0, "CAN_COLLIDE"];
_unit setSkill ["aimingAccuracy", 1];
_unit setSkill ["aimingShake", 1];
_unit setSkill ["aimingSpeed", 1];
_unit setSkill ["endurance", 1];
_unit setSkill ["spotDistance", 1];
_unit setSkill ["spotTime", 1];
_unit setSkill ["courage", 1];
_unit setSkill ["reloadSpeed", 1];
_unit setSkill ["commanding", 1];
_unit setSkill ["general", 1];
//_unit setBehaviour "STEALTH";
_unit setBehaviour "AWARE";
_unit setCombatMode "YELLOW";
_unit setVariable ["class",_faction,true];
_unit setVariable ["group",_groupID];
_unit enableFatigue false;
_fsmID = [_unit, typeOf _unit,_faction,_position] execFSM "\breakingpoint_code\system\ai_unit.fsm";
_fsmid setFSMVariable ["_handle", _fsmID];
_unit setVariable ["fsm_handle", _fsmid];
_unit setVariable ['BIS_noCoreConversations',true];
_unit setVariable ["ai",true,true];

_unit removeAllEventHandlers "Killed";
_unit removeAllEventHandlers "HandleDamage";
_unit removeAllEventHandlers "FiredNear";

_unit addEventHandler ["Killed", {_this call BP_fnc_handleKilledAI;}];
_unit addEventHandler ["HandleDamage", {_this call BP_fnc_handleDamageAI;}];
_unit addEventHandler ["FiredNear", {_this call BP_fnc_firedNearAI;}];

//Set Respawn Data
_unit setVariable ["bodyName",(name _unit),true];
_unit setVariable ["respawn",[_group,_groupID,_classname,_position,_faction,_unit]];

_unit addWeapon "ItemMap";
_unit addWeapon "ItemSurgeryKit";

switch (typeOf _unit) do
{
	//Rangers
	case "BP_Ranger_Assault1":
	{
		_unit addWeapon "BP_M16A4_AI";              //BP_M16A4
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_M16A4"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Assault1_F":
	{
		_unit addWeapon "BP_M16A4_AI";              //BP_M16A4
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_M16A4"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Assault2":
	{
		_unit addWeapon "BP_Minimi_762_AI";         //BP_Minimi_762
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_Minimi_762"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Assault2_F":
	{
		_unit addWeapon "BP_Minimi_762_AI";         //BP_Minimi_762
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_Minimi_762"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Sniper1":
	{
		_unit addWeapon "BP_M40A3_AI";        //BP_M40A3
		_unit addPrimaryWeaponItem "BP_L14X";
		_unit setVariable ["lootWeapon","BP_M40A3"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Sniper1_F":
	{
		_unit addWeapon "BP_M40A3_AI";        //BP_M40A3
		_unit addPrimaryWeaponItem "BP_L14X";
		_unit setVariable ["lootWeapon","BP_M40A3"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Sniper2":
	{
		_unit addWeapon "BP_Tavor_AI";              //BP_Tavor
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_Tavor"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Sniper2_F":
	{
		_unit addWeapon "BP_Tavor_AI";              //BP_Tavor
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_Tavor"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Ranger_Sniper3":
	{
		_unit addWeapon "BP_M107_AI";        //BP_M107_DES
		_unit addPrimaryWeaponItem "BP_NXS";
		_unit setVariable ["lootWeapon","BP_M107_DES"];
		_unit addMagazine "BP_100Rnd_50Cal_AI";
		_unit addMagazine "BP_100Rnd_50Cal_AI";
	};
	case "BP_Ranger_Sniper3_F":
	{
		_unit addWeapon "BP_M107_AI";        //BP_M107_DES
		_unit addPrimaryWeaponItem "BP_NXS";
		_unit setVariable ["lootWeapon","BP_M107_DES"];
		_unit addMagazine "BP_100Rnd_50Cal_AI";
		_unit addMagazine "BP_100Rnd_50Cal_AI";
	};
	
	//Nomad
	case "BP_Nomad_Assault1":
	{
		_unit addWeapon "BP_AR10_AI";             //BP_AR10
		_unit addPrimaryWeaponItem "BP_Unertl8x";
		_unit setVariable ["lootWeapon","BP_AR10"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Nomad_Assault1_F":
	{
		_unit addWeapon "BP_AR10_AI";             //BP_AR10
		_unit addPrimaryWeaponItem "BP_Unertl8x";
		_unit setVariable ["lootWeapon","BP_AR10"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Nomad_Assault2":
	{
		_unit addWeapon "BP_Minimi_HG_AI";          //BP_Minimi_HG
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_Minimi_HG"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Nomad_Assault2_F":
	{
		_unit addWeapon "BP_Minimi_HG_AI";          //BP_Minimi_HG
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_Minimi_HG"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Nomad_Sniper1":
	{
		_unit addWeapon "BP_AWSM_AI";            //BP_AWSM
		_unit addPrimaryWeaponItem "BP_L14X";
		_unit setVariable ["lootWeapon","BP_AWSM"];
		_unit addMagazine "BP_100Rnd_50Cal_AI";
		_unit addMagazine "BP_100Rnd_50Cal_AI";
	};
	case "BP_Nomad_Sniper1_F":
	{
		_unit addWeapon "BP_AWSM_AI";            //BP_AWSM
		_unit addPrimaryWeaponItem "BP_L14X";
		_unit setVariable ["lootWeapon","BP_AWSM"];
		_unit addMagazine "BP_100Rnd_50Cal_AI";
		_unit addMagazine "BP_100Rnd_50Cal_AI";
	};
	case "BP_Nomad_Sniper2":
	{
		_unit addWeapon "BP_Win70F_AI";      //BP_Win70F
		_unit addPrimaryWeaponItem "BP_VX3";
		_unit setVariable ["lootWeapon","BP_Win70F"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Nomad_Sniper2_F":
	{
		_unit addWeapon "BP_Win70F_AI";      //BP_Win70F
		_unit addPrimaryWeaponItem "BP_VX3";
		_unit setVariable ["lootWeapon","BP_Win70F"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Nomad_Sniper3":
	{
		_unit addWeapon "BP_G36DMR_AI";         //BP_G36DMR
		_unit addPrimaryWeaponItem "BP_M3A";
		_unit setVariable ["lootWeapon","BP_G36DMR"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Nomad_Sniper3_F":
	{
		_unit addWeapon "BP_G36DMR_AI";         //BP_G36DMR
		_unit addPrimaryWeaponItem "BP_M3A";
		_unit setVariable ["lootWeapon","BP_G36DMR"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	
	//Outlaws
	case "BP_Outlaw_Assault1":
	{
		_unit addWeapon "BP_AKM_AI";        //BP_AKM
		_unit setVariable ["lootWeapon","BP_AKM"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Outlaw_Assault1_F":
	{
		_unit addWeapon "BP_AKM_AI";        //BP_AKM
		_unit setVariable ["lootWeapon","BP_AKM"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Outlaw_Assault2":
	{
		_unit addWeapon "BP_Zafir_AI";           //BP_Zafir
		_unit addPrimaryWeaponItem "optic_hamr";
		_unit setVariable ["lootWeapon","BP_Zafir"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Outlaw_Assault2_F":
	{
		_unit addWeapon "BP_Zafir_AI";           //BP_Zafir
		_unit addPrimaryWeaponItem "optic_hamr";
		_unit setVariable ["lootWeapon","BP_Zafir"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Outlaw_Sniper1":
	{
		_unit addWeapon "BP_GM6_AI";           //BP_GM6_SOS
		_unit addPrimaryWeaponItem "BP_NXS";
		_unit setVariable ["lootWeapon","BP_GM6_SOS"];
		_unit addMagazine "BP_100Rnd_50Cal_AI";
		_unit addMagazine "BP_100Rnd_50Cal_AI";
	};
	case "BP_Outlaw_Sniper1_F":
	{
		_unit addWeapon "BP_GM6_AI";           //BP_GM6_SOS
		_unit addPrimaryWeaponItem "BP_NXS";
		_unit setVariable ["lootWeapon","BP_GM6_SOS"];
		_unit addMagazine "BP_100Rnd_50Cal_AI";
		_unit addMagazine "BP_100Rnd_50Cal_AI";
	};
	case "BP_Outlaw_Sniper2":
	{
		_unit addWeapon "BP_SVDK_AI";           //BP_SVDK
		_unit addPrimaryWeaponItem "BP_PSOP";
		_unit setVariable ["lootWeapon","BP_SVDK"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Outlaw_Sniper2_F":
	{
		_unit addWeapon "BP_SVDK_AI";           //BP_SVDK
		_unit addPrimaryWeaponItem "BP_PSOP";
		_unit setVariable ["lootWeapon","BP_SVDK"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Outlaw_Sniper3":
	{
		_unit addWeapon "BP_ScarH_AI";        //BP_ScarH
		_unit addPrimaryWeaponItem "BP_L14x";
		_unit setVariable ["lootWeapon","BP_ScarH"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Outlaw_Sniper3_F":
	{
		_unit addWeapon "BP_ScarH_AI";        //BP_ScarH
		_unit addPrimaryWeaponItem "BP_L14x";
		_unit setVariable ["lootWeapon","BP_ScarH"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};

	/*
	//Hunters
	case "BP_Hunter_Assault1":
	{
		_unit addWeapon "BP_M4_300_AI";              //BP_M4_300
		_unit addPrimaryWeaponItem "BP_optic_ACOG";
		_unit setVariable ["lootWeapon","BP_M4_300"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Hunter_Assault2":
	{
		_unit addWeapon "BP_AKMRIS_AI";          //BP_SA582
		_unit addPrimaryWeaponItem "optic_aco";
		_unit setVariable ["lootWeapon","BP_SA582"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Hunter_Sniper1":
	{
		_unit addWeapon "BP_LRR_AI";          //BP_LRR_F
		_unit addPrimaryWeaponItem "BP_NXS";
		_unit setVariable ["lootWeapon","BP_LRR_F"];
		_unit addMagazine "BP_100Rnd_50Cal_AI";
		_unit addMagazine "BP_100Rnd_50Cal_AI";
	};
	case "BP_Hunter_Sniper2":
	{
		_unit addWeapon "BP_SR25_AI";          //BP_SR25
		_unit addPrimaryWeaponItem "BP_L14x";
		_unit setVariable ["lootWeapon","BP_SR25"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	case "BP_Hunter_Sniper3":
	{
		_unit addWeapon "BP_FALM_AI";          //BP_FALM
		_unit addPrimaryWeaponItem "BP_L14X";
		_unit setVariable ["lootWeapon","BP_FALM"];
		_unit addMagazine "BP_500Rnd_762x51_AI";
		_unit addMagazine "BP_500Rnd_762x51_AI";
	};
	*/
};

_unit