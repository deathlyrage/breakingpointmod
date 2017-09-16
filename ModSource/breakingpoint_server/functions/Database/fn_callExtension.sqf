private "_res";
//_ticketRequest = format ["r:%1",("BreakingPointExt" callExtension format ["s:%1",(format _this)])];
_ticketRequest = "r:" + ("BreakingPointExt" callExtension ("s:" + (format _this)));

uiSleep (random .03);
waitUntil {
	_res = "BreakingPointExt" callExtension _ticketRequest;
	(_res != "WAIT")
};

(parseSimpleArray _res)