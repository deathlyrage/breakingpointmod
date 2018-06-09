		buildCrash0[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_01",0.70794576,1,40};
		buildCrash1[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_02",0.70794576,1,40};
		buildCrash2[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_03",0.70794576,1,40};
		buildCrash3[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_04",0.70794576,1,40};
		soundBuildingCrash[] = {"buildCrash0",0.25,"buildCrash1",0.25,"buildCrash2",0.25,"buildCrash3",0.25};
		WoodCrash0[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_wood_small_01",0.70794576,1,40};
		WoodCrash1[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_wood_small_02",0.70794576,1,40};
		WoodCrash2[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_wood_small_03",0.70794576,1,40};
		WoodCrash3[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_wood_small_04",0.70794576,1,40};
		soundWoodCrash[] = {"woodCrash0",0.25,"woodCrash1",0.25,"woodCrash2",0.25,"woodCrash3",0.25};
		ArmorCrash0[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_06",0.70794576,1,40};
		ArmorCrash1[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_05",0.70794576,1,40};
		ArmorCrash2[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_04",0.70794576,1,40};
		ArmorCrash3[] = {"\breakingpoint_vehicles\bp_old_bike\sounds\Crash\crash_bicycle_03",0.70794576,1,40};
		soundArmorCrash[] = {"ArmorCrash0",0.25,"ArmorCrash1",0.25,"ArmorCrash2",0.25,"ArmorCrash3",0.25};


		attenuationEffectType = "CarAttenuation";
		soundGetIn[]={"",db-5,1};
		soundGetOut[]={"",db-5,1, 40};
		soundDammage[]={"", db-5, 1};
		soundEngineOnInt[] = {"",0.39810717,1.0};
		soundEngineOnExt[] = {"",0.4466836,1.0,200};
		soundEngineOffInt[] = {"",0.39810717,1.0};
		soundEngineOffExt[] = {"",0.4466836,1.0,200};	
		

class Sounds
{
	#define	FACTOR(val,from,to)	(val factor[from,to])
	#define	RANGE(val,from,band0,to,band1) FACTOR2(val,from,(from+band0),to,(to+band1))
	#define	FACTOR2(val,from0,to0,from1,to1) (FACTOR(val,from0,to0)	*	FACTOR(val,to1,from1))

	#define	MAX_RPM	6900
	#define	RPM(rpm) (rpm/MAX_RPM)

	#define	FACTOR_RPM(from,to)	FACTOR(RPM(rpm),RPM(from),RPM(to))
	#define	FACTOR2_RPM(from0,to0,from1,to1) (FACTOR_RPM(from0,to0)	*	FACTOR_RPM(to1,from1))
	#define	RANGE_RPM(from,band0,to,band1) FACTOR2_RPM(from,(from+band0),to,(to+band1))
	
	#define HZ_IDLE FACTOR_RPM(400,1150)
	#define HZ_RPM1 FACTOR_RPM(900,2100)
	#define HZ_RPM2	FACTOR_RPM(1300,3100)
	#define HZ_RPM3 FACTOR_RPM(2200,4100)
	#define HZ_RPM4 FACTOR_RPM(3300,4900)
	#define HZ_RPM5 FACTOR_RPM(4200,6200)
	#define HZ_RPM6 FACTOR_RPM(5100,6900)
	
	#define VOLUME_IDLE FACTOR2_RPM(400,700,900,1100)
	#define VOLUME_RPM1 FACTOR2_RPM(870,1100,1300,2100)
	#define VOLUME_RPM2 FACTOR2_RPM(1250,2050,2300,3100)
	#define VOLUME_RPM3 FACTOR2_RPM(2250,3050,3300,4100)
	#define VOLUME_RPM4 FACTOR2_RPM(3250,4050,4200,4870)
	#define VOLUME_RPM5 FACTOR2_RPM(4150,4800,5150,6150)
	#define VOLUME_RPM6 FACTOR_RPM(5100,6100)
	class Engine
		{
			sound[] =  {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\low1", db+10, 1.0, 35};
			frequency = "(randomizer*0.01+1.0)*rpm";
			volume = "camPos*engineOn*((speed factor[0.1, 0.6]) min (speed factor[0.6, 0.1]))";
		};
		class EngineHighOut
		{
			sound[] = {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\high1", db+10, 1.0, 50};
			frequency = "(randomizer*0.05+1.0)*rpm";
			volume = "camPos*engineOn*(speed factor[0.4, 0.9])";
		};
		class IdleOut
		{
			sound[] = {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\idle", db+10, 1.0, 35};
			frequency = "1";
			volume = "camPos*engineOn*(speed factor[0.05, 0.9])";
		};

	/*INTERNAL SOUNDS MMT*/
		class EngineLowIn
		{
			sound[] = {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\low1", db-5, 1.0};
			frequency = "(randomizer*0.1+1)*speed";
			volume = "(1-camPos)*engineOn*((speed factor[0.1, 0.6]) min (speed factor[0.6, 0.1]))";
		};
		class EngineHighIn
		{
			sound[] = {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\high1", db-5, 1.0};
			frequency = "(randomizer*0.05+1.0)*rpm";
			volume = "(1-camPos)*engineOn*(speed factor[0.4, 0.9])";
		};
		class IdleIn
		{
			sound[] = {"breakingpoint_vehicles\bp_old_bike\sounds\Wheeled\MMT\idle", db-5, 1.0};
			frequency = "1";
			volume = "(1-camPos)*engineOn*(speed factor[0.05, 0.9])";
		};
	class	Movement
	{
		sound	=	"soundEnviron";
		frequency	=	"1";
		volume = "0";
	};
 			class TiresRockOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1", db-2, 1.0, 60};
				frequency = "1";
				volume = "camPos*rock*(speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1", db-2, 1.0, 60};
				frequency = "1";
				volume = "camPos*sand*(speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2", db-2, 1.0, 60};
				frequency = "1";
				volume = "camPos*grass*(speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2", db-2, 1.0, 60};
				frequency = "1";
				volume = "camPos*mud*(speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1", db-2, 1.0, 60};
				frequency = "1";
				volume = "camPos*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2", db-2, 1.0, 60};
				frequency = "1";
				volume = "camPos*asphalt*(speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_ext_car_3", db-2, 1.0, 90};
				frequency = "1";
				volume = "camPos*(damper0 max 0.02)*(speed factor[0, 8])";
			};

			class TiresRockIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1", db-2, 1.0};
				frequency = "1";
				volume = "(1-camPos)*rock*(speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2", db-2, 1.0};
				frequency = "1";
				volume = "(1-camPos)*sand*(speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2", db-2, 1.0};
				frequency = "1";
				volume = "(1-camPos)*grass*(speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2", db-2, 1.0};
				frequency = "1";
				volume = "(1-camPos)*mud*(speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1", db-2, 1.0};
				frequency = "1";
				volume = "(1-camPos)*gravel*(speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2", db-2, 1.0};
				frequency = "1";
				volume = "(1-camPos)*asphalt*(speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[] = {"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3", db-2, 1.0};
				frequency = "1";
				volume = "(damper0 max 0.1)*(speed factor[0, 8])*(1-camPos)";
			};
	
	class breaking_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04", db+5, 1, 80}; //db-3 +10
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	
	
	class acceleration_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db+5, 1, 80};
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
	};	
	class turn_left_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db+5, 1, 80};
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
	};	

	class turn_right_ext_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02", db+5, 1, 80};
		frequency	=	1;
		volume = engineOn*camPos*asphalt*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	
		
	class breaking_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking", db+5, 1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
	};	
	class acceleration_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration", db+5,	1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 1]);
	};	
	class turn_left_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db+5, 1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[1, 15]);
	};	

	class turn_right_ext_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt", db+5, 1, 60};
		frequency	=	1;
		volume = engineOn*camPos*(1-asphalt)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[1, 15]);
	};	

	class breaking_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int", db+0, 1}; //db-10 +10
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	
	
	class acceleration_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db+0, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
	};	
	class turn_left_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db+0, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
	};	
	class turn_right_int_road
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int", db+0, 1};
		frequency	=	1;
		volume = engineOn*asphalt*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};	

	class breaking_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_14_dirt_breaking_int", db+0, 1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[-01, -0.4])*(Speed Factor[2, 15]);
	};	
	class acceleration_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_16_dirt_acceleration_int", db+0, 1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(LongSlipDrive Factor[0.1, 0.4])*(Speed Factor[15, 2]);
	};	
	class turn_left_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db+0,	1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[0.1, 0.4])*(Speed Factor[2, 15]);
	};	
	class turn_right_int_dirt
	{
		sound[]	=	{"A3\Sounds_F\vehicles\soft\noises\slipping_tires_18_dirt_int", db+0,	1};
		frequency	=	1;
		volume = engineOn*(1-asphalt)*(1-camPos)*(latSlipDrive Factor[-0.1, -0.4])*(Speed Factor[2, 15]);
	};
};