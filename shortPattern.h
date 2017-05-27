#pragma once

/************************************************************
************************************************************/
#include "L_common.h"

/************************************************************
************************************************************/
enum{
	MAXPROGRESS_ANIM_KEY				= 10000,
	MAXPROGRESS_ANIM_KEY_x_VALID_RATIO	= 9000,
};

/************************************************************
function prototype to user of this object
************************************************************/
void FuncSp_test();

//
int FuncSp__Lum_const_Zero(const int Progress);
int FuncSp__Lum_const_Max(const int Progress);

// 
int FuncSp__Lum_Flash(const int Progress);
int FuncSp__Lum_Flash_Bl(const int Progress);

// 
int FuncSp__Lum_On_1_3(const int Progress);
int FuncSp__Lum_On_2_3(const int Progress);
int FuncSp__Lum_On_3_3(const int Progress);

int FuncSp__Lum_On_1_4(const int Progress);
int FuncSp__Lum_On_2_4(const int Progress);
int FuncSp__Lum_On_3_4(const int Progress);
int FuncSp__Lum_On_4_4(const int Progress);

int FuncSp__Lum_On_1_5(const int Progress);
int FuncSp__Lum_On_2_5(const int Progress);
int FuncSp__Lum_On_3_5(const int Progress);
int FuncSp__Lum_On_4_5(const int Progress);
int FuncSp__Lum_On_5_5(const int Progress);

int FuncSp__Lum_On_1_6(const int Progress);
int FuncSp__Lum_On_2_6(const int Progress);
int FuncSp__Lum_On_3_6(const int Progress);
int FuncSp__Lum_On_4_6(const int Progress);
int FuncSp__Lum_On_5_6(const int Progress);
int FuncSp__Lum_On_6_6(const int Progress);

int FuncSp__Lum_On_1_7(const int Progress);
int FuncSp__Lum_On_2_7(const int Progress);
int FuncSp__Lum_On_3_7(const int Progress);
int FuncSp__Lum_On_4_7(const int Progress);
int FuncSp__Lum_On_5_7(const int Progress);
int FuncSp__Lum_On_6_7(const int Progress);
int FuncSp__Lum_On_7_7(const int Progress);

int FuncSp__Lum_Off_1_3(const int Progress);
int FuncSp__Lum_Off_2_3(const int Progress);
int FuncSp__Lum_Off_3_3(const int Progress);

int FuncSp__Lum_Off_1_4(const int Progress);
int FuncSp__Lum_Off_2_4(const int Progress);
int FuncSp__Lum_Off_3_4(const int Progress);
int FuncSp__Lum_Off_4_4(const int Progress);

int FuncSp__Lum_Off_1_5(const int Progress);
int FuncSp__Lum_Off_2_5(const int Progress);
int FuncSp__Lum_Off_3_5(const int Progress);
int FuncSp__Lum_Off_4_5(const int Progress);
int FuncSp__Lum_Off_5_5(const int Progress);

int FuncSp__Lum_Off_1_6(const int Progress);
int FuncSp__Lum_Off_2_6(const int Progress);
int FuncSp__Lum_Off_3_6(const int Progress);
int FuncSp__Lum_Off_4_6(const int Progress);
int FuncSp__Lum_Off_5_6(const int Progress);
int FuncSp__Lum_Off_6_6(const int Progress);

int FuncSp__Lum_Off_1_7(const int Progress);
int FuncSp__Lum_Off_2_7(const int Progress);
int FuncSp__Lum_Off_3_7(const int Progress);
int FuncSp__Lum_Off_4_7(const int Progress);
int FuncSp__Lum_Off_5_7(const int Progress);
int FuncSp__Lum_Off_6_7(const int Progress);
int FuncSp__Lum_Off_7_7(const int Progress);

//
int FuncSp__Lum_Flash_1_2(const int Progress);
int FuncSp__Lum_Flash_2_2(const int Progress);

int FuncSp__Lum_Flash_1_3(const int Progress);
int FuncSp__Lum_Flash_2_3(const int Progress);
int FuncSp__Lum_Flash_3_3(const int Progress);

int FuncSp__Lum_Flash_1_4(const int Progress);
int FuncSp__Lum_Flash_2_4(const int Progress);
int FuncSp__Lum_Flash_3_4(const int Progress);
int FuncSp__Lum_Flash_4_4(const int Progress);

int FuncSp__Lum_Flash_1_5(const int Progress);
int FuncSp__Lum_Flash_2_5(const int Progress);
int FuncSp__Lum_Flash_3_5(const int Progress);
int FuncSp__Lum_Flash_4_5(const int Progress);
int FuncSp__Lum_Flash_5_5(const int Progress);

int FuncSp__Lum_Flash_1_6(const int Progress);
int FuncSp__Lum_Flash_2_6(const int Progress);
int FuncSp__Lum_Flash_3_6(const int Progress);
int FuncSp__Lum_Flash_4_6(const int Progress);
int FuncSp__Lum_Flash_5_6(const int Progress);
int FuncSp__Lum_Flash_6_6(const int Progress);

int FuncSp__Lum_Flash_1_7(const int Progress);
int FuncSp__Lum_Flash_2_7(const int Progress);
int FuncSp__Lum_Flash_3_7(const int Progress);
int FuncSp__Lum_Flash_4_7(const int Progress);
int FuncSp__Lum_Flash_5_7(const int Progress);
int FuncSp__Lum_Flash_6_7(const int Progress);
int FuncSp__Lum_Flash_7_7(const int Progress);

//
int FuncSp__Lum_Flashx2(const int Progress);
int FuncSp__Lum_Flashx2_2(const int Progress);

int FuncSp__Lum_Flashx3(const int Progress);
int FuncSp__Lum_Flashx3_2(const int Progress);
int FuncSp__Lum_Flashx3_3(const int Progress);

int FuncSp__Lum_Flashx4(const int Progress);
int FuncSp__Lum_Flashx4_2(const int Progress);
int FuncSp__Lum_Flashx4_3(const int Progress);
int FuncSp__Lum_Flashx4_4(const int Progress);

int FuncSp__Lum_Flashx5(const int Progress);
int FuncSp__Lum_Flashx5_2(const int Progress);
int FuncSp__Lum_Flashx5_3(const int Progress);
int FuncSp__Lum_Flashx5_4(const int Progress);
int FuncSp__Lum_Flashx5_5(const int Progress);

int FuncSp__Lum_Flashx6(const int Progress);
int FuncSp__Lum_Flashx6_2(const int Progress);
int FuncSp__Lum_Flashx6_3(const int Progress);
int FuncSp__Lum_Flashx6_4(const int Progress);
int FuncSp__Lum_Flashx6_5(const int Progress);
int FuncSp__Lum_Flashx6_6(const int Progress);

int FuncSp__Lum_Flashx7(const int Progress);
int FuncSp__Lum_Flashx7_2(const int Progress);
int FuncSp__Lum_Flashx7_3(const int Progress);
int FuncSp__Lum_Flashx7_4(const int Progress);
int FuncSp__Lum_Flashx7_5(const int Progress);
int FuncSp__Lum_Flashx7_6(const int Progress);
int FuncSp__Lum_Flashx7_7(const int Progress);

