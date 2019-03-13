#include "SnapShotManager.h"
SnapShotManager::SnapShotManager() {

}

void SnapShotManager::setup() {
	camWidth = 320;
	camHeight = 180;

	bSnapshot = false;
	showCam = false;

	imageCounter = 0;

	vector<ofVideoDevice> devices = vidGrabber.listDevices();

	for (int i = 0; i < devices.size(); i++) {
		if (devices[i].bAvailable) {
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
		}
		else {
			ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
		}
	}

	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);

	videoInverted.allocate(camWidth, camHeight, OF_PIXELS_RGB);
	videoTexture.allocate(videoInverted);

	if (ofIsGLProgrammableRenderer()) {
		shaderBlurX.load("shadersGL3/shaderBlurX");
		shaderBlurY.load("shadersGL3/shaderBlurY");
	}
	else {
		shaderBlurX.load("shadersGL2/shaderBlurX");
		shaderBlurY.load("shadersGL2/shaderBlurY");
	}

	fboBlurOnePass.allocate(camWidth, camHeight);
	fboBlurTwoPass.allocate(camWidth, camHeight);

}

void SnapShotManager::update() {
	vidGrabber.update();

	if (ofGetElapsedTimeMillis() - timerSnapshot > 5000) {
		showCam = false;
	}
}

//--------------------------------------------------------------
void SnapShotManager::draw() {

	if (showCam) {
		img.setFromPixels(vidGrabber.getPixels());

		float blur = 5;

		//----------------------------------------------------------
		fboBlurOnePass.begin();

		shaderBlurX.begin();
		shaderBlurX.setUniform1f("blurAmnt", blur);

		img.draw(0, 0);

		shaderBlurX.end();

		fboBlurOnePass.end();

		//----------------------------------------------------------
		fboBlurTwoPass.begin();

		shaderBlurY.begin();
		shaderBlurY.setUniform1f("blurAmnt", blur);

		fboBlurOnePass.draw(0, 0);

		shaderBlurY.end();

		fboBlurTwoPass.end();

		//----------------------------------------------------------
		ofSetColor(ofColor::white);
		fboBlurTwoPass.draw(0, 0);
	}
	if (bSnapshot == true) {
		
		imgToSave.grabScreen(0, 0, 320, 180);

		string fileName = "snapshot_HD_"+ofToString( imageCounter) +".png";
		imgToSave.save(fileName);

		fileName = "snapshot_VGA_" + ofToString(imageCounter) + ".png";
		imgToSave.resize(160,90);
		imgToSave.save(fileName);
		bSnapshot = false;

		imageCounter++;
	}
}

//--------------------------------------------------------------
void SnapShotManager::SaveImage( ) {
		bSnapshot = true;
		showCam = true;

		timerSnapshot = ofGetElapsedTimeMillis();
}
