/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgMovesBPZombie1 : CfgMovesAnimal_Base_F 
{
	primaryActionMaps[] = {"BPZombieActions","NoActions"};
	skeletonName = "OFP2_ManSkeleton";
	gestures = "CfgGesturesMale";
	collisionVertexPattern[] = {"1a","2a","3a","4a","5a","6a","7a","8a","9a","10a","11a","12a","13a","14a","15a","16a","17a","18a","19a","20a","21a","22a","23a","24a","25a","26a","27a","28a","29a","30a","31a","32a","33a","34a","1c","2c","3c","4c","5c","6c","7c","8c"};
	collisionGeomCompPattern[] = {1,3};
	
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
		
		class Zombie_Stop : StandBase {
			enableDirectControl = 1;
			actions = "BPZombieActions";
			duty = -1;
			//file = "\breakingpoint_anim\zmb\BPZombie1_Idle.rtm";
			file = "\breakingpoint_anim\zmb\BP_Zombie_Runner_Idle.rtm";
			connectTo[] = {"Zombie_Walk", 0.1, "Zombie_Run", 0.1, "Zombie_Sprint", 0.1};
			interpolateTo[] = {"Zombie_Die", 0.1, "Zombie_Attack", 0.1, "Zombie_Sprint", 0.1, "Zombie_Run", 0.1, "Zombie_Walk", 0.1, "Zombie_Stop", 0.1};
			headBobStrength = 0.3;
			headBobMode = 2;
			canPullTrigger = 0;
			disableWeapons = 1;
			disableWeaponsLong = 1;
			enableOptics = 0;
			speed = 0.09;
			soundEnabled = false;
			preload = true;
			looped = true;
			Walkcycles = 2;
			interpolationSpeed = 1;
			//speed = 1e+010;
			relSpeedMin = 1.100000;
			relSpeedMax = 1.100000;
		};

		class Zombie_Walk : Zombie_Stop {
			actions = "BPZombieWalk";
			file = "\breakingpoint_anim\zmb\BP_Zombie_Runner_Walk.rtm";
			//file = "\breakingpoint_anim\zmb\BPZombie1_Walk.rtm";
			head = "headDefault";
			connectTo[] = {};
			//interpolateTo[] = {};
			//connectTo[] = {"Zombie_Stop", 0.1, "Zombie_Run", 0.1};
			//connectFrom[] = {"Zombie_Stop", 0.1, "Zombie_Run", 0.1};
			soundOverride = "walk";
			soundEnabled = true;
			canPullTrigger = false;
			duty = -0.7;
			relSpeedMin = 1.0;
			relSpeedMax = 1.2;
			walkcycles = 2;
			speed = 0.910000;
			looped = true;
		};
		
		class Zombie_Run : Zombie_Stop {
			actions = "BPZombieRun";
			file = "\breakingpoint_anim\zmb\BP_Zombie_Runner_Run.rtm";
			//file = "\breakingpoint_anim\zmb\BPZombie1_Run.rtm";
			head = "headDefault";
			connectTo[] = {};
			//interpolateTo[] = {};
			//connectTo[] = {"Zombie_Stop", 0.1, "Zombie_Walk", 0.1};
			//connectFrom[] = {"Zombie_Stop", 0.1, "Zombie_Walk", 0.1};
			soundOverride = "run";
			soundEnabled = true;
			canPullTrigger = false;
			duty = -0.5;
			relSpeedMin = 1.1;
			relSpeedMax = 1.4;
			walkcycles = 2;
			speed = 1.22000;
			onLandEnd = 1;
			looped = true;
			headBobStrength = 0.3;
			headBobMode = 2;
			enableDirectControl = 0;
			interpolationRestart = 1;
			interpolationSpeed = 2.500000;
		};
		
		class Zombie_Sprint : Zombie_Stop {
			actions = "BPZombieSprint";
			file = "\breakingpoint_anim\zmb\BP_Zombie_Runner_Sprint_V3.rtm";
			//file = "\breakingpoint_anim\zmb\BPZombie1_Sprint.rtm";
			head = "headDefault";
			connectTo[] = {};
			interpolateTo[] = {"Zombie_Die", 0.05, "Zombie_Attack", 0.05, "Zombie_Sprint", 0.05};
			//connectTo[] = {"Zombie_Stop", 0.1, "Zombie_Run", 0.1};
			//connectFrom[] = {"Zombie_Stop", 0.1, "Zombie_Run", 0.1};
			soundOverride = "sprint";
			soundEnabled = true;
			canPullTrigger = false;
			duty = 0.5;
			relSpeedMin = 1.5;
			relSpeedMax = 1.6;
			walkcycles = 2;
			speed = 1.11;
			onLandEnd = 1;
			looped = true;
			static = 1;
			enableDirectControl = 0;
			interpolationRestart = 1;
			interpolationSpeed = 2.500000;
		};
		
		class Zombie_Attack: Zombie_Stop {
			actions = "BPZombieActions";
			file = "\breakingpoint_anim\zmb\BPZombie2_Attack1.rtm";
			speed = 1;
			soundEnabled = 0;
			interpolateTo[] = {"Zombie_Die", 0.02};
			looped = false;
		};
		
		class Zombie_Die : DefaultDie {
			file = "\A3\anims_f\Data\Anim\Sdr\dth\pne\stp\ras\Rfl\AdthPpneMstpSrasWrflDnon_1";
			speed = 0.7;
			looped = 0;
			onLandBeg = 1;
			onLandEnd = 1;
			soundEnabled = 0;
			ragdoll = 1;
			headBobMode = 2;
			disableWeapons = 1;
			disableWeaponsLong = 1;
			actions = "NoActions";
			variantsPlayer[] = {};
			variantsAI[] = {};
			variantAfter[] = {0, 0, 0};
			interpolateFrom[] = {"Zombie_Stop", 0.1, "Zombie_Walk", 0.1, "Zombie_Sprint", 0.1};
			terminal = true;
		};
	};
	
	class Actions : Actions {
		class NoActions : NoActions 
		{
			turnSpeed = 8;
			Die = "Zombie_Die";
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = 0;
			BP_Zomb_Act_Attack1[] = {"BP_Zomb_Attack1","Gesture"};
			BP_Zomb_Act_Attack2[] = {"BP_Zomb_Attack2","Gesture"};
		};
		
		class BPZombieActions : NoActions 
		{
			Default = "Zombie_Stop";
			Stop = "Zombie_Stop";
			StopRelaxed = "Zombie_Stop";
			//TurnL = "Zombie_Stop";
			//TurnR = "Zombie_Stop";
			//TurnLRelaxed = "Zombie_Stop";
			//TurnRRelaxed = "Zombie_Stop";
			JumpOff = "Zombie_Stop";
			WalkF = "Zombie_Walk";
			SlowF = "Zombie_Run";
			FastF = "Zombie_Sprint";
			EvasiveForward = "Zombie_Sprint";
			Die = "Zombie_Die";
			CanNotMove = "";
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = "ManPosNoWeapon";
		};
		
		class BPZombieWalk : BPZombieActions
		{
			
		};
		
		class BPZombieRun : BPZombieActions
		{
			
		};
		
		class BPZombieSprint : BPZombieActions
		{
			useFastMove = 1;
		};
	};
	
	class Interpolations {};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};

	class BlendAnims : BlendAnims {
		wholeBody[] = {"Pelvis", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "Camera", 1, "weapon", 1, "launcher", 1, "neck", 1, "neck1", 1, "head", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftLeg", 1, "LeftLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightLeg", 1, "RightLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
		aimingDefault[] = {"head", 0.6, "neck1", 0.6, "neck", 0.6, "weapon", 1, "launcher", 1, "LeftShoulder", 0.8, "LeftArm", 0.8, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 0.8, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.6};
		aimingPistol[] = {"head", 0.6, "neck1", 0.6, "neck", 0.6, "LeftShoulder", 1, "launcher", 1, "weapon", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.6};
		aimingLauncher[] = {"head", 0.6, "neck1", 0.6, "neck", 0.6, "launcher", 1, "weapon", 1, "LeftShoulder", 0.8, "LeftArm", 0.8, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 0.8, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.6};
		aimingCivil[] = {"neck1", 0.25, "neck", 0.25, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.5};
		aimingCivilKneel[] = {"neck1", 0.25, "neck", 0.25, "Spine", 0.3, "Spine1", 0.4, "Spine2", 0.5, "Spine3", 0.5, "LeftShoulder", 0.5, "LeftArm", 0.2, "LeftArmRoll", 0.15, "LeftForeArm", 0.1, "LeftForeArmRoll", 0.05, "RightShoulder", 0.5, "RightArm", 0.2, "RightArmRoll", 0.15, "RightForeArm", 0.1, "RightForeArmRoll", 0.05};
		aimingLying[] = {"weapon", 1, "LeftShoulder", 0.8, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine2", 0.2, "Spine3", 0.6};
		aimingLyingPistol[] = {"LeftShoulder", 0.8, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 0.8, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "Spine2", 0.2, "Spine3", 0.6};
		legsLyingAiming[] = {"weapon", 0, "LeftShoulder", 0.2, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "RightShoulder", 0.2, "RightArm", 0, "RightArmRoll", 0, "RightForeArm", 0, "RightForeArmRoll", 0, "RightHand", 0, "RightHandRing", 0, "RightHandPinky1", 0, "RightHandPinky2", 0, "RightHandPinky3", 0, "RightHandRing1", 0, "RightHandRing2", 0, "RightHandRing3", 0, "RightHandMiddle1", 0, "RightHandMiddle2", 0, "RightHandMiddle3", 0, "RightHandIndex1", 0, "RightHandIndex2", 0, "RightHandIndex3", 0, "RightHandThumb1", 0, "RightHandThumb2", 0, "RightHandThumb3", 0, "Spine2", 0.8, "Spine3", 0.4, "spine1", 1, "pelvis", 1, "leftupleg", 1, "leftuplegroll", 1, "leftleg", 1, "leftlegroll", 1, "leftfoot", 1, "LeftToeBase", 1, "rightupleg", 1, "rightuplegroll", 1, "rightleg", 1, "rightlegroll", 1, "rightfoot", 1, "RightToeBase", 1};
		legsLyingAimingPistol[] = {"LeftShoulder", 0.2, "LeftArm", 0, "LeftArmRoll", 0, "LeftForeArm", 0, "LeftForeArmRoll", 0, "LeftHand", 0, "LeftHandRing", 0, "LeftHandPinky1", 0, "LeftHandPinky2", 0, "LeftHandPinky3", 0, "LeftHandRing1", 0, "LeftHandRing2", 0, "LeftHandRing3", 0, "LeftHandMiddle1", 0, "LeftHandMiddle2", 0, "LeftHandMiddle3", 0, "LeftHandIndex1", 0, "LeftHandIndex2", 0, "LeftHandIndex3", 0, "LeftHandThumb1", 0, "LeftHandThumb2", 0, "LeftHandThumb3", 0, "RightShoulder", 0.2, "RightArm", 0, "RightArmRoll", 0, "RightForeArm", 0, "RightForeArmRoll", 0, "RightHand", 0, "RightHandRing", 0, "RightHandPinky1", 0, "RightHandPinky2", 0, "RightHandPinky3", 0, "RightHandRing1", 0, "RightHandRing2", 0, "RightHandRing3", 0, "RightHandMiddle1", 0, "RightHandMiddle2", 0, "RightHandMiddle3", 0, "RightHandIndex1", 0, "RightHandIndex2", 0, "RightHandIndex3", 0, "RightHandThumb1", 0, "RightHandThumb2", 0, "RightHandThumb3", 0, "Spine2", 0.8, "Spine3", 0.4, "spine1", 1, "pelvis", 1, "leftupleg", 1, "leftuplegroll", 1, "leftleg", 1, "leftlegroll", 1, "leftfoot", 1, "LeftToeBase", 1, "rightupleg", 1, "rightuplegroll", 1, "rightleg", 1, "rightlegroll", 1, "rightfoot", 1, "RightToeBase", 1};
		headDefault[] = {"head", 1, "neck1", 0.5, "neck", 0.5};
		leaningDefault[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7, "pelvis", 0.4};
		crewShake_half[] = {"weapon", 0.5, "Camera", 0.5, "launcher", 0.5, "Head", 0.5, "Neck", 0.5, "Neck1", 0.5, "LeftShoulder", 0.45, "LeftArm", 0.35, "LeftArmRoll", 0.25, "LeftForeArm", 0.15, "RightShoulder", 0.45, "RightArm", 0.35, "RightArmRoll", 0.25, "RightForeArm", 0.315, "spine3", 0.475, "spine2", 0.45, "spine1", 0.4, "spine", 0.35, "pelvis", 0.2, "LeftUpLeg", 0.1, "LeftUpLegRoll", 0.25, "LeftLeg", 0.1, "RightUpLeg", 0.1, "RightUpLegRoll", 0.25, "RightLeg", 0.1};
		crewShake[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 0.9, "LeftArm", 0.7, "LeftArmRoll", 0.5, "LeftForeArm", 0.3, "RightShoulder", 0.9, "RightArm", 0.7, "RightArmRoll", 0.5, "RightForeArm", 0.3, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7, "pelvis", 0.4, "LeftUpLeg", 0.2, "LeftUpLegRoll", 0.5, "LeftLeg", 0.2, "RightUpLeg", 0.2, "RightUpLegRoll", 0.5, "RightLeg", 0.2};
		aimingUpDefault[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		aimingUpCivilKneel[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7, "LeftShoulder", 0.95, "LeftArm", 0.45, "LeftArmRoll", 0.35, "LeftForeArm", 0.25, "LeftForeArmRoll", 0.15, "RightShoulder", 0.95, "RightArm", 0.45, "RightArmRoll", 0.35, "RightForeArm", 0.25, "RightForeArmRoll", 0.15};
		aimingUpLying[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.9, "spine2", 0.7, "spine1", 0.5};
		aimingUpPistol[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		aimingUpCivil[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		aimingUpLauncher[] = {"weapon", 1, "Camera", 1, "launcher", 1, "Head", 1, "Neck", 1, "Neck1", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "spine3", 0.95, "spine2", 0.9, "spine1", 0.8, "spine", 0.7};
		legsDefault[] = {"LeftUpLeg", 0.9, "LeftUpLegRoll", 0.9, "LeftLeg", 0.95, "LeftLegRoll", 0.95, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 0.9, "RightUpLegRoll", 0.9, "RightLeg", 0.95, "RightLegRoll", 0.95, "RightFoot", 1, "RightToeBase", 1};
		idleDefault[] = {"Pelvis", 1, "Spine", 1, "Spine1", 1, "Spine2", 1, "Spine3", 1, "Camera", 1, "weapon", 1, "launcher", 1, "neck", 1, "neck1", 1, "head", 1, "LeftShoulder", 1, "LeftArm", 1, "LeftArmRoll", 1, "LeftForeArm", 1, "LeftForeArmRoll", 1, "LeftHand", 1, "LeftHandRing", 1, "LeftHandRing1", 1, "LeftHandRing2", 1, "LeftHandRing3", 1, "LeftHandPinky1", 1, "LeftHandPinky2", 1, "LeftHandPinky3", 1, "LeftHandMiddle1", 1, "LeftHandMiddle2", 1, "LeftHandMiddle3", 1, "LeftHandIndex1", 1, "LeftHandIndex2", 1, "LeftHandIndex3", 1, "LeftHandThumb1", 1, "LeftHandThumb2", 1, "LeftHandThumb3", 1, "RightShoulder", 1, "RightArm", 1, "RightArmRoll", 1, "RightForeArm", 1, "RightForeArmRoll", 1, "RightHand", 1, "RightHandRing", 1, "RightHandRing1", 1, "RightHandRing2", 1, "RightHandRing3", 1, "RightHandPinky1", 1, "RightHandPinky2", 1, "RightHandPinky3", 1, "RightHandMiddle1", 1, "RightHandMiddle2", 1, "RightHandMiddle3", 1, "RightHandIndex1", 1, "RightHandIndex2", 1, "RightHandIndex3", 1, "RightHandThumb1", 1, "RightHandThumb2", 1, "RightHandThumb3", 1, "LeftUpLeg", 1, "LeftUpLegRoll", 1, "LeftLeg", 1, "LeftLegRoll", 1, "LeftFoot", 1, "LeftToeBase", 1, "RightUpLeg", 1, "RightUpLegRoll", 1, "RightLeg", 1, "RightLegRoll", 1, "RightFoot", 1, "RightToeBase", 1};
	};
};
class CfgMovesBPZombieImp1: CfgMovesBPZombie1
{
	class States
	{
		class Zombie_Stop: StandBase
		{
			enableDirectControl=1;
			actions="BPZombieActions";
			duty=-1;
			file="\breakingpoint_anim\zmb\BP_Zombie_Runner_Idle.rtm";
			connectTo[]=
			{
				"Zombie_Walk",
				0.1,
				"Zombie_Run",
				0.1,
				"Zombie_Sprint",
				0.1
			};
			interpolateTo[]=
			{
				"Zombie_Die",
				0.1,
				"Zombie_Attack",
				0.1,
				"Zombie_Sprint",
				0.1,
				"Zombie_Run",
				0.1,
				"Zombie_Walk",
				0.1,
				"Zombie_Stop",
				0.1
			};
			headBobStrength=0.30000001;
			headBobMode=2;
			canPullTrigger=0;
			disableWeapons=1;
			disableWeaponsLong=1;
			enableOptics=0;
			speed=0.090000004;
			soundEnabled="false";
			preload="true";
			looped="true";
			Walkcycles=2;
			interpolationSpeed=1;
			relSpeedMin=1.1;
			relSpeedMax=1.1;
		};
		class Zombie_Walk: Zombie_Stop
		{
			actions="BPZombieWalk";
			file="\breakingpoint_anim\zmb\BP_Zombie_Runner_Walk.rtm";
			head="headDefault";
			connectTo[]={};
			soundOverride="walk";
			soundEnabled="true";
			canPullTrigger="false";
			duty=-0.69999999;
			relSpeedMin=1.2;
			relSpeedMax=1.4;
			walkcycles=2;
			speed=1.11;
			looped="true";
		};
		class Zombie_Run: Zombie_Stop
		{
			actions="BPZombieRun";
			file="\breakingpoint_anim\zmb\BP_Zombie_Runner_Run.rtm";
			head="headDefault";
			connectTo[]={};
			soundOverride="run";
			soundEnabled="true";
			canPullTrigger="false";
			duty=-0.5;
			relSpeedMin=1.3;
			relSpeedMax=1.6;
			walkcycles=2;
			speed=1.42;
			onLandEnd=1;
			looped="true";
			headBobStrength=0.30000001;
			headBobMode=2;
			enableDirectControl=0;
			interpolationRestart=1;
			interpolationSpeed=2.5;
		};
		class Zombie_Sprint: Zombie_Stop
		{
			actions="BPZombieSprint";
			file="\breakingpoint_anim\zmb\BP_Zombie_Runner_Sprint_V3.rtm";
			head="headDefault";
			connectTo[]={};
			interpolateTo[]=
			{
				"Zombie_Die",
				0.050000001,
				"Zombie_Attack",
				0.050000001,
				"Zombie_Sprint",
				0.050000001
			};
			soundOverride="sprint";
			soundEnabled="true";
			canPullTrigger="false";
			duty=0.5;
			relSpeedMin=2.5;
			relSpeedMax=2.6;
			walkcycles=2;
			speed=2.1099999;
			onLandEnd=1;
			looped="true";
			static=1;
			enableDirectControl=0;
			interpolationRestart=1;
			interpolationSpeed=2.5;
		};
		class Zombie_Attack: Zombie_Stop
		{
			actions="BPZombieActions";
			file="\breakingpoint_anim\zmb\BPZombie2_Attack1.rtm";
			speed=1.3;
			soundEnabled=0;
			interpolateTo[]=
			{
				"Zombie_Die",
				0.02
			};
			looped="false";
		};
		class Zombie_Die: DefaultDie
		{
			file="\A3\anims_f\Data\Anim\Sdr\dth\pne\stp\ras\Rfl\AdthPpneMstpSrasWrflDnon_1";
			speed=0.69999999;
			looped=0;
			onLandBeg=1;
			onLandEnd=1;
			soundEnabled=0;
			ragdoll=1;
			headBobMode=2;
			disableWeapons=1;
			disableWeaponsLong=1;
			actions="NoActions";
			variantsPlayer[]={};
			variantsAI[]={};
			variantAfter[]={0,0,0};
			interpolateFrom[]=
			{
				"Zombie_Stop",
				0.1,
				"Zombie_Walk",
				0.1,
				"Zombie_Sprint",
				0.1
			};
			terminal="true";
		};
	};
};
