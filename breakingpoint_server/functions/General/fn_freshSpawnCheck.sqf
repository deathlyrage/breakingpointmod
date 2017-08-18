private ["_player","_freshSpawn"];
_player = _this;
_freshSpawn = _player getVariable ["freshSpawn",false];
if (_freshSpawn) then
{
	_freshSpawnTime = _player getVariable ["freshSpawnTime",0];
	if ((diag_tickTime - _freshSpawnTime) > 600) then
	{
		_player setVariable ["freshSpawn",nil];
		_player setVariable ["freshSpawnTime",nil];
	};
};