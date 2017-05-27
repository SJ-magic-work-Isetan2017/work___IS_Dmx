/************************************************************
ShortPattern definition
	int (*pFunc)(int)
************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ofMain.h"
#include "shortPattern.h"


/************************************************************
************************************************************/
enum{
	LUM_MAX = 255,
};

/************************************************************
param
************************************************************/
/********************
for test code
********************/
static PFUNC_SHORTPATTERN pFunc[] = {
	FuncSp__Lum_const_Zero,
	FuncSp__Lum_const_Max,
	FuncSp__Lum_Flash,
	FuncSp__Lum_Flash_Bl,
	FuncSp__Lum_On_1_3,
	FuncSp__Lum_On_2_3,
	FuncSp__Lum_On_3_3,
	FuncSp__Lum_On_1_4,
	FuncSp__Lum_On_2_4,
	FuncSp__Lum_On_3_4,
	FuncSp__Lum_On_4_4,
	
	FuncSp__Lum_On_1_5,
	FuncSp__Lum_On_2_5,
	FuncSp__Lum_On_3_5,
	FuncSp__Lum_On_4_5,
	FuncSp__Lum_On_5_5,
	FuncSp__Lum_On_1_6,
	FuncSp__Lum_On_2_6,
	FuncSp__Lum_On_3_6,
	FuncSp__Lum_On_4_6,
	FuncSp__Lum_On_5_6,

	FuncSp__Lum_On_6_6,
	FuncSp__Lum_On_1_7,
	FuncSp__Lum_On_2_7,
	FuncSp__Lum_On_3_7,
	FuncSp__Lum_On_4_7,
	FuncSp__Lum_On_5_7,
	FuncSp__Lum_On_6_7,
	FuncSp__Lum_On_7_7,
	FuncSp__Lum_Off_1_3,
	FuncSp__Lum_Off_2_3,

	FuncSp__Lum_Off_3_3,
	FuncSp__Lum_Off_1_4,
	FuncSp__Lum_Off_2_4,
	FuncSp__Lum_Off_3_4,
	FuncSp__Lum_Off_4_4,
	FuncSp__Lum_Off_1_5,
	FuncSp__Lum_Off_2_5,
	FuncSp__Lum_Off_3_5,
	FuncSp__Lum_Off_4_5,
	FuncSp__Lum_Off_5_5,

	FuncSp__Lum_Off_1_6,
	FuncSp__Lum_Off_2_6,
	FuncSp__Lum_Off_3_6,
	FuncSp__Lum_Off_4_6,
	FuncSp__Lum_Off_5_6,
	FuncSp__Lum_Off_6_6,
	FuncSp__Lum_Off_1_7,
	FuncSp__Lum_Off_2_7,
	FuncSp__Lum_Off_3_7,
	FuncSp__Lum_Off_4_7,

	FuncSp__Lum_Off_5_7,
	FuncSp__Lum_Off_6_7,
	FuncSp__Lum_Off_7_7,
	FuncSp__Lum_Flash_1_2,
	FuncSp__Lum_Flash_2_2,
	FuncSp__Lum_Flash_1_3,
	FuncSp__Lum_Flash_2_3,
	FuncSp__Lum_Flash_3_3,
	FuncSp__Lum_Flash_1_4,
	FuncSp__Lum_Flash_2_4,

	FuncSp__Lum_Flash_3_4,
	FuncSp__Lum_Flash_4_4,
	FuncSp__Lum_Flash_1_5,
	FuncSp__Lum_Flash_2_5,
	FuncSp__Lum_Flash_3_5,
	FuncSp__Lum_Flash_4_5,
	FuncSp__Lum_Flash_5_5,
	FuncSp__Lum_Flash_1_6,
	FuncSp__Lum_Flash_2_6,
	FuncSp__Lum_Flash_3_6,

	FuncSp__Lum_Flash_4_6,
	FuncSp__Lum_Flash_5_6,
	FuncSp__Lum_Flash_6_6,
	FuncSp__Lum_Flash_1_7,
	FuncSp__Lum_Flash_2_7,
	FuncSp__Lum_Flash_3_7,
	FuncSp__Lum_Flash_4_7,
	FuncSp__Lum_Flash_5_7,
	FuncSp__Lum_Flash_6_7,
	FuncSp__Lum_Flash_7_7,

	FuncSp__Lum_Flashx2,
	FuncSp__Lum_Flashx2_2,
	FuncSp__Lum_Flashx3,
	FuncSp__Lum_Flashx3_2,
	FuncSp__Lum_Flashx3_3,
	FuncSp__Lum_Flashx4,
	FuncSp__Lum_Flashx4_2,
	FuncSp__Lum_Flashx4_3,
	FuncSp__Lum_Flashx4_4,
	FuncSp__Lum_Flashx5,

	FuncSp__Lum_Flashx5_2,
	FuncSp__Lum_Flashx5_3,
	FuncSp__Lum_Flashx5_4,
	FuncSp__Lum_Flashx5_5,
	FuncSp__Lum_Flashx6,
	FuncSp__Lum_Flashx6_2,
	FuncSp__Lum_Flashx6_3,
	FuncSp__Lum_Flashx6_4,
	FuncSp__Lum_Flashx6_5,
	FuncSp__Lum_Flashx6_6,

	FuncSp__Lum_Flashx7,
	FuncSp__Lum_Flashx7_2,
	FuncSp__Lum_Flashx7_3,
	FuncSp__Lum_Flashx7_4,
	FuncSp__Lum_Flashx7_5,
	FuncSp__Lum_Flashx7_6,
	FuncSp__Lum_Flashx7_7,
};
static const int Num_ShortPatterns = sizeof(pFunc) / sizeof(pFunc[0]);



