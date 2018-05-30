/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd

	Written by Th3Dilli for the Breaking Point Mod for ArmA 3.
*/

params ["_event","_unitUID","_medicUID"];

_healedRecently = false;

_medicalCooldown = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "applyMedicine" >> "medicalCooldown");


switch (_event) do {
	case "medBandage";
	case "medFieldDressing":
	{
		{
			if(_x select 0 == _unitUID && _x select 1 == _medicUID) then
			{
				if(_x select 2 > time) then
				{
					_healedRecently = true;
				}
				else
				{
					_x set [2,(time + _medicalCooldown)];
				};
			};
		} foreach BP_applyBandage;
		if(!_healedRecently) then
		{
			BP_applyBandage pushBack [_unitUID,_medicUID,(time + _medicalCooldown)];
		};
	};
	case "medPainK":
	{
		{
			if(_x select 0 == _unitUID && _x select 1 == _medicUID) then
			{
				if(_x select 2 > time) then
				{
					_healedRecently = true;
				}
				else
				{
					_x set [2,(time + _medicalCooldown)];
				};
			};
		} foreach BP_applyPainkiller;
		if(!_healedRecently) then
		{
			BP_applyPainkiller pushBack [_unitUID,_medicUID,(time + _medicalCooldown)];
		};
	};
	case "medSurgery":
	{
		{
			if(_x select 0 == _unitUID && _x select 1 == _medicUID) then
			{
				if(_x select 2 > time) then
				{
					_healedRecently = true;
				}
				else
				{
					_x set [2,(time + _medicalCooldown)];
				};
			};
		} foreach BP_applySurgery;
		if(!_healedRecently) then
		{
			BP_applySurgery pushBack [_unitUID,_medicUID,(time + _medicalCooldown)];
		};
	};
	case "medMorphine":
	{
		{
			if(_x select 0 == _unitUID && _x select 1 == _medicUID) then
			{
				if(_x select 2 > time) then
				{
					_healedRecently = true;
				}
				else
				{
					_x set [2,(time + _medicalCooldown)];
				};
			};
		} foreach BP_applyMorphine;
		if(!_healedRecently) then
		{
			BP_applyMorphine pushBack [_unitUID,_medicUID,(time + _medicalCooldown)];
		};
	};
};
_healedRecently