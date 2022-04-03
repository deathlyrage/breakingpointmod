/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd

	Written by Th3Dilli for the Breaking Point Mod for ArmA 3.
*/

params ["_unitUID"];

_repairedRecently = false;

_repairCooldown = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "repairVehicle" >> "repairCooldown");
_found = false;
{
	if(_x select 0 == _unitUID) then
	{
		_found = true;
		if(_x select 1 > time) then
		{
			_repairedRecently = true;
		}
		else
		{
			_x set [1,(time + _repairCooldown)];
		};
	};
} foreach BP_applyRepair;

if(!_found) then
{
	BP_applyRepair pushBack [_unitUID,(time + _repairCooldown)];
};

_repairedRecently