//Animation mode 0 - characters enter the screen from the left and arch towards the camera.
disableSerialization;

private ["_ctrl", "_char", "_pos", "_slot"];
_ctrl = _this select 0;
_char = _this select 1;
_pos = _this select 2;
_slot = _this select 3;

//Remove control from pool.
call (compile ("BIS_Credits_Pool" + (str _slot) + " = BIS_Credits_Pool" + (str _slot) + " - [_ctrl]"));

//Assign correct character.
_ctrl ctrlSetText _char;

//Start animation.
_ctrl ctrlSetPosition [-0.1, 0.3];
_ctrl ctrlSetFade 0;
_ctrl ctrlSetScale 0.2;
_ctrl ctrlCommit 0;

_ctrl ctrlSetPosition [(_pos * 0.03) + 0.1,0.05 + _slot / 400];
_ctrl ctrlCommit 0.5;

_ctrl ctrlSetScale 4;
_ctrl ctrlCommit 0.25;

sleep 0.25;

_ctrl ctrlSetScale 1;
_ctrl ctrlCommit 0.25;

//Make sure the proper text / fade level is set.
sleep 2;

_ctrl ctrlSetText _char;
_ctrl ctrlSetFade 0;
_ctrl ctrlSetPosition [(_pos * 0.03) + 0.1,0.05 + _slot / 400];
_ctrl ctrlSetScale 1;
_ctrl ctrlCommit 0;

/*sleep ((2 + ((6 - (_slot / 30)) * ((30 * 0.06) + 0.5))) - 0.25);

_ctrl ctrlSetFade 1;
_ctrl ctrlCommit 1;*/

true