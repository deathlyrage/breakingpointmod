private ["_invalid","_invalidLength","_invalidCharacters","_nameLength","_inStr"];
_invalid = false;
_invalidLength = 20;
_invalidCharacters = [';','!','@','#','$','%','^','&','[',']','{','}',',','.','/','\','|','\','`','<','>','+','-','=','*','_',':'];
_invalidWords = ["exec","local","remote","createVehicle","createVehicleLocal","mission","INSERT","DELETE","SELECT","BIS",".com","www.","youtube",".tv"];
_invalidUnicode = [21,22,23,24,25,26,27];

//Check Name Length
_nameArray = (toArray _this);
_nameLength = (count _nameArray);
if (_nameLength > _invalidLength) exitWith {true};

//Check For Characters
{
	//if ((toArray _x) in _nameArray) exitWith { _invalid = true; };
	_inStr = [_this,_x,false] call BP_fnc_inString;
	if (_inStr) exitWith { _invalid = true; };
} foreach _invalidCharacters;

//Manually Check Special Characters via Unicode ID
{
	if (_x in _nameArray) exitWith { _invalid = true; };
} foreach _invalidUnicode;

//Check For Words
{
	_inStr = [_this,_x,false] call BP_fnc_inString;
	if (_inStr) exitWith { _invalid = true; };
} foreach _invalidWords;

_invalid