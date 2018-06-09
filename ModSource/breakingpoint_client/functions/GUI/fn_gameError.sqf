/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

scriptName "BP_fnc_gameError";

private ["_msgID","_msg"];
_msgID = _this;
_msg = format ["Invalid BP_fnc_gameError Define for Message ID %1.",_msgID];

if (typeName _msgID == "STRING") then {
	cutText [_msgID, "PLAIN DOWN"];
} else {
	switch (_this) do
	{
		case 1: {
			_msg = "This player doesn't need medical attention.";
		};
		case 2: {
			_msg = "This player is not hungry.";
		};
		case 3: {
			_msg = "This player is not thirsty.";
		};
		case 4: {
			_msg = "No points gained, player still recovering from wounds.";
		};
		case 5: {
			_msg = "No Points are gained on this map.";
		};
		case 6: {
			_msg = "No Points gained. Fresh spawn killed.";
		};
		case 7: {
			_msg = "No Points gained. Buddy killed.";
		};
		case 8: {
			_msg = "The server has entered shutdown mode. All Non-Critical Functionality has been disabled.";
			if (!BP_Debug) then {
				["BP_Shutdown"] call BP_fnc_loginError;
			};
		};
		//Haven Explosive Success
		case 9: {
			_msg = "Successfully Planted IED on Lock.";
		};
		//Haven Explosive Failure
		case 10: {
			_msg = "Failed Planted IED on Lock. You already have a IED on the lock.";
		};
		//Haven Reinforcement Success
		case 11: {
			_msg = "Successfully Reinforced Haven.";
		};
		//Haven Reinforcement Failure
		case 12: {
			_msg = "Failed To Reinforce Haven. Havens can only be reinforced up to level 5.";
		};
	};

	cutText [_msg, "PLAIN DOWN"];
};
