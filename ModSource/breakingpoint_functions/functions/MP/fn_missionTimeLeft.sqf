/*
	Author: Karel Moricky

	Description:
	Returns time in seconds until the mission end.
	Remaining time can be set using 'estimatedTimeLeft' command

	Parameter(s): None
	
	Returns:
	NUMBER - time in seconds. -1 when no time was set yet.
*/

if (estimatedEndServerTime != 0) then {
	(estimatedEndServerTime - servertime) max 0
} else {
	-1
};