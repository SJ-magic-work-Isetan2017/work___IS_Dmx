/************************************************************
setup for ISETAN DMX controller
	Hardware setting
		wifi off
		Firewall off
		IP address
			IPv4の設定	手入力
			IP			2.0.0.2
			subnet mask	255.0.0.0
		
	Software setting
		"ISETAN_DMX"の箇所
************************************************************/
#include "L_common.h"
#include "shortPattern.h"
#include "BlockPattern.h"
#include "BlockGrouping.h"
#include "Weight.h"

#include "Light.h"

/************************************************************
************************************************************/
enum{
	SIZE_DMX_UNIVERSE = 512,
};

enum LED_DEVICE_TYPE{
	LED_DEVICE_TYPE_SONY,
	LED_DEVICE_TYPE_ISETAN,
};

/************************************************************
private class
************************************************************/
class ODE{
private:
	char ch_IP[BUF_SIZE];
	
public:
	unsigned char universe[SIZE_DMX_UNIVERSE];
	
	ODE(const char* _ch_IP)
	{
		strcpy(ch_IP, _ch_IP);
		
		for(int i = 0; i < SIZE_DMX_UNIVERSE; i++){
			universe[i] = 0;
		}
	}
	const char* get_IP()
	{
		return ch_IP;
	}
};

struct LED_PARAM{
private:
	void xRatio_eachCh(unsigned char& val, double ratio){
		val = (unsigned char)(val * ratio);
		if(val < 0)		val = 0;
		if(255 < val)	val = 255;
	}
	
	void set_1ch(unsigned char& val, int NewVal){
		if(NewVal < 0)		NewVal = 0;
		if(255 < NewVal)	NewVal = 255;
		val = (unsigned char)NewVal;
	}
	
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;
	// unsigned char W;
	
	LED_PARAM()
	: R(0), G(0), B(0) //, W(0)
	{
	}
	
	LED_PARAM(int r, int g, int b)
	: R(r), G(g), B(b) //, W(0)
	{
	}
	
	void clear()
	{
		R = 0; G = 0; B = 0;
		// W = 0;
	}
	
	void xRatio(double ratio){
		xRatio_eachCh(R, ratio);
		xRatio_eachCh(G, ratio);
		xRatio_eachCh(B, ratio);
	}
	
	void set(int r, int g, int b){
		set_1ch(R, r);
		set_1ch(G, g);
		set_1ch(B, b);
	}
};

struct LED_LIGHT{
	const int ODE_id;
	const int AddressFrom;
	const enum LED_DEVICE_TYPE LedDeviceType;
	
	LED_PARAM LedParam;
	
	LED_LIGHT(int _ODE_id, int _AddressFrom, enum LED_DEVICE_TYPE _LedDeviceType)
	: ODE_id(_ODE_id), AddressFrom(_AddressFrom), LedDeviceType(_LedDeviceType)
	{
	}
};

/************************************************************
param
************************************************************/
/********************
********************/
static ODE ode[] = {
	// ODE("10.7.157.106"),
	// ODE("10.7.206.7"),
	ODE("2.106.193.8"),
};
static const int NUM_ODES = sizeof(ode) / sizeof(ode[0]);

/********************
ISETAN_DMX
********************/
static LED_LIGHT LedLight[] = {
//				ODE id		AddressFrom					Hardware(Start Address) setting 
/*	0	*/	LED_LIGHT(	0	,	0	,	LED_DEVICE_TYPE_ISETAN	),	//	1
/*	1	*/	LED_LIGHT(	0	,	7	,	LED_DEVICE_TYPE_ISETAN	),	//	8
/*	2	*/	LED_LIGHT(	0	,	14	,	LED_DEVICE_TYPE_ISETAN	),	//	15
/*	3	*/	LED_LIGHT(	0	,	21	,	LED_DEVICE_TYPE_ISETAN	),	//	22
/*	4	*/	LED_LIGHT(	0	,	28	,	LED_DEVICE_TYPE_ISETAN	),	//	29
/*	5	*/	LED_LIGHT(	0	,	35	,	LED_DEVICE_TYPE_ISETAN	),	//	36
};

static const int NUM_LEDS = sizeof(LedLight) / sizeof(LedLight[0]);

/********************
********************/
static const LED_PARAM LedColor_init(0, 0, 255);
static LED_PARAM LedColor_From = LedColor_init;
static LED_PARAM LedColor_To = LedColor_init;
static LED_PARAM LedColor = LedColor_init;
static float et_interval_ColorChange = 0;
static float et_ColorChange_Start = 0;





