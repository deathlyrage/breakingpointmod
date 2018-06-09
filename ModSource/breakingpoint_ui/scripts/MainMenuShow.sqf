disableSerialization;
private ["_control", "_dialog"];
_control = _this select 0;
_dialog = ctrlParent _control;


_display = ctrlParent ( _this select 0);
 
_control = _display displayctrl 8001;
_pos = ctrlPosition _control  ;


_function_showMenu = 
{
	//Enable controls for proper function of focus;
	(_dialog displayCtrl 117) ctrlEnable true; 
	(_dialog displayCtrl 101) ctrlEnable true;
	(_dialog displayCtrl 105) ctrlEnable true;
	(_dialog displayCtrl 115) ctrlEnable true;	
	//Zmizeni kontrolu:
	(_dialog displayCtrl 117) ctrlSetFade 1;
	(_dialog displayCtrl 8001) ctrlSetFade 1;
	(_dialog displayCtrl 8002) ctrlSetFade 1;
	(_dialog displayCtrl 8003) ctrlSetFade 1;
	
	(_dialog displayCtrl 101) ctrlSetFade 1;
	(_dialog displayCtrl 8101) ctrlSetFade 1;
	(_dialog displayCtrl 8102) ctrlSetFade 1;
	(_dialog displayCtrl 8103) ctrlSetFade 1;
	
	(_dialog displayCtrl 105) ctrlSetFade 1;
	(_dialog displayCtrl 8201) ctrlSetFade 1;
	(_dialog displayCtrl 8202) ctrlSetFade 1;
	(_dialog displayCtrl 8203) ctrlSetFade 1;
	
	(_dialog displayCtrl 115) ctrlSetFade 1;
	(_dialog displayCtrl 8301) ctrlSetFade 1;
	(_dialog displayCtrl 8302) ctrlSetFade 1;
	(_dialog displayCtrl 8303) ctrlSetFade 1;
	
	(_dialog displayCtrl 117) ctrlCommit 0;
	(_dialog displayCtrl 8001) ctrlCommit 0;
	(_dialog displayCtrl 8002) ctrlCommit 0;
	(_dialog displayCtrl 8003) ctrlCommit 0;
	
	(_dialog displayCtrl 101) ctrlCommit 0;
	(_dialog displayCtrl 8101) ctrlCommit 0;
	(_dialog displayCtrl 8102) ctrlCommit 0;
	(_dialog displayCtrl 8103) ctrlCommit 0;
	
	(_dialog displayCtrl 105) ctrlCommit 0;
	(_dialog displayCtrl 8201) ctrlCommit 0;
	(_dialog displayCtrl 8202) ctrlCommit 0;
	(_dialog displayCtrl 8203) ctrlCommit 0;
	
	(_dialog displayCtrl 115) ctrlCommit 0;
	(_dialog displayCtrl 8301) ctrlCommit 0;
	(_dialog displayCtrl 8302) ctrlCommit 0;
	(_dialog displayCtrl 8303) ctrlCommit 0;
	
	//Presun pod "PLAY"
	(_dialog displayCtrl 117) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8001) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8002) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8003) ctrlSetPosition [0.408,0.78];
	
	(_dialog displayCtrl 101) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8101) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8102) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8103) ctrlSetPosition [0.545,0.78];
	
	(_dialog displayCtrl 105) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8201) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8202) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8203) ctrlSetPosition [0.688,0.78];
	
	(_dialog displayCtrl 115) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8301) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8302) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8303) ctrlSetPosition [0.688,0.78];
	
	(_dialog displayCtrl 117) ctrlCommit 0;
	(_dialog displayCtrl 8001) ctrlCommit 0;
	(_dialog displayCtrl 8002) ctrlCommit 0;
	//(_dialog displayCtrl 8003) ctrlCommit 0;
	
	(_dialog displayCtrl 101) ctrlCommit 0;
	(_dialog displayCtrl 8101) ctrlCommit 0;
	(_dialog displayCtrl 8102) ctrlCommit 0;
	//(_dialog displayCtrl 8103) ctrlCommit 0;
	
	(_dialog displayCtrl 105) ctrlCommit 0;
	(_dialog displayCtrl 8201) ctrlCommit 0;
	(_dialog displayCtrl 8202) ctrlCommit 0;
	//(_dialog displayCtrl 8203) ctrlCommit 0;
	
	(_dialog displayCtrl 115) ctrlCommit 0;
	(_dialog displayCtrl 8301) ctrlCommit 0;
	(_dialog displayCtrl 8302) ctrlCommit 0;
	//(_dialog displayCtrl 8303) ctrlCommit 0;
	
	//Znovu objeveni kontrolu:
	(_dialog displayCtrl 117) ctrlSetFade 0;
	(_dialog displayCtrl 8001) ctrlSetFade 0;
	(_dialog displayCtrl 8002) ctrlSetFade 0;
	//(_dialog displayCtrl 8003) ctrlSetFade 0;
	
	(_dialog displayCtrl 101) ctrlSetFade 0;
	(_dialog displayCtrl 8101) ctrlSetFade 0;
	(_dialog displayCtrl 8102) ctrlSetFade 0;
	//(_dialog displayCtrl 8103) ctrlSetFade 0;
	
	(_dialog displayCtrl 105) ctrlSetFade 0;
	(_dialog displayCtrl 8201) ctrlSetFade 0;
	(_dialog displayCtrl 8202) ctrlSetFade 0;
	//(_dialog displayCtrl 8203) ctrlSetFade 0;
	
	(_dialog displayCtrl 115) ctrlSetFade 0;
	(_dialog displayCtrl 8301) ctrlSetFade 0;
	(_dialog displayCtrl 8302) ctrlSetFade 0;
	//(_dialog displayCtrl 8303) ctrlSetFade 0;
	
	
	(_dialog displayCtrl 117) ctrlCommit 1;
	(_dialog displayCtrl 8001) ctrlCommit 1;
	(_dialog displayCtrl 8002) ctrlCommit 1;
	//(_dialog displayCtrl 8003) ctrlCommit 1;
	
	(_dialog displayCtrl 101) ctrlCommit 1;
	(_dialog displayCtrl 8101) ctrlCommit 1;
	(_dialog displayCtrl 8102) ctrlCommit 1;
	//(_dialog displayCtrl 8103) ctrlCommit 1;
	
	(_dialog displayCtrl 105) ctrlCommit 1;
	(_dialog displayCtrl 8201) ctrlCommit 1;
	(_dialog displayCtrl 8202) ctrlCommit 1;
	//(_dialog displayCtrl 8203) ctrlCommit 1;
	
	(_dialog displayCtrl 115) ctrlCommit 1;
	(_dialog displayCtrl 8301) ctrlCommit 1;
	(_dialog displayCtrl 8302) ctrlCommit 1;
	//(_dialog displayCtrl 8303) ctrlCommit 1;
	
	//Presun na mista:
	(_dialog displayCtrl 117) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8001) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8002) ctrlSetPosition [0.55,0.64];

	
	(_dialog displayCtrl 101) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8101) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8102) ctrlSetPosition [0.55,0.64];

	
	(_dialog displayCtrl 105) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8201) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8202) ctrlSetPosition [0.55,0.64];

	
	(_dialog displayCtrl 115) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8301) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8302) ctrlSetPosition [0.55,0.64];

	
	
	(_dialog displayCtrl 117) ctrlCommit 0.8;
	(_dialog displayCtrl 8001) ctrlCommit 0.8;
	(_dialog displayCtrl 8002) ctrlCommit 0.8;
	//(_dialog displayCtrl 8003) ctrlCommit 0.8;
	
	(_dialog displayCtrl 101) ctrlCommit 0.8;
	(_dialog displayCtrl 8101) ctrlCommit 0.8;
	(_dialog displayCtrl 8102) ctrlCommit 0.8;
	//(_dialog displayCtrl 8103) ctrlCommit 0.8;
	
	(_dialog displayCtrl 105) ctrlCommit 0.8;
	(_dialog displayCtrl 8201) ctrlCommit 0.8;
	(_dialog displayCtrl 8202) ctrlCommit 0.8;
	//(_dialog displayCtrl 8203) ctrlCommit 0.8;
	
	(_dialog displayCtrl 115) ctrlCommit 0.8;
	(_dialog displayCtrl 8301) ctrlCommit 0.8;
	(_dialog displayCtrl 8302) ctrlCommit 0.8;
	//(_dialog displayCtrl 8303) ctrlCommit 0.8;
	
	
	(_dialog displayCtrl 117) ctrlSetPosition [0.41,0.64];
	(_dialog displayCtrl 8001) ctrlSetPosition [0.41,0.64];
	(_dialog displayCtrl 8002) ctrlSetPosition [0.41,0.64];
	(_dialog displayCtrl 8003) ctrlSetPosition [0.392,0.78];	