/************************************************************
function prototype
************************************************************/
static int Lum_Flash(const int Progress, const int MaxProgress);
static int Lum_On_x_x(const int num, const int den, const int Progress, const int MaxProgress);
static int Lum_Off_x_x(const int num, const int den, const int Progress, const int MaxProgress);
static int Lum_Flash_x_x(const int num, const int den, const int Progress, const int MaxProgress);
static int Lum_FlashxX_x(const int num, const int den, const int Progress, const int MaxProgress);


/************************************************************
function
************************************************************/

/******************************
test code
	void LIGHT::test()
	に記述して、light.test()をvoid AUTOMAGIC_CORE::test()から呼ぶ
******************************/
void FuncSp_test()
{
	for(int i = 0; i < Num_ShortPatterns; i++){
		char buf[1000];
		sprintf(buf, "../../../test_sp_%d.csv", i);
		
		FILE* fp;
		fp = fopen(buf, "w");
		if(fp == NULL){
			printf("File open Error\n");
			std::exit(1);
		}
		
		const int offset = 2000;
		for(int j = -offset; j < MAXPROGRESS_ANIM_KEY + offset; j+= 10){
			int val = pFunc[i](j);
			fprintf_Log_forTestCode(fp, "%d,%d\n", j, val);
		}
		
		fclose(fp);
	}
}

/******************************
******************************/
int FuncSp__Lum_const_Zero(const int Progress)
{
	return 0;
}

/******************************
******************************/
int FuncSp__Lum_const_Max(const int Progress)
{
	return LUM_MAX;
}

/******************************
******************************/
int Lum_Flash(const int Progress, const int MaxProgress)
{
	if(Progress < 0){
		return LUM_MAX;
	}else if(MaxProgress <= Progress){
		return 0;
	}else{
		return int (-(double(LUM_MAX) / MaxProgress) * Progress + LUM_MAX);
	}
}

