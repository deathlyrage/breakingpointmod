/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

switch _this do 
{
	case localize "str_channel_global" : {["str_channel_global",0]};
	case localize "str_channel_side" : {["str_channel_side",1]};
	case localize "str_channel_command" : {["str_channel_command",2]};
	case localize "str_channel_group" : {["str_channel_group",3]};
	case localize "str_channel_vehicle" : {["str_channel_vehicle",4]};
	case localize "str_channel_direct" : {["str_channel_direct",5]};
	case "Ranger": {"Ranger",6};
	case "Nomad": {"Nomad",7};
	case "Outlaw": {"Outlaw",8};
	default {["",-1]};
}