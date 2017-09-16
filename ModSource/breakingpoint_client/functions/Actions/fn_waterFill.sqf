/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_playerPos","_canFill","_isPond","_isWell","_pondPos","_objectsWell","_onLadder","_hasbottleitem","_config","_item","_text","_objectsPond","_qty","_dis","_sfx"];
_item = 		_this select 0;
_playerPos = 	getPosATL player;
_canFill = 		count nearestObjects [_playerPos, ["Land_StallWater_F","Land_Water_source_F"], 10] > 0;
_canFill_1 = 	count nearestObjects [_playerPos, ["Land_BarrelWater_F"], 10] > 0;
_isPond = 		false;
_isWell = 		false;
_pondPos = 		[];
_objectsWell = 	[];

if (_canFill_1) then {
	_canFill = true;
};

_onLadder =		(getNumber (configFile >> "CfgMovesMaleSdr" >> "States" >> (animationState player) >> "onLadder")) == 1;
if (_onLadder) exitWith {};

_hasbottleitem = _item in magazines player;

_config = configFile >> "CfgMagazines" >> _item;
_text = getText (_config >> "displayName");

if (!_hasbottleitem) exitWith {};

if (!BP_isSwimming) then {
	player playActionNow "PutDown";
};

if (!_canFill) then {
	_objectsWell = 	nearestObjects [_playerPos, [], 4];
	{
		//Check for Well
		_isWell = ["well",str(_x),false] call BP_fnc_inString;
		if (_isWell) then {_canFill = true};
		//Check For Water
		_isWater = ["water",str(_x),false] call BP_fnc_inString;
		if (_isWater) then {_canFill = true};
		//Check For Other
		_isOther = ["kasna_new",str(_x),false] call BP_fnc_inString;
		if (_isOther) then {_canFill = true};
	} count _objectsWell;
};

if (!_canFill) then {
	_objectsPond = 		nearestObjects [_playerPos, [], 50];
	{
		//Check for pond
		_isPond = ["pond",str(_x),false] call BP_fnc_inString;
		if (_isPond) then {
			_pondPos = (_x worldToModel _playerPos) select 2;
			if (_pondPos < 0) then {
				_canFill = true;
			};
		};
	} count _objectsPond;
};

if (_canFill) then {
	_qty = {_x == "WaterbotEmpty"} count magazines player;

	player playActionNow "PutDown";

	if ("WaterbotEmpty" in magazines player) then {
		player removeMagazines "WaterbotEmpty";
		for "_x" from 1 to _qty do {
			sleep 1;
			_dis=5;
			_sfx = "fillwater";
			[player,_sfx,0,false,_dis] call BP_fnc_objSpeak;  
			[player,_dis,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
			
			player addMagazine "Waterbot";
		};
	};
};