/************************************************************
************************************************************/
#include "ofApp.h"

#include <time.h>

/************************************************************
************************************************************/

/******************************
******************************/
ofApp::ofApp(int _BootMode)
: Osc_MusicPlayer("127.0.0.1", 12348, 12352)
, b_NoUdpMessageYet(true)
{
	srand((unsigned) time(NULL));
	
	BootMode = (BOOT_MODE)(_BootMode);
}

/******************************
******************************/
ofApp::~ofApp()
{
}

/******************************
******************************/
void ofApp::exit()
{
	Light.exit();
	
	printf("\n> Good bye\n");
}

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	font.loadFont("RictyDiminished-Regular.ttf", 15);
	
	/********************
	********************/
	ofSetWindowTitle("DMX");
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	ofSetWindowShape(WIDTH, HEIGHT);
	ofSetEscapeQuitsApp(false);
	
	/*
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	// ofEnableSmoothing();
	*/
	
	/********************
	********************/
	udpConnection.Create();
	udpConnection.Bind(UDP_RECEIVE_PORT);
	udpConnection.SetNonBlocking(true);
	
	/********************
	********************/
	Light.setup();
	
	/********************
	********************/
	Gui_Param = new GUI_PARAM;
	Gui_Param->setup("Param", "gui.xml", 10, 80);
}

/******************************
******************************/
void ofApp::update_OscFrom_MusicPlayer()
{
	while(Osc_MusicPlayer.OscReceive.hasWaitingMessages()){
		ofxOscMessage m_receive;
		Osc_MusicPlayer.OscReceive.getNextMessage(&m_receive);
		
		if(m_receive.getAddress() == "/Quit"){
			ofExit();
			return;
			// std::exit(1);
			
		}else if(m_receive.getAddress() == "/MusicTime"){
			MusicTime = m_receive.getArgAsInt32(0);
		}
	}
}

/******************************
******************************/
void ofApp::RefreshVerts()
{
	const float ofs_y = 60;
	const float height = 3;
	float Width_fft = ofMap(fft_Gain[1], 0, Gui_Param->fftGain_Range, 0, ofGetWidth());
	
	/********************
	1-2
	0-3
	********************/
	VboVerts[0].set(ofVec3f(ofGetWidth() * 0/3, ofs_y + height + 1, 0));
	VboVerts[1].set(ofVec3f(ofGetWidth() * 0/3, ofs_y - 1, 0));
	VboVerts[2].set(ofVec3f(ofGetWidth() * 1/3, ofs_y - 1, 0));
	VboVerts[3].set(ofVec3f(ofGetWidth() * 1/3, ofs_y + height + 1, 0));
	
	VboVerts[4].set(ofVec3f(ofGetWidth() * 1/3, ofs_y + height + 1, 0));
	VboVerts[5].set(ofVec3f(ofGetWidth() * 1/3, ofs_y - 1, 0));
	VboVerts[6].set(ofVec3f(ofGetWidth() * 2/3, ofs_y - 1, 0));
	VboVerts[7].set(ofVec3f(ofGetWidth() * 2/3, ofs_y + height + 1, 0));
	
	VboVerts[8].set(ofVec3f(ofGetWidth() * 2/3, ofs_y + height + 1, 0));
	VboVerts[9].set(ofVec3f(ofGetWidth() * 2/3, ofs_y - 1, 0));
	VboVerts[10].set(ofVec3f(ofGetWidth() * 3/3, ofs_y - 1, 0));
	VboVerts[11].set(ofVec3f(ofGetWidth() * 3/3, ofs_y + height + 1, 0));
	
	VboVerts[12].set(ofVec3f(0, ofs_y + height, 0));
	VboVerts[13].set(ofVec3f(0, ofs_y, 0));
	VboVerts[14].set(ofVec3f(Width_fft, ofs_y, 0));
	VboVerts[15].set(ofVec3f(Width_fft, ofs_y + height, 0));
}

/******************************
******************************/
void ofApp::Refresh_BarColor()
{
	for(int i = 0; i < NUM_FFT_VERTS/4; i++){
		VboColor[i].set(0.0, 0.0, 1.0, 0.3);
	}
	for(int i = NUM_FFT_VERTS/4; i < NUM_FFT_VERTS*2/4; i++){
		VboColor[i].set(0.0, 1.0, 0.0, 0.3);
	}
	for(int i = NUM_FFT_VERTS*2/4; i < NUM_FFT_VERTS*3/4; i++){
		VboColor[i].set(1.0, 0.0, 0.0, 0.3);
	}
	for(int i = NUM_FFT_VERTS * 3/4; i < NUM_FFT_VERTS*4/4; i++){
		VboColor[i].set(1.0, 1.0, 1.0, 0.5);
	}
}

