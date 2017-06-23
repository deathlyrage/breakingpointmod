/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_fnc_damageEvent";

params ["_unit","_hit","_damageHit","_damageBlood","_source","_ammo"];

//["damageEvent: %1",_this] call BP_fnc_debugConsoleFormat;

if (isServer) then 
{
	if (isPlayer _unit) then {
		BP_DamageEvent = _this;
		(owner _unit) publicVariableClient "BP_DamageEvent";
	} else {
		if !(_unit isKindOf "BP_Stronghold_AI") then {
			_unit setDamage ((damage _unit) + _damageHit);
		};
	};
} else {
	//Player Damage
	if (_unit == player) exitWith {
		[_unit,_hit,0.10,_source,_ammo] call BP_fnc_damageHandler;
		if (_unit != _source) then {
			[_unit,_source,_damageHit] call BP_fnc_damageHandlerHit;
			r_player_killer = _source;
		};
		r_player_blood = r_player_blood - _damageBlood;
	};
};