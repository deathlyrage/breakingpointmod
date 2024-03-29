
params ["_unit","_bool","_channel"];

//Series of checks?
if (isNull _unit) exitWith {}; //Null unit
if (_channel < 1) exitWith {}; //No channels below 1 should be passed.

switch (_channel) do
{
	case 1: { if (_bool) then {BP_Radio_Ranger radioChannelAdd [_unit];} else {BP_Radio_Ranger radioChannelRemove [_unit];};};
	case 2: { if (_bool) then {BP_Radio_Outlaw radioChannelAdd [_unit];} else {BP_Radio_Outlaw radioChannelRemove [_unit];};};
	case 3: { if (_bool) then {BP_Radio_Nomad radioChannelAdd [_unit];} else {BP_Radio_Nomad radioChannelRemove [_unit];};};
	case 4: { if (_bool) then {BP_Radio_Hunter radioChannelAdd [_unit];} else {BP_Radio_Hunter radioChannelRemove [_unit];};};
	case 5: { if (_bool) then {BP_Radio_Engineer radioChannelAdd [_unit];} else {BP_Radio_Engineer radioChannelRemove [_unit];};};
	case 6: { if (_bool) then {BP_Radio_Survivalist radioChannelAdd [_unit];} else {BP_Radio_Survivalist radioChannelRemove [_unit];};};
	case 7: { if (_bool) then {BP_Radio_Watchers radioChannelAdd [_unit];} else {BP_Radio_Watchers radioChannelRemove [_unit];};};	
};