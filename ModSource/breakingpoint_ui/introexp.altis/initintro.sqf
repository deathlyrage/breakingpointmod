enableSaving [ false, false ];
[
	//--- Blue wall
	{
		["InitDummy",["Altis",[21941.6,21010,0.630594],27.2694,0.27,[5.45456,2.20455],10,0,808.655,0.3,1,1.0407,-0.0480006,1.12922]] call bis_fnc_camera;
	},
	//--- Wind Mills
	//{
	//	["InitDummy",["Altis",[8709.82,12068.3,15.4907],33.9212,0.7,[0,0],0,0,342.867,0.00373997,0,1,0,1]] call bis_fnc_camera;
	//},
	//--- Amphitheatre
	{
		["InitDummy",["Altis",[20065.6,20023,18.9501],21.2237,0.32,[-26.3095,7.33259],10,0,363.087,0,1,1.16209,-0.0469839,1.11101]] call bis_fnc_camera;
	},
	//--- Graveyard
	{
		["InitDummy",["Altis",[17326.7,12626.6,15.327],184.215,0.39,[-29.2857,-8.39286],10,0,1053.76,0,1,1.1006,-0.0305857,1.00442]] call bis_fnc_camera;
	}
] call BIS_fnc_initWorldScene;

setviewdistance 200;

_null = [] spawn {
	while {TRUE} do {
		playMusic "bp_val_34";
		sleep 32;
	};
};