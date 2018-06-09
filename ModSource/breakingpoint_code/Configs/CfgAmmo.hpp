/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgAmmo
{
	class DirectionalBombBase;
	class BP_TripMine_Ammo : DirectionalBombBase
	{
		hit=30;
		indirectHit=30;
		indirectHitRange=5;
		model="\A3\Weapons_F\explosives\mine_AP_tripwire";
		mineModelDisabled="\A3\Weapons_F\explosives\mine_AP_tripwire_d";
		defaultMagazine="";
		icon="iconExplosiveAP";
		soundHit[]={"A3\Sounds_F\weapons\mines\mine_3",3.16228,1,1500};
		underwaterHitRangeCoef=2;
		explosionAngle=360;
		explosionEffects="MineExplosion";
		CraterEffects="MineCrater";
		whistleDist=8;
		cost=200;
		mineTrigger="WireTrigger";
		mineInconspicuousness=50;
	};
	
	class MineBase;
	class BP_ATMine_Ammo : MineBase
	{
		hit=2000;
		indirectHit=2000;
		indirectHitRange=2;
		model="\A3\Weapons_f\Explosives\mine_at";
		mineModelDisabled="\A3\Weapons_f\Explosives\mine_at_d";
		defaultMagazine="BP_ATMine_Mag";
		soundHit[]={"A3\Sounds_F\weapons\mines\mine_debris_2",3.16228,1,2000};
		explosionEffects="ATMineExplosion";
		CraterEffects="ATMineCrater";
		whistleDist=8;
		mineInconspicuousness=40;
		mineTrigger="TankTriggerMagnetic";
	};
	
	//class BP_BearTrap_Ammo : MineBase
	//{
	//	hit=2000;
	//	indirectHit=2000;
	//	indirectHitRange=2;
	//	model="\A3\Weapons_f\Explosives\mine_at";
	//	mineModelDisabled="\A3\Weapons_f\Explosives\mine_at_d";
	//	defaultMagazine="BP_BearTrap_Mag";
	//	soundHit[]={"A3\Sounds_F\weapons\mines\mine_debris_2",3.16228,1,2000};
	//	explosionEffects="NoExplosion";
	//	CraterEffects="NoCrater";
	//	whistleDist=8;
	//	mineInconspicuousness=40;
	//	mineTrigger="RangeTrigger";
	//};
	
	class BulletBase;
	class zombie : BulletBase {	
		hit = 1;
		typicalSpeed = 1;
		timeToLive = 0;
		airFriction = -0.000001;
		soundFly[] = {"", 0, 1};
		soundEngine[] = {"", 0, 1};
		visibleFire = 0.1;	// how much is visible when this weapon is fired
		audibleFire = 0.02;
		caliber = 1;
		legFracture = false;
		explosionEffects = "";
		craterEffects = "";
		
		class Melee {
			damageHit = 0; // Hit Damage (Zombies)
			damageBlood = 1225; // Blood Damage (Players)
			anim = "BP_Zomb_Act_Attack2";
			radius = 3.5; //Radius In Meters Of Targets
			angle = 65; //Angle Of Hit Detection
			sounds[] = 
			{
				{"breakingpoint_jsrs\sounds\Hatchet1.wav", 1.384893, 1, 70},
				{"breakingpoint_jsrs\sounds\Hatchet1.wav", 1.184893, 0.7, 70},
				{"breakingpoint_jsrs\sounds\Hatchet1.wav", 1.284893, 1.1, 70}
			};
		};
		
		class Medical
		{
			//Instant Bleeding (Bullet will always make you bleed on impact)
			InstantBleeding = 0; // 0 - Disabled / 1 - Enabled

			//Medical State Level (Bullet Hit will always put you in this state)
			// 0 - None / 1 - Pain / 2 - Small Bandage / 3 - Field Dressing / 4 - Surgery Kit
			MedicalState = 0;
			MedicalChance = 85;
			
			// Bleeding Level (Rate of blood loss)
			// 0 - 30bps / 1 - 50bps / 2 - 75bps / 3 - 100bps
			BleedingLevel = 1;
			BleedingChance = 25;

			// Infection (Bullet Wound Chance Of Infection)
			Infection = 1; // 0 - Disabled / 1 - Enabled
			InfectionChance = 1.0; //Between 0.1 -> 1.0

			// Knockout (Bullet Wound Chance Of Knockout)
			Knockout = 0; // 0 - Disabled / 1 - Enabled
			KnockoutChance = 0; //Between 0.1 -> 1.0

			//Blood Damage Scale
			scale = 0;
		};
	};
};
