//Receive a ticket id from caller and poll and wait until it returns data
private "_res";
waitUntil {
	_res = "BreakingPointExt" callExtension _this;
	(_res != "WAIT")
};

(parseSimpleArray _res)