/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["_zed","_selection","_damage","_source","_projectile"];

//Handle Damage being Applied
//_hitpoint = "HitBody";
if ((_selection == "head_hit") and !(_projectile == "")) then { 
//_hitpoint = "HitHead"; 
_zed setDamage (0.85 + random 0.5);
};

["damageHandlerZ: Zed: %1 | Selection: %2 | Damage: %3 | Source: %4 | Projectile: %5",_zed,_selection,_damage,_source,_projectile] call BP_fnc_debugConsoleFormat;

/*
if (local _zed) then {
	if (_damage > 1 and _projectile != "") then {
		//Record deliberate critical damages
		switch (_selection) do {
			case "head_hit": {
				if (!(_zed getVariable["hitRegistered",false])) then {
					_headShots = _hitter getVariable["headShots",0];
					_hitter setVariable["headShots",(_headShots + 1),false];
					_zed setVariable["hitRegistered",true];
				};
			};
		};
	};
};
*/

//Fire Arrows
if (_projectile == "BP_Arrow_Ball_Fire") then
{
	_fire = _zed getVariable ["fire",objNull];
	if (isNull _fire) then
	{
		_zed setVariable ["fire",_zed];
		[(netID _zed),(netID _zed)] remoteExecCall ["BPServer_fnc_igniteEntity",2];
	};
};

//Non Melee / Stab
//if !(_projectile isKindOf "Melee" || {_projectile isKindOf "BP_Stab"}) then
//{	
//	_NoDmg = ["leftarm","rightarm","rightforearm","leftforearm","hands","legs","rightleg","leftleg","rightupleg","leftupleg"];
//
//	if (_selection in _NoDmg) then {
//		_damage = 0;
//	} else {
//		switch (_selection) do {
//			case "head_hit":
//			{
//				_damage = _damage / 2;
//			};
//			case "":
//			{
//				_damage = _damage / 10;
//				if (_damage > 7) then {
//					_damage = _damage - 4;
//				};
//				if (_damage > 3) then {
//					_damage = _damage - 2;
//				};
//			};
//			case "body":
//			{
//				_damage = _damage / 14;
//			};
//			case "spine1":
//			{
//				_damage = _damage / 14;
//			};
//			case "spine2":
//			{
//				_damage = _damage / 14;
//			};
//		};
//	};
//};

if (isBurning _zed) then
{
	_damage = _damage / 50;

	_fire = _zed getVariable ["fire",objNull];
	if (isNull _fire) then
	{
		_zed setVariable ["fire",_zed];
		[(netID _zed),(netID _zed)] remoteExecCall ["BPServer_fnc_igniteEntity",2];
	};
};

//Handle Damage being Applied
//_hitpoint = "HitBody";
//if (_selection == "head_hit") then { _hitpoint = "HitHead"; };
//_currentDmg = _unit getHitPointDamage _hitpoint;
//_currentDmg = _currentDmg + _damage;
//_unit setHitPointDamage [_hitpoint,_currentDmg];

//_damage;
