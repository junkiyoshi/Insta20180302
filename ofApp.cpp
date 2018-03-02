#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(230);
	ofSetWindowTitle("Insta");

	ofNoFill();
	ofSetLineWidth(2);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float radius = 350;

	for (int i = 0; i < 10; i++) {

		ofRotate(1.5);
		ofBeginShape();
		for (int deg = 0; deg <= 360; deg += 1) {

			float x = radius * cos(deg * DEG_TO_RAD);
			float y = radius * sin(deg * DEG_TO_RAD);

			if (deg % 15 == 0) {

				this->noise_value = ofNoise(i, x * 0.005, y * 0.005, ofGetFrameNum() * 0.005);
			}

			x = (radius * noise_value) * cos(deg * DEG_TO_RAD);
			y = (radius * noise_value) * sin(deg * DEG_TO_RAD);

			ofVertex(x, y);
		}
		ofEndShape();
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}