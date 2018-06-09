/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_dis","_qty","_item","_playerPos","_canUse","_finished"];
_item = 		_this select 0;
_playerPos = 	getPosATL player;
_canUse = count nearestObjects [_playerPos, ["Land_FuelStation_02_pump_F","Land_FuelStation_01_pump_F","Land_Ind_TankSmall","land_fuelstation_w","Land_FuelStation_Feed_F","Land_A_FuelStation_Feed","Land_Tank_rust_F","Land_fs_feed_F","Land_Ind_FuelStation_Feed_EP1","Land_FuelStation_01_pump_malevil_F"], 4] > 0;

if (!_canUse) exitWith { cutText ["You must be near a fuel source to fill fuel cans." , "PLAIN DOWN"]; };

_finished = call BP_fnc_medicAnim;

if (_finished) then
{
	{
		_empty = _x;
		_full = BP_FuelFull select _forEachIndex;
		
		_qty = {_x == _empty} count magazines player;
		
		if (_empty in magazines player) then {
			for "_x" from 1 to _qty do {
				player removeMagazine _empty;
				player addMagazine _full;
			};
			_dis = 10;
			[player,"refuel",0,false,_dis] call BP_fnc_objSpeak;  
			_handle = [player,_dis,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
			[_handle] call BP_fnc_addThreadHandle;
		};
	} forEach BP_FuelEmpty;
};




