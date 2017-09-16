/*
	Breaking Point Mod for Arma 3

	Released under Arma Public Share Like Licence (APL-SA)
	https://www.bistudio.com/community/licenses/arma-public-license-share-alike

	Alderon Games Pty Ltd
*/

class CfgHeads {
	class Default_A3 {
		model = "\A3\characters_f\Heads\m_white_01";
		
		class Wounds {
			tex[] = {};
			mat[] = {"A3\Characters_F\Heads\Data\m_white_01.rvmat", "A3\characters_f\Heads\Data\m_white_01_injury.rvmat", "A3\characters_f\Heads\Data\m_white_01_injury.rvmat"};
		};
		selectionHeadWound = "injury_head";
		selectionPersonality = "personality";
		selectionPersonalityHL = "hl";
		
		class Grimaces {
			class Eyes {
				type = "eyes";
				eyeMaxAngle = 0.26;
				eyelidUpStartAngle = 0.0;
				eyelidUpMaxAngle = 3.14;
				eyelidDownStartAngle = 0.0;
				eyelidDownMaxAngle = 3.14;
			};
			
			class Lipsync {
				type = "lipsync";
				vizem[] = {"A3\Characters_F\Heads\Anim\male\Neutral.rtm", "A3\Characters_F\Heads\Anim\male\vizem\a.rtm", "A3\Characters_F\Heads\Anim\male\vizem\e2.rtm", "A3\Characters_F\Heads\Anim\male\vizem\f.rtm", "A3\Characters_F\Heads\Anim\male\vizem\m.rtm", "A3\Characters_F\Heads\Anim\male\vizem\y.rtm", "A3\Characters_F\Heads\Anim\male\vizem\v.rtm", "A3\Characters_F\Heads\Anim\male\vizem\i.rtm"};
			};
			
			class RTM_Face {
				type = "rtm";
				anim = "A3\Characters_F\Heads\Anim\male\Neutral.rtm";
				anims[] = {"A3\Characters_F\Heads\Anim\male\Neutral.rtm", 1};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\Neutral.rtm", 1};
			};
			
			class NeutralFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\1a_frown_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1a_neutral_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1a_smile_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_frown_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_neutral_165_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_smile_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1c_frown_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1c_neutral_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1c_smile_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1d_frown_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1d_neutral_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1d_smile_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_frown_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_neutral_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_smile_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1f_frown_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1f_neutral_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1f_smile_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1g_frown_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1g_neutral_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1g_smile_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1h_frown_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1h_neutral_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1h_smile_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1i_frown_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1i_neutral_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1i_smile_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1j_neutral_200_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_smile_200_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2a_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2a_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2a_smile_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2b_frown_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2b_neutral_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2b_smile_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2c_frown_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2c_neutral_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2c_smile_110_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_neutral_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2e_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2e_neutral_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2e_smile_200_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\2f_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_smile_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2g_frown_120_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2g_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2g_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
			};
			
