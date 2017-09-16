//Animation mode 3 - characters enter the screen from a random position outside the screen.
disableSerialization;

private ["_ctrl", "_char", "_pos", "_slot"];
_ctrl = _this select 0;
_char = _this select 1;
_pos = _this select 2;
_slot = _this select 3;

call (compile ("BIS_Credits_Pool" + (str _slot) + " = BIS_Credits_Pool" + (str _slot) + " - [_ctrl]"));

_ctrl ctrlSetText _char;

//Select a random quadrant and position.
private ["_quadrant", "_rdmX", "_rdmY"];
_quadrant = random 4;
_quadrant = _quadrant - (_quadrant % 1);

switch (_quadrant) do 
{
	case 0: 
	{
		_rdmX = -0.1;
		_rdmY = (random 1);
	};
	
	case 1: 
	{
		_rdmX = (random 1);
		_rdmY = -0.1;
	};
	
	case 2: 
	{
		_rdmX = 1.1;
		_rdmY = (random 1);
	};
	
	case 3: 
	{
		_rdmX = (random 1);
		_rdmY = 1.1;
	};
	
	default {};			
};
	
_ctrl ctrlSetPosition [_rdmX, _rdmY];
_ctrl ctrlSetFade 0;
_ctrl ctrlSetScale 1;
_ctrl ctrlCommit 0;

_ctrl ctrlSetPosition [(_pos * 0.03) + 0.1,0.05 + _slot / 400];
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