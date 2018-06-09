/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//unit: Object - Object the event handler is assigned to
//container: Object - connected container or weaponholder

params ["_unit","_container"];

["onInventoryClosed: Unit: %1 | Container: %2",_unit,_container] call BP_fnc_debugConsoleFormat;

BP_CurrentContainer = objNull;

if (!isNull BP_InventoryThread) then
{
	terminate BP_InventoryThread;
	BP_InventoryThread = scriptNull;
};

if (!isNull _container) then 
{
	if (_container isKindOf "Bag_Base") then {
		_isInside = [_unit] call BP_fnc_isInsideBuilding;
		playSound3D ["a3\sounds_f\characters\stances\concrete_adjust_prone_right.wss", _unit, _isInside, getPosASL _unit,1,1,20];
	};

	[(netID _container)] remoteExecCall ["BPServer_fnc_containerClosed",2];
};

closeDialog 0;
