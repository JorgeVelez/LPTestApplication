#include "DataHandler.h"
DataHandler::DataHandler() {

}

void DataHandler::setup() {

	action_url = "http://thisisnotanumber.org/lp-test/getData.php";
	ofAddListener(httpUtils.newResponseEvent, this, &DataHandler::newResponse);
	httpUtils.start();

}

void DataHandler::update() {

}

void DataHandler::getQuestionsDataAndConfig() {
	ofxHttpForm form;
	form.action = action_url;
	form.method = OFX_HTTP_POST;
	form.addFormField("command", "getQuestions");
	form.addFormField("user", ofToString(counter));
	httpUtils.addForm(form);
	requestStr = "message sent: " + ofToString(counter);
	counter++;

	webServiceCalled = "initial";
}
	
void DataHandler::storeResponse() {
	ofxHttpForm form;
	form.action = action_url;
	form.method = OFX_HTTP_POST;
	form.addFormField("command", "setResponse");
	form.addFormField("question", "1");
	form.addFormField("response", "121");
	form.addFormField("question", "3");
	httpUtils.addForm(form);
	requestStr = "message sent: " + ofToString(counter);
	counter++;

	webServiceCalled = "storeResponse";

}

//--------------------------------------------------------------
void DataHandler::newResponse(ofxHttpResponse & response) {
	responseStr = ofToString(response.status) + ": " + (string)response.responseBody;
	result.parse((string)response.responseBody);
	responseStr =result["index"].asString();
	

	if (webServiceCalled == "initial")
		ofNotifyEvent(onResultInitial, result);

	if (webServiceCalled == "storeResponse")
		ofNotifyEvent(onResultstoreResponse, result);

}

void DataHandler::draw() {
	//ofDrawBitmapString(requestStr, 20, 20);
	//ofDrawBitmapString(responseStr, 20, 60);
}