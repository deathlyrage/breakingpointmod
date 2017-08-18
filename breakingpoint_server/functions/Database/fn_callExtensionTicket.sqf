//Create Ticket For Async MySQL Call and Return Ticket ID
//(format ["r:%1",("BreakingPointExt" callExtension format ["s:%1",(format _this)])])
("r:" + ("BreakingPointExt" callExtension ("s:" + (format _this))))