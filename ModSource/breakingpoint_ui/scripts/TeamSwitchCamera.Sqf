disableSerialization;
//	*************************************************************************************
//					Script pro TeamSwitch
//	*************************************************************************************



//	Pozice jednotek
_start_unit = (_this select 0); //Startovni jednotka
_destination_unit = (_this select 1); // Cilova jednotka
_PauseTimeAcc =  (_this select 2); //V jakem spomaleni teamswitch bezi, at je rychlost kamery rovnaka

_p1pos = getPos _start_unit;
_p2pos = getPos _destination_unit;
_px1=_p1pos select 0;
_pz1=_p1pos select 1;
_px2=_p2pos select 0;
_pz2=_p2pos select 1;


_camspeed = (3 / _PauseTimeAcc); //Davam to na zacatek, at se to muze pouzit i na linii 31



// Vytvory a nastavy kameru
_FlyCam = "camera" camCreate [_px1, _pz1 - 4, 2 ];
_FlyCam CameraEffect ["internal","back"];
showcinemaborder false;					//Vypne cinema pruhy
_FlyCam camSetTarget getPos _start_unit;			//Nastavi cil kamery na prvni jednotku
_FlyCam camCommit 0;					//Aktualizace kamery

waitUntil {camCommitted _flycam};			//Cekej dokud neprobehne

_Dist = _destination_unit distance _FlyCam;

_FlyCam camSetTarget getPos _destination_unit;			//Zameri kameru na 2.jednotku
_FlyCam camSetPos [_px1, _pz1 - 4, 2 + _Dist/400];	// Vystoupání kamery nad hrace
_FlyCam camCommit 3;
waitUntil {camCommitted _flycam};


if ((_destination_unit distance _FlyCam) > 10) then
{
	while {((_destination_unit distance _FlyCam)) > 10} do
	{
	
		_FlyCam camCommit (_camspeed * 33); // puvodne 100	
		sleep (0.05 / _PauseTimeAcc);
		_Retarder = ((_destination_unit distance _FlyCam) * (((180 / (_Dist / 100)) / 100)));
		_Retarder = ((_Dist/200) - (sin(_retarder)* (_Dist/200)-2));
		_CamSpeed = ((_destination_unit distance _FlyCam) * (((_retarder / (_Dist / 100)) / 100)));
		_FlyCam camSetPos [_px2, _pz2 - 4,(_p2pos select 2) + (_destination_unit distance _FlyCam)/5];	
		_FlyCam camCommit _CamSpeed;
	};
};

_FlyCam camSetPos [_px2, _pz2 - 5,(_p2pos select 2) + 5];
_FlyCam camCommit _CamSpeed;
waitUntil {camCommitted _flycam};

true;
exit;