/************************************************************
************************************************************/

/******************************
******************************/
LIGHT::LIGHT()
: LastMusicTime(-1)
, fp_Event_AnimationChange(NULL)
, fp_Event_ColorChange(NULL)

, et_Default_AnimationInterval(0.5) // 120 BPM
, et_Default_AnimationInterval_slow(1.0)
, et_AnimationInterval(et_Default_AnimationInterval)

, et_LastTransition(0)
, State(STATE_FFT)
, Event_AnimationChange(STATE_NONE)
{
	/********************
	********************/
	BlockGrouping_id = Dice_BlockGrouping(State);
	SelectBlockPattern(State, BlockGrouping, BlockGrouping_id);
}

/******************************
******************************/
LIGHT::~LIGHT()
{
	/********************
	********************/
	Send_AllZero_to_AllOde();
	
	/********************
	********************/
	if(fp_Event_AnimationChange)	fclose(fp_Event_AnimationChange);
	if(fp_Event_ColorChange) 		fclose(fp_Event_ColorChange);
}

/******************************
******************************/
void LIGHT::Reset()
{
	/********************
	********************/
	Send_AllZero_to_AllOde();
	
	/********************
	********************/
	et_AnimationInterval = et_Default_AnimationInterval;
	et_LastTransition = 0;
	State = STATE_FFT;
	Event_AnimationChange =  STATE_NONE;
	
	BlockGrouping_id = Dice_BlockGrouping(State);
	SelectBlockPattern(State, BlockGrouping, BlockGrouping_id);
}

/******************************
******************************/
void LIGHT::exit()
{
	/********************
	********************/
	if(BootMode == BOOT_MODE__AUTOPLAY){
		for(int i = 0; i < NUM_THREAD_TIMETABLE; i++){
			thread_TimeTable[i]->exit();
			try{
				/********************
				stop済みのthreadをさらにstopすると、Errorが出るようだ。
				********************/
				if(thread_TimeTable[i]->isThreadRunning()){
					thread_TimeTable[i]->stopThread();
					while(thread_TimeTable[i]->isThreadRunning()){
						thread_TimeTable[i]->waitForThread(true);
					}
				}
				
			}catch(...){
				printf("Thread exiting Error\n");
			}
		}
	}
}

/******************************
******************************/
int LIGHT::Dice_BlockGrouping(STATE State)
{
	/********************
	********************/
	if(State == STATE_NONE){
		ERROR_MSG(); std::exit(1);
	}
	
	/********************
	********************/
	int Weight[NUM_GROUPTYPES];
	
	for(int i = 0; i < NUM_GROUPTYPES; i++){
		Weight[i] = W_BlockGrouping[State][i];
	}
	
	
	const int MAX_TRY = 5;
	int index;
	
	for(int i = 0; i < MAX_TRY; i++){
		index = Dice_index(Weight, NUM_GROUPTYPES);
		if(index == -1) { ERROR_MSG(); ofExit(); return; }
		
		if(index != BlockGrouping_id) break;
	}

	return index;
}

/******************************
******************************/
int LIGHT::get_num_PatternTypes_in_Bp(const BLOCK_PATTERN *Bp_Pattern)
{
	int num;
	for( num = 0; strcmp(Bp_Pattern[num].name, "BP_END") != 0; num++ ){
	}
	
	return num;
}

