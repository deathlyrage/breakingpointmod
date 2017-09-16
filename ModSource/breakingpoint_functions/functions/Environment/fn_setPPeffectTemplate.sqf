/*
	Author: Karel Moricky

	Description:
	Apply post-process effects according to template from CfgPostprocessTemplates

	Parameter(s):
		0: STRING - template class
		1 (Optional): NUMBER - commit time in seconds (default: 0)
		2 (Optional): BOOL - true for global execution (default: true)

	Returns:
	BOOL
*/

#define VALUEVAR	"bis_fnc_setppeffecttemplate_value"

private ["_defaultVar","_cfg","_commit","_isGlobal"];
_defaultVar = missionnamespace getvariable [VALUEVAR,["",0]];

_cfg = [_this,0,_defaultVar select 0,["",configfile]] call bis_fnc_param;
_commit = [_this,1,_defaultVar select 1,[0]] call bis_fnc_param;
_isGlobal = [_this,2,ismultiplayer,[true]] call bis_fnc_param;

/*
if (_isGlobal) exitwith {
	private ["_isPersistent"];
	_isPersistent = isnil {missionnamespace getvariable VALUEVAR};
	missionnamespace setvariable [VALUEVAR,[_cfg,_commit]];
	publicvariable VALUEVAR;
	[[nil,nil,false],_fnc_scriptname,true,_isPersistent] call bis_fnc_mp;
	true
};
*/

//--- Set default PP effect during the first call, so desired PP can transition from it
if (missionnamespace getvariable ["bis_fnc_setppeffecttemplate_first",true]) then {
	missionnamespace setvariable ["bis_fnc_setppeffecttemplate_first",false];
	["Default",0,false] call bis_fnc_setPPeffectTemplate;
};
if (typename _cfg == typename "") then {_cfg = [["CfgPostProcessTemplates",_cfg],configfile >> "CfgPostProcessTemplates" >> "Default"] call bis_fnc_loadClass;};
{
	if (isarray (_cfg >> _x)) then {
		private ["_data"];
		_data = getarray (_cfg >> _x);
		_x ppeffectadjust _data;
		_x ppeffectcommit _commit;
		_x ppeffectenable true;
	} else {
		_x ppeffectenable false;
	};
} foreach ["colorCorrections","filmGrain"];
true