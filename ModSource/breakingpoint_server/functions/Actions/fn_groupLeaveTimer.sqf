/*
	Breaking Point Mod for Arma 3
	fn_groupLeaveTimer.sqf created by Th3Dilli
	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/
_groupLeaveTimerOn = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "groupLeaveTimer" >> "groupLeaveTimeOut");
if(_groupLeaveTimerOn > 0) then
{
	params ["_playerNetID"];
	_player = objectFromNetID _playerNetID;

	//Unit Valid
	if (isNull _player) exitWith {};

	//Unit is Player
	if (!isPlayer _player) exitWith {};

	//Unit is alive
	if (!alive _player) exitWith {};

	_playerUID = getPlayerUID _player;
	_groupLeaveTimeOutTime = getNumber (configFile >> "CfgBreakingPointServerSettings" >> "groupLeaveTimer" >> "groupLeaveTimeOut");
	_groupLeaveTimeOutTime = time + _groupLeaveTimeOutTime;
	_groupTimerActive = false;

	////check if player is allready in "BP_groupLeaveTimers" and overwrite
	for [{_i=0}, {_i < (count BP_groupLeaveTimers) && !_groupTimerActive}, {_i = _i + 1}] do
	{
		_checkPlayer = BP_groupLeaveTimers select _i;
		if((_checkPlayer select 0) == _playerUID) then
		{
			(BP_groupLeaveTimers select _i) set [1,_groupLeaveTimeOutTime];
			_groupTimerActive = true;
		};
	};
	if(!_groupTimerActive) then
		{
			BP_groupLeaveTimers pushBack [_playerUID,_groupLeaveTimeOutTime];
		};
};