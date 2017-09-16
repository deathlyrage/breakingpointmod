/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgMovesAnimal_Base_F 
{
	access = ReadAndCreate;
	collisionVertexPattern[] = {};
	collisionGeomCompPattern[] = {1};
	
	class Default {
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
	};
	
	class StandBase : Default {
		duty = -1;
		head = "headDefault";
		speed = 1e+010;
		relSpeedMin = 0.7;
		relSpeedMax = 1.1;
		looped = true;
		soundEnabled = true;
		enableDirectControl = 0;
		disableWeapons = true;
		disableWeaponsLong = true;
	};
	
	class DefaultDie : Default {
		aiming = "aimingNo";
		legs = "legsNo";
		head = "headNo";
	};
	
	class ManActions {
		Stop = "";
		StopRelaxed = "";
		TurnL = "";
		TurnR = "";
		TurnLRelaxed = "";
		TurnRRelaxed = "";
		Default = "";
		JumpOff = "";
		ReloadMagazine = "";
		ReloadMGun = "";
		ReloadAT = "";
		ReloadMortar = "";
		ThrowGrenade = "";
		WalkF = "";
		WalkLF = "";
		WalkRF = "";
		WalkL = "";
		WalkR = "";
		WalkLB = "";
		WalkRB = "";
		WalkB = "";
		SlowF = "";
		SlowLF = "";
		SlowRF = "";
		SlowL = "";
		SlowR = "";
		SlowLB = "";
		SlowRB = "";
		SlowB = "";
		FastF = "";
		FastLF = "";
		FastRF = "";
		FastL = "";
		FastR = "";
		FastLB = "";
		FastRB = "";
		FastB = "";
		EvasiveForward = "";
		EvasiveLeft = "";
		EvasiveRight = "";
		EvasiveBack = "";
		StartSwim = "";
		StopSwim = "";
		Down = "";
		Up = "";
		PlayerStand = "";
		PlayerCrouch = "";
		PlayerProne = "";
		Lying = "";
		Stand = "";
		Combat = "";
		Crouch = "";
		CanNotMove = "";
		Civil = "";
		CivilLying = "";
		FireNotPossible = "";
		Die = "";
		WeaponOn = "";
		WeaponOff = "";
		StrokeFist = "";
		StrokeGun = "";
		SitDown = "";
		Salute = "";
		BinocOn = "";
		BinocOff = "";
		PutDown = "";
		PutDownEnd = "";
		Medic = "";
		Treated = "";
		LadderOnDown = "";
		LadderOnUp = "";
		LadderOff = "";
		LadderOffTop = "";
		LadderOffBottom = "";
		GetInLow = "";
		GetInMedium = "";
		GetInHigh = "";
		GetOutLow = "";
		GetOutMedium = "";
		GetOutHigh = "";
		TakeFlag = "";
		HandGunOn = "";
		LookAround = "";
		Eat = "";
		StopEat = "";
		Rest = "";
		StopRest = "";
	};
	
	class Actions {
		class NoActions : ManActions {
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			stance = "ManStanceUndefined";
			upDegree = 0;
		};
	};
	
	class Interpolations {};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
	
	class BlendAnims {
		aimingDefault[] = {"head", 1};
		untiltWeaponDefault[] = {};
		legsDefault[] = {};
		headDefault[] = {"Head", 1};
		aimingNo[] = {};
		legsNo[] = {};
		headNo[] = {};
		aimingUpDefault[] = {};
	};
};

