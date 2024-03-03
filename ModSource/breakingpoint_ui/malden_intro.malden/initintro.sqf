enableSaving [ false, false ];
[
	/*//---0 Lighthouse bay
	{
		["InitDummy",["Malden",[7564.71,2692.03,6.89921],37.4215,0.75,[-7.97729,0],0,0,0.0260889,0.3,1,1,0,1]] call bis_fnc_camera;
		setdate [2035,7,1,5,44];
	},*/
	//---1 BusStop La Pessagne - Final
//	{
//		["InitDummy",["Malden",[3124.86,6341.82,2.01254],64.71,0.75,[-9.20459,0],0,0,540.046,0.3,1,1,0,1]] call bis_fnc_camera;
//		setdate [2035,7,1,5,44];
//	},
//	//---2 Houdan Farm
//	{
//		["InitDummy",["Malden",[6626.68,6065.05,2.64275],241.263,0.75,[-10.0227,0],2.11996,0,541.834,0.3,1,1,0,1]] call bis_fnc_camera;
//		setdate [2035,7,1,5,44];
//		setviewdistance 200;
//	},
//	//---3 Le Port crossroad
//	{
//		["InitDummy",["Malden",[7883.64,4067.09,1.70904],32.3639,0.75,[-2.65909,0],2.17213,0,540.014,0.3,1,1,0,1]] call bis_fnc_camera;
//		setdate [2035,7,1,5,44];
//		setviewdistance 200;
//	},
//	//---4 Desert
//	{
//		["InitDummy",["Malden",[7578.11,10901.1,3.65216],65.1881,0.75,[-18.8182,0],2.48519,0,540.027,0.3,0.941398,1,0,1]] call bis_fnc_camera;
//		setdate [2035,7,1,5,44];
//		setviewdistance 200;
//	},
	//---5 Backyard
	{
		["InitDummy",["Malden",[750.351,12179.7,7.952],149.469,0.75,[-47.0138,5.23464],10,0,379.019,0.382607,0.546957,1,0,1]] call bis_fnc_camera;
		setdate [2035,7,1,5,44];
	}
] call BIS_fnc_initWorldScene;

0 fademusic 0.7;
playMusic "bp_val_34";
addMusicEventHandler ["MusicStop", {[] spawn {sleep 12; playMusic "bp_val_34"}}];