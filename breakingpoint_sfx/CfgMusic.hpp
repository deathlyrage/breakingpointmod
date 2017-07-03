/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgMusic
{
	class PitchWhine
	{
		name = "PitchWhine";
		sound[] = {"\breakingpoint_sfx\effects\pitchWine.ogg", db+5, 1.0};
	};
	class BP_track_death_1
	{
		name = "Death";
		sound[] = {"\breakingpoint_sfx\tracks\BP_DeathScreen.wss", db+0, 1.0};
	};
	class BP_track_intro_1
	{
		name = "Intro";
		sound[] = {"\breakingpoint_sfx\tracks\track_intro_1.ogg", db+0, 1.0};
		duration = ;
	};
	class bp_val_0 //NIGHT ONLY
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\Calm_Night_Ambience.ogg", db+0, 1.0};
		duration = 85;
	};
	class bp_val_1
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_1.ogg", db+0, 1.0};
		duration = 28;
	};
	class bp_val_2
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_2.ogg", db+0, 1.0};
		duration = 14;
	};
	class bp_val_3
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_3.ogg", db+0, 1.0};
		duration = 15;
	};
	class bp_val_4
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_4.ogg", db+0, 1.0};
		duration = 27;
	};
	class bp_val_5
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_5.ogg", db+0, 1.0};
		duration = 14;
	};
	class bp_val_6
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_6.ogg", db+0, 1.0};
		duration = 11;
	};
	class bp_val_7
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_7.ogg", db+0, 1.0};
		duration = 19;
	};
	class bp_val_8
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_8.ogg", db+0, 1.0};
		duration = 16;
	};
	class bp_val_9
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_9.ogg", db+0, 1.0};
		duration = 20;
	};
	class bp_val_10
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_10.ogg", db+0, 1.0};
		duration = 21;
	};
	class bp_val_11
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_11.ogg", db+0, 1.0};
		duration = 22;
	};
	class bp_val_12
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_12.ogg", db+0, 1.0};
		duration = 19;
	};
	class bp_val_13
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\darker_ambiance_13.ogg", db+0, 1.0};
		duration = 18;
	};
	class bp_val_14
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_2.ogg", db+0, 1.0};
		duration = 47;
	};
	class bp_val_15
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_3.ogg", db+0, 0.9};
		duration = 28;
	};
	class bp_val_16
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_4.ogg", db+0, 0.9};
		duration = 13;
	};
	class bp_val_17
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_5.ogg", db+0, 1.0};
		duration = 28;
	};
	class bp_val_18
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_6.ogg", db+0, 0.9};
		duration = 19;
	};
	class bp_val_19
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_7.ogg", db-3, 1.0};
		duration = 21;
	};
	class bp_val_20
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_8.ogg", db-3, 1.0};
		duration = 9;
	};
	class bp_val_21
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\short_ambience_9.ogg", db+0, 1.0};
		duration = 20;
	};
	class bp_val_22 //NIGHT ONLY
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\heavy_ambience.ogg", db+0, 0.9};
		duration = 76;
	};
	class bp_val_23
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\minor_ambience.ogg", db+0, 1.0};
		duration = 57;
	};
	class bp_val_24 //NIGHT ONLY
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\moody_ambience.ogg", db+0, 1.0};
		duration = 88;
	};
	
	class bp_val_25 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\surviving.ogg", db+0, 1.0};
		duration = 86;
	};
	
	class bp_val_26 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\surviving_2.ogg", db+0, 1.0};
		duration = 58;
	};
	
	class bp_val_27 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\Windswept.ogg", db+0, 1.0};
		duration = 58;
	};
	
	class bp_val_28 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\Hope.ogg", db+0, 0.7};
		duration = 85;
	};

    class bp_val_29 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\UneasyFeeling.ogg", db+0, 1.0};
		duration = 138;
	};	
     
    class bp_val_30 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\Building.ogg", db+0, 1.0};
		duration = 108;
	};

    class bp_val_31 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\OppressiveMachines.ogg", db+0, 1.0};
		duration = 76;
	};
 
    class bp_val_32 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\OppressiveMachines2.ogg", db+0, 1.0};
		duration = 63;
	};

    class bp_val_33 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\OppressiveMachines3.ogg", db+0, 1.0};
		duration = 82;
	};

    class bp_val_34 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\LonelyDesert.ogg", db+0, 1.0};
		duration = 146;
	};

    class bp_val_35 
	{
		name = "";
		sound[] = {"\breakingpoint_sfx\samples\NightFairy.ogg", db+0, 1.0};
		duration = 51;
	};	
};
