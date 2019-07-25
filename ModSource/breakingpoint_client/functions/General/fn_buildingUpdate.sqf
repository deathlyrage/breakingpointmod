/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

if (isNil "BP_Buildings") exitWith {};
if (isNil "BP_BuildingsLocks") exitWith {};

//Update Havens
{
	_building = objectFromNetID _x;
	if (!isNull _building) then
	{
		_buildingDoors = getNumber (configFile >> "CfgVehicles" >> typeof _building >> "numberOfDoors");
		_disabledDoor = BP_BuildingsLocks select _forEachIndex;
		for "_i" from 1 to _buildingDoors do {
			_building setVariable ["bis_disabled_Door_" + str _i,_disabledDoor];
		};
	};
} forEach BP_Buildings;