/******************************
******************************/
int FuncSp__Lum_Flash(const int Progress)
{
	return Lum_Flash(Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_Bl(const int Progress)
{
	return Lum_Flash(Progress, MAXPROGRESS_ANIM_KEY_x_VALID_RATIO);
}

/******************************
******************************/
int Lum_On_x_x(const int num, const int den, const int Progress, const int MaxProgress)
{
	if(Progress < 0){
		return 0;
	}else if(MaxProgress < Progress){
		return LUM_MAX;
	}else{
		if(Progress < MaxProgress * (num - 1) / den){
			return 0;
		}else{
			return LUM_MAX;
		}
	}
}

/******************************
******************************/
int FuncSp__Lum_On_1_3(const int Progress)
{
	return LUM_MAX;
}

/******************************
******************************/
int FuncSp__Lum_On_2_3(const int Progress)
{
	return Lum_On_x_x(2, 3, Progress, MAXPROGRESS_ANIM_KEY);
}
/******************************
******************************/
int FuncSp__Lum_On_3_3(const int Progress)
{
	return Lum_On_x_x(3, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_1_4(const int Progress)
{
	return LUM_MAX;
}

/******************************
******************************/
int FuncSp__Lum_On_2_4(const int Progress)
{
	return Lum_On_x_x(2, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_3_4(const int Progress)
{
	return Lum_On_x_x(3, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_4_4(const int Progress)
{
	return Lum_On_x_x(4, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_1_5(const int Progress)
{
	return LUM_MAX;
}

/******************************
******************************/
int FuncSp__Lum_On_2_5(const int Progress)
{
	return Lum_On_x_x(2, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_3_5(const int Progress)
{
	return Lum_On_x_x(3, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_4_5(const int Progress)
{
	return Lum_On_x_x(4, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_5_5(const int Progress)
{
	return Lum_On_x_x(5, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_1_6(const int Progress)
{
	return LUM_MAX;
}

/******************************
******************************/
int FuncSp__Lum_On_2_6(const int Progress)
{
	return Lum_On_x_x(2, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_3_6(const int Progress)
{
	return Lum_On_x_x(3, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_4_6(const int Progress)
{
	return Lum_On_x_x(4, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_5_6(const int Progress)
{
	return Lum_On_x_x(5, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_6_6(const int Progress)
{
	return Lum_On_x_x(6, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_1_7(const int Progress)
{
	return LUM_MAX;
}

/******************************
******************************/
int FuncSp__Lum_On_2_7(const int Progress)
{
	return Lum_On_x_x(2, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_3_7(const int Progress)
{
	return Lum_On_x_x(3, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_4_7(const int Progress)
{
	return Lum_On_x_x(4, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_5_7(const int Progress)
{
	return Lum_On_x_x(5, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_6_7(const int Progress)
{
	return Lum_On_x_x(6, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_On_7_7(const int Progress)
{
	return Lum_On_x_x(7, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int Lum_Off_x_x(const int num, const int den, const int Progress, const int MaxProgress)
{
	if(Progress < 0){
		return LUM_MAX;
	}else if(MaxProgress <= Progress){
		return 0;
	}else{
		if(Progress <= MaxProgress * (num - 1) / den){
			return LUM_MAX;
		}else{
			return 0;
		}
	}
}

/******************************
******************************/
int FuncSp__Lum_Off_1_3(const int Progress)
{
	return 0;
}

/******************************
******************************/
int FuncSp__Lum_Off_2_3(const int Progress)
{
	return Lum_Off_x_x(2, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_3_3(const int Progress)
{
	return Lum_Off_x_x(3, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_1_4(const int Progress)
{
	return 0;
}

/******************************
******************************/
int FuncSp__Lum_Off_2_4(const int Progress)
{
	return Lum_Off_x_x(2, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_3_4(const int Progress)
{
	return Lum_Off_x_x(3, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_4_4(const int Progress)
{
	return Lum_Off_x_x(4, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_1_5(const int Progress)
{
	return 0;
}

/******************************
******************************/
int FuncSp__Lum_Off_2_5(const int Progress)
{
	return Lum_Off_x_x(2, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_3_5(const int Progress)
{
	return Lum_Off_x_x(3, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_4_5(const int Progress)
{
	return Lum_Off_x_x(4, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_5_5(const int Progress)
{
	return Lum_Off_x_x(5, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_1_6(const int Progress)
{
	return 0;
}

/******************************
******************************/
int FuncSp__Lum_Off_2_6(const int Progress)
{
	return Lum_Off_x_x(2, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_3_6(const int Progress)
{
	return Lum_Off_x_x(3, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_4_6(const int Progress)
{
	return Lum_Off_x_x(4, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_5_6(const int Progress)
{
	return Lum_Off_x_x(5, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_6_6(const int Progress)
{
	return Lum_Off_x_x(6, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_1_7(const int Progress)
{
	return 0;
}

/******************************
******************************/
int FuncSp__Lum_Off_2_7(const int Progress)
{
	return Lum_Off_x_x(2, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_3_7(const int Progress)
{
	return Lum_Off_x_x(3, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_4_7(const int Progress)
{
	return Lum_Off_x_x(4, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_5_7(const int Progress)
{
	return Lum_Off_x_x(5, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_6_7(const int Progress)
{
	return Lum_Off_x_x(6, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Off_7_7(const int Progress)
{
	return Lum_Off_x_x(7, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int Lum_Flash_x_x(const int num, const int den, const int Progress, const int MaxProgress)
{
	if(Progress < 0){
		return 0;
	}else if(MaxProgress <= Progress){
		return 0;
	}else{
		const int ProgressFrom	= MaxProgress * (num - 1) / den;
		const int ProgressTo		= MaxProgress * num / den;
		
		if( (Progress < ProgressFrom) || (ProgressTo < Progress) ){
			return 0;
		}else{
			double a = - double(LUM_MAX) * den / MaxProgress;
			
			int val = int(a * (Progress - ProgressFrom) + LUM_MAX);
			if(val < 0)			val = 0;
			if(LUM_MAX < val)	val = LUM_MAX;
			
			return val;
		}
	}
}

/******************************
******************************/
int FuncSp__Lum_Flash_1_2(const int Progress)
{
	return Lum_Flash_x_x(1, 2, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_2_2(const int Progress)
{
	return Lum_Flash_x_x(2, 2, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_1_3(const int Progress)
{
	return Lum_Flash_x_x(1, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_2_3(const int Progress)
{
	return Lum_Flash_x_x(2, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_3_3(const int Progress)
{
	return Lum_Flash_x_x(3, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_1_4(const int Progress)
{
	return Lum_Flash_x_x(1, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_2_4(const int Progress)
{
	return Lum_Flash_x_x(2, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_3_4(const int Progress)
{
	return Lum_Flash_x_x(3, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_4_4(const int Progress)
{
	return Lum_Flash_x_x(4, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_1_5(const int Progress)
{
	return Lum_Flash_x_x(1, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_2_5(const int Progress)
{
	return Lum_Flash_x_x(2, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_3_5(const int Progress)
{
	return Lum_Flash_x_x(3, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_4_5(const int Progress)
{
	return Lum_Flash_x_x(4, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_5_5(const int Progress)
{
	return Lum_Flash_x_x(5, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_1_6(const int Progress)
{
	return Lum_Flash_x_x(1, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_2_6(const int Progress)
{
	return Lum_Flash_x_x(2, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_3_6(const int Progress)
{
	return Lum_Flash_x_x(3, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_4_6(const int Progress)
{
	return Lum_Flash_x_x(4, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_5_6(const int Progress)
{
	return Lum_Flash_x_x(5, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_6_6(const int Progress)
{
	return Lum_Flash_x_x(6, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_1_7(const int Progress)
{
	return Lum_Flash_x_x(1, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_2_7(const int Progress)
{
	return Lum_Flash_x_x(2, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_3_7(const int Progress)
{
	return Lum_Flash_x_x(3, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_4_7(const int Progress)
{
	return Lum_Flash_x_x(4, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_5_7(const int Progress)
{
	return Lum_Flash_x_x(5, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_6_7(const int Progress)
{
	return Lum_Flash_x_x(6, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flash_7_7(const int Progress)
{
	return Lum_Flash_x_x(7, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int Lum_FlashxX_x(const int num, const int den, const int Progress, const int MaxProgress)
{
	if(Progress < 0){
		return 0;
	}else if(MaxProgress <= Progress){
		return 0;
	}else{
		
		double Width = double(MaxProgress) / den;
		double a = -LUM_MAX / Width;
		
		int ZoneId = int(Progress / Width); // which "Zone id" the "Progress" of this time belongs.
		
		if( (num - 1) <= ZoneId ){
			int val = int(a * (Progress - Width * ZoneId) + LUM_MAX);
			if(val < 0)			val = 0;
			if(LUM_MAX < val)	val = LUM_MAX;
			
			return val;
			
		}else{
			return 0;
		}
	}
}

/******************************
******************************/
int FuncSp__Lum_Flashx2(const int Progress)
{
	return Lum_FlashxX_x(1, 2, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx2_2(const int Progress)
{
	return Lum_FlashxX_x(2, 2, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx3(const int Progress)
{
	return Lum_FlashxX_x(1, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx3_2(const int Progress)
{
	return Lum_FlashxX_x(2, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx3_3(const int Progress)
{
	return Lum_FlashxX_x(3, 3, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx4(const int Progress)
{
	return Lum_FlashxX_x(1, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx4_2(const int Progress)
{
	return Lum_FlashxX_x(2, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx4_3(const int Progress)
{
	return Lum_FlashxX_x(3, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx4_4(const int Progress)
{
	return Lum_FlashxX_x(4, 4, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx5(const int Progress)
{
	return Lum_FlashxX_x(1, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx5_2(const int Progress)
{
	return Lum_FlashxX_x(2, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx5_3(const int Progress)
{
	return Lum_FlashxX_x(3, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx5_4(const int Progress)
{
	return Lum_FlashxX_x(4, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx5_5(const int Progress)
{
	return Lum_FlashxX_x(5, 5, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx6(const int Progress)
{
	return Lum_FlashxX_x(1, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx6_2(const int Progress)
{
	return Lum_FlashxX_x(2, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx6_3(const int Progress)
{
	return Lum_FlashxX_x(3, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx6_4(const int Progress)
{
	return Lum_FlashxX_x(4, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx6_5(const int Progress)
{
	return Lum_FlashxX_x(5, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx6_6(const int Progress)
{
	return Lum_FlashxX_x(6, 6, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx7(const int Progress)
{
	return Lum_FlashxX_x(1, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx7_2(const int Progress)
{
	return Lum_FlashxX_x(2, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx7_3(const int Progress)
{
	return Lum_FlashxX_x(3, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx7_4(const int Progress)
{
	return Lum_FlashxX_x(4, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx7_5(const int Progress)
{
	return Lum_FlashxX_x(5, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx7_6(const int Progress)
{
	return Lum_FlashxX_x(6, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

/******************************
******************************/
int FuncSp__Lum_Flashx7_7(const int Progress)
{
	return Lum_FlashxX_x(7, 7, Progress, MAXPROGRESS_ANIM_KEY);
}

