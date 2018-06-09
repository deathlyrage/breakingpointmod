_container = objectFromNetID (_this select 0);
_player = objectFromNetID (_this select 1);

if (isNull _container) exitWith {};
if (isNull _player) exitWith {};

["containerTakeAll: %1 %2",_container,_player] call BP_fnc_debugConsoleFormat;

//Fetch Container Inventory & Remove Contents to Prevent Duplication
_containerMags = magazinesAmmoCargo _container;
clearMagazineCargoGlobal _container;
_containerItems = itemCargo _container;
clearItemCargoGlobal _container;

//Add Magazines
0 = 
{
	_x params ["_magName","_magAmmo"];

	//Attempt Add to Player
	if (_player canAdd _magName) then
	{
		_player addMagazine [_magName,_magAmmo];
	} else {
		_container addMagazineAmmoCargo [_magName,1,_magAmmo];
	};	
} count _containerMags;

//Add Items
0 = 
{
	//Attempt Add to Player
	if (_player canAdd _x) then
	{
		_player addItem _x;
	} else {
		_container addItemCargoGlobal [_x,1];
	};
} count _containerItems;