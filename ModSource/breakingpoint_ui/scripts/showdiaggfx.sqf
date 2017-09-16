disableSerialization;
private  ["_y","_x"];

_control = (_this select 0);
_dialog = ctrlParent _control;

_control = (_dialog displayCtrl 1002);

_posX = ((ctrlPosition _control ) select 0); 
_posY = ((ctrlPosition _control ) select 1);

if (_posY < -10 ) then {
	_y = 10;
	setaperture 1;
} else {
	_y = -10;
	setaperture 0;
};

for [{_x=0},{_x<=(1110)},{_x=_x+1}] do 
{
	_control = (_dialog displayCtrl _x);
	_posX = ((ctrlPosition _control ) select 0); 
	_posY = ((ctrlPosition _control ) select 1);

	_control ctrlSetPosition [(_posX + _y), (_posY + _y)]; 		
	_control ctrlCommit 0;	

};

true;
