/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private ["_body","_name","_method","_methodStr"];
_body = (_this select 3);
_name = _body getVariable ["bodyName","unknown"];
_method = _body getVariable ["deathType",0];
_methodStr = "";

switch (_method) do
{
	case 1: { _methodStr = "small caliber handgun fire.";  };
	case 2: { _methodStr = "large caliber handgun fire.";  };
	case 3: { _methodStr = "small caliber rifle fire.";  };
	case 4: { _methodStr = "large caliber rifle fire.";  };
	case 5: { _methodStr = "extremely large caliber rifle fire.";  };
	case 6: { _methodStr = "buckshot.";  };
	case 7: { _methodStr = "being stabbed to death.";  };
	case 8: { _methodStr = "zombies.";  };
	case 9: { _methodStr = "starvation.";  };
	case 10: { _methodStr = "dehydration.";  };
	case 11: { _methodStr = "a fall.";  };
	case 12: { _methodStr = "an explosion";  };
	case 13: { _methodStr = "being run over by a vehicle.";  };
	case 14: { _methodStr = "illness.";  };
	case 15: { _methodStr = "an adrenaline overdose";  };
	case 16: { _methodStr = "a bullet to the head."; };
	case 17: { _methodStr = "blood loss."; };
	case 18: { _methodStr = "a bullet to the heart."; };
	default { _methodStr = "an unknown cause."; };
};

_groupID = _body getVariable ["group","0"];
if (_groupID != "0") then
{
	_groupTag = _body getVariable ["groupTag",""];
	_groupName = _body getVariable ["groupName",""];
	cutText [format["[%1] %2 from Legion '%3' appears to have died from %4",_groupTag,_name,_groupName,_methodStr], "PLAIN DOWN"];
} else {
	cutText [format["%1 appears to have died from %2",_name,_methodStr], "PLAIN DOWN"];
};