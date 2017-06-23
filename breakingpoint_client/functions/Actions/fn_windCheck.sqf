/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

_effect = "#particlesource" createVehicleLocal (getPosATL player);
_effect setParticleClass "PointBubbles2";
sleep 0.25;
deleteVehicle _effect;