/******************************
******************************/
void ofApp::setup_on_1stMessage()
{
	if(b_NoUdpMessageYet){
		/********************
		********************/
		b_NoUdpMessageYet = false;
		
		/********************
		********************/
		fft_Gain.resize(N);
		AudioSample_Rev.resize(N);
		
		/********************
		********************/
		for(int i = 0; i < fft_Gain.size(); i++)			fft_Gain[i] = 0;
		for(int i = 0; i < AudioSample_Rev.size(); i++)		AudioSample_Rev[i] = 0;
		
		RefreshVerts();
		Refresh_BarColor();
		
		/********************
		********************/
		Vbo.setVertexData(VboVerts, NUM_FFT_VERTS, GL_DYNAMIC_DRAW);
		Vbo.setColorData(VboColor, NUM_FFT_VERTS, GL_DYNAMIC_DRAW);
	}
}

/******************************
******************************/
void ofApp::update_UdpFrom_Analyzer()
{
	/********************
	********************/
	char udpMessage[SIZE_UPD];
	udpConnection.Receive(udpMessage,SIZE_UPD);
	string message=udpMessage;
	if(message!=""){
		vector<string> params = ofSplitString(message, "</p>");
		
		vector<string> _AudioSample_Rev = ofSplitString(params[0], ",");
		vector<string> _fft_Gain = ofSplitString(params[1], ",");
		
		if(b_NoUdpMessageYet){
			N = _AudioSample_Rev.size() - 1; // "0" is added at last value.
			printf("\n> UseFftResult\n");
			printf("N = %d\n", N);
			
			setup_on_1stMessage();
		}
		
		for(int i = 0; i < N; i++){
			AudioSample_Rev[i] = atof(_AudioSample_Rev[i].c_str());
			fft_Gain[i] = atof(_fft_Gain[i].c_str());
		}
		
		while(message != ""){
			udpConnection.Receive(udpMessage,SIZE_UPD);
			message = udpMessage;
		}
	}

	/********************
	********************/
	if(b_NoUdpMessageYet == false){
		/********************
		********************/
		RefreshVerts();
		Refresh_BarColor();
		
		/********************
		以下は、audioOutからの呼び出しだと segmentation fault となってしまった.
		********************/
		Vbo.updateVertexData(VboVerts, NUM_FFT_VERTS);
		Vbo.updateColorData(VboColor, NUM_FFT_VERTS);
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	/********************
	********************/
	ElapsedTime = ofGetElapsedTimef();
	
	/********************
	********************/
	update_OscFrom_MusicPlayer();
	update_UdpFrom_Analyzer();
	
	/********************
	********************/
	if(b_NoUdpMessageYet == false){
		Light.update(fft_Gain[1]);
	}
}

/******************************
******************************/
void ofApp::draw_time()
{
	/********************
	********************/
	char buf[BUF_SIZE];
	
	if(MusicTime == -1){
		sprintf(buf, "--STOP--");
		
	}else{
		int min	= MusicTime / 1000 / 60;
		int sec	= MusicTime / 1000 - min * 60;
		int ms	= MusicTime % 1000;
		
		sprintf(buf, "%6d:%6d:%6d (%6.1f)", min, sec, ms, ofGetFrameRate());
	}
	
	
	/********************
	********************/
	// ofSetColor(255, 255, 255);
	ofSetColor(180);
	
	font.drawString(buf, 10, 40);
	
	/********************
	********************/
	Gui_Param->gui.draw();
}

/******************************
******************************/
void ofApp::draw_fftBar()
{
	ofPushStyle();
	
	ofEnableAlphaBlending();
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	
	if(b_NoUdpMessageYet == false){
		glPointSize(1.0);
		glLineWidth(1);
		
		Vbo.draw(GL_QUADS, 0, NUM_FFT_VERTS);
	}
	
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	ofBackground(30);
	ofSetColor(255);
	
	/********************
	********************/
	if(BootMode == BOOT_MODE__TEST){
		Light.draw();
		
	}else if(b_NoUdpMessageYet == false){
		Light.draw();
		draw_fftBar();
	}
	
	/********************
	********************/
	draw_time();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key){
		case 'r':
		case 't':
		case 'y':
		case 'u':
			Light.setEvent_AnimationChange(MusicTime, STATE_FFT);
			break;
			
		case 'f':
			Light.setEvent_AnimationChange(MusicTime, STATE_NORMAL);
			break;
			
		case 'j':
			Light.setEvent_AnimationChange(MusicTime, STATE_SPEED);
			break;
			
		case 'b':
			Light.setEvent_AnimationChange(MusicTime, STATE_BEAT);
			break;
			
		case ' ':
			Light.setEvent_AnimationChange(MusicTime, STATE_OFF);
			break;
			
		case 'o':
			Light.setEvent_AnimationChange(MusicTime, STATE_ON);
			break;
			
		case OF_KEY_RETURN:
			Light.setEvent_AnimationChange(MusicTime, STATE_STROBE);
			break;
			
		case 'c':
			Light.setEvent_ColorChange(MusicTime);
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
