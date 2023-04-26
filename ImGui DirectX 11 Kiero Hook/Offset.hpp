
namespace Offset {
	//Server
	uintptr_t sv_cheats = 0x29F0FE0;
	//Camera
	uintptr_t cg_fov = 0x2A119E0;
	uintptr_t cg_fovmin = 0x2A11A40;
	uintptr_t cg_thirdperson = 0x2A16180;
	//Visual
	uintptr_t cg_usecolorcontrol = 0x2A14DA0;
	//Overlay
	uintptr_t Is_InGame = 0xD5CD40; //DDB1C0 DDBAA0
	//position
	uintptr_t POS_X = 0x23427C8;
	uintptr_t POS_Y = 0x23427C8 + 0x4;
	uintptr_t POS_Z = 0x23427C8 + 0x8;
	
}

namespace Function {


	void Teleport(float X, float Y, float Z)
	{
		*(float*)Offset::POS_X = X;
		*(float*)Offset::POS_Y = Y;
		*(float*)Offset::POS_Z = Z;
	}

	void CG_FOVMIN(float value)
	{
		*(float*)Offset::cg_fovmin = value;
	}
	void CG_FOV(float value)
	{
		*(float*)Offset::cg_fov = value;
	}

	void CG_THIRDPERSON(int value)
	{
		*(int*)Offset::cg_thirdperson = value;
	}


	void SV_CHEATS(bool value)
	{
		*(int*)Offset::sv_cheats = value;
	}

	void CG_USECOLCONTROL(int value)
	{
		*(int*)Offset::cg_usecolorcontrol = value;
	}

	void unlock_mouse(int zeroUnlock)
	{
		*(int*)0x02B69958 = zeroUnlock;
	}

	void SmokeSettings(float a1, float a2, float a3, float a4)
	{
		*(float*)0xBF5D70 = a1;
		*(float*)(0xBF5D70 + 0x4) = a2;
		*(float*)(0xBF5D70 + 0x8) = a3;
		*(float*)(0xBF5D70 + 0xC) = a4;
	}

	void ColHUDSettings(float a1, float a2, float a3, float a4)
	{
		*(float*)0xD1FCA0 = a1;
		*(float*)(0xD1FCA0 + 0x4) = a2;
		*(float*)(0xD1FCA0 + 0x8) = a3;
		*(float*)(0xD1FCA0 + 0xC) = a4;
	}

	void vc_fbm(float a1, float a2, float a3, float a4)
	{
		*(float*)0x2A0D2A0 = a1;
		*(float*)(0x2A0D2A0 + 0x4) = a2;
		*(float*)(0x2A0D2A0 + 0x8) = a3;
		*(float*)(0x2A0D2A0 + 0xC) = a4;
	}
	void vc_fsm(float a1, float a2, float a3, float a4)
	{
		*(float*)0x2A0D240 = a1;
		*(float*)(0x2A0D240 + 0x4) = a2;
		*(float*)(0x2A0D240 + 0x8) = a3;
		*(float*)(0x2A0D240 + 0xC) = a4;
	}
	void vc_rgbh(float a1, float a2, float a3, float a4)
	{
		*(float*)0x2A0CAC0 = a1;
		*(float*)(0x2A0CAC0 + 0x4) = a2;
		*(float*)(0x2A0CAC0 + 0x8) = a3;
		*(float*)(0x2A0CAC0 + 0xC) = a4;
	}
	void vc_yl(float a1, float a2, float a3, float a4)
	{
		*(float*)0x2A0CBE0 = a1;
		*(float*)(0x2A0CBE0 + 0x4) = a2;
		*(float*)(0x2A0CBE0 + 0x8) = a3;
		*(float*)(0x2A0CBE0 + 0xC) = a4;
	}
	void vc_yh(float a1, float a2, float a3, float a4)
	{
		*(float*)0x2A0CB80 = a1;
		*(float*)(0x2A0CB80 + 0x4) = a2;
		*(float*)(0x2A0CB80 + 0x8) = a3;
		*(float*)(0x2A0CB80 + 0xC) = a4;
	}
	void vc_rgbl(float a1, float a2, float a3, float a4)
	{
		*(float*)0x2A0CB20 = a1;
		*(float*)(0x2A0CB20 + 0x4) = a2;
		*(float*)(0x2A0CB20 + 0x8) = a3;
		*(float*)(0x2A0CB20 + 0xC) = a4;
	}