//	(_dialog displayCtrl 8003) ctrlSetPosition [0.408,0.78];
	
	(_dialog displayCtrl 101) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8101) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8102) ctrlSetPosition [0.55,0.64];
	(_dialog displayCtrl 8103) ctrlSetPosition [0.532,0.78];
	
	(_dialog displayCtrl 105) ctrlSetPosition [0.69,0.64];
	(_dialog displayCtrl 8201) ctrlSetPosition [0.69,0.64];
	(_dialog displayCtrl 8202) ctrlSetPosition [0.69,0.64];
	(_dialog displayCtrl 8203) ctrlSetPosition [0.673,0.78];
	
	(_dialog displayCtrl 115) ctrlSetPosition [0.55,0.46];
	(_dialog displayCtrl 8301) ctrlSetPosition [0.55,0.46];
	(_dialog displayCtrl 8302) ctrlSetPosition [0.55,0.46];
	(_dialog displayCtrl 8303) ctrlSetPosition [0.532,0.6];
	
	
	(_dialog displayCtrl 117) ctrlCommit 0.3;
	(_dialog displayCtrl 8001) ctrlCommit 0.3;
	(_dialog displayCtrl 8002) ctrlCommit 0.3;
	(_dialog displayCtrl 8003) ctrlCommit 0.1;
	
	(_dialog displayCtrl 101) ctrlCommit 0.3;
	(_dialog displayCtrl 8101) ctrlCommit 0.3;
	(_dialog displayCtrl 8102) ctrlCommit 0.3;
	(_dialog displayCtrl 8103) ctrlCommit 0.1;
	
	(_dialog displayCtrl 105) ctrlCommit 0.3;
	(_dialog displayCtrl 8201) ctrlCommit 0.3;
	(_dialog displayCtrl 8202) ctrlCommit 0.3;
	(_dialog displayCtrl 8203) ctrlCommit 0.1;
	
	(_dialog displayCtrl 115) ctrlCommit 0.3;
	(_dialog displayCtrl 8301) ctrlCommit 0.3;
	(_dialog displayCtrl 8302) ctrlCommit 0.3;
	(_dialog displayCtrl 8303) ctrlCommit 0.1;
	
	(_dialog displayCtrl 8003) ctrlSetFade 0;
	(_dialog displayCtrl 8103) ctrlSetFade 0;
	(_dialog displayCtrl 8203) ctrlSetFade 0;
	(_dialog displayCtrl 8303) ctrlSetFade 0;
	
	(_dialog displayCtrl 8003) ctrlCommit 1;
	(_dialog displayCtrl 8103) ctrlCommit 1;
	(_dialog displayCtrl 8203) ctrlCommit 1;
	(_dialog displayCtrl 8303) ctrlCommit 1;
	true;
};