/*
class CfgGesturesDog 
{
	class Default {
		actions = "NoActions";
		file = "";
		looped = 1;
		speed = 0.5;
		relSpeedMin = 1;
		relSpeedMax = 1;
		soundEnabled = 0;
		soundOverride = "";
		soundEdge[] = {0.5, 1};
		terminal = 0;
		equivalentTo = "";
		connectAs = "";
		connectFrom[] = {};
		connectTo[] = {};
		interpolateWith[] = {};
		interpolateTo[] = {};
		interpolateFrom[] = {};
		mask = "empty";
		interpolationSpeed = 6;
		interpolationRestart = 0;
		preload = 0;
		disableWeapons = 1;
		enableOptics = 1;
		showWeaponAim = 1;
		enableMissile = 1;
		enableBinocular = 1;
		showItemInHand = 0;
		showItemInRightHand = 0;
		showHandGun = 0;
		canPullTrigger = 1;
		walkcycles = 1;
		headBobMode = 0;
		headBobStrength = 0;
		leftHandIKBeg = 0;
		leftHandIKEnd = 0;
		rightHandIKBeg = 0;
		rightHandIKEnd = 0;
		leftHandIKCurve[] = {1};
		rightHandIKCurve[] = {1};
		forceAim = 0;
	};
	
	class States 
	{
		class BP_Dog_Attack1 : Default 
		{
			//actions = "BPZombieActions";
			file = "\breakingpoint_anim\dogs\dogAttack";
			speed = 1;
			soundOverride = "";
			soundEnabled = 0;
			looped = false;
			duty = 1.0;
			aimingBody = "aimingUpDefault";
			mask = "handsWeapon";
			leftHandIKBeg = false;
			leftHandIKCurve[] = {1};
			leftHandIKEnd = false;
			rightHandIKBeg = false;
			rightHandIKCurve[] = {1};
			rightHandIKEnd = false;
			weaponIK = 0;
			enableOptics = false;
			showWeaponAim = false;
			disableWeapons = true;
			disableWeaponsLong = true;
			canPullTrigger = 0;
			//soundOverride = "rifle_to_handgun"; <<<--- Insert here attack sound class
		};
	};
	class BlendAnims {
		handsWeapon[] = {"head",1,"neck1",1,"neck",1,"weapon",1,"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,"Spine",1,"Spine1",1,"Spine2",1,"Spine3",1,"pelvis","MaskStart"};
		upperTorso[] = {"head",1,"neck1",1,"neck",1,"weapon",1,"LeftShoulder",1,"LeftArm",1,"LeftArmRoll",1,"LeftForeArm",1,"LeftForeArmRoll",1,"LeftHand",1,"LeftHandRing",1,"LeftHandPinky1",1,"LeftHandPinky2",1,"LeftHandPinky3",1,"LeftHandRing1",1,"LeftHandRing2",1,"LeftHandRing3",1,"LeftHandMiddle1",1,"LeftHandMiddle2",1,"LeftHandMiddle3",1,"LeftHandIndex1",1,"LeftHandIndex2",1,"LeftHandIndex3",1,"LeftHandThumb1",1,"LeftHandThumb2",1,"LeftHandThumb3",1,"RightShoulder",1,"RightArm",1,"RightArmRoll",1,"RightForeArm",1,"RightForeArmRoll",1,"RightHand",1,"RightHandRing",1,"RightHandPinky1",1,"RightHandPinky2",1,"RightHandPinky3",1,"RightHandRing1",1,"RightHandRing2",1,"RightHandRing3",1,"RightHandMiddle1",1,"RightHandMiddle2",1,"RightHandMiddle3",1,"RightHandIndex1",1,"RightHandIndex2",1,"RightHandIndex3",1,"RightHandThumb1",1,"RightHandThumb2",1,"RightHandThumb3",1,"Spine",1,"Spine1",1,"Spine2",1,"Spine3",1};
	};
};
*/