/******************************
******************************/
void LIGHT::SelectBlockPattern(STATE State, BLOCK_GROUP *BlockGrouping, int BlockGrouping_id)
{
	/********************
	********************/
	if(State == STATE_NONE){
		ERROR_MSG(); std::exit(1);
	}
	
	/********************
	set Bp_Pattern_index of BpInfo_Luminance (, BpInfo_Pan, BpInfo_Tilt)
	********************/
	for(int LedBlock = 0; !Is_PeriodOfBlockGroup(BlockGrouping[BlockGrouping_id].Block[LedBlock]); LedBlock++){
		int NumLogicalChs = get_Num_LogicalChs_inThisBlock(BlockGrouping[BlockGrouping_id].Block[LedBlock]);
		
		if(0 < NumLogicalChs){
			int NumCandidates = get_num_PatternTypes_in_Bp(BlockGrouping[BlockGrouping_id].Block[LedBlock].Bp_Pattern);
			int* Weight = (int*)malloc(sizeof(int) * NumCandidates);
			
			BP_INFO *BpInfo = &BlockGrouping[BlockGrouping_id].Block[LedBlock].BpInfo_Luminance; // わざわざ別変数で受けているのは、Pan, Tiltがあった場合の名残り
			enum DEVICE_CH_TYPE DeviceChType = BpInfo->DeviceChType;
			
			for(int i = 0; i < NumCandidates; i++){
				Weight[i] = BlockGrouping[BlockGrouping_id].Block[LedBlock].Bp_Pattern[i].Weight[DeviceChType][State];
			}
			
			BpInfo->Bp_Pattern_index = Dice_index(Weight, NumCandidates);
			if(BpInfo->Bp_Pattern_index == -1) { ERROR_MSG(); ofExit(); return; }
			
			/* */
			Set_LedTrackID_by_SymmetricType(BpInfo, BlockGrouping[BlockGrouping_id].Block[LedBlock].Bp_Pattern[BpInfo->Bp_Pattern_index].SymmetricType, NumLogicalChs);
			
			Dice_StartPatternId(BpInfo, BlockGrouping[BlockGrouping_id].Block[LedBlock].Bp_Pattern[BpInfo->Bp_Pattern_index].StartPatternId_Candidate);

			/********************
			********************/
			free(Weight);
		}
	}
}

/******************************
******************************/
void LIGHT::Set_LedTrackID_by_SymmetricType(BP_INFO *BpInfo, SYMMETRIC_TYPE SymmetricType, int NumLogicalChs)
{
	/********************
	まず順序通り並べる.
	********************/
	for(int i = 0; i < NumLogicalChs; i++){
		BpInfo->ChId[i] = i;
	}
	
	/********************
	********************/
	if(SymmetricType == SYMMETRY_RIGID){
		/* nothing. */
	}else if( SymmetricType == SYMMETRY_RANDOM ){
		Dice_LedTrackOrder_Random(BpInfo, NumLogicalChs);
		
	}else if(SymmetricType == SYMMETRY_LINE){
		Dice_LedTrackOrder_Line(BpInfo, NumLogicalChs);
		
	}else{
		ERROR_MSG(); ofExit(); return;
	}
}

/******************************
******************************/
void LIGHT::Dice_LedTrackOrder_Line(BP_INFO *BpInfo, int NumLogicalChs)
{
	int RandomNumber = rand() % 2;
	
	if(RandomNumber == 0){
		/* そのまま */
	}else{
		/* Reverse */
		int i;
		for(i = 0; i < NumLogicalChs; i++){
			BpInfo->ChId[i] = NumLogicalChs - i - 1;
		}
	}
}

/******************************
******************************/
void LIGHT::Dice_StartPatternId(BP_INFO *BpInfo, int StartPatternId_Candidate)
{
	BpInfo->Pattern_index = rand() % (StartPatternId_Candidate + 1);
}

/******************************
description
	fisher yates法
	偏りをなくすため、回を追うごとに乱数範囲を狭めていくのがコツ
	http://www.fumiononaka.com/TechNotes/Flash/FN0212003.html
******************************/
void LIGHT::Dice_LedTrackOrder_Random(BP_INFO *BpInfo, int NumLogicalChs)
{
	int i= NumLogicalChs;
	
	while(i--){
		int j = rand() % (i + 1);
		
		int temp = BpInfo->ChId[i];
		BpInfo->ChId[i] = BpInfo->ChId[j];
		BpInfo->ChId[j] = temp;
	}
}

/******************************
******************************/
void LIGHT::Send_AllZero_to_AllOde()
{
	for(int i = 0; i < NUM_ODES; i++){
		for(int j = 0; j < SIZE_DMX_UNIVERSE; j++){
			ode[i].universe[j] = 0;
		}
		
		artnet.sendDmx(ode[i].get_IP(), ode[i].universe, SIZE_DMX_UNIVERSE);
	}
}

