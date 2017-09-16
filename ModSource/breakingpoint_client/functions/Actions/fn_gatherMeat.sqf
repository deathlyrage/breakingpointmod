/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_hasKnife","_hasKnifeBlunt","_type","_config","_isPlayer","_isZombie","_isAnimal"];

params ["","","","_item"];

_hasKnife = "ItemKnife" in magazines player;
_hasKnifeBlunt = "ItemKnifeBlunt" in magazines player;
_type = typeOf _item;
_config = configFile >> "CfgSurvival" >> "Meat" >> _type;
_alive = (alive _item);
_isPlayer = ((_type in BP_AllPlayers) or (isPlayer _item));
_isZombie = (_item isKindOf "zZombie_Base");
_isAnimal = (_item isKindOf "Animal");

//Remove Action to Prevent Spamming
player removeAction s_player_butcher;
s_player_butcher = -1;

//Gutting Duplication Mutex Lock
_alreadyGutted = _item getVariable ["gutted",false];
if (_alreadyGutted) exitWith {};

//Warning Dialog for Gutting Players
_leaveReturn = true;
if (_isPlayer and _alive) then { _leaveReturn = ["Are you sure you want to end this player's life in the most gruesome and painful way possible? ","Gut Player",nil,true] call BIS_fnc_guiMessage; };
if (!_leaveReturn) exitWith {};

r_action_gut = true;

if (_hasKnife or _hasKnifeBlunt) then 
{
	_dis=10;
	[player,"gut",0,false,_dis] call BP_fnc_objSpeak;  
	[player,_dis,true,(getPosATL player)] spawn BP_fnc_zombieAlert;
	
	_finished = call BP_fnc_medicAnim;
	if (_finished) then
	{
		//Remove Fire From Body
		_fire = _item getVariable ["fire",objNull];
		if !(isNull _fire) then
		{
			[_item,_fire] remoteExecCall ["BP_fnc_fireDelete",0];
		};
		
		//Add Gutted Meat
		["medGut",(netID _item),(netID player)] remoteExecCall ["BPServer_fnc_medicalUpdate",2];
	};
};

r_action_gut = false;