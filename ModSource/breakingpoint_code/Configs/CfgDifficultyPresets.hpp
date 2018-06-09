/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgDifficultyPresets
{
	defaultPreset = "Veteran";
	myArmorCoef = 1.5;
	groupArmorCoef = 1.5;
	recoilCoef = 1;
	visionAidCoef = 0.8;
	divingLimitMultiplier = 1.0;
	animSpeedCoef = 0;
	cancelThreshold = 0;
	showCadetHints = 1;
	showCadetWP = 1;

	class Recruit
	{
		displayName = "$STR_Difficulty0";
		optionDescription = "$STR_Difficulty0_desc";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
		class Options
		{
			groupIndicators=0;
			friendlyTags=0;
			enemyTags=0;
			detectedMines=0;
			commands=0;
			waypoints=0;
			weaponInfo=1;
			stanceIndicator=0;
			reducedDamage=0;
			staminaBar=0;
			weaponCrosshair=0;
			visionAid=0;
			thirdPersonView=0;
			cameraShake=0;
			scoreTable=0;
			deathMessages=0;
			vonID=0;
			mapContent=0;
			autoReport=0;
			multipleSaves=0;
		};
	};

	class Regular
	{
		displayName = "$STR_Difficulty1";
		optionDescription = "$STR_Difficulty1_desc";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
		class Options
		{
			groupIndicators=0;
			friendlyTags=0;
			enemyTags=0;
			detectedMines=0;
			commands=0;
			waypoints=0;
			weaponInfo=1;
			stanceIndicator=0;
			reducedDamage=0;
			staminaBar=0;
			weaponCrosshair=0;
			visionAid=0;
			thirdPersonView=1;
			cameraShake=0;
			scoreTable=0;
			deathMessages=0;
			vonID=0;
			mapContent=0;
			autoReport=0;
			multipleSaves=0;
		};
	};
	
	class Veteran
	{
		displayName = "Veteran";
		optionDescription = "";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
		class Options
		{
			groupIndicators=0;
			friendlyTags=0;
			enemyTags=0;
			detectedMines=0;
			commands=0;
			waypoints=0;
			weaponInfo=1;
			stanceIndicator=0;
			reducedDamage=0;
			staminaBar=0;
			weaponCrosshair=0;
			visionAid=0;
			thirdPersonView=0;
			cameraShake=0;
			scoreTable=0;
			deathMessages=0;
			vonID=1;
			mapContent=0;
			autoReport=0;
			multipleSaves=0;
		};
	};
	
	class Custom
	{
		displayName = "$STR_Difficulty_Custom";
		optionDescription = "$STR_Difficulty_Custom_desc";
		optionPicture = "\A3\Ui_f\data\Logos\arma3_white_ca.paa";
		class Options
		{
			groupIndicators=0;
			friendlyTags=0;
			enemyTags=0;
			detectedMines=0;
			commands=0;
			waypoints=0;
			weaponInfo=1;
			stanceIndicator=0;
			reducedDamage=0;
			staminaBar=0;
			weaponCrosshair=0;
			visionAid=0;
			thirdPersonView=0;
			cameraShake=0;
			scoreTable=0;
			deathMessages=0;
			vonID=0;
			mapContent=0;
			autoReport=0;
			multipleSaves=0;
		};
	};
};

//BTW THIS IS WHEN ARMA FUCKED UP ALL THE DIFFICULTY SETTINGS FOR NO GOD DAMN REASON. 
/*
class CfgDifficulties {
	class Veteran {
		displayName = "$STR_Difficulty2";
		description = "$STR_Difficulty2_desc";
		showCadetHints = 0;
		showCadetWP = 0;
		maxPilotHeight = 10000;
		scoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		scoreChar = "*";
		badScoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		badScoreChar = "X";
		skillFriendly = 1.0;
		precisionFriendly = 1.0;
		skillEnemy = 1.0;
		precisionEnemy = 1.0;
		myArmorCoef = 1.0;
		groupArmorCoef = 1.0;
		peripheralVisionAid = 0;
		visionAid = 0;
		HealSpeedMedicMedikit = 0.1;
		HealSpeedMedicFAK = 0.1;
		HealSpeedMedic = 0.1;
		HealSpeedSoldierFAK = 0.04;
		HealSpeedSoldier = 0.04;
		BleedingRate = 0.08;
		CancelThreshold = 0.2;
		DivingLimitMultiplier = 1.0;
		recoilCoef = 1;
		autoReload = false;
		animSpeedCoef = 0;
		
		class Flags {
			armor[] = {0, 0};
			friendlyTag[] = {0, 0};
			enemyTag[] = {0, 0};
			mineTag[] = {0, 0};
			hud[] = {1, 1}; //
			hudPerm[] = {0, 0};
			hudWp[] = {1, 1};
			hudWpPerm[] = {0, 0};
			autoSpot[] = {0, 0};
			map[] = {0, 0};
			weaponCursor[] = {0, 0};
			autoGuideAT[] = {0, 0};
			clockIndicator[] = {1, 1};
			3rdPersonView[] = {1, 1};
			ultraAI[] = {1, 1};
			unlimitedSaves[] = {0, 0};
			deathMessages[] = {0, 0};
			netStats[] = {0, 0};
			vonId[] = {1, 1};
			cameraShake[] = {1, 1};
			hudGroupInfo[] = {0, 0};
			extendetInfoType[] = {0, 1};
			roughLanding[] = {0, 0};
			windEnabled[] = {1, 0};
			autoTrimEnabled[] = {0, 0};
			stressDamageEnabled[] = {1, 0};
		};
	};
	
	class Mercenary {
		displayName = "$STR_Difficulty3";
		description = "$STR_Difficulty3_desc";
		showCadetHints = 0;
		showCadetWP = 0;
		maxPilotHeight = 10000;
		scoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		scoreChar = "*";
		badScoreImage = "#(argb,8,8,3)color(1,1,1,1)";
		badScoreChar = "X";
		skillFriendly = 1.0;
		precisionFriendly = 1.0;
		skillEnemy = 0.85;
		precisionEnemy = 0.85;
		myArmorCoef = 1.0;
		groupArmorCoef = 1.0;
		peripheralVisionAid = 0;
		visionAid = 0;
		HealSpeedMedicMedikit = 0.1;
		HealSpeedMedicFAK = 0.1;
		HealSpeedMedic = 0.1;
		HealSpeedSoldierFAK = 0.04;
		HealSpeedSoldier = 0.04;
		BleedingRate = 0.08;
		CancelThreshold = 0.2;
		DivingLimitMultiplier = 1.0;
		recoilCoef = 1;
		autoReload = false;
		animSpeedCoef = 0;
		
		class Flags {
			armor[] = {0, 0};
			friendlyTag[] = {0, 0};
			enemyTag[] = {0, 0};
			mineTag[] = {0, 0};
			hud[] = {1, 1};
			hudPerm[] = {0, 0};
			hudWp[] = {1, 1};
			hudWpPerm[] = {0, 0};
			autoSpot[] = {0, 0};
			map[] = {0, 0};
			weaponCursor[] = {0, 0};
			autoGuideAT[] = {0, 0};
			clockIndicator[] = {0, 0};
			3rdPersonView[] = {0, 0};
			ultraAI[] = {1, 1};
			unlimitedSaves[] = {0, 0};
			deathMessages[] = {0, 0};
			netStats[] = {0, 0};
			vonID[] = {1, 1};
			cameraShake[] = {1, 0};
			hudGroupInfo[] = {0, 0};
			extendetInfoType[] = {0, 0};
			roughLanding[] = {0, 0};
			windEnabled[] = {1, 0};
			autoTrimEnabled[] = {0, 0};
			stressDamageEnabled[] = {1, 0};
		};
	};
};

*/