			class DeadFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\Dead.rtm", 1};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\Dead.rtm", 1};
			};
			
			class UnconsciousFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\unconscious.rtm", 1};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\unconscious.rtm", 1};
			};
			
			class DangerFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\1a_frown_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1a_neutral_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_frown_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_neutral_165_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\1c_neutral_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1d_frown_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1d_neutral_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1f_neutral_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1g_frown_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1g_neutral_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1h_neutral_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1i_frown_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1i_neutral_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_neutral_200_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2a_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2a_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2b_neutral_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2c_neutral_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_neutral_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2e_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2e_neutral_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2f_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2g_frown_120_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2g_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
			};
			
			class HurtFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\1a_frown_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_frown_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1c_frown_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1d_frown_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_frown_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1g_frown_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1h_frown_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1i_frown_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1j_neutral_200_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2a_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2b_frown_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2b_neutral_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2c_frown_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2c_neutral_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2e_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2f_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2g_frown_120_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2g_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\1a_frown_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1a_neutral_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_frown_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_neutral_165_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\1c_frown_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1c_neutral_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1d_frown_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1d_neutral_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_frown_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_neutral_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1f_frown_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1f_neutral_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1g_frown_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1g_neutral_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1h_frown_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1h_neutral_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1i_frown_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1i_neutral_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1j_neutral_200_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2a_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2a_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2b_frown_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2b_neutral_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2c_frown_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2c_neutral_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_neutral_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2e_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2e_neutral_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2f_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2g_frown_120_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2g_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\still3_03gulp.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still3_03gulp.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still3_03gulp.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still3_03gulp.rtm", 3.0};
			};
			
			class AwareFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
			};
			
			class SafeFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still2_09.rtm", 4.6, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\1a_neutral_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1a_smile_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_neutral_165_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_smile_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1c_neutral_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1c_smile_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1d_neutral_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1d_smile_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_neutral_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_smile_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1f_neutral_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1f_smile_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1g_neutral_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1g_smile_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1h_neutral_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1h_smile_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1i_neutral_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1i_smile_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_neutral_200_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_smile_200_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2a_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2a_smile_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2b_neutral_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2b_smile_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2c_neutral_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2c_smile_110_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_neutral_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2e_neutral_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2e_smile_200_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\2f_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_smile_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2g_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2g_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\1a_frown_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1a_neutral_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1a_smile_170_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_frown_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_neutral_165_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\1b_smile_165_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1c_frown_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1c_neutral_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1c_smile_110_r.rtm", 3, "A3\Characters_F\Heads\Anim\male\1d_frown_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1d_neutral_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1d_smile_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_frown_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_neutral_180_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1e_smile_180_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\1f_frown_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1f_neutral_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1f_smile_240_r.rtm", 8, "A3\Characters_F\Heads\Anim\male\1g_frown_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1g_neutral_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1g_smile_90_l.rtm", 3, "A3\Characters_F\Heads\Anim\male\1h_frown_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1h_neutral_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1h_smile_150_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\1i_frown_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1i_neutral_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1i_smile_180_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\1j_neutral_200_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\1j_smile_200_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2a_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2a_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2a_smile_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2b_frown_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2b_neutral_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2b_smile_190_r.rtm", 5, "A3\Characters_F\Heads\Anim\male\2c_frown_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2c_neutral_110_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2c_smile_110_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_neutral_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2d_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2e_frown_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2e_neutral_200_r.rtm", 6, "A3\Characters_F\Heads\Anim\male\2e_smile_200_l.rtm", 6, "A3\Characters_F\Heads\Anim\male\2f_frown_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_neutral_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2f_smile_80_l.rtm", 2.5, "A3\Characters_F\Heads\Anim\male\2g_frown_120_l.rtm", 5, "A3\Characters_F\Heads\Anim\male\2g_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2g_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_frown_120_r.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_neutral_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\2h_smile_120_l.rtm", 4, "A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still2_09.rtm", 4.6, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
			};
			
			class CombatFace : RTM_Face {
				anims[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
				animsAI[] = {"A3\Characters_F\Heads\Anim\male\still1_02.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still1_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still1_06.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still1_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still1_09.rtm", 3.6, "A3\Characters_F\Heads\Anim\male\still2_01.rtm", 2.6, "A3\Characters_F\Heads\Anim\male\still2_05.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still2_07.rtm", 3.0, "A3\Characters_F\Heads\Anim\male\still2_08.rtm", 3.3, "A3\Characters_F\Heads\Anim\male\still4_01.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_02.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_03.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_04.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_05.rtm", 5.0, "A3\Characters_F\Heads\Anim\male\still4_06.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_07.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_08.rtm", 6.0, "A3\Characters_F\Heads\Anim\male\still4_09.rtm", 4.0, "A3\Characters_F\Heads\Anim\male\still4_10.rtm", 6.0};
			};
			
			class Neutral {
				type = "compound";
				
				class Items {
					class NeutralFace : MaskFace_A3 {};
					
					class Lipsync : LipMask_A3 {};
				};
			};
			
			class Dead {
				type = "compound";
				
				class Items {
					class DeadFace : MaskFace_A3 {};
				};
			};
			
			class Unconscious {
				type = "compound";
				
				class Items {
					class UnconsciousFace : MaskFace_A3 {};
				};
			};
			
			class Danger {
				type = "compound";
				
				class Items {
					class DangerFace : MaskFace_A3 {};
					
					class Lipsync : LipMask_A3 {};
				};
			};
			
			class Hurt {
				type = "compound";
				
				class Items {
					class HurtFace : MaskFace_A3 {};
					
					class Lipsync : LipMask_A3 {};
				};
			};
			
			class Aware {
				type = "compound";
				
				class Items {
					class AwareFace : MaskFace_A3 {};
					
					class Lipsync : LipMask_A3 {};
				};
			};
			
			class Safe {
				type = "compound";
				
				class Items {
					class SafeFace : MaskFace_A3 {};
					
					class Lipsync : LipMask_A3 {
				};
			};
			
			class Combat {
				type = "compound";
				
				class Items {
					class CombatFace : MaskFace_A3 {};
					
					class Lipsync : LipMask_A3 {};
				};
			};
		};
	};
	class DefaultHead_A3 : Default_A3 {
		model = "\A3\characters_f\Heads\m_white_01";
		
		class Wounds {
			tex[] = {};
			mat[] = {"A3\Characters_F\Heads\Data\m_white_01.rvmat", "A3\characters_f\Heads\Data\m_white_01_injury.rvmat", "A3\characters_f\Heads\Data\m_white_01_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_02.rvmat", "A3\characters_f\Heads\Data\m_white_02_injury.rvmat", "A3\characters_f\Heads\Data\m_white_02_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_03.rvmat", "A3\characters_f\Heads\Data\m_white_03_injury.rvmat", "A3\characters_f\Heads\Data\m_white_03_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_04.rvmat", "A3\characters_f\Heads\Data\m_white_04_injury.rvmat", "A3\characters_f\Heads\Data\m_white_04_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_05.rvmat", "A3\characters_f\Heads\Data\m_white_05_injury.rvmat", "A3\characters_f\Heads\Data\m_white_05_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_06.rvmat", "A3\characters_f\Heads\Data\m_white_06_injury.rvmat", "A3\characters_f\Heads\Data\m_white_06_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_07.rvmat", "A3\characters_f\Heads\Data\m_white_07_injury.rvmat", "A3\characters_f\Heads\Data\m_white_07_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_08.rvmat", "A3\characters_f\Heads\Data\m_white_08_injury.rvmat", "A3\characters_f\Heads\Data\m_white_08_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_09.rvmat", "A3\characters_f\Heads\Data\m_white_09_injury.rvmat", "A3\characters_f\Heads\Data\m_white_09_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_10.rvmat", "A3\characters_f\Heads\Data\m_white_10_injury.rvmat", "A3\characters_f\Heads\Data\m_white_10_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_11.rvmat", "A3\characters_f\Heads\Data\m_white_11_injury.rvmat", "A3\characters_f\Heads\Data\m_white_11_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_12.rvmat", "A3\characters_f\Heads\Data\m_white_12_injury.rvmat", "A3\characters_f\Heads\Data\m_white_12_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_13.rvmat", "A3\characters_f\Heads\Data\m_white_13_injury.rvmat", "A3\characters_f\Heads\Data\m_white_13_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_14.rvmat", "A3\characters_f\Heads\Data\m_white_14_injury.rvmat", "A3\characters_f\Heads\Data\m_white_14_injury.rvmat", "A3\Characters_F\Heads\Data\m_white_15.rvmat", "A3\characters_f\Heads\Data\m_white_15_injury.rvmat", "A3\characters_f\Heads\Data\m_white_15_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_hairy_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_bald_muscular_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_old_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white.rvmat", "A3\Characters_F\Heads\Data\hl_white_injury.rvmat", "A3\Characters_F\Heads\Data\hl_white_injury.rvmat"};
		};
	};
	class BP_ZombieHead : Default_A3 {
		model = "\A3\characters_f\Heads\m_white_01";
		class Wounds {
			tex[] = {};
			mat[] = {};
		};
	};
};
