/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_vehicle","_cfgHitPoints","_hps"];
_vehicle = _this;
_cfgHitPoints = configFile >> "CfgVehicles" >> (typeOf _vehicle) >> "HitPoints";
_hps = [];

//Explore inheritance structure fully
while {(configName _cfgHitPoints) != ""} do 
{
	for "_i" from 0 to ((count _cfgHitPoints) - 1) do 
	{
		_hp = configName (_cfgHitPoints select _i);
		_hps pushBackUnique _hp;
	};

	_cfgHitPoints = inheritsFrom _cfgHitPoints;
};

_hps