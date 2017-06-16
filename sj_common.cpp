/************************************************************
************************************************************/
#include "sj_common.h"

/************************************************************
************************************************************/
/********************
printf("%f\n", FLT_MAX);
> 340282346638528859811704183484516925440.000000
で1ヶ月の展示には十分.
********************/
float ElapsedTime;
int MusicTime = -1;

BOOT_MODE BootMode;
GUI_PARAM* Gui_Param;

/************************************************************
************************************************************/
static FILE* fp_Log[NUM_THREAD_TIMETABLE];



/************************************************************
************************************************************/

/******************************
******************************/
void GUI_PARAM::setup(string GuiName, string FileName, float x, float y)
{
	/********************
	********************/
	gui.setup(GuiName.c_str(), FileName.c_str(), x, y);
	
	/********************
	********************/
	gui.add(Alpha_FixedLed.setup("Alpha_FixedLed", 255, 0, 255));
	
	gui.add(fftGain_Range.setup("fftGain_Range", 0.015, 0, 0.2));
	
	/********************
	********************/
	GuiGroup_Test.setup("Connection Test");
	GuiGroup_Test.add(LedId.setup("LedId", 0, 0, 20));
	{
		ofColor initColor = ofColor(0, 0, 0, 255);
		ofColor minColor = ofColor(0, 0, 0, 0);
		ofColor maxColor = ofColor(255, 255, 255, 255);
		
		GuiGroup_Test.add(TestColor.setup("color", initColor, minColor, maxColor));
	}
	gui.add(&GuiGroup_Test);
}

/******************************
******************************/
void fopen_LogFile()
{
	for(int i = 0; i < NUM_THREAD_TIMETABLE; i++){
		char FileName[BUF_SIZE];
		sprintf(FileName, "../../../data/Log_%d.csv", i);
		
		fp_Log[i] = fopen(FileName, "w");
		if(fp_Log[i] == NULL)	{ ERROR_MSG(); std::exit(1); }
	}
}

/******************************
******************************/
void fclose_LogFile()
{
	for(int i = 0; i < NUM_THREAD_TIMETABLE; i++){
		if(fp_Log[i]) fclose(fp_Log[i]);
	}
}

/******************************
******************************/
void fprint_debug_Log(char* message, int FileId)
{
/*
	if(NUM_THREAD_TIMETABLE <= FileId)	{ ERROR_MSG(); std::exit(1); }
	
	
	if(FileId == -1){
		for(int i = 0; i < NUM_THREAD_TIMETABLE; i++){
			fprintf(fp_Log[i], "%s", message);
		}
	}else{
		fprintf(fp_Log[FileId], "%s", message);
	}
*/
}

