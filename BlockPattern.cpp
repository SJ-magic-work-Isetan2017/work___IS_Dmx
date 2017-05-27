/************************************************************
// test code
// check if "StartPatternId_Candidate" is correct in all the Bp_x class object.

int cal_Num_StartPatternId_Candidate(BLOCK_PATTERN BlockPattern)
{
	int i;
	for(i = 0; BlockPattern.pShortPattern[i][0] != NULL; i++){
	}
	
	return i - 1;
}

void LIGHT::test()
{
	for(int i = 0; Bp_7[i].pShortPattern[0][0] != NULL; i++){
		int StartPatternId_Candidate_caled = cal_Num_StartPatternId_Candidate(Bp_7[i]);
		if(StartPatternId_Candidate_caled < Bp_7[i].StartPatternId_Candidate){
			printf("Error in:Bp_7[%d]\n", i);
		}
	}
	
	for(int i = 0; Bp_6[i].pShortPattern[0][0] != NULL; i++){
		int StartPatternId_Candidate_caled = cal_Num_StartPatternId_Candidate(Bp_6[i]);
		if(StartPatternId_Candidate_caled < Bp_6[i].StartPatternId_Candidate){
			printf("Error in:Bp_6[%d]\n", i);
		}
	}

	for(int i = 0; Bp_5[i].pShortPattern[0][0] != NULL; i++){
		int StartPatternId_Candidate_caled = cal_Num_StartPatternId_Candidate(Bp_5[i]);
		if(StartPatternId_Candidate_caled < Bp_5[i].StartPatternId_Candidate){
			printf("Error in:Bp_5[%d]\n", i);
		}
	}

	for(int i = 0; Bp_4[i].pShortPattern[0][0] != NULL; i++){
		int StartPatternId_Candidate_caled = cal_Num_StartPatternId_Candidate(Bp_4[i]);
		if(StartPatternId_Candidate_caled < Bp_4[i].StartPatternId_Candidate){
			printf("Error in:Bp_4[%d]\n", i);
		}
	}

	for(int i = 0; Bp_3[i].pShortPattern[0][0] != NULL; i++){
		int StartPatternId_Candidate_caled = cal_Num_StartPatternId_Candidate(Bp_3[i]);
		if(StartPatternId_Candidate_caled < Bp_3[i].StartPatternId_Candidate){
			printf("Error in:Bp_3[%d]\n", i);
		}
	}

	for(int i = 0; Bp_2[i].pShortPattern[0][0] != NULL; i++){
		int StartPatternId_Candidate_caled = cal_Num_StartPatternId_Candidate(Bp_2[i]);
		if(StartPatternId_Candidate_caled < Bp_2[i].StartPatternId_Candidate){
			printf("Error in:Bp_2[%d]\n", i);
		}
	}

	for(int i = 0; Bp_1[i].pShortPattern[0][0] != NULL; i++){
		int StartPatternId_Candidate_caled = cal_Num_StartPatternId_Candidate(Bp_1[i]);
		if(StartPatternId_Candidate_caled < Bp_1[i].StartPatternId_Candidate){
			printf("Error in:Bp_1[%d]\n", i);
		}
	}
	
	printf("Finish:checking\n");
}
************************************************************/
	

/************************************************************
// test code

// printout All Block pattern name
// Pattern定義が完了した後、重みをつけるために、作成済みpatternを列挙するのに使用
void LIGHT::test()
{
	FILE* fp;
	
	fp = fopen("../../../Bp_7.txt", "w");
	for(int i = 0; strcmp(Bp_7[i].name, "BP_END") != 0; i++ ){
		fprintf_Log_forTestCode(fp, "%s\n", Bp_7[i].name);
	}
	fclose(fp);
	
	fp = fopen("../../../Bp_6.txt", "w");
	for(int i = 0; strcmp(Bp_6[i].name, "BP_END") != 0; i++ ){
		fprintf_Log_forTestCode(fp, "%s\n", Bp_6[i].name);
	}
	fclose(fp);

	fp = fopen("../../../Bp_5.txt", "w");
	for(int i = 0; strcmp(Bp_5[i].name, "BP_END") != 0; i++ ){
		fprintf_Log_forTestCode(fp, "%s\n", Bp_5[i].name);
	}
	fclose(fp);
	
	fp = fopen("../../../Bp_4.txt", "w");
	for(int i = 0; strcmp(Bp_4[i].name, "BP_END") != 0; i++ ){
		fprintf_Log_forTestCode(fp, "%s\n", Bp_4[i].name);
	}
	fclose(fp);
	
	fp = fopen("../../../Bp_3.txt", "w");
	for(int i = 0; strcmp(Bp_3[i].name, "BP_END") != 0; i++ ){
		fprintf_Log_forTestCode(fp, "%s\n", Bp_3[i].name);
	}
	fclose(fp);

	fp = fopen("../../../Bp_2.txt", "w");
	for(int i = 0; strcmp(Bp_2[i].name, "BP_END") != 0; i++ ){
		fprintf_Log_forTestCode(fp, "%s\n", Bp_2[i].name);
	}
	fclose(fp);

	fp = fopen("../../../Bp_1.txt", "w");
	for(int i = 0; strcmp(Bp_1[i].name, "BP_END") != 0; i++ ){
		fprintf_Log_forTestCode(fp, "%s\n", Bp_1[i].name);
	}
	fclose(fp);
}
************************************************************/

/************************************************************
// test code
// print out : DeviceType/State ごと : BlockPattern候補と選択される確率
// 各Patternが、狙った所に候補として挙がっていることを確認

int get_num_PatternTypes_in_Bp(const BLOCK_PATTERN *Bp_Pattern)
{
	int num;
	for( num = 0; strcmp(Bp_Pattern[num].name, "BP_END") != 0; num++ ){
	}
	
	return num;
}

void LIGHT::test()
{
	enum{
		BUF_SIZE = 2000,
	};
	
	for(int id = 0; id < 8; id++){
		const BLOCK_PATTERN *Bp_Pattern = NULL;
		char LogFileName[BUF_SIZE];
		
		if( id == 0 ){
			continue;
			
		}else{
			switch(id){
				case 1:	Bp_Pattern = &Bp_1[0];	break;
				case 2:	Bp_Pattern = &Bp_2[0];	break;
				case 3:	Bp_Pattern = &Bp_3[0];	break;
				case 4:	Bp_Pattern = &Bp_4[0];	break;
				case 5:	Bp_Pattern = &Bp_5[0];	break;
				case 6:	Bp_Pattern = &Bp_6[0];	break;
				case 7:	Bp_Pattern = &Bp_7[0];	break;
			}
			
			sprintf(LogFileName, "../../../Bp_%d.txt", id);
		}
		
		int NumPatterns = get_num_PatternTypes_in_Bp(Bp_Pattern);
		
		
		FILE* fp;
		fp = fopen(LogFileName, "w");
		
		for(int DeviceChType = DEVICE_CH_TYPE__FIX_STAGE_LIGHT; DeviceChType < int(NUM_DEVICE_CH_TYPE); DeviceChType++){
			fprintf_Log_forTestCode(fp, "--------------------------------------------------\n");
			for(int State = STATE_FFT; State < int(NUM_STATES); State++){
				int TotalWeight = 0;
				for(int i = 0; i < NumPatterns; i++){
					TotalWeight += Bp_Pattern[i].Weight[DeviceChType][State];
				}
				
				// 
				switch(DeviceChType){
					case DEVICE_CH_TYPE__FIX_STAGE_LIGHT:		fprintf_Log_forTestCode(fp, "StageLight  ");		break;
				}
				
				switch(State){
					case STATE_FFT:		fprintf_Log_forTestCode(fp, "STATE_FFT ");		break;
					case STATE_NORMAL:	fprintf_Log_forTestCode(fp, "STATE_NORMAL ");	break;
					case STATE_SPEED:	fprintf_Log_forTestCode(fp, "STATE_SPEED ");	break;
					case STATE_STROBE:	fprintf_Log_forTestCode(fp, "STATE_STROBE ");	break;
					case STATE_BEAT:	fprintf_Log_forTestCode(fp, "STATE_BEAT ");		break;
				}
				
				// 
				fprintf_Log_forTestCode(fp, "\n");
				if(TotalWeight == 0){
					fprintf_Log_forTestCode(fp, "\tXXXXX no chance to select pattern XXXXX\n");
				}else{
					for(int i = 0; i < NumPatterns; i++){
						if(Bp_Pattern[i].Weight[DeviceChType][State]){
							fprintf_Log_forTestCode(fp, "\t%-50s\t%.1f[%%]\n", Bp_Pattern[i].name, double(Bp_Pattern[i].Weight[DeviceChType][State]) * 100 / TotalWeight);
						}
					}
				}
				fprintf_Log_forTestCode(fp, "\n");
			}
		}
		
		fclose(fp);
	}
}
************************************************************/




/************************************************************
************************************************************/
#include <stdio.h>

#include "L_common.h"

#include "ShortPattern.h"
#include "BlockPattern.h"

/************************************************************
************************************************************/
const struct BLOCK_PATTERN Bp_7[] = {																																																																				
	// LUM__Still -------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_7_LUM__STILL__OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	1	,	1	,	1	,	1	,	1	,	1	,	1	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STILL__ON",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__StillFlow -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_7_LUM__STILLFLOW__FLOW",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_7	,	FuncSp__Lum_On_2_7	,	FuncSp__Lum_On_3_7	,	FuncSp__Lum_On_4_7	,	FuncSp__Lum_On_5_7	,	FuncSp__Lum_On_6_7	,	FuncSp__Lum_On_7_7	},																																																			
			{	FuncSp__Lum_Off_1_7	,	FuncSp__Lum_Off_2_7	,	FuncSp__Lum_Off_3_7	,	FuncSp__Lum_Off_4_7	,	FuncSp__Lum_Off_5_7	,	FuncSp__Lum_Off_6_7	,	FuncSp__Lum_Off_7_7	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STILLFLOW__FLOW_x3",																																																																		
		3	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_7	,	FuncSp__Lum_On_2_7	,	FuncSp__Lum_On_3_7	,	FuncSp__Lum_On_4_7	,	FuncSp__Lum_On_5_7	,	FuncSp__Lum_On_6_7	,	FuncSp__Lum_On_7_7	},																																																			
			{	FuncSp__Lum_Off_1_7	,	FuncSp__Lum_Off_2_7	,	FuncSp__Lum_Off_3_7	,	FuncSp__Lum_Off_4_7	,	FuncSp__Lum_Off_5_7	,	FuncSp__Lum_Off_6_7	,	FuncSp__Lum_Off_7_7	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STILLFLOW__OPEN",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_4_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_1_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_4_4	},																																																			
			{	FuncSp__Lum_Off_4_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_1_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_4_4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STILLFLOW__OPEN_x3",																																																																		
		3	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_4_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_1_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_4_4	},																																																			
			{	FuncSp__Lum_Off_4_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_1_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_4_4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STILLFLOW__CLOSE",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_4_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_1_4	},																																																			
			{	FuncSp__Lum_Off_1_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_4_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_1_4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STILLFLOW__CLOSE_x3",																																																																		
		3	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_4_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_1_4	},																																																			
			{	FuncSp__Lum_Off_1_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_4_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_1_4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__FlashBl -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_2CH",																																																																		
		1	,	// Speed																																																																
		6	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_3CH",																																																																		
		1	,	// Speed																																																																
		6	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_4CH",																																																																		
		1	,	// Speed																																																																
		6	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_5CH",																																																																		
		1	,	// Speed																																																																
		6	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_2_7CH",																																																																		
		1	,	// Speed																																																																
		13	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_3_7CH",																																																																		
		1	,	// Speed																																																																
		13	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_OPEN",																																																																		
		1	,	// Speed																																																																
		2	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__FLASH_BL__FLASH_CLOSE",																																																																		
		1	,	// Speed																																																																
		2	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__Strobe -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_7_LUM__STROBE__STROBE_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STROBE__STROBE_x4_OFF",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STROBE__STROBE_x4_2CH",																																																																		
		1	,	// Speed																																																																
		6	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STROBE__STROBE_x4_3CH",																																																																		
		1	,	// Speed																																																																
		6	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STROBE__STROBE_x4_4CH",																																																																		
		1	,	// Speed																																																																
		6	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STROBE__ORDER_x7",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_1_7	,	FuncSp__Lum_Flash_2_7	,	FuncSp__Lum_Flash_3_7	,	FuncSp__Lum_Flash_4_7	,	FuncSp__Lum_Flash_5_7	,	FuncSp__Lum_Flash_6_7	,	FuncSp__Lum_Flash_7_7	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_7_LUM__STROBE__SPREAD_x7_OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx7	,	FuncSp__Lum_Flashx7_2	,	FuncSp__Lum_Flashx7_3	,	FuncSp__Lum_Flashx7_4	,	FuncSp__Lum_Flashx7_5	,	FuncSp__Lum_Flashx7_6	,	FuncSp__Lum_Flashx7_7	},																																																			
		//	{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// -----------------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_END",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
};																																																																				

const struct BLOCK_PATTERN Bp_6[] = {																																																																				
	// LUM__Still -------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_6_LUM__STILL__OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	1	,	0	,	0	,	0	,	0	,	0	,	1	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__STILL__ON",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__StillFlow -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_6_LUM__STILLFLOW__FLOW",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_6	,	FuncSp__Lum_On_2_6	,	FuncSp__Lum_On_3_6	,	FuncSp__Lum_On_4_6	,	FuncSp__Lum_On_5_6	,	FuncSp__Lum_On_6_6	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_6	,	FuncSp__Lum_Off_2_6	,	FuncSp__Lum_Off_3_6	,	FuncSp__Lum_Off_4_6	,	FuncSp__Lum_Off_5_6	,	FuncSp__Lum_Off_6_6	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	1	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__STILLFLOW__FLOW_x3",																																																																		
		3	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_6	,	FuncSp__Lum_On_2_6	,	FuncSp__Lum_On_3_6	,	FuncSp__Lum_On_4_6	,	FuncSp__Lum_On_5_6	,	FuncSp__Lum_On_6_6	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_6	,	FuncSp__Lum_Off_2_6	,	FuncSp__Lum_Off_3_6	,	FuncSp__Lum_Off_4_6	,	FuncSp__Lum_Off_5_6	,	FuncSp__Lum_Off_6_6	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	1	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__FlashBl -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_6_LUM__FLASH_BL__FLASH",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__FLASH_BL__FLASH_2CH",																																																																		
		1	,	// Speed																																																																
		5	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__FLASH_BL__FLASH_3CH",																																																																		
		1	,	// Speed																																																																
		5	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__FLASH_BL__FLASH_2_6CH",																																																																		
		1	,	// Speed																																																																
		11	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__FLASH_BL__FLASH_3_7CH",																																																																		
		1	,	// Speed																																																																
		11	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__Strobe -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_6_LUM__STROBE__STROBE_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__STROBE__STROBE_x4_OFF",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__STROBE__STROBE_x4_2CH",																																																																		
		1	,	// Speed																																																																
		5	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__STROBE__STROBE_x4_3CH",																																																																		
		1	,	// Speed																																																																
		5	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__STROBE__ORDER_x6",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_1_6	,	FuncSp__Lum_Flash_2_6	,	FuncSp__Lum_Flash_3_6	,	FuncSp__Lum_Flash_4_6	,	FuncSp__Lum_Flash_5_6	,	FuncSp__Lum_Flash_6_6	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"BP_6_LUM__STROBE__SPREAD_x6_OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx6	,	FuncSp__Lum_Flashx6_2	,	FuncSp__Lum_Flashx6_3	,	FuncSp__Lum_Flashx6_4	,	FuncSp__Lum_Flashx6_5	,	FuncSp__Lum_Flashx6_6	,	NULL	},																																																			
		//	{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// -----------------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_END",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
};																																																																				

const struct BLOCK_PATTERN Bp_5[] = {																																																																				
	// LUM__Still -------------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_5_LUM__STILL__OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	1	,	1	,	1	,	1	,	1	,	0	,	1	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__STILL__ON",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__StillFlow -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_5_LUM__STILLFLOW__FLOW",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_5	,	FuncSp__Lum_On_2_5	,	FuncSp__Lum_On_3_5	,	FuncSp__Lum_On_4_5	,	FuncSp__Lum_On_5_5	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_5	,	FuncSp__Lum_Off_2_5	,	FuncSp__Lum_Off_3_5	,	FuncSp__Lum_Off_4_5	,	FuncSp__Lum_Off_5_5	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__STILLFLOW__FLOW_x3",																																																																		
		3	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_5	,	FuncSp__Lum_On_2_5	,	FuncSp__Lum_On_3_5	,	FuncSp__Lum_On_4_5	,	FuncSp__Lum_On_5_5	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_5	,	FuncSp__Lum_Off_2_5	,	FuncSp__Lum_Off_3_5	,	FuncSp__Lum_Off_4_5	,	FuncSp__Lum_Off_5_5	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__FlashBl -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_5_LUM__FLASH_BL__FLASH",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__FLASH_BL__FLASH_2CH",																																																																		
		1	,	// Speed																																																																
		4	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__FLASH_BL__FLASH_2_5CH",																																																																		
		1	,	// Speed																																																																
		9	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__Strobe -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_5_LUM__STROBE__STROBE_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__STROBE__STROBE_x4_OFF",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__STROBE__STROBE_x4_2CH",																																																																		
		1	,	// Speed																																																																
		4	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__STROBE__ORDER_x5",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_1_5	,	FuncSp__Lum_Flash_2_5	,	FuncSp__Lum_Flash_3_5	,	FuncSp__Lum_Flash_4_5	,	FuncSp__Lum_Flash_5_5	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_5_LUM__STROBE__SPREAD_x5_OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx5	,	FuncSp__Lum_Flashx5_2	,	FuncSp__Lum_Flashx5_3	,	FuncSp__Lum_Flashx5_4	,	FuncSp__Lum_Flashx5_5	,	NULL	,	NULL	},																																																			
		//	{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// -----------------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_END",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
};																																																																				

const struct BLOCK_PATTERN Bp_4[] = {																																																																				
	// LUM__Still -------------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_4_LUM__STILL__OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	1	,	1	,	1	,	1	,	1	,	0	,	1	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__STILL__ON",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__StillFlow -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_4_LUM__STILLFLOW__FLOW",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_4_4	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_4_4	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__STILLFLOW__FLOW_x3",																																																																		
		3	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_4	,	FuncSp__Lum_On_2_4	,	FuncSp__Lum_On_3_4	,	FuncSp__Lum_On_4_4	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_4	,	FuncSp__Lum_Off_2_4	,	FuncSp__Lum_Off_3_4	,	FuncSp__Lum_Off_4_4	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__FlashBl -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_4_LUM__FLASH_BL__FLASH",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__FLASH_BL__FLASH_2CH",																																																																		
		1	,	// Speed																																																																
		3	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__FLASH_BL__FLASH_2_4CH",																																																																		
		1	,	// Speed																																																																
		7	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__Strobe -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_4_LUM__STROBE__STROBE_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__STROBE__STROBE_x4_OFF",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__STROBE__STROBE_x4_2CH",																																																																		
		1	,	// Speed																																																																
		3	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__STROBE__ORDER_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_1_4	,	FuncSp__Lum_Flash_2_4	,	FuncSp__Lum_Flash_3_4	,	FuncSp__Lum_Flash_4_4	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_4_LUM__STROBE__SPREAD_x4_OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4_2	,	FuncSp__Lum_Flashx4_3	,	FuncSp__Lum_Flashx4_4	,	NULL	,	NULL	,	NULL	},																																																			
		//	{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// -----------------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_END",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
};																																																																				

const struct BLOCK_PATTERN Bp_3[] = {																																																																				
	// LUM__Still -------------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_3_LUM__STILL__OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	1	,	0	,	0	,	0	,	0	,	0	,	1	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__STILL__ON",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__StillFlow -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_3_LUM__STILLFLOW__FLOW",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_3	,	FuncSp__Lum_On_2_3	,	FuncSp__Lum_On_3_3	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_3	,	FuncSp__Lum_Off_2_3	,	FuncSp__Lum_Off_3_3	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	1	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__STILLFLOW__FLOW_x3",																																																																		
		3	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_On_1_3	,	FuncSp__Lum_On_2_3	,	FuncSp__Lum_On_3_3	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Off_1_3	,	FuncSp__Lum_Off_2_3	,	FuncSp__Lum_Off_3_3	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_LINE,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	1	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__FlashBl -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_3_LUM__FLASH_BL__FLASH",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__FLASH_BL__FLASH_1CH",																																																																		
		1	,	// Speed																																																																
		2	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__FLASH_BL__FLASH_1_3CH",																																																																		
		1	,	// Speed																																																																
		5	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__Strobe -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_3_LUM__STROBE__STROBE_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__STROBE__STROBE_x4_OFF",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__STROBE__STROBE_x4_1CH",																																																																		
		1	,	// Speed																																																																
		2	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__STROBE__STROBE_x4_2CH",																																																																		
		1	,	// Speed																																																																
		2	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__STROBE__ORDER_x3",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_1_3	,	FuncSp__Lum_Flash_2_3	,	FuncSp__Lum_Flash_3_3	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_3_LUM__STROBE__SPREAD_x3_OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx3	,	FuncSp__Lum_Flashx3_2	,	FuncSp__Lum_Flashx3_3	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		//	{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// -----------------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_END",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
};																																																																				

const struct BLOCK_PATTERN Bp_2[] = {																																																																				
	// LUM__Still -------------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_2_LUM__STILL__OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	1	,	0	,	0	,	0	,	0	,	0	,	1	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_2_LUM__STILL__ON",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Max	,	FuncSp__Lum_const_Max	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__StillFlow -----------------------------------------------------------------------------------------------------------------																																																																			
																																																																				
	// Lum__FlashBl -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_2_LUM__FLASH_BL__FLASH",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_2_LUM__FLASH_BL__FLASH_1CH",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__Strobe -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_2_LUM__STROBE__STROBE_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_2_LUM__STROBE__STROBE_x4_OFF",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_2_LUM__STROBE__STROBE_x4_1CH",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RANDOM,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// -----------------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_END",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
};																																																																				

const struct BLOCK_PATTERN Bp_1[] = {																																																																				
	// LUM__Still -------------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_1_LUM__STILL__OFF",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	1	,	0	,	0	,	0	,	0	,	0	,	1	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_1_LUM__STILL__ON",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_const_Max	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	1	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__StillFlow -----------------------------------------------------------------------------------------------------------------																																																																			
																																																																				
	// Lum__FlashBl -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_1_LUM__FLASH_BL__FLASH",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flash_Bl	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	1	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// Lum__Strobe -----------------------------------------------------------------------------------------------------------------																																																																			
	{	"Bp_1_LUM__STROBE__STROBE_x4",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
	{	"Bp_1_LUM__STROBE__STROBE_x4_OFF",																																																																		
		1	,	// Speed																																																																
		1	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	FuncSp__Lum_Flashx4	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	FuncSp__Lum_const_Zero	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	1	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
																																																																				
	// -----------------------------------------------------------------------------------------------------------------------------																																																																			
	{	"BP_END",																																																																		
		1	,	// Speed																																																																
		0	,	// StartPatternId_Candidate																																																																
		{																																																																		
			{	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	,	NULL	},																																																			
		},																																																																		
		SYMMETRY_RIGID,																																																																		
		{//		none		fft		Normal		Speed		Strobe		Beat		On		Off																																																		
/*StageLight*/			{	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	},																																																	
		},																																																																		
	},																																																																			
};																																																																				