_function_hideMenu = 
{
	private  ["_hide_delay"];
	_hide_delay = 0.3;
	
	//Disable controls so they don't get focus when hidden;
	(_dialog displayCtrl 117) ctrlEnable false; 
	(_dialog displayCtrl 101) ctrlEnable false;
	(_dialog displayCtrl 105) ctrlEnable false;
	(_dialog displayCtrl 115) ctrlEnable false;
		
	
	//Presun na mista:
	(_dialog displayCtrl 117) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8001) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8002) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8003) ctrlSetPosition [0.55,0.825];
	
	(_dialog displayCtrl 101) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8101) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8102) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8103) ctrlSetPosition [0.545,0.78];
	
	(_dialog displayCtrl 105) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8201) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8202) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8203) ctrlSetPosition [0.545,0.78];
	
	(_dialog displayCtrl 115) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8301) ctrlSetPosition [0.55,0.825];
	(_dialog displayCtrl 8302) ctrlSetPosition [0.55,0.825];
	//(_dialog displayCtrl 8303) ctrlSetPosition [0.545,0.78];
	
	(_dialog displayCtrl 117) ctrlSetFade 1;
	(_dialog displayCtrl 8001) ctrlSetFade 1;
	(_dialog displayCtrl 8002) ctrlSetFade 1;
	(_dialog displayCtrl 8003) ctrlSetFade 1;
	
	(_dialog displayCtrl 101) ctrlSetFade 1;
	(_dialog displayCtrl 8101) ctrlSetFade 1;
	(_dialog displayCtrl 8102) ctrlSetFade 1;
	(_dialog displayCtrl 8103) ctrlSetFade 1;
	
	(_dialog displayCtrl 105) ctrlSetFade 1;
	(_dialog displayCtrl 8201) ctrlSetFade 1;
	(_dialog displayCtrl 8202) ctrlSetFade 1;
	(_dialog displayCtrl 8203) ctrlSetFade 1;
	
	(_dialog displayCtrl 115) ctrlSetFade 1;
	(_dialog displayCtrl 8301) ctrlSetFade 1;
	(_dialog displayCtrl 8302) ctrlSetFade 1;
	(_dialog displayCtrl 8303) ctrlSetFade 1;
	
	
	(_dialog displayCtrl 117) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8001) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8002) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8003) ctrlCommit _hide_delay/3;
	
	(_dialog displayCtrl 101) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8101) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8102) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8103) ctrlCommit _hide_delay/3;
	
	(_dialog displayCtrl 105) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8201) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8202) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8203) ctrlCommit _hide_delay/3;
	
	(_dialog displayCtrl 115) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8301) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8302) ctrlCommit _hide_delay;
	(_dialog displayCtrl 8303) ctrlCommit _hide_delay/3;
	sleep _hide_delay;