/******************************
******************************/
void LIGHT::setup()
{
	/********************
	ISETAN_DMX
	********************/
    //at first you must specify the Ip address of this machine
    // artnet.setup("10.0.0.2"); //make sure the firewall is deactivated at this point
	artnet.setup("2.0.0.2"); //make sure the firewall is deactivated at this point
	
	/********************
	********************/
	fp_Event_ColorChange = fopen("../../../Dmx_Color(Rec).txt", "w");
	if(fp_Event_ColorChange == NULL) { ERROR_MSG(); std::exit(1); }
	
	if(BootMode == BOOT_MODE__REC){
		fp_Event_AnimationChange = fopen("../../../Dmx_Anim(Rec).txt", "w");
		if(fp_Event_AnimationChange == NULL) { ERROR_MSG(); std::exit(1); }
		
	}else if(BootMode == BOOT_MODE__AUTOPLAY){
		thread_TimeTable[THREAD_TIMETABLE__EVENT] = THREAD__EVENT_TIMETABLE::getInstance();
		thread_TimeTable[THREAD_TIMETABLE__COLOR] = THREAD__COLOR_TIMETABLE::getInstance();
		
		for(int i = 0; i < NUM_THREAD_TIMETABLE; i++){
			if(thread_TimeTable[i]->setup()){ // if Scenario File not exist, no start.
				thread_TimeTable[i]->startThread(true, false); // blocking, non verboss
			}
		}
	}
}

/******************************
******************************/
void LIGHT::setEvent_AnimationChange(int MusicTime, STATE _event)
{
	/********************
	********************/
	if(State == STATE_NONE){
		ERROR_MSG(); std::exit(1);
	}
	
	/********************
	********************/
	if(BootMode == BOOT_MODE__REC){
		Event_AnimationChange = _event;
		fprintf(fp_Event_AnimationChange, "<time> %10d %d\n", MusicTime, Event_AnimationChange);
	}
}

/******************************
******************************/
void LIGHT::setEvent_ColorChange(int MusicTime)
{
	/********************
	先に作成されたAnimation Scenarioを流しながら、Color Scenarioをつくるので、BootModeによらず、記録する.
	********************/
	// if(BootMode == BOOT_MODE__REC){
		fprintf(fp_Event_ColorChange, "<time> %10d\n", MusicTime);
		printf("Rec:color change\n");
	// }
}

/******************************
******************************/
void LIGHT::checkScenario_AnimationChange(int MusicTime)
{
	if(BootMode == BOOT_MODE__AUTOPLAY){
		thread_TimeTable[THREAD_TIMETABLE__EVENT]->update(MusicTime);
		Event_AnimationChange = STATE( ((THREAD__EVENT_TIMETABLE*)thread_TimeTable[THREAD_TIMETABLE__EVENT])->checkEvent());
	}
}


/******************************
******************************/
void LIGHT::checkScenario_ColorChange(int MusicTime)
{
	if(BootMode == BOOT_MODE__AUTOPLAY){
		thread_TimeTable[THREAD_TIMETABLE__COLOR]->update(MusicTime);
		
		TIME_N_DATASET__COLOR ret;
		((THREAD__COLOR_TIMETABLE*)thread_TimeTable[THREAD_TIMETABLE__COLOR])->checkEvent(ret);
		
		if(ret.R != -1){
			LedColor_From = LedColor;
			LedColor_To.set(ret.R, ret.G, ret.B);
			
			et_interval_ColorChange = ret.t_interval_ColorChange;
			
			et_ColorChange_Start = ElapsedTime;
		}
	}
}

/******************************
******************************/
void LIGHT::AnimationTransition()
{
	/********************
	********************/
	if(Event_AnimationChange == STATE_NONE) return;
	
	/********************
	********************/
	if( Event_AnimationChange == STATE_BEAT ){
		if(State != STATE_BEAT){
			// 1発目:slow.
			et_AnimationInterval = et_Default_AnimationInterval_slow;
		}else{
			// 2発目以降:計測値
			et_AnimationInterval = ElapsedTime - et_LastTransition;
		}
	}else{
		// other:元に戻す.
		et_AnimationInterval = et_Default_AnimationInterval;
	}
	
	/********************
	********************/
	switch(Event_AnimationChange){
		case STATE_NONE:
			// nothing.
			break;
			
		case STATE_FFT:
			// nothing.
			break;
			
		case STATE_BEAT:
			// STATE_BEATに入ったら、一度抜けるまではpattern changeなし.
			if(State != STATE_BEAT){
				BlockGrouping_id = Dice_BlockGrouping(Event_AnimationChange);
				SelectBlockPattern(Event_AnimationChange, BlockGrouping, BlockGrouping_id);
			}
			
			break;
			
		default:
			BlockGrouping_id = Dice_BlockGrouping(Event_AnimationChange);
			SelectBlockPattern(Event_AnimationChange, BlockGrouping, BlockGrouping_id);
			break;
	}
	
	State = Event_AnimationChange;
	Event_AnimationChange = STATE_NONE;
	
	/********************
	********************/
	for(int LedBlock = 0; !Is_PeriodOfBlockGroup(BlockGrouping[BlockGrouping_id].Block[LedBlock]); LedBlock++){
		BlockGrouping[BlockGrouping_id].Block[LedBlock].Set_AllBpInfo_LastBeat(ElapsedTime);
	}
	
	/********************
	********************/
	et_LastTransition = ElapsedTime;
}

/******************************
******************************/
void LIGHT::update_LedParam(float fft_Gain)
{
	if(State == STATE_FFT)	update_LedParm_fft(fft_Gain);
	else					update_LedParam_shortPatten();
}

/******************************
******************************/
void LIGHT::update_LedParm_fft(float fft_Gain)
{
	float Lev = ofMap(fft_Gain, 0, Gui_Param->fftGain_Range, 0, 1.0);
	LED_PARAM param = LedColor;
	param.xRatio(Lev);
	
	for(int i = 0; i < NUM_LEDS; i++){
		LedLight[i].LedParam = param;
	}
}

/******************************
******************************/
void LIGHT::update_LedParam_shortPatten()
{
	/********************
	********************/
	for(int i = 0; i < NUM_LEDS; i++)	LedLight[i].LedParam.clear();
	
	for(int LedBlock = 0; !Is_PeriodOfBlockGroup(BlockGrouping[BlockGrouping_id].Block[LedBlock]); LedBlock++){
		update_OneBlock(BlockGrouping[BlockGrouping_id].Block[LedBlock]);
	}
}

/******************************
******************************/
void LIGHT::update_OneBlock(BLOCK& block)
{
	/********************
	********************/
	BP_INFO *BpInfo = &block.BpInfo_Luminance; // わざわざ別変数で受けているのは、Pan, Tiltがあった時の名残り.
	
	/********************
	********************/
	int NUM_LOGICAL_CHS = get_Num_LogicalChs_inThisBlock(block);
	int Progress;
	
	if(0 < NUM_LOGICAL_CHS){
		Progress = CalProgress(et_AnimationInterval, BpInfo->et_LastBeat, block.Bp_Pattern[BpInfo->Bp_Pattern_index].Speed);
	}else{
		Progress = 0;
	}
	
	/********************
	********************/
	for(int i = 0; i < NUM_LOGICAL_CHS; i++){
		/********************
		i番目のLed出力を算出.
		BlockPatternはtrack入れ替えがあるので注意.
		LedColorは入れ替えなどないので、そのまま.
		********************/
		int ChTrackId = BpInfo->ChId[i]; // LogicalChのi番目はどのBlockPattern trackを参照するか.
		int Lev = CalLev_from_ShortPattern(block.Bp_Pattern[BpInfo->Bp_Pattern_index].pShortPattern[BpInfo->Pattern_index][ChTrackId], Progress);
		
		/********************
		********************/
		LED_PARAM param = LedColor;
		param.xRatio(double(Lev)/255);
		
		int NUM_PHYSICAL_CHS = get_Num_PhysicalChs_inThisLogicalCh(block.LogicalCh[i]);
		for(int j = 0; j < NUM_PHYSICAL_CHS; j++){
			int id_physicalLed = block.LogicalCh[i].PhysicalCh[j];

			LedLight[id_physicalLed].LedParam = param;
		}
	}

	/********************
	********************/
	/* if finish pattern, go to next. */
	if( MAXPROGRESS_ANIM_KEY <= Progress ){
		PatternIndex_next(block.Bp_Pattern[BpInfo->Bp_Pattern_index], BpInfo->Pattern_index);
		
		// if(State != STATE_BEAT){
			BpInfo->et_LastBeat = ElapsedTime;
		// }
	}
}

/******************************
******************************/
void LIGHT::PatternIndex_next(const BLOCK_PATTERN& BlockPattern, int& Pattern_index)
{
	Pattern_index++;
	
	if(BlockPattern.pShortPattern[Pattern_index][0] == NULL){
		Pattern_index = 0;
	}
}

