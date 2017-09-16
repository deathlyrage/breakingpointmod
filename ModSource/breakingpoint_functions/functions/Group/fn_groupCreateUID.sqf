/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_ref","_refID"];
_ref = ("WeaponHolderSimulated" createVehicleLocal [0,0,0]);
_refID = _ref call BP_fnc_getBuildingID;
deleteVehicle _ref;
if (_refID == "0") then { _refID = format ["%1",floor(random 999999)]; };
_refID