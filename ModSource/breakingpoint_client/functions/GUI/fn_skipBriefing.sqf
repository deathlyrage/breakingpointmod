/*
    Breaking Point Mod for Arma 3

    Released under Arma Public Share Like Licence (APL-SA)
    https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Alderon Games Pty Ltd
*/

if (!isDedicated) then 
{
	//Von Handles
	VoN_Time = 0;

    0 = [] spawn 
	{
        VoN_isOn = false;
        VoN_currentTxt = "";
        VoN_channelId = -1;
        _fncDown = {
            if (!VoN_isOn) then {
                if (!isNull findDisplay 55 && !isNull findDisplay 63) then {
                    VoN_isOn = true;
                    ctrlText (findDisplay 63 displayCtrl 101)
                    call BP_fnc_vonEvent;
                    findDisplay 55 displayAddEventHandler ["Unload", {
                        VoN_isOn = false;
                        "" call BP_fnc_vonEvent;
                    }]; 
                };
            };
            false
        };
        _fncUp = {
            if (VoN_isOn) then {
                _ctrlText = ctrlText (findDisplay 63 displayCtrl 101);
                if (VoN_currentTxt != _ctrlText) then {
                    _ctrlText call BP_fnc_vonEvent;
                };
            };
            false
        };
        waitUntil {!isNull findDisplay 46};
        findDisplay 46 displayAddEventHandler ["KeyDown", _fncDown];
        findDisplay 46 displayAddEventHandler ["KeyUp", _fncUp];
        findDisplay 46 displayAddEventHandler ["MouseButtonDown", _fncDown];
        findDisplay 46 displayAddEventHandler ["MouseButtonUp", _fncUp];
        findDisplay 46 displayAddEventHandler ["JoystickButton", _fncDown];
    };

	//Skip Briefing
	0 = [] spawn {
		waitUntil {
			if (getClientState == "BRIEFING READ") exitWith {true}; 
			if (!isNull findDisplay 53) exitWith { 
				ctrlActivate (findDisplay 53 displayCtrl 1);
				findDisplay 53 closeDisplay 1;
				true
			};
			false 
		};
	};

};