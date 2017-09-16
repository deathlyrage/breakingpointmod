scriptName "Functions\systems\fn_invAdd.sqf";
/*
	File: fn_invAdd.sqf
	Author: Vilem

	Description:
	Adds item to inventory - checks if there is room for it. Checks if add was done by engine.

	Parameter(s):
	1: <object> unit
	2: <string | config class> inventory item (weapon | magazine | other item) - name or class

	Returns:
	<bool> true if successfully added to inventory
	or
	when forcing add - <array> list of removed items (TODO: indicate fail to add)
*/

private["_return","_unit","_item","_items","_slotsItem","_slotsEmpty","_slotsItem","_success","_slotsAfterAdd","_forceAdd","_forceAddRemovedItems","_successGlob","_removedItems","_lastItem","_c"];
_unit = _this select 0;
_item = _this select 1;
_ammo = _this select 2;
_forceAdd = false; if ((count _this) > 2) then {_forceAdd = _this select 2;};
_forceAddRemovedItems = [];
_removedItems = [];

if ((typeName _unit) != "OBJECT") exitWith {textLogFormat ["INV_ Error: BIS_FNC_invAdd - 1st parameter must be unit! %1", _this];false};
if (((typeName _item) != "CONFIG") && ((typeName _item) != "STRING") && ((typeName _item) != "ARRAY" )) exitWith {textLogFormat ["INV_ Error: BIS_FNC_invAdd - 2nd parameter must be config|string|array of (config|string)! %1", _this];false};
if (isNil {_item})  exitWith {textLogFormat ["INV_ Error: BIS_FNC_invAdd - 2nd parameter - _item is undefined! %1", _this];false};


//sub-function to remove items if forcing add----------------------------------
private ["_fnc_removeItemsToGetEmptySlot"];
_fnc_removeItemsToGetEmptySlot =
{
  private ["_removedItems","_done"]; _removedItems = []; _done = false;
  private ["_slotNo"];

  _unit = _this select 0;
  _slotNo = _this select 1;
  _slotInstancesNeeded = _this select 2;

  _slotInstancesEmpty = 0;

  {
    scopeName "removeItems";

    //if (
    //textLogFormat ["INV_ADD trying to remove: _x %1 (_slotNo %2)", _x, _slotNo];

    private["_slotsToBeFreedByRemovingItem"];
    _slotsToBeFreedByRemovingItem = (([_x] call BIS_fnc_invSlotType) select _slotNo);
    if (_slotsToBeFreedByRemovingItem > 0) then
    {//we can get slot we want by removing -> remove
      //textLogFormat ["INV_ADD --removing: _x %1 (_slotNo %2) [_unit, _x] %3", _x, _slotNo, [_unit, _x]];
      //textLogFormat ["INV_ADD --removing: %1", count ([_unit] call bis_fnc_inv),BIS_fnc_invRemove];
      _removedItems = _removedItems + [_x];
      [_unit, _x,1] call BIS_fnc_invRemove;
      //textLogFormat ["INV_ADD --removing: %1", count ([_unit] call bis_fnc_inv)];
      _slotInstancesNeeded = _slotInstancesNeeded - _slotsToBeFreedByRemovingItem;
    };

    if (_slotInstancesNeeded <= 0) then {BreakOut "removeItems";}; //stop removing items if we have enough place...

  } forEach ([_unit] call BIS_fnc_inv);

  _removedItems
};




textLogFormat ["INV_ADD _unit _item %1", [_unit, _item]];

_items= _item;
if (typename _item !="ARRAY") then {_items=[_item];};

_slotsEmpty = [_unit] call BIS_fnc_invSlotsEmpty;


_lastItem = _items select 0;
_slotsItem = [_lastItem] call BIS_fnc_invSlotType;
_successGlob =true; // for return value
{
	_success = true;
	_item = _x;


	if (_item!=_lastItem) then { // do not need check slot-size if item is same
		_slotsItem = [_item] call BIS_fnc_invSlotType;
	};


	if ((count _slotsEmpty) == 0) exitWith {textLogFormat ["INV_ Error: empty _slotsEmpty __ %1", [_this]];};

	_slotsAfterAdd = [_slotsItem, _slotsEmpty] call BIS_fnc_vectorDiff; //slots empty minus slots for added item (ie. difference of slots item to )


//	textLogFormat ["INV_ADD _slotsItem _slotsEmpty _slotsAfterAdd %1", [_slotsItem, _slotsEmpty, _slotsAfterAdd]];

	private ["_slotNo"]; _slotNo = 0;  //counter
	_c = 0;
	{
	  if (_x < 0) then
	  {//item needs slot that is taken (or not existent)
	    if (_slotsAfterAdd select _c != _slotsEmpty select _c)  then // check only changed slots
	    {
	      if (_forceAdd) then
	      {//go through inventory, remove items that block wanted slot //TODO: ? optimalization - store array with slots taken by items, do not call BIS_fnc_SlotType each time for each item
	        private ["_result"];
	        _removedItems = _removedItems + ([_unit, _slotNo, abs (_x)] call _fnc_removeItemsToGetEmptySlot);
//	        textLogFormat ["INV_ADD _result %1", _result];
	        if (count _result == 0) then {_success = _false};
	      }
	      else
	      {//cannot add (not forcing - not removing items)
	        _success = false;
	      };
	    };
	  };

//	  textLogFormat ["INV_ADD _x slot: %1 ", _x, _success];

	  _slotNo = _slotNo + 1;
	  _c=_c+1;
	} forEach _slotsAfterAdd;


	private ["_invCount0", "_invCount1"]; //checking add success
	_invCount0 = (count (weapons _unit) + count (magazines _unit));

	if (_success) then
	{
	  if ((typeName _item) == "CONFIG") then
	  {
	    if (_item == (configfile >> "cfgweapons" >> (configName _item))) then {_unit addWeapon configName _item;};
	    if (_item == (configfile >> "cfgmagazines" >> (configName _item))) then {_unit addMagazine [configName _item,_ammo];};
	  }
	  else
	  {
	    if ((typeName _item) == "STRING") then
	    {
	      if (isClass (configfile >> "cfgweapons" >> (_item))) then {_unit addWeapon _item;}
	      else
	      {
	        if (isClass (configfile >> "cfgmagazines" >> (_item))) then {_unit addMagazine [_item,_ammo];};
	      };
	    };
	  };
	};

	_invCount1 = (count (weapons _unit) + count (magazines _unit));
	if (_invCount0 == _invCount1) then {_success = false;}; //engine prevented adding (2x lasermarkers forbidden etc.)
	if (_success) then{_slotsEmpty = _slotsAfterAdd;}; //
	_successGlob  = _successGlob and _success;
	_lastItem=_item;

} foreach _items;
if (_forceAdd) exitWith {_removedItems};

_successGlob