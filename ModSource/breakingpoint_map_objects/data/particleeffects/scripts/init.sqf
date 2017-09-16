_v=_this select 0;
if(isNil 'BIS_Effects_Init') then
	{
	BIS_Effects_Init=true;
	BIS_Effects_EH_Fired=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\fired.sqf";
	BIS_Effects_EH_Killed=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\killed.sqf";

	BIS_Effects_Rifle=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\rifle.sqf";
	BIS_Effects_Cannon=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\cannon.sqf";
	BIS_Effects_HeavyCaliber=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\heavycaliber.sqf";
	BIS_Effects_HeavySniper=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\heavysniper.sqf";
	BIS_Effects_Rocket=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\rocket.sqf";
	BIS_Effects_SmokeShell=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\smokeshell.sqf";
	BIS_Effects_SmokeLauncher=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\smokelauncher.sqf";
	BIS_Effects_Flares=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\flares.sqf";

	//must use spawn command for these:
	BIS_Effects_Burn=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\destruction\burn.sqf";
	BIS_Effects_AircraftVapour=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\misc\aircraftvapour.sqf";
	BIS_Effects_AirDestruction=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\destruction\AirDestruction.sqf";
	BIS_Effects_AirDestructionStage2=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\destruction\AirDestructionStage2.sqf";
	BIS_Effects_Secondaries=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\destruction\Secondaries.sqf";
	//BIS_Effects_RocketTrail=compile preprocessFileLineNumbers "\ca\Data\ParticleEffects\SCRIPTS\muzzle\rockettrail.sqf";

	};

/*
if (_v iskindof "Plane")
then
{
	[_v] spawn BIS_Effects_AircraftVapour;
};
*/

/*if (isnil 'BIS_functions_mainscope') then
	{
	BIS_functions_mainscope = _this select 0;
	if (isServer) then
		{
		private ["_ok"];
		_ok = _this execVM "ca\modules\functions\main.sqf";
		}
	};
if (isnil 'RE') then
	{
	private ["_ok"];
	_ok = [] execVM "\ca\Modules\MP\data\scripts\MPframework.sqf";
	};
*/
