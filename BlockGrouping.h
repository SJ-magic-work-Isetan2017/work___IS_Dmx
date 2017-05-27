/************************************************************
// test code
//		check if "Bp_Pattern" is correct(compare logical Chs and Bp_Pattern).
//		Physical ch setting check
//

void LIGHT::Check(FILE* fp, BLOCK_GROUP *BlockGrouping, int NUM_GROUPTYPES)
{
	for(int GroupId = 0; GroupId < NUM_GROUPTYPES; GroupId++){
		
		// check if "Bp_Pattern" is correct.
		for(int i = 0; !Is_PeriodOfBlockGroup(BlockGrouping[GroupId].Block[i]); i++){
			int NumLogicalChs = get_Num_LogicalChs_inThisBlock(BlockGrouping[GroupId].Block[i]);
			
			switch(NumLogicalChs){
				case 0:
					break;
				case 1:
					if(BlockGrouping[GroupId].Block[i].Bp_Pattern != Bp_1){
						ERROR_MSG();
						printf("Error in Group_%d %d[th] Block\n", GroupId, i);
						std::exit(1);
					}
					break;
				case 2:
					if(BlockGrouping[GroupId].Block[i].Bp_Pattern != Bp_2){
						ERROR_MSG();
						printf("Error in Group_%d %d[th] Block\n", GroupId, i);
						std::exit(1);
					}
					break;
				case 3:
					if(BlockGrouping[GroupId].Block[i].Bp_Pattern != Bp_3){
						ERROR_MSG();
						printf("Error in Group_%d %d[th] Block\n", GroupId, i);
						std::exit(1);
					}
					break;
				case 4:
					if(BlockGrouping[GroupId].Block[i].Bp_Pattern != Bp_4){
						ERROR_MSG();
						printf("Error in Group_%d %d[th] Block\n", GroupId, i);
						std::exit(1);
					}
					break;
				case 5:
					if(BlockGrouping[GroupId].Block[i].Bp_Pattern != Bp_5){
						ERROR_MSG();
						printf("Error in Group_%d %d[th] Block\n", GroupId, i);
						std::exit(1);
					}
					break;
				case 6:
					if(BlockGrouping[GroupId].Block[i].Bp_Pattern != Bp_6){
						ERROR_MSG();
						printf("Error in Group_%d %d[th] Block\n", GroupId, i);
						std::exit(1);
					}
					break;
				case 7:
					if(BlockGrouping[GroupId].Block[i].Bp_Pattern != Bp_7){
						ERROR_MSG();
						printf("Error in Group_%d %d[th] Block\n", GroupId, i);
						std::exit(1);
					}
					break;
				default:
					printf("Error in Group_%d %d[th] Block\n", GroupId, i);
					std::exit(1);
					break;
			}
			
		}
		
		
		// Physical ch setting check
		fprintf_Log_forTestCode(fp, "------------------------------------------------------------\n");
		fprintf_Log_forTestCode(fp, "[%d]:%s\n", GroupId, BlockGrouping[GroupId].BlockName);
		fprintf_Log_forTestCode(fp, "------------------------------------------------------------\n");
		
		for(int i = 0; !Is_PeriodOfBlockGroup(BlockGrouping[GroupId].Block[i]); i++){
			int NumLogicalChs = get_Num_LogicalChs_inThisBlock(BlockGrouping[GroupId].Block[i]);
			
			if(NumLogicalChs){
				fprintf_Log_forTestCode(fp, "Block_%d\n", i);
				
				for(int j = 0; j < NumLogicalChs; j++){
					fprintf_Log_forTestCode(fp, "\tLogicalCh_%4d = ", j);
					
					int NumPhysicalChs = get_Num_PhysicalChs_inThisLogicalCh(BlockGrouping[GroupId].Block[i].LogicalCh[j]);
					
					for(int k = 0; k < NumPhysicalChs; k++){
						fprintf_Log_forTestCode(fp, "%4d, ", BlockGrouping[GroupId].Block[i].LogicalCh[j].PhysicalCh[k]);
					}
					fprintf_Log_forTestCode(fp, "\n");
				}
				fprintf_Log_forTestCode(fp, "\n");
			}
		}
		fprintf_Log_forTestCode(fp, "\n");
	}
}

void LIGHT::test()
{
	FILE* fp;
	
	fp = fopen("../../../SJ_Blocking.txt", "w");
	Check(fp, BlockGrouping, NUM_GROUPTYPES);
	fclose(fp);

	printf("Finish\n");
}
************************************************************/



#pragma once

/************************************************************
************************************************************/
#include "L_common.h"

/************************************************************
************************************************************/

struct PHYSICAL_CH_SET{
	enum{
		MAX_CHS_IN_1LOGICAL_CH = 100,
	};
	int PhysicalCh[MAX_CHS_IN_1LOGICAL_CH];
};

struct BP_INFO{
	/********************
	********************/
	enum DEVICE_CH_TYPE DeviceChType;
	
	/********************
	********************/
	int Bp_Pattern_index;
	int Pattern_index;
	float et_LastBeat;
	int ChId[MAX_CHS_IN_A_BLOCK];
};

struct BLOCK{
	/********************
	********************/
	PHYSICAL_CH_SET LogicalCh[MAX_CHS_IN_A_BLOCK + 1];
	
	const BLOCK_PATTERN *Bp_Pattern;
	
	/********************
	********************/
	BP_INFO BpInfo_Luminance;
	
	/********************
	********************/
	void Set_AllBpInfo_LastBeat(float now)
	{
		BpInfo_Luminance.et_LastBeat = now;
	}
};

struct BLOCK_GROUP{
	enum{
		MAX_BLOCKS = 100,
	};
	
	char BlockName[BUF_SIZE];
	BLOCK Block[MAX_BLOCKS];
};

/************************************************************
šššššššššššššššššššššššššššššš
Copy from Excel below.
šššššššššššššššššššššššššššššš
************************************************************/
BLOCK_GROUP BlockGrouping[] = {						
	{					
		"GP__CH6",				
		{				
			{ // Block			
				{ // LogicalCh:Physical ch set		
					{0,-1},	// CH0
					{1,-1},	// CH1
					{2,-1},	// CH2
					{3,-1},	// CH3
					{4,-1},	// CH4
					{5,-1},	// CH5
						// CH6
					{-1},	
				},		
				Bp_6,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
			{ // END			
				{ // LogicalCh:Physical ch set		
						// CH0
						// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				NULL,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
		},				
	},					
	{					
		"GP__CH3",				
		{				
			{ // Block			
				{ // LogicalCh:Physical ch set		
					{0,1,-1},	// CH0
					{2,3,-1},	// CH1
					{4,5,-1},	// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				Bp_3,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
			{ // END			
				{ // LogicalCh:Physical ch set		
						// CH0
						// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				NULL,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
		},				
	},					
	{					
		"GP__CH3_DIRECTION",				
		{				
			{ // Block			
				{ // LogicalCh:Physical ch set		
					{0,3,-1},	// CH0
					{1,4,-1},	// CH1
					{2,5,-1},	// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				Bp_3,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
			{ // END			
				{ // LogicalCh:Physical ch set		
						// CH0
						// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				NULL,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
		},				
	},					
	{					
		"GP__CH3_SYMMETRY",				
		{				
			{ // Block			
				{ // LogicalCh:Physical ch set		
					{0,5,-1},	// CH0
					{1,4,-1},	// CH1
					{2,3,-1},	// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				Bp_3,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
			{ // END			
				{ // LogicalCh:Physical ch set		
						// CH0
						// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				NULL,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
		},				
	},					
	{					
		"GP__CH2",				
		{				
			{ // Block			
				{ // LogicalCh:Physical ch set		
					{0,1,2,-1},	// CH0
					{3,4,5,-1},	// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				Bp_2,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
			{ // END			
				{ // LogicalCh:Physical ch set		
						// CH0
						// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				NULL,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
		},				
	},					
	{					
		"GP__CH1",				
		{				
			{ // Block			
				{ // LogicalCh:Physical ch set		
					{0,1,2,3,4,5,-1},	// CH0
						// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				Bp_1,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
			{ // END			
				{ // LogicalCh:Physical ch set		
						// CH0
						// CH1
						// CH2
						// CH3
						// CH4
						// CH5
						// CH6
					{-1},	
				},		
				NULL,	// Bp_Pattern	
				{ // BpInfo_Luminance		
					DEVICE_CH_TYPE__FIX_STAGE_LIGHT,	
				},		
			},			
		},				
	},					
};						
						
const int NUM_GROUPTYPES = sizeof(BlockGrouping) / sizeof(BlockGrouping[0]);						
						
						
