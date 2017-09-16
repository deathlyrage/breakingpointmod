/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params ["","","","_body"];

player removeAction s_player_lootbody;
s_player_lootbody = -1;
player removeAction s_player_studybody;
s_player_studybody = -1;

if (isNull _body) exitWith {};

//Handle Traitor Flag
//_ai = _body getVariable ["ai",false];
//if (_ai) then
//{
//	if (BP_FactionStronghold > 0) then
//	{
//		//Check if Player is Friendly with AI not Not.
//		if (side player == civilian) then {
//			//FLag Player as Traitor
//			player setVariable ["traitorFlag",true,true];
//			
//			//Check Strongholds
//			call BP_fnc_strongholdCheck;
//			
//			//Check Faction Specific Clothing
//			call BP_fnc_checkFactionClothing;
//		};
//	};
//};

//Enable Simulation If It Isn't Already
if !(simulationEnabled _body) then { _body enableSimulation true; };

//Delay
sleep 1;

//Handle Animation Result
_finished = call BP_fnc_medicAnim;

if (_finished) then 
{
	//Remove Fire
	_fire = _body getVariable ["fire",objNull];
	if !(isNull _fire) then
	{
		[_body,_fire] remoteExecCall ["BP_fnc_fireDelete",0];
	};
	
	//Loot Remains
	[(netID player),(netID _body)] remoteExecCall ["BPServer_fnc_playerLoot",2];
} else {
	r_interrupt = false;
	player switchMove "";
	player playActionNow "stop";
};
