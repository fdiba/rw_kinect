#include "ofApp.h"

int previewWidth = 640;
int previewHeight = 480;

//--------------------------------------------------------------
void ofApp::setup(){

	kinect.open();
	kinect.initDepthSource();
	kinect.initColorSource();
	//kinect.initInfraredSource();

	ofSetWindowShape(previewWidth * 2, previewHeight * 2);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	kinect.getDepthSource()->draw(0, 0, previewWidth, previewHeight);
	kinect.getColorSource()->draw(previewWidth, 0, previewWidth, previewHeight);
	//kinect.getInfraredSource()->draw(0, 0, previewWidth, previewHeight);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
