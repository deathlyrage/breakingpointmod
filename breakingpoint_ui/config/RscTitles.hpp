
class RscTitles 
{
	titles[] = {"TitleScreen", "DeathScreenStart", "DeathScreenEnd", "BP_Combatlog", "BP_Shutdown", "BP_Ghosting", "BP_Unconscious", "BP_BloodspraySmall", "BP_BloodsprayMedium", "BP_BloodsprayLarge", "Bp_BloodsprayStunned", "BP_Flashbang", "BP_Resting", "BP_AuthFailed", "BP_InvalidVersion", "BP_OutdatedServer", "BP_InvalidAddons", "BP_Rejected", "BP_InvalidName", "BP_NoPlayerID", "BP_ServerNotReady", "BP_Whitelist", "RscTitleStructuredText"};

	class TitleScreen {
		idd = -1;
		movingEnable = "false";
		duration = 30;
		fadein = 0;
		name = "TitleScreen";
		controls[] = {"TitleScreen"};
		
		class TitleScreen : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\general\BP_screen_title.paa";
		};
	};
	
	class DeathScreenStart {
		idd = -1;
		movingEnable = "false";
		duration = 30;
		fadein = 0;
		name = "DeathScreenStart";
		controls[] = {"DeathScreenStart"};
		
		class DeathScreenStart : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_DeathScreenStart.paa";
		};
	};

	class DeathScreenEnd {
		idd = -1;
		movingEnable = "false";
		duration = 30;
		fadein = 0;
		name = "DeathScreenEnd";
		controls[] = {"DeathScreenEnd"};
		
		class DeathScreenEnd : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_DeathScreenEnd.paa";
		};
	};
	
	class DeathScreenEndZed {
		idd = -1;
		movingEnable = "false";
		duration = 30;
		fadein = 0;
		name = "DeathScreenEndZed";
		controls[] = {"DeathScreenEndZed"};
		
		class DeathScreenEndZed : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_DeathScreenEndZed.paa";
		};
	};
	
	class BP_Shutdown {
		idd = -1;
		movingEnable = "false";
		duration = 500;
		fadein = 0;
		name = "Shutdown";
		controls[] = {"Shutdown"};
		
		class Shutdown : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_Shutdown.jpg";
		};
	};
	
	class BP_Combatlog {
		idd = -1;
		movingEnable = "false";
		duration = 500;
		fadein = 0;
		name = "Combatlog";
		controls[] = {"Combatlog"};
		
		class Combatlog : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_Combatlog.jpg";
		};
	};
		
	class BP_Ghosting {
		idd = -1;
		movingEnable = "false";
		duration = 500;
		fadein = 0;
		name = "BP_Ghosting";
		controls[] = {"BP_Ghosting"};
		
		class BP_Ghosting : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_Ghosting.jpg";
		};
	};

	class BP_Unconscious {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 1;
		name = "BP_Unconscious";
		controls[] = {"BP_Unconscious"};
		
		class BP_Unconscious : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Unconscious.paa";
		};
	};

	/*
	class BP_Loading_1 {
		idd = -1;
		movingEnable = "false";
		duration = 120;
		fadein = 0;
		name = "BP_Loading_1";
		controls[] = {"BP_Loading_1"};
		
		class BP_Loading_1 : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\general\BP_screen_loading_1.jpg";
		};
	};
	*/

	class BP_BloodspraySmall {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "BloodspraySmall";
		controls[] = {"BloodspraySmall"};
		
		class BloodspraySmall : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_BloodspraySmall.paa";
		};
	};

	class BP_BloodsprayMedium {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "BloodsprayMedium";
		controls[] = {"BloodsprayMedium"};
		
		class BloodsprayMedium : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_BloodsprayMedium.paa";
		};
	};

	class BP_BloodsprayLarge {
		idd = -1;
		movingEnable = "true";
		duration = 6;
		fadein = 1;
		name = "BloodsprayLarge";
		controls[] = {"BloodsprayLarge"};
		
		class BloodsprayLarge : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_BloodsprayLarge.paa";
		};
	};
	
	class BP_BloodsprayStunned {
		idd = -1;
		movingEnable = "true";
		duration = 30;
		fadein = 1;
		name = "BloodsprayStunned";
		controls[] = {"BloodsprayStunned"};
		
		class BloodsprayStunned : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_BloodsprayStunned.paa";
		};
	};
	
	class BP_Flashbang {
		idd = -1;
		movingEnable = "true";
		duration = 10;
		fadein = 1;
		name = "Flashbang";
		controls[] = {"Flashbang"};
		
		class Flashbang : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Flashbang.paa";
		};
	};
	
	class BP_Resting {
		idd = -1;
		movingEnable = "true";
		duration = 7;
		fadein = 1;
		name = "Resting";
		controls[] = {"Resting"};
		
		class Resting : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Resting.paa";
		};
	};

	class BP_AuthFailed {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "AuthFailed";
		controls[] = {"AuthFailed"};
		
		class AuthFailed : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_AuthFailed.jpg";
		};
	};

	class BP_InvalidVersion {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "InvalidVersion";
		controls[] = {"InvalidVersion"};
		
		class InvalidVersion : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_InvalidVersion.jpg";
		};
	};
	
	class BP_OutdatedServer {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "OutdatedServer";
		controls[] = {"OutdatedServer"};
		
		class OutdatedServer : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_OutdatedServer.jpg";
		};
	};
	
	class BP_InvalidAddons {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "InvalidAddons";
		controls[] = {"InvalidAddons"};
		
		class InvalidAddons : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_InvalidAddons.jpg";
		};
	};
	
	class BP_LegionOnly {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "LegionOnly";
		controls[] = {"LegionOnly"};
		
		class LegionOnly : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_LegionOnly.jpg";
		};
	};
	
	class BP_Rejected {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "Rejected";
		controls[] = {"Rejected"};
		
		class Rejected : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_Rejected.jpg";
		};
	};

	class BP_InvalidName {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 1;
		name = "InvalidName";
		controls[] = {"InvalidName"};
		
		class InvalidName : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_InvalidName.jpg";
		};
	};
	
	class BP_ServerFailure {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "ServerFailure";
		controls[] = {"ServerFailure"};
		
		class ServerFailure : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_ServerFailure.jpg";
		};
	};
	
	class BP_NoPlayerID {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "NoPlayerID";
		controls[] = {"NoPlayerID"};
		
		class NoPlayerID : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_NoPlayerID.jpg";
		};
	};

	class BP_ServerNotReady {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "ServerNotReady";
		controls[] = {"ServerNotReady"};
		
		class ServerNotReady : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_ServerNotReady.jpg";
		};
	};

	class BP_Whitelist {
		idd = -1;
		movingEnable = "false";
		duration = 46;
		fadein = 0;
		name = "Whitelist";
		controls[] = {"Whitelist"};
		
		class Whitelist : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_Whitelist.jpg";
		};
	};
	
	class BP_HiveFailure {
		idd = -1;
		movingEnable = "false";
		duration = 45;
		fadein = 0;
		name = "HiveFailure";
		controls[] = {"HiveFailure"};
		
		class HiveFailure : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\errors\BP_HiveFailure.jpg";
		};
	};
	
	class BP_Scratch_1 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Scratch";
		controls[] = {"Scratch"};
		
		class Scratch : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Scratch_1.paa";
		};
	};
	
	class BP_Scratch_2 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Scratch";
		controls[] = {"Scratch"};
		
		class Scratch : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Scratch_2.paa";
		};
	};
	
	class BP_Scratch_3 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Scratch";
		controls[] = {"Scratch"};
		
		class Scratch : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Scratch_3.paa";
		};
	};
	
	class BP_Scratch_4 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Scratch";
		controls[] = {"Scratch"};
		
		class Scratch : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Scratch_4.paa";
		};
	};
	
	class BP_Scratch_5 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Scratch";
		controls[] = {"Scratch"};
		
		class Scratch : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Scratch_5.paa";
		};
	};
	
	class BP_Dog_1 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Dog";
		controls[] = {"Dog"};
		
		class Dog : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Dog_1.paa";
		};
	};

	class BP_Dog_2 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Dog";
		controls[] = {"Dog"};
		
		class Dog : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Dog_2.paa";
		};
	};
	
	class BP_Dog_3 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Dog";
		controls[] = {"Dog"};
		
		class Dog : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Dog_3.paa";
		};
	};
	
	class BP_Dog_4 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Dog";
		controls[] = {"Dog"};
		
		class Dog : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Dog_4.paa";
		};
	};
	
	class BP_Dog_5 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Dog";
		controls[] = {"Dog"};
		
		class Dog : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Dog_5.paa";
		};
	};
	
	class BP_Dog_6 {
		idd = -1;
		movingEnable = "true";
		duration = 5;
		fadein = 1;
		name = "Dog";
		controls[] = {"Dog"};
		
		class Dog : RscPicture {
			x = "0.00001 * safezoneW + safezoneX";
			y = "0.00001 * safezoneH + safezoneY";
			w = "1 * safezoneW";
			h = "1 * safezoneH";
			text = "\breakingpoint_ui\medical\BP_Dog_6.paa";
		};
	};
};