/******************************
******************************/
int LIGHT::CalProgress(float Beat_interval, float et_LastBeat, double Speed)
{
	if(Beat_interval <= 0){
		ERROR_MSG(); ofExit(); return;
		
	}else if(ElapsedTime <= et_LastBeat){
		return 0;
		
	}else if( Beat_interval <= (int)((ElapsedTime - et_LastBeat) * Speed) ){
		return MAXPROGRESS_ANIM_KEY;
		
	}else{
		return (int)( (ElapsedTime - et_LastBeat) * Speed * MAXPROGRESS_ANIM_KEY / Beat_interval );
	}
}

/******************************
******************************/
int LIGHT::CalLev_from_ShortPattern(PFUNC_SHORTPATTERN pFunc_sp, int Progress)
{
	/********************
	********************/
	if(Progress < 0)	{ ERROR_MSG(); ofExit(); return; }
	
	if(MAXPROGRESS_ANIM_KEY <= Progress){
		return pFunc_sp(MAXPROGRESS_ANIM_KEY);
	}else{
		return pFunc_sp(Progress);
	}
}

/******************************
******************************/
void LIGHT::update(float fft_Gain)
{
	/********************
	********************/
	if(BootMode == BOOT_MODE__TEST)	return;

	
	/********************
	********************/
	if( IsMusicLoop(MusicTime) && (BootMode == BOOT_MODE__AUTOPLAY) ){
		for(int i = 0; i < NUM_THREAD_TIMETABLE; i++){
			thread_TimeTable[i]->stopThread();
			thread_TimeTable[i]->waitForThread(true);
			thread_TimeTable[i]->Reset();
			thread_TimeTable[i]->startThread(true, false);
		}
		
		Reset();
		
	}else{
		/********************
		********************/
		if(BootMode == BOOT_MODE__AUTOPLAY){
			if(thread_TimeTable[THREAD_TIMETABLE__EVENT]->IsReady()){
				/********************
				もしNotReadyの時は、Skipしてしまうが、すぐ処理終わるので、多分そんなcaseはない.
				IsReady()をLoopしてここで粘って待ってしまうと、IsReady()の向こう側でlock()しているので、高速にlockが回ってしまい、
				threadedFunctionに処理が回らなくなる
				その結果、フリーズするので、注意.
				********************/
				checkScenario_AnimationChange(MusicTime);
			}
			if(thread_TimeTable[THREAD_TIMETABLE__COLOR]->IsReady()){
				checkScenario_ColorChange(MusicTime);
			}
		}
		
		/********************
		********************/
		ColorTransition();
		AnimationTransition();
	}
	
	update_LedParam(fft_Gain);
	
	/********************
	********************/
	LastMusicTime = MusicTime;
}

/******************************
******************************/
void LIGHT::ColorTransition()
{
	/********************
	********************/
	if(BootMode != BOOT_MODE__AUTOPLAY) return;
	
	/********************
	********************/
	if(et_interval_ColorChange == 0){
		LedColor = LedColor_To;
		return;
	}

	/********************
	********************/
	enum{
		MAXPROGRESS = 10000,
	};

	int Progress;
	if(ElapsedTime <= et_ColorChange_Start){
		Progress = 0;
	}else if(et_interval_ColorChange <= ElapsedTime - et_ColorChange_Start){
		Progress = MAXPROGRESS;
	}else{
		Progress = (ElapsedTime - et_ColorChange_Start) * MAXPROGRESS / et_interval_ColorChange;
	}
	
	LedColor.set	(
					LedColor_From.R + (LedColor_To.R - LedColor_From.R) * Progress / MAXPROGRESS,
					LedColor_From.G + (LedColor_To.G - LedColor_From.G) * Progress / MAXPROGRESS,
					LedColor_From.B + (LedColor_To.B - LedColor_From.B) * Progress / MAXPROGRESS
					);

	/******************************
	******************************/
	if(MAXPROGRESS <= Progress){
		et_interval_ColorChange = 0;
	}
}

/******************************
******************************/
bool LIGHT::IsMusicLoop(int MusicTime)
{
	if(MusicTime < LastMusicTime)	return true;
	else							return false;
}

/******************************
******************************/
void LIGHT::draw()
{
	if(BootMode == BOOT_MODE__TEST){
		draw_test();
	}else{
		if(MusicTime == -1)	Send_AllZero_to_AllOde();
		else				draw_demo();
	}
}

