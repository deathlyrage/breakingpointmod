/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgMovesDog_BP : CfgMovesAnimal_Base_F 
{
	access = ReadAndCreate;
	enableDirectControl = 0;
	skeletonName = "Dog_F";
	collisionVertexPattern[] = {"1a", "2a", "3a", "4a", "5a", "6a", "7a", "8a", "9a", "10a", "11a", "12a", "13a", "14a", "15a", "16a", "17a", "18a", "19a", "20a", "21a", "22a", "23a", "24a", "25a", "26a", "27a", "28a", "29a", "30a", "31a", "32a", "33a", "34a"};
	collisionGeomCompPattern[] = {1};
	
	class Default : Default {
		GetOutPara = "";
		weaponLowered = 0;
		canBlendStep = 0;
		idle = "idleDefault";
		access = 3;
		actions = "NoActions";
		file = "";
		looped = true;
		speed = 0.5;
		disableWeapons = false;
		enableOptics = false;
		disableWeaponsLong = false;
		showWeaponAim = false;
		enableMissile = false;
		enableBinocular = false;
		showItemInHand = false;
		showItemInRightHand = false;
		showHandGun = false;
		onLandBeg = false;
		onLandEnd = false;
		onLadder = false;
		canPullTrigger = true;
		canReload = 1;
		duty = -0.5;
		visibleSize = 0.75012;
		aimPrecision = 1;
		camShakeFire = 1;
		relSpeedMin = 1;
		relSpeedMax = 1;
		soundEnabled = true;
		soundOverride = "";
		soundEdge[] = {0.5, 1};
		terminal = false;
		ragdoll = 0;
		limitGunMovement = true;
		variantsPlayer[] = {};
		variantsAI[] = {""};
		equivalentTo = "";
		connectAs = "";
		variantAfter[] = {5, 10, 20};
		connectFrom[] = {};
		connectTo[] = {};
		interpolateWith[] = {};
		interpolateTo[] = {};
		interpolateFrom[] = {};
		ignoreMinPlayTime[] = {};
		aiming = "aimingDefault";
		aimingBody = "aimingUpDefault";
		leaning = "leaningDefault";
		legs = "legsDefault";
		head = "headDefault";
		leaningFactorBeg = 0;
		leaningFactorEnd = 0;
		leaningFactorZeroPoint = -1;
		interpolationSpeed = 6;
		interpolationRestart = false;
		enableDirectControl = 1;
		headBobMode = 0;
		headBobStrength = 0;
		collisionShape = "A3\anims_f\Data\Geom\Sdr\Perc_Wnon.p3d";
		//collisionShape = "A3\anims_f\Data\Geom\Sdr\geom_empty.p3d";// this for test, zombies will not push players in walls and not walk troth objects
		hasCollShapeSafe = false;
		collisionShapeSafe = "";
		boundingSphere = 1.0;
		enableAutoActions = false;
		leftHandIKEnd = false;
		leftHandIKBeg = false;
		rightHandIKBeg = false;
		rightHandIKEnd = false;
		leftHandIKCurve[] = {};
		rightHandIKCurve[] = {};
		weaponIK = 0;
		preload = false;
		Walkcycles = 1;
		forceAim = 0;
		adjstance = "m";
		useIdles = 0;
		weaponObstructed = 0;
	};
	
	//class ManActions : Default {};
	
	/*
	class Default : Default 
	{
		//Bonus
		weaponLowered = 0;
		adjstance = "m";
		//End Of Bonus
		access = ReadOnlyVerified;
		file = "";
		looped = true;
		speed = 0.5;
		disableWeapons = true;
		enableOptics = true;
		disableWeaponsLong = false;
		canreload = 1;
		showWeaponAim = true;
		enableMissile = false;
		enableBinocular = false;
		showItemInHand = false;
		showItemInRightHand = false;
		showHandGun = false;
		onLandBeg = false;
		onLandEnd = false;
		onLadder = false;
		canPullTrigger = true;
		duty = -0.51;
		predictSpeedCoef = 1;
		visibleSize = 1;
		aimPrecision = 1;
		relSpeedMin = 1.0;
		relSpeedMax = 1.0;
		soundEnabled = true;
		soundOverride = "";
		soundEdge[] = {0.5, 1};
		soundEdge1 = 0.5;
		soundEdge2 = 1;
		terminal = false;
		limitGunMovement = true;
		variantsPlayer[] = {};
		variantsAI[] = {};
		equivalentTo = "";
		connectAs = "";
		variantAfter[] = {5, 10, 20};
		connectFrom[] = {};
		connectTo[] = {};
		interpolateWith[] = {};
		interpolateTo[] = {};
		interpolateFrom[] = {};
		aiming = "aimingNo";
		leaning = "aimingNo";
		untiltWeapon = "aimingNo";
		aimingBody = "aimingUpDefault";
		legs = "legsNo";
		head = "headDefault";
		leaningFactorBeg = 0;
		leaningFactorEnd = 0;
		leaningFactorZeroPoint = -1;
		leaningCorrectionAngleBeg = 0;
		leaningCorrectionAngleEnd = 0;
		interpolationSpeed = 6;
		interpolationRestart = false;
		hasCollShapeSafe = false;
		collisionShapeSafe = "";
		boundingSphere = true;
		enableDirectControl = 1;
		enableAutoActions = false;
		leftHandIKBeg = false;
		leftHandIKEnd = false;
		leftHandIKCurve = 0;
		rightHandIKCurve = 0;
		rightHandIKBeg = false;
		rightHandIKEnd = false;
		weaponIK = 0;
		preload = false;
		walkcycles = 1;
		forceAim = 0;
		showDisposableGun = 0;
		headBobStrength = 0.5;
		headBobMode = 1;
		collisionShape = "A3\animals_f_beta\dog\Dog_CollShape.p3d";
	};
	*/
	
	class StandBase : Default {
		aiming = "aimingDefault";
		disableWeapons = true;
		leaningFactorBeg = 1;
		leaningFactorEnd = 1;
	};
	
	class DefaultDie : Default {
		aiming = "aimingNo";
		legs = "legsNo";
		head = "headNo";
		disableWeapons = true;
		interpolationRestart = true;
		soundOverride = "fallbody";
		soundEdge1 = 0.45;
		soundEdge2 = 0.45;
	};
	
	class States {
		class Dog_Stop : StandBase {
			enableDirectControl = 1;
			actions = "FinActions";
			duty = -1;
			//file = "\A3\animals_f_beta\Dog\data\Anim\dogIdle9";
			file = "\A3\animals_f_beta\Dog\Data\anim\dogIdle1.rtm";
			showWeaponAim = false;
			disableWeapons = true;
			disableWeaponsLong = true;
			//variantsAI[] = {"Dog_Idle_01", 0.04, "Dog_Bark", 0.04, "Dog_Growl", 0.04, "Dog_Walk", 0.1, "Dog_Sprint", 0.1};
			//variantsAI[] = {"Dog_Idle_01", 0.04};
			//variantsAI[] = {};
			//variantsAI[] = {};
			//variantsPlayer[] = {};
			//variantAfter[] = {3, 6, 9};
			//speed = 1e+010; //-3
			speed = -3;
			relSpeedMin = 0.7;
			relSpeedMax = 1.1;
			looped = true;
			soundEnabled = false;
			
			//connectTo[] = {"Dog_Walk", 0.2, "Dog_Sprint", 0.02};
			//interpolateTo[] = {"Dog_Idle_01", 0.05, "Dog_Bark", 0.05, "Dog_Growl", 0.05, "Dog_Walk", 0.2, "Dog_Sprint", 0.02, "Dog_die", 0.2};
			
			connectTo[] = {"Dog_Walk", 0.1, "Dog_Run", 0.1, "Dog_Sprint", 0.1};
			interpolateTo[] = {"Dog_Die", 0.1, "Dog_Sprint", 0.1, "Dog_Run", 0.1, "Dog_Walk", 0.1};
			
			enableBinocular = true;
			leftHandIKBeg = true;
			leftHandIKEnd = true;
			rightHandIKBeg = true;
			rightHandIKEnd = true;
			interpolationSpeed = 1;
			preload = true;
		};
		
		class Dog_TurnL : Dog_Stop {
			file = "\A3\animals_f_beta\Dog\data\anim\dog_rotateL.rtm";
			connectTo[] = {"Dog_Stop", 0.1};
			interpolateTo[] = {"Dog_Stop", 0.1};
			speed = 1;
		};
		
		class Dog_TurnR : Dog_TurnL {
			file = "\A3\animals_f_beta\Dog\data\anim\dog_rotateR.rtm";
		};
		
		class Dog_Bark : Dog_Stop {
			file = "\A3\animals_f_beta\Dog\Data\anim\dogBarkingLoop.rtm";
			speed = -3;
			variantsAI[] = {};
			variantAfter[] = {3, 6, 9};
			interpolateTo[] = {"Dog_Stop", 0.1, "Dog_Die", 0.2};
			looped = true;
		};
		
		class Dog_Growl : Dog_Stop {
			file = "\A3\animals_f_beta\Dog\Data\anim\dogGrowlingLoop.rtm";
			speed = -3;
			variantsAI[] = {};
			variantAfter[] = {3, 6, 9};
			equivalentTo = "Dog_Growl";
			interpolateTo[] = {"Dog_Stop", 0.1, "Dog_Die", 0.2};
			looped = true;
		};
		
		class Dog_Sprint : Dog_Stop {
			actions = "FinSprint";
			file = "\A3\animals_f_beta\Dog\data\Anim\dogRun.rtm";
			duty = 0.5;
			speed = -1.47;
			connectTo[] = {};
			interpolateTo[] = {"Dog_Run", 0.02, "Dog_Stop", 0.02, "Dog_Sprint", 0.02, "Dog_Walk", 0.02, "Dog_Die_sprint", 0.02};
			variantsAI[] = {};
		};
		
		class Dog_Run : Dog_Stop {
			file = "\A3\animals_f_beta\Dog\data\Anim\dogTrot";
			duty = -0.5;
			speed = -1.63;
			connectTo[] = {};
			interpolateTo[] = {"Dog_Run", 0.02, "Dog_Stop", 0.02, "Dog_Sprint", 0.02, "Dog_Walk", 0.02, "Dog_Die_run", 0.02};
			variantsAI[] = {};
		};
		
		class Dog_Walk : Dog_Stop {
			actions = "FinRun";
			duty = -0.7;
			file = "\A3\animals_f_beta\Dog\data\Anim\dogWalk";
			speed = -2.03;
			variantAfter[] = {3, 10, 20};
			connectTo[] = {};
			interpolateTo[] = {"Dog_Run", 0.02, "Dog_Stop", 0.02, "Dog_Sprint", 0.02, "Dog_Walk", 0.02, "Dog_Die", 0.02};
			variantsAI[] = {};
		};
		
		class Dog_Die : DefaultDie {
			enableDirectControl = 0;
			actions = "NoActions";
			file = "\A3\animals_f_beta\Dog\data\Anim\dogDeath";
			speed = 1.2;
			looped = false;
			variantsPlayer[] = {};
			variantsAI[] = {};
			variantAfter[] = {0, 0, 0};
			interpolateFrom[] = {"Dog_Stop", 0.02, "Dog_Walk", 0.2, "Dog_Sprint", 0.02};
			terminal = true;
		};

		class Dog_Die_sprint : Dog_Die {
			file = "\A3\animals_f_beta\Dog\data\Anim\dogRunDeath.rtm";
			interpolateFrom[] = {"Dog_Sprint", 0.1};
			terminal = true;
		};
		
		class Dog_Die_run : Dog_Die {
			file = "\A3\animals_f_beta\Dog\data\Anim\dogTrotDeath.rtm";
			interpolateFrom[] = {"Dog_Run", 0.1};
			terminal = true;
		};
	};
	
	class Actions : Actions {
		class NoActions : NoActions {
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = 0;
		};
		
		
		class FinActions : NoActions 
		{
			Default = "Dog_Stop";
			Stop = "Dog_Stop";
			StopRelaxed = "Dog_Stop";
			//TurnL = "Zombie_Stop";
			//TurnR = "Zombie_Stop";
			//TurnLRelaxed = "Zombie_Stop";
			//TurnRRelaxed = "Zombie_Stop";
			//JumpOff = "Dog_Stop";
			WalkF = "Dog_Walk";
			SlowF = "Dog_Run";
			FastF = "Dog_Sprint";
			EvasiveForward = "Dog_Sprint";
			Die = "Dog_Die";
			CanNotMove = "";
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = "ManPosNoWeapon";
		};
		
		//class FinActions : NoActions {
		//	Stop = "Dog_Stop";
		//	StopRelaxed = "Dog_Stop";
		//	TurnL = "Dog_TurnL";
		//	TurnR = "Dog_TurnR";
		//	TurnLRelaxed = "Dog_TurnL";
		//	TurnRRelaxed = "Dog_TurnR";
		//	Default = "Dog_Stop";
		//	JumpOff = "Dog_Stop";
		//	WalkF = "Dog_Walk";
		//	SlowF = "Dog_Run";
		//	FastF = "Dog_Sprint";
		//	EvasiveForward = "Dog_Sprint";
		//	Down = "Dog_Stop";
		//	Up = "Dog_Stop";
		//	PlayerStand = "Dog_Stop";
		//	PlayerProne = "Dog_Stop";
		//	PlayerCrouch = "Dog_Stop";
		//	Crouch = "Dog_Stop";
		//	Lying = "Dog_Stop";
		//	Stand = "Dog_Stop";
		//	Combat = "Dog_Stop";
		//	CanNotMove = "Dog_Stop";
		//	Civil = "Dog_Stop";
		//	CivilLying = "Dog_Stop";
		//	FireNotPossible = "Dog_Stop";
		//	Die = "Dog_Die";
		//	turnSpeed = 8;
		//	limitFast = 5.5;
		//	useFastMove = 0;
		//	upDegree = "ManPosNoWeapon";
		//};
		
		class FinRun : FinActions {
			Die = "Dog_Die_run";
		};
		
		class FinSprint : FinActions {
			FastF = "Dog_Sprint";
			EvasiveForward = "Dog_Sprint";
			Die = "Dog_Die_sprint";
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 1;
		};
	};
	
	class Interpolations {};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
	
	class BlendAnims : BlendAnims {
		aimingDefault[] = {"head", 1, "head", 1, "head", 1};
		untiltWeaponDefault[] = {};
		legsDefault[] = {};
		headDefault[] = {};
		aimingNo[] = {};
		legsNo[] = {};
		headNo[] = {};
		aimingUpDefault[] = {};
	};
};
