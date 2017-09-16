/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

private["_qty","_vehicle"];
_vehicle = _this select 0;
_qty = _this select 1;

if (isServer) then{
    if(local _vehicle) then {
        _vehicle setFuel _qty;
    };
};

if (!isDedicated) then {
    _vehicle setFuel _qty;
};

