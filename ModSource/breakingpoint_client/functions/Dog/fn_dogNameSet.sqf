/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

disableSerialization;

params ["_dog","_player"];

_createDialog = 
{
	closeDialog 0;
	createDialog "RscDisplayDogName";
	BP_DogNameSet = nil;
	_display = findDisplay 6909;
	_control = _display displayCtrl 1400;
	waitUntil {!isNil "BP_DogNameSet"};
	BP_DogName = ctrlText _control;
	closeDialog 0;
};

_invalid = true;
while {_invalid} do
{
	cutText ["Dog Names are limited from A-Z, 0-9 and 8 characters max.","PLAIN DOWN"];

	call _createDialog;

	_invalid = false;
	_allowedCharacters = toArray ("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .,");
	_currentCharacters = toArray (BP_DogName);
	_charCount = count _currentCharacters;

	{ if !(_x in _allowedCharacters) exitWith {_invalid = true;}; } count _currentCharacters;
	
	if (_charCount > 8) then { _invalid = true};
};

_dog setName [BP_DogName,BP_DogName,""];
_dog setVariable ["bodyName",BP_DogName,true];