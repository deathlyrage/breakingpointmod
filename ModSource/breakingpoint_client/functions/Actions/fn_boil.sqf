/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd

	Written by KamikazeXex for the Breaking Point Mod for ArmA 3.
*/

private _fire = _this select 3;
private _nameWater = getText(configFile >> "CfgMagazines" >> "Waterbot" >> "displayName");
private _nammeEmpty = getText (configFile >> "CfgMagazines" >> "ItemCanEmpty" >> "displayName");

private _hasWater = "Waterbot" in magazines player;
if (!_hasWater) exitWith { cutText[format["You must have %1 in your inventory to boil it..", _nameWater], "PLAIN DOWN"]; };

private _hasContainer = "ItemCanEmpty" in magazines player;
if (!_hasContainer) exitWith { cutText[format["%1 must be in your main inventory to boil the water.", _nammeEmpty], "PLAIN DOWN"]; };

player removeAction s_player_boil;
s_player_boil = -1;

if (_hasWater and _hasContainer) then
{
	if ("Waterbot" in magazines player) then
	{
		private _qty = {_x == "Waterbot"} count magazines player;
		private _qtyBoiled = 0;

		call BP_fnc_medicalRemoveMedicActions;
		r_action = false;

		player playActionNow "Medic";

		r_interrupt = false;
		private _animState = animationState player;
		r_doLoop = true;
		private _started = false;
		private _finished = false;

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

			private _dis=6;
			private _sfx = "cook";
			[player,_sfx,0,false,_dis] call BP_fnc_objSpeak;
			private _handle = [player,_dis,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
			[_handle] call BP_fnc_addThreadHandle;

			sleep _qty;
			for "_x" from 1 to _qty do
			{
				if ("Waterbot" in magazines player) then
				{
					player removeMagazine "Waterbot";
					player addMagazine "WaterbotBoiled";
					_qtyBoiled = _qtyBoiled + 1;
				};
			};
			//Display Qty Cooked Message if Any Successfully Cooked.
			if (_qtyBoiled > 0) then {
				cutText[format["You have boiled %1 bottles of water.", _qty],"PLAIN DOWN"];
			};
		} else {
			r_interrupt = false;
			player playActionNow "stop";
		};
	};
};

/*
"Waterbot"
"WaterbotEmpty"
"WaterbotBoiled"
*/