/******************************
******************************/
void LIGHT::draw_test()
{
	for(int i = 0; i < NUM_LEDS; i++){
		switch(LedLight[i].LedDeviceType){
			case LED_DEVICE_TYPE_SONY:
				if(i == Gui_Param->LedId){
					ofColor color = Gui_Param->TestColor;
					
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 0 ] = Gui_Param->Alpha_FixedLed;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 1 ] = color.r;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 2 ] = color.g;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 3 ] = color.b;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 4 ] = 0; // W
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 5 ] = 1; // Strobe = open.
					
				}else{
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 0 ] = 0; // dimmer
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 1 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 2 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 3 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 4 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 5 ] = 0; // strobe
				}
				break;
				
			case LED_DEVICE_TYPE_ISETAN: // ISETAN_DMX
				if(i == Gui_Param->LedId){
					ofColor color = Gui_Param->TestColor;
					
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 0 ] = Gui_Param->Alpha_FixedLed;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 1 ] = color.r;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 2 ] = color.g;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 3 ] = color.b;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 4 ] = 0; // W
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 5 ] = 0; // Strobe
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 6 ] = 0; // Color function.
					
				}else{
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 0 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 1 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 2 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 3 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 4 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 5 ] = 0;
					ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 6 ] = 0;
					
				}
				break;
		}
		
		
	}
	
	for(int i = 0; i < NUM_ODES; i++){
		artnet.sendDmx(ode[i].get_IP(), ode[i].universe, SIZE_DMX_UNIVERSE);
	}
}

/******************************
******************************/
void LIGHT::draw_demo()
{
	/********************
	********************/
	for(int i = 0; i < NUM_LEDS; i++){
		switch(LedLight[i].LedDeviceType){
			case LED_DEVICE_TYPE_SONY:
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 0 ] = Gui_Param->Alpha_FixedLed;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 1 ] = LedLight[i].LedParam.R;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 2 ] = LedLight[i].LedParam.G;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 3 ] = LedLight[i].LedParam.B;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 4 ] = 0; // LedLight[i].LedParam.W;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 5 ] = 1; // Strobe = open.
				
				break;
				
			case LED_DEVICE_TYPE_ISETAN: // ISETAN_DMX
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 0 ] = Gui_Param->Alpha_FixedLed;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 1 ] = LedLight[i].LedParam.R;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 2 ] = LedLight[i].LedParam.G;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 3 ] = LedLight[i].LedParam.B;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 4 ] = 0; // LedLight[i].LedParam.W;
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 5 ] = 0; // Strobe.
				ode[ LedLight[i].ODE_id ].universe[ LedLight[i].AddressFrom + 6 ] = 0; // Color function.
				
				break;
		}
	}
	
	/********************
	********************/
	for(int i = 0; i < NUM_ODES; i++){
		artnet.sendDmx(ode[i].get_IP(), ode[i].universe, SIZE_DMX_UNIVERSE);
	}
}

/******************************
******************************/
int LIGHT::Dice_index(int *Weight, int NUM)
{
	/***********************
	cal sum of Weight
	***********************/
	int TotalWeight = 0;
	int i;
	for(i = 0; i < NUM; i++){
		TotalWeight += Weight[i];
	}
	
	if(TotalWeight == 0) { return -1; }
	
	/***********************
	random number
	***********************/
	int RandomNumber = rand() % TotalWeight;
	
	/***********************
	define play mode
	***********************/
	int index;
	for(TotalWeight = 0, index = 0; /* */; index++){
		TotalWeight += Weight[index];
		if(RandomNumber < TotalWeight) break;
	}
	
	return index;
}

/******************************
******************************/
bool LIGHT::Is_PeriodOfBlockGroup(BLOCK& Block)
{
	if(Block.Bp_Pattern == NULL)	return true;
	else							return false;
}

/******************************
******************************/
int LIGHT::get_Num_LogicalChs_inThisBlock(BLOCK& Block)
{
	int num;
	for(num = 0; Block.LogicalCh[num].PhysicalCh[0] != -1; num++){
	}
	
	return num;
}

/******************************
******************************/
int LIGHT::get_Num_PhysicalChs_inThisLogicalCh(PHYSICAL_CH_SET& LogicalCh)
{
	int num;
	for(num = 0; num < LogicalCh.MAX_CHS_IN_1LOGICAL_CH && LogicalCh.PhysicalCh[num] != -1; num++){
	}
	
	if(LogicalCh.MAX_CHS_IN_1LOGICAL_CH <= num)	{ ERROR_MSG(); ofExit(); return; }
	
	return num;
}
