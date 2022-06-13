/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgLocationTypes {
	class Airport;	// External class reference
	
	class myairport : Airport {
		name = "CMC Airport";
		drawStyle = "icon";
		color[] = {1, 1, 1, 1};
		size = 32;
		textSize = 0.04;
		shadow = false;
		importance = 2;
		texture = "\newhaven\map_data_newhaven\icons\Airport32_ca.paa";
		font = "PuristaMedium";
	};
	class hospital;	// External class reference
	
	class myhosp : hospital {
		name = "Hospital";
		drawStyle = "icon";
		color[] = {1, 1, 1, 1};
		size = 32;
		textSize = 0.04;
		shadow = false;
		importance = 2;
		texture = "\newhaven\map_data_newhaven\icons\hosp32.paa";
		font = "PuristaMedium";
	};
};
