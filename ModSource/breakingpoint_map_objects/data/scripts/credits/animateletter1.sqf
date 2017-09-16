//Animation mode 1 - characters enter the screen behind the camera and move away from the camera.
disableSerialization;

private ["_ctrl", "_char", "_pos", "_slot"];
_ctrl = _this select 0;
_char = _this select 1;
_pos = _this select 2;
_slot = _this select 3;

call (compile ("BIS_Credits_Pool" + (str _slot) + " = BIS_Credits_Pool" + (str _slot) + " - [_ctrl]"));

_ctrl ctrlSetText _char;
	
_ctrl ctrlSetPosition [(_pos * 0.03) + 0.1,0.05 + _slot / 400];
_ctrl ctrlSetFade 0;
_ctrl ctrlSetScale 10;
_ctrl ctrlCommit 0;

_ctrl ctrlSetScale 1;
_ctrl ctrlCommit 0.5;

//Make sure the proper text / fade level is set.
sleep 2;

_ctrl ctrlSetText _char;
_ctrl ctrlSetFade 0;
_ctrl ctrlSetPosition [(_pos * 0.03) + 0.1,0.05 + _slot / 400];
_ctrl ctrlSetScale 1;
_ctrl ctrlCommit 0;

/*sleep (2 + ((6 - (_slot / 30)) * ((30 * 0.06) + 0.5)));

_ctrl ctrlSetFade 1;
_ctrl ctrlCommit 1;*/

true