/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_obj = player;
{
	_obj = _x;
	{
		_obj removeAction _x;
	} forEach r_player_actions;
} forEach r_action_targets;
r_player_actions = [];
r_action_targets = [];