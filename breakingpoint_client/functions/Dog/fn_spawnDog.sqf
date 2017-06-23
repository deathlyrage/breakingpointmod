/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_classname","_owner","_position"];

// -- Dog Unit -- //
//_dog = (group _owner) createUnit [_classname, _position, [], 0, "CAN_COLLIDE"];
//_fsmid = [_dog, typeOf _dog] execFSM "\breakingpoint_code\system\dog_unit.fsm";

// -- Dog Agent
_dog = createAgent [_classname, _position, [], 0, "CAN_COLLIDE"];
_dog setVariable ['BIS_fnc_animalBehaviour_disable',true];
_dog setVariable ['BIS_noCoreConversations',true];

// -- Test AI Script
//_cry = _dog spawn 
//{
//	while {alive _this} do 
//	{
//		_this setDestination [getPosATL player, "LEADER PLANNED", true];
//		sleep 1;
//	};
//};

// -- Real AI Script --
_fsmid = [_dog, typeOf _dog] execFSM "\breakingpoint_code\system\dog_agent.fsm";
_fsmid setFSMVariable ["_handle", _fsmid];
_fsmid setFSMVariable ["_isTamed", true];

// Set Owner's Dog
_owner setVariable ["dog",_dog,true];
_owner setVariable ["dogID", _fsmid];
_dog setVariable ["fsm_handle", _fsmid];
_owner reveal _dog;

//Disable Unneeded AI Modes
{ _dog disableAI _x; } forEach ["FSM","AUTOTARGET","TARGET","AIMINGERROR","SUPPRESSION","CHECKVISIBLE","COVER","AUTOCOMBAT"];

_dog