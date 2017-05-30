/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxArtnet.h"

#include "sj_common.h"
#include "L_common.h"
#include "th_Event.h"
#include "th_Color.h"

/************************************************************
************************************************************/
struct BLOCK;
struct BLOCK_GROUP;
struct PHYSICAL_CH_SET;
struct BLOCK_PATTERN;
struct BP_INFO;

struct LED_PARAM;

/************************************************************
************************************************************/

/**************************************************
**************************************************/
class LIGHT{
private:
	/****************************************
	****************************************/
	/********************
	********************/
	ofxArtnet artnet;
	
	int LastMusicTime;
	float et_LastTransition;
	
	FILE* fp_Event_AnimationChange;
	FILE* fp_Event_ColorChange;
	
	STATE State;
	STATE Event_AnimationChange;
	
	THREAD_BASE* thread_TimeTable[NUM_THREAD_TIMETABLE];
	
	/********************
	********************/
	int BlockGrouping_id;
	
	const float et_Default_AnimationInterval;
	const float et_Default_AnimationInterval_slow;
	float et_AnimationInterval;

	
	/****************************************
	****************************************/
	void Send_AllZero_to_AllOde();
	void draw_test();
	void draw_demo();
	
	void checkScenario_AnimationChange(int MusicTime);
	void checkScenario_ColorChange(int MusicTime);
	void AnimationTransition();
	void update_LedParam(float fft_Gain);
	bool IsMusicLoop(int MusicTime);
	int Dice_index(int *Weight, int NUM);
	bool Is_PeriodOfBlockGroup(BLOCK& Block);
	int get_Num_LogicalChs_inThisBlock(BLOCK& Block);
	int get_Num_PhysicalChs_inThisLogicalCh(PHYSICAL_CH_SET& LogicalCh);
	
	int Dice_BlockGrouping(STATE State);
	int get_num_PatternTypes_in_Bp(const BLOCK_PATTERN *Bp_Pattern);
	void Set_LedTrackID_by_SymmetricType(BP_INFO *BpInfo, SYMMETRIC_TYPE SymmetricType, int NumLogicalChs);
	void Dice_LedTrackOrder_Line(BP_INFO *BpInfo, int NumLogicalChs);
	void Dice_StartPatternId(BP_INFO *BpInfo, int StartPatternId_Candidate);
	void Dice_LedTrackOrder_Random(BP_INFO *BpInfo, int NumLogicalChs);
	void SelectBlockPattern(STATE State, BLOCK_GROUP *BlockGrouping, int BlockGrouping_id);
	
	void update_LedParm_fft(float fft_Gain);
	void update_LedParam_shortPatten();
	int CalProgress(float Beat_interval, float et_LastBeat, double Speed);
	int CalLev_from_ShortPattern(PFUNC_SHORTPATTERN pFunc_sp, int Progress);
	void update_OneBlock(BLOCK& block);
	void PatternIndex_next(const BLOCK_PATTERN& BlockPattern, int& Pattern_index);
	void ColorTransition();
	
	void Reset();
	
	
public:
	/****************************************
	****************************************/
	LIGHT();
	~LIGHT();
	
	void exit();
	void setup();
	void update(float fft_Gain);
	void draw();
	
	void setEvent_AnimationChange(int MusicTime, STATE _event);
	void setEvent_ColorChange(int MusicTime);
};
