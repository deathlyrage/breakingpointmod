/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_text","_rawmeat","_cookedmeat","_meat","_meatcooked","_qty","_qtyCooked","_dis","_sfx"];

_fire = _this select 3;

player removeAction s_player_cook;
s_player_cook = -1;

_rawmeat = meatraw;
_cookedmeat = meatcooked;

{
	_meat = _x;
	_meatcooked = _cookedmeat select (_rawmeat find _meat);
	if (_meat in magazines player) then {
		_text = 	getText (configFile >> "CfgMagazines" >> _meatcooked >> "displayName");
		_qty = {_x == _meat} count magazines player;
		_qtyCooked = 0;

		call BP_fnc_medicalRemoveMedicActions;
		r_action = false;

		player playActionNow "Medic";

		r_interrupt = false;
		_animState = animationState player;
		r_doLoop = true;
		_started = false;
		_finished = false;
		//[player,"bandage",0,false] call BP_fnc_objSpeak;
		while {r_doLoop} do {
			_animState = animationState player;
			_isMedic = ["medic",_animState] call BP_fnc_inString;
			if (_isMedic) then {
				_started = true;
			};
			if (_started and !_isMedic) then {
				r_doLoop = false;
				_finished = true;
			};
			if (r_interrupt) then {
				r_doLoop = false;
			};
			
			if (r_player_dead) exitWith {};
			
			sleep 0.1;
		};
		r_doLoop = false;

		if (_finished) then 
		{
			//if (!inflamed _fire and (!_fire isKindOf "BP_Stove")) exitWith { cutText ["The fire needs to be ignited to cook food.", "PLAIN DOWN"]; };
		
			_dis=6;
			_sfx = "cook";
			[player,_sfx,0,false,_dis] call BP_fnc_objSpeak;  
			_handle = [player,_dis,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
			[_handle] call BP_fnc_addThreadHandle;
			
			sleep _qty;
			for "_x" from 1 to _qty do {
				if (_meat in magazines player) then
				{
					player removeMagazine _meat;
					player addMagazine _meatcooked;
					_qtyCooked = _qtyCooked + 1;
				};
			};
			//Display Qty Cooked Message if Any Successfully Cooked.
			if (_qtyCooked > 0) then {
				cutText [format["You have cooked %1 %2.",_qtyCooked,_text], "PLAIN DOWN"];
			};
		} else {
			r_interrupt = false;
			player playActionNow "stop";
		};
	};
} count _rawmeat;