/*
class CfgMovesDog_BP : CfgMovesAnimal_Base_F 
{
	access = ReadAndCreate;
	enableDirectControl = 0;
	skeletonName = "BP_DogSkeleton";
	gestures = "CfgGesturesMale";
	collisionVertexPattern[] = {};
	collisionGeomCompPattern[] = {};

	class Default : Default 
	{
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
		collisionShape = "breakingpoint_anim\dogs\Dog_CollShape.p3d";
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
	
	class States 
	{
		class Dog_Stop: StandBase
		{
			enableDirectControl = 1;
			actions = "DogActions";
			duty = -1;
			file = "\breakingpoint_anim\dogs\dogStop";
			showWeaponAim = false;
			disableWeapons = true;
			disableWeaponsLong = true;
			speed = 1e+010;
			relSpeedMin = 0.7;
			relSpeedMax = 1.1;
			looped = 1;
			soundEnabled = false;
			ConnectTo[] = {"Dog_TurnR",0.1,"Dog_Attack",0.1,"Dog_Sniff",0.1,"Dog_StopV2",0.1,"Dog_StopV1",0.1,"Dog_TurnL",0.1,"Dog_Sprint",0.02,"Dog_Run",0.02,"Dog_Walk",0.2};
			InterpolateTo[] = {"Dog_TurnR",0.1,"Dog_Die",0.02,"Dog_TurnL",0.1,"Dog_Sprint",0.02,"Dog_Run",0.02,"Dog_Walk",0.2};
			interpolationSpeed = 1;
			preload = true;
		};
		class Dog_TurnL: Dog_Stop
		{
			file = "\breakingpoint_anim\dogs\dog_rotateL.rtm";
			speed = 1;
			ConnectTo[] = {"Dog_Stop",0.1};
			InterpolateTo[] = {"Dog_Stop",0.1};
		};
		class Dog_TurnR: Dog_TurnL
		{
			file = "\breakingpoint_anim\dogs\dog_rotateR.rtm";
			ConnectTo[] = {"Dog_Stop",0.1};
			InterpolateTo[] = {"Dog_Stop",0.1};
		};
		class Dog_StopV1: Dog_Stop
		{
			file = "\breakingpoint_anim\dogs\dogIDLE";
			speed = 2.14;
			variantAfter[] = {5,7,10};
			looped = 0;
			ConnectTo[] = {"Dog_Stop",0.1};
			InterpolateTo[] = {"Dog_Die",0.02};
		};
		class Dog_StopV2: Dog_Stop
		{
			file = "\breakingpoint_anim\dogs\dogBark";
			speed = 1;
			variantAfter[] = {1,1,1};
			looped = 0;
			ConnectTo[] = {"Dog_Stop",0.1};
			InterpolateTo[] = {"Dog_Die",0.02};
		};
		class Dog_Attack: Dog_Stop
		{
			file = "\breakingpoint_anim\dogs\dogAttack";
			speed = 1;
			variantAfter[] = {1,1,1};
			looped = 0;
			ConnectTo[] = {"Dog_Stop",0.1};
			InterpolateTo[] = {"Dog_Die",0.02};
		};
		class Dog_Sniff: Dog_Stop
		{
			file = "\breakingpoint_anim\dogs\dogGestureSniff";
			speed = 0.3;
			mask = "frontBody";	
			variantAfter[] = {1,1,1};
			looped = 0;
			ConnectTo[] = {"Dog_Stop",0.1};
			InterpolateTo[] = {"Dog_Die",0.02};
		};
		class Dog_SitDown: Dog_Stop
		{
			actions = "DogSit";
			file = "\breakingpoint_anim\dogs\dogSit1In";
			speed = 1.43;
			variantAfter[] = {1,1,1};
			looped = 0;
			relSpeedMin = 0.996672;
			relSpeedMax = 0.996672;
			ConnectTo[] = {};
			InterpolateTo[] = {"Dog_Die",0.02};
		};
		class Dog_LieDown: Dog_Stop
		{
			actions = "DogSit";
			file = "\breakingpoint_anim\dogs\dogStandDown";
			speed = 1.428571;
			variantAfter[] = {1,1,1};
			looped = 0;
			relSpeedMin = 0.996672;
			relSpeedMax = 0.996672;
			ConnectTo[] = {};
			InterpolateTo[] = {"Dog_Die",0.02};
		};
		class Dog_GetUp: Dog_Stop
		{
			actions = "DogSit";
			file = "\breakingpoint_anim\dogs\dogDownStand";
			speed = 1.428571;
			variantAfter[] = {1,1,1};
			looped = 0;
			relSpeedMin = 0.996672;
			relSpeedMax = 0.996672;
			ConnectTo[] = {"Dog_Stop",0.1,"Dog_Run",0.1,"Dog_Walk",0.1,"Dog_Sprint",0.1};
			InterpolateTo[] = {"Dog_Die",0.02,"Dog_Run",0.1,"Dog_Walk",0.1,"Dog_Sprint",0.1};
		};
		class Dog_Siting: Dog_Stop
		{
			actions = "DogSit";
			file = "\breakingpoint_anim\dogs\dogSit2Idle";
			speed = 1.58;
			variantAfter[] = {1,1,1};
			looped = 1;
			ConnectTo[] = {};
			InterpolateTo[] = {"Dog_Die",0.02};
		};
		class Dog_SitUp: Dog_Stop
		{
			actions = "DogSit";
			file = "\breakingpoint_anim\dogs\dogSit3Out";
			speed = 1.08;
			variantAfter[] = {1,1,1};
			looped = 0;
			relSpeedMin = 0.996672;
			relSpeedMax = 0.996672;
			ConnectTo[] = {"Dog_Stop",0.1,"Dog_Run",0.1,"Dog_Walk",0.1,"Dog_Sprint",0.1};
			InterpolateTo[] = {"Dog_Die",0.02,"Dog_Run",0.1,"Dog_Walk",0.1,"Dog_Sprint",0.1};
		};
		class Dog_Sprint: Dog_Stop
		{
			actions = "DogSprint";
			file = "\breakingpoint_anim\dogs\dogSprint";
			duty = 0.5;
			speed = 5;
			ConnectTo[] = {"Dog_Stop",0.02,"Dog_Attack",0.1,"Dog_Run",0.02,"Dog_Walk",0.02};
			InterpolateTo[] = {"Dog_Die",0.02,"Dog_Stop",0.02,"Dog_Run",0.02,"Dog_Walk",0.02};
		};
		class Dog_Run: Dog_Stop
		{
			file = "\breakingpoint_anim\dogs\dogRun";
			duty = -0.5;
			speed = 3;
			ConnectTo[] = {"Dog_Stop",0.02,"Dog_Attack",0.1,"Dog_Sprint",0.02,"Dog_Walk",0.02};
			InterpolateTo[] = {"Dog_Die",0.02,"Dog_Stop",0.02,"Dog_Sprint",0.02,"Dog_Walk",0.02};
		};
		
		class Dog_Walk: Dog_Stop
		{
			duty = -0.7;
			file = "\breakingpoint_anim\dogs\dogWalk";
			speed = 2;
			variantAfter[] = {3,10,20};
			ConnectTo[] = {"Dog_Stop",0.2,"Dog_Attack",0.1,"Dog_Sprint",0.2,"Dog_Run",0.2};
			InterpolateTo[] = {"Dog_Die",0.02,"Dog_Stop",0.2,"Dog_Sprint",0.2,"Dog_Run",0.2};
		};
		
		class Dog_Die: DefaultDie
		{
			enableDirectControl = 0;
			actions = "NoActions";
			file = "\breakingpoint_anim\dogs\dogDeath";
			speed = 1.2;
			looped = 0;
			variantsPlayer[] = {};
			variantsAI[] = {""};
			variantAfter[] = {0,0,0};
			terminal = 1;
			soundEnabled = 0;
			//collisionShape = "";
			ConnectTo[] = {};
			InterpolateTo[] = {};
		};
	};
	
	class Actions : Actions 
	{
		class NoActions: NoActions
		{
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = 0;
			BP_Dog_Act_Attack1[] = {"BP_Dog_Attack1","Gesture"};
		};
		class DogActions: NoActions
		{
			Stop = "Dog_Stop";
			StopRelaxed = "Dog_Stop";
			TurnL = "Dog_TurnL";
			TurnR = "Dog_TurnR";
			TurnLRelaxed = "Dog_TurnL";
			TurnRRelaxed = "Dog_TurnR";
			Default = "Dog_Stop";
			JumpOff = "Dog_Stop";
			WalkF = "Dog_Walk";
			//WalkF = "Dog_Run";
			SlowF = "Dog_Run";
			FastF = "Dog_Sprint";
			EvasiveForward = "Dog_Sprint";
			Down = "Dog_Stop";
			Up = "Dog_Stop";
			PlayerStand = "Dog_Stop";
			PlayerProne = "Dog_Stop";
			PlayerCrouch = "";
			Crouch = "";
			Lying = "Dog_Stop";
			Stand = "Dog_Stop";
			Combat = "Dog_Stop";
			CanNotMove = "Dog_Stop";
			Civil = "Dog_Stop";
			CivilLying = "Dog_Stop";
			FireNotPossible = "Dog_StopV1";
			Die = "Dog_Die";
			turnSpeed = 8;
			limitFast = 5.5;
			useFastMove = 0;
			upDegree = "ManPosNoWeapon";
			//StartSwim = "Dog_Die";
			
		};
		class DogSprint: DogActions
		{
			Die = "Dog_Die";
			turnSpeed = 4;
			limitFast = 5.5;
			useFastMove = 1;
		};
		class DogSit: NoActions
		{
			Up = "Dog_Stop";
			PlayerStand = "Dog_Stop";
			Stand = "Dog_Stop";
			WalkF = "Dog_Walk";
			//WalkF = "Dog_Run";
			SlowF = "Dog_Run";
			FastF = "Dog_Sprint";
			EvasiveForward = "Dog_Sprint";
			PlayerCrouch = "Dog_Stop";
			Crouch = "Dog_Stop";
			Die = "Dog_Die";
			upDegree = "ManPosNoWeapon";
			//StartSwim = "Dog_Die";		
		};
	};
	
	class Interpolations {};
	transitionsInterpolated[] = {};
	transitionsSimple[] = {};
	transitionsDisabled[] = {};
	
	class BlendAnims: BlendAnims
	{
		aimingDefault[] = {"head",1,"Jaw",1,"Neck1",0.5,"Tongue1",1,"Tongue2",1};
		untiltWeaponDefault[] = {};
		legsDefault[] = {};
		headDefault[] = {"head",1,"Jaw",1,"Neck1",0.5,"Tongue1",1,"Tongue2",1};
		aimingNo[] = {};
		legsNo[] = {};
		headNo[] = {};
		aimingUpDefault[] = {};
		frontBody[] = {
			
			//"spine",0.1,
			//"spine1",0.3,
			//"spine2",0.6,
			
			"neck",1,
			"neck1",1,
			"head",1,
			"Jaw",1,
			"Tongue1",1,
			"Tongue2",1,
			"leftArm",0.5,
			"rightArm",0.5,
			"leftEar",1,
			"rightEar",1
		};
	};
};
*/