// schování mimo obrazovku
	(_dialog displayCtrl 117) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8001) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8002) ctrlSetPosition [2.55546,2.829];
	(_dialog displayCtrl 8003) ctrlSetPosition [2.545,2.9];
	
	(_dialog displayCtrl 101) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8101) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8102) ctrlSetPosition [2.55546,2.829];
	(_dialog displayCtrl 8103) ctrlSetPosition [2.545,2.9];
	
	(_dialog displayCtrl 105) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8201) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8202) ctrlSetPosition [2.55546,2.829];
	(_dialog displayCtrl 8203) ctrlSetPosition [2.545,2.9];
	
	(_dialog displayCtrl 115) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8301) ctrlSetPosition [2.55,2.825];
	(_dialog displayCtrl 8302) ctrlSetPosition [2.55546,2.829];
	(_dialog displayCtrl 8303) ctrlSetPosition [2.545,2.9];
	
	(_dialog displayCtrl 117) ctrlCommit 0.1;
	(_dialog displayCtrl 8001) ctrlCommit 0.1;
	(_dialog displayCtrl 8002) ctrlCommit 0.1;
	(_dialog displayCtrl 8003) ctrlCommit 0.1;
	
	(_dialog displayCtrl 101) ctrlCommit 0.1;
	(_dialog displayCtrl 8101) ctrlCommit 0.1;
	(_dialog displayCtrl 8102) ctrlCommit 0.1;
	(_dialog displayCtrl 8103) ctrlCommit 0.1;
	
	(_dialog displayCtrl 105) ctrlCommit 0.1;
	(_dialog displayCtrl 8201) ctrlCommit 0.1;
	(_dialog displayCtrl 8202) ctrlCommit 0.1;
	(_dialog displayCtrl 8203) ctrlCommit 0.1;
	
	(_dialog displayCtrl 115) ctrlCommit 0.1;
	(_dialog displayCtrl 8301) ctrlCommit 0.1;
	(_dialog displayCtrl 8302) ctrlCommit 0.1;
	(_dialog displayCtrl 8303) ctrlCommit 0.1;
	true;
};


	if ((_pos select 0) > 1)  then 
	{
		call _function_showMenu;
	} 
	else
	{
		call _function_hideMenu;
	};


//"resource" diag_enable true;

true
