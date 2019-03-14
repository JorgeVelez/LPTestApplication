#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(255, 255, 255);
	ofSetColor(0, 0, 0);

	//states
	doAskNextQuestion = false;
	doDrawButtons = false;

	//counters
	currentQuestionIndex = -1;

	//data manager
	dataHandler.setup();
	ofAddListener(dataHandler.onResultInitial, this, &ofApp::onInitialResponseHandler);
	ofAddListener(dataHandler.onResultstoreResponse, this, &ofApp::onResultstoreResponseHandler);

	dataHandler.getQuestionsDataAndConfig();

	//snapshotManager
	snapShotManager.setup();	

	//buttons
	yesButton.setSize(80, 40);
	ofPoint pos = ofPoint(ofGetWidth() * 0.5f-100, ofGetHeight() * 0.5f);
	yesButton.setPosition(pos);
	yesButton.setBorderColor(ofColor::black);
	yesButton.setHighlightColor(ofColor(150, 150, 150));
	yesButton.setLabelColor(ofColor::black);
	ofFile fontPath = ofFile("fonts/Verdana.ttf");
	yesButton.loadFont(fontPath.getAbsolutePath(), 14, "YES");

	noButton.setSize(80, 40);
	pos = ofPoint(ofGetWidth() * 0.5f+100, ofGetHeight() * 0.5f);
	noButton.setPosition(pos);
	noButton.setBorderColor(ofColor::black);
	noButton.setHighlightColor(ofColor(150, 150, 150));
	noButton.setLabelColor(ofColor::black);
	noButton.loadFont(fontPath.getAbsolutePath(), 14, "NO");

	//type
	verdana30.load("fonts/Verdana.ttf", 30, true, true);
	verdana30.setLineHeight(34.0f);
	verdana30.setLetterSpacing(1.035);
	verdana30.alig
}

//--------------------------------------------------------------
void ofApp::update(){
	snapShotManager.update();

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	snapShotManager.draw();

	dataHandler.draw();

	//ofDrawBitmapString(responseStr, 20, 60);
	ofSetColor(ofColor::black);
	verdana30.drawString(currentQuestion, 200, 300);

	if (doDrawButtons) {
		yesButton.draw();
		noButton.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
}

//--------------------------------------------------------------
void ofApp::onInitialResponseHandler(ofxJSONElement & data) {
	
	localData = data;
	databaseRowIndex = localData["index"].asString();
	
	responseStr += "got index assigned\n";

	std::size_t numImages = MIN(99, localData["data"].size());
	for (Json::ArrayIndex i = 0; i < numImages; ++i)
		numQuestions++;

	ofLog(OF_LOG_NOTICE, "numQuestions " + ofToString(numQuestions));

	askNextQuestion();

	doDrawButtons = true;
}

//--------------------------------------------------------------
void ofApp::onResultstoreResponseHandler(ofxJSONElement & data) {

}

//--------------------------------------------------------------
void ofApp::askNextQuestion() {
	currentQuestionIndex++;

	if (currentQuestionIndex<numQuestions) {
		currentQuestion = localData["data"][currentQuestionIndex]["question"].asString();
	}
	else {
		currentQuestion = "Questions are over";
		doDrawButtons = false;
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
void ofApp::mousePressed(int x, int y, int button) {

	if (doDrawButtons) {
		yesButton.triggerOn(x, y);

		if (yesButton.getIsPressed()) {

			askNextQuestion();
			snapShotManager.SaveImage();
		}

		noButton.triggerOn(x, y);

		if (noButton.getIsPressed()) {

			askNextQuestion();
			snapShotManager.SaveImage();
		}
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

	yesButton.triggerOff();
	noButton.triggerOff();
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
