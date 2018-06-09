/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

params [["_object",objNull,[objNull]],["_iLootType","",[""]],["_min",0,[0]],["_max",0,[0]]];

if (isNull _object) exitWith {};
if (_iLootType == "") exitWith {};

// Mission config file loot table override.
_config = configFile >> "CfgObjectLoot" >> _iLootType;
if (isClass (missionConfigFile >> "CfgObjectLoot" >> _iLootType)) then
{
	_config = missionConfigFile >> "CfgObjectLoot" >> _iLootType;
};

_itemTypes =	[] + getArray (_config >> "itemType");
_numItems = floor(random _max);
if (_numItems < _min) then { _numItems = _min; };

while {_numItems > 0} do 
{
	_numItems = _numItems - 1;
	_index = BP_COLBase find _iLootType;
	_weights = BP_COLChances select _index;
	_cntWeights = count _weights;
	_index = floor(random _cntWeights);
	_index = _weights select _index;
	_itemType = _itemTypes select _index;
	
	_itemType params ["_lootClass","_lootType"];
	
	switch (_lootType) do 
	{
		default {};
		case "magazine": {
			_object addMagazineCargoGlobal [_lootClass,1];
		};
		case "weapon": {
			//Add Weapon
			_object addWeaponCargoGlobal [_lootClass,1];

			//Add Random Mags ( Random 0 or 1 )
			_mags = [] + getArray (configFile >> "cfgWeapons" >> _lootClass >> "magazines");
			if ((count _mags) > 0) then {
				_magRndCount = round(random 3);
				_object addMagazineCargoGlobal [(_mags select 0), (_magRndCount)];
			};
		};
		case "weaponA": {
			//Add Weapon
			_object addWeaponCargoGlobal [_lootClass,1];

			//Add Attachments
			_attach = getArray (configFile >> "cfgWeapons" >> _lootClass >> "linkedAttach");
			{
				_object addItemCargoGlobal [_x, 1];
			} count _attach;

			//Add Random Mags ( Random 0 or 1 )
			_mags = [] + getArray (configFile >> "cfgWeapons" >> _lootClass >> "magazines");
			if ((count _mags) > 0) then {
				_magRndCount = round(random 1);
				if (_magRndCount > 0) then {
					_object addMagazineCargoGlobal [(_mags select 0), (_magRndCount)];
				};
			};
		};
		case "weaponNA": {
			_object addWeaponCargoGlobal [_lootClass,1];
		};
		case "vest": {
			_object addItemCargoGlobal [_lootClass,1];
		};
		case "uniform": {
			_object addItemCargoGlobal [_lootClass,1];
		};
		case "headgear": {
			_object addItemCargoGlobal [_lootClass,1];
		};
		case "toolbelt": {
			_object addItemCargoGlobal [_lootClass,1];
		};
		case "backpack": {
			_object addBackpackCargoGlobal [_lootClass,1];
		};
	};
};