	void SunLight(float light)
	{
		*(float*)0x2A09E80 = light;
	}
	void DarkMap(int mode)
	{
		if (mode == 1) //Simple
		{
		
	
			*(float*)0x2A09220 = -1000; //r_lodBiasRigid
			*(float*)0x2A092E0 = -1000; //r_lodBiasSkinned
			*(float*)0x2A0F7C0 = 1; //r_skyTransition
			*(float*)0x2A0EE00 = 3.9; //r_exposureValue
			*(float*)0x2A09E80 = 1; //r_lightTweakSunLight
			*(float*)0x2A10960 = 0; //r_sky_intensity_factor0

			*(int*)0x2A0D840 = 0; //r_dof_enable
			*(int*)0x2A0B560 = 2; //sm_sunquality
			*(int*)0x2A0C7C0 = 0; //r_filmUseTweaks (je sais pas pourquoi, quand je met 1 il fait un black screen)
			*(int*)0x2A0CC40 = 1; //r_bloomTweaks
			*(int*)0x2A0EDA0 = 1; //r_exposureTweak
			

			vc_fbm(0, 0, 0, 0);
			vc_fsm(0, 0, 0, 0);
			vc_rgbh(0.1, 0, 0.3, 0);
			vc_yl(0, 0, 0.25, 0);
			vc_yh(0.02, 0, 0.1, 0);
			vc_rgbl(0.02, 0, 0.1, 0);


		}
		if (mode == 2) //Yellow
		{

			*(float*)0x2A09220 = -1000; //r_lodBiasRigid
			*(float*)0x2A092E0 = -1000; //r_lodBiasSkinned
			*(float*)0x2A0F7C0 = 1; //r_skyTransition
			*(float*)0x2A0EE00 = 3.9; //r_exposureValue
			*(float*)0x2A09E80 = 1; //r_lightTweakSunLight
			*(float*)0x2A10960 = 0; //r_sky_intensity_factor0

			*(int*)0x2A0D840 = 0; //r_dof_enable
			*(int*)0x2A0B560 = 2; //sm_sunquality
			*(int*)0x2A0C7C0 = 0; //r_filmUseTweaks (je sais pas pourquoi, quand je met 1 il fait un black screen)
			*(int*)0x2A0CC40 = 1; //r_bloomTweaks
			*(int*)0x2A0EDA0 = 1; //r_exposureTweak


			vc_fbm(0, 0, 0, 0);
			vc_fsm(0, 0, 0, 0);
			vc_rgbh(0.3, 0.3, 0, 0);
			vc_yl(0, 0, 0, 0);
			vc_yh(0, 0, 0, 0);
			vc_rgbl(0.3, 0.3, 0, 0);


		}
		if (mode == 3) //Red
		{

			*(float*)0x2A09220 = -1000; //r_lodBiasRigid
			*(float*)0x2A092E0 = -1000; //r_lodBiasSkinned
			*(float*)0x2A0F7C0 = 1; //r_skyTransition
			*(float*)0x2A0EE00 = 3.9; //r_exposureValue
			*(float*)0x2A09E80 = 1; //r_lightTweakSunLight
			*(float*)0x2A10960 = 0; //r_sky_intensity_factor0

			*(int*)0x2A0D840 = 0; //r_dof_enable
			*(int*)0x2A0B560 = 2; //sm_sunquality
			*(int*)0x2A0C7C0 = 0; //r_filmUseTweaks (je sais pas pourquoi, quand je met 1 il fait un black screen)
			*(int*)0x2A0CC40 = 1; //r_bloomTweaks
			*(int*)0x2A0EDA0 = 1; //r_exposureTweak


			vc_fbm(0, 0, 0, 0);
			vc_fsm(0, 0, 0, 0);
			vc_rgbh(0.3, 0, 0, 0);
			vc_yl(0, 0, 0, 0);
			vc_yh(0, 0, 0, 0);
			vc_rgbl(0.3, 0, 0, 0);


		}
		if (mode == 4) //Green
		{

			*(float*)0x2A09220 = -1000; //r_lodBiasRigid
			*(float*)0x2A092E0 = -1000; //r_lodBiasSkinned
			*(float*)0x2A0F7C0 = 1; //r_skyTransition
			*(float*)0x2A0EE00 = 3.9; //r_exposureValue
			*(float*)0x2A09E80 = 1; //r_lightTweakSunLight
			*(float*)0x2A10960 = 0; //r_sky_intensity_factor0

			*(int*)0x2A0D840 = 0; //r_dof_enable
			*(int*)0x2A0B560 = 2; //sm_sunquality
			*(int*)0x2A0C7C0 = 0; //r_filmUseTweaks (je sais pas pourquoi, quand je met 1 il fait un black screen)
			*(int*)0x2A0CC40 = 1; //r_bloomTweaks
			*(int*)0x2A0EDA0 = 1; //r_exposureTweak


			vc_fbm(0, 0, 0, 0);
			vc_fsm(0, 0, 0, 0);
			vc_rgbh(0, 0.3, 0, 0);
			vc_yl(0, 0, 0, 0);
			vc_yh(0, 0, 0, 0);
			vc_rgbl(0, 0.3, 0, 0);


		}
		if (mode == 5) //Cyan
		{

			*(float*)0x2A09220 = -1000; //r_lodBiasRigid
			*(float*)0x2A092E0 = -1000; //r_lodBiasSkinned
			*(float*)0x2A0F7C0 = 1; //r_skyTransition
			*(float*)0x2A0EE00 = 3.9; //r_exposureValue
			*(float*)0x2A09E80 = 1; //r_lightTweakSunLight
			*(float*)0x2A10960 = 0; //r_sky_intensity_factor0

			*(int*)0x2A0D840 = 0; //r_dof_enable
			*(int*)0x2A0B560 = 2; //sm_sunquality
			*(int*)0x2A0C7C0 = 0; //r_filmUseTweaks (je sais pas pourquoi, quand je met 1 il fait un black screen)
			*(int*)0x2A0CC40 = 1; //r_bloomTweaks
			*(int*)0x2A0EDA0 = 1; //r_exposureTweak


			vc_fbm(0, 0, 0, 0);
			vc_fsm(0, 0, 0, 0);
			vc_rgbh(0, 0.3, 0.3, 0);
			vc_yl(0, 0, 0, 0);
			vc_yh(0, 0, 0, 0);
			vc_rgbl(0, 0.3, 0.3, 0);


		}
	}

	void chams(float a1, float a2, float a3)
	{
		*(float*)0x2A0F1C0 = a1;
		*(float*)(0x2A0F1C0 + 0x4) = a2;
		*(float*)(0x2A0F1C0 + 0x8) = a3;
	}

	void WaterSheetingScreenFX(bool value)
	{
		*(int*)0x2A0DEA0 = value;
	}

	void PoisonScreenFX(bool value)
	{
		*(int*)0x2A0E620 = value;
	}

	void SkyRotation(float rotation)
	{
		*(float*)0x2A0F820 = rotation;
	}
}


