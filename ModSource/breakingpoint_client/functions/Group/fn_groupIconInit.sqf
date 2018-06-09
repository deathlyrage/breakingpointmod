/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

//Group Icons - Init
r_group_count = 0;
r_group_members = [];
r_group_membersIcons = [];

r_group_colours =
[
	[1, 1, 1, 1],		//None (White)
	[1, 0, 0, 1], 		//Red
	[0, 1, 0, 1], 		//Green
	[0, 0, 1, 1], 		//Blue
	[0.85, 0.85, 0, 1], 	//Yellow
	[0.85, 0.4, 0, 1], 	//Orange
	[0.7, 0.7, 0.7, 1],	//Light Grey
	[0.4, 0.8, 0.2, 1], 	//Pale Green
	[30, 216, 216, 1],	//Teal
	[51, 0, 0, 1], 		//Dark Red
	[0, 204, 102, 1], 	//Light Green
	[128, 128, 0, 1], 	//Olive
	[0, 0, 128, 1], 		//Navy
	[255, 215, 0, 1], 	//Gold
	[210, 180, 140, 1], 	//Tan
	[167, 30, 216, 1],	//Purple
	[216, 30, 191, 1],		//Pink
	
	//Duplicated Colours again to prevent script errors
	[1, 1, 1, 1],		//None (White)
	[1, 0, 0, 1], 		//Red
	[0, 1, 0, 1], 		//Green
	[0, 0, 1, 1], 		//Blue
	[0.85, 0.85, 0, 1], 	//Yellow
	[0.85, 0.4, 0, 1], 	//Orange
	[0.7, 0.7, 0.7, 1],	//Light Grey
	[0.4, 0.8, 0.2, 1], 	//Pale Green
	[30, 216, 216, 1],	//Teal
	[51, 0, 0, 1], 		//Dark Red
	[0, 204, 102, 1], 	//Light Green
	[128, 128, 0, 1], 	//Olive
	[0, 0, 128, 1], 		//Navy
	[255, 215, 0, 1], 	//Gold
	[210, 180, 140, 1], 	//Tan
	[167, 30, 216, 1],	//Purple
	[216, 30, 191, 1]		//Pink
];