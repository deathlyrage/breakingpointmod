/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_dikCode", "_handled"];
_dikCode = _this select 1;
_handled = false;

_inVehicle = ((vehicle player) != player);
_isHostage = player getVariable ["med_hostage", false];
_isWater = (surfaceIsWater (getPosATL player));

if (_dikCode in actionKeys "Throw") then 
{
	//Reverse Pickpocket Grenade
	_container = BP_CurrentContainer;
	_hasGrenade = "HandGrenade" in magazines player;
	if (_hasGrenade and (_container isKindOf "BP_Bag_Base") and (_container != backpackContainer player)) then 
	{
		_handled = true;
		
		//Find Backpack Owner
		_target = objNull;
		{ if ((backpackContainer _x) == _container) exitWith { _target = _x; }; } count allPlayers;
		
		//Run Event
		["medGrenade",(netID _target),(netID player)] remoteExecCall ["BPServer_fnc_medicalUpdate",2];
		
		//Message
		cutText ["Reverse Pickpocket Hand Grenade Placed. Watch out for the mess next time the victim opens the inventory.","PLAIN DOWN"];
	};
	
};

_handled