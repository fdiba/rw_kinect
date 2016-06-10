#include "ofApp.h"

int previewWidth = 640;
int previewHeight = 480;

ofImage image;

//--------------------------------------------------------------
void ofApp::setup(){

	kinect.open();
	kinect.initDepthSource();
	kinect.initColorSource();

	kinect.initBodySource();

	//kinect.initInfraredSource();

	camera.setDistance(10);

	ofSetWindowShape(1920, 1080);
	//ofSetWindowShape(previewWidth * 2, previewHeight * 2);


}

//--------------------------------------------------------------
void ofApp::update(){
	
	kinect.update();

	mesh = kinect.getDepthSource()->getMesh(false,
		ofxKinectForWindows2::Source::Depth::PointCloudOptions::TextureCoordinates::ColorCamera);

	/*if (kinect.isFrameNew()) {

		//auto depth = kinect.getDepthSource();

		

	}*/

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//kinect.getDepthSource()->draw(0, 0, previewWidth, previewHeight);
	//kinect.getColorSource()->draw(previewWidth, 0, previewWidth, previewHeight);
	//kinect.getInfraredSource()->draw(0, 0, previewWidth, previewHeight);

	// SETTING THE BACKGROUND A MUTED BLUE
	ofBackground(75, 95, 115);

	// DRAW THE COLOR CAMERA TO MAKE SURE THE KINECT IS WORKING
	//ofSetColor(255);
	//kinect.getColorSource()->draw(0, 0, 320, 180);

	// WE ARE NOW SWITCHING TO THE 3D VIEW
	camera.begin();

	ofPushStyle();
	// FOR THIS MESH, I SCALED THE Z NEGATIVE TO MATCH DEPTH
	// THIS IS DEVELOPER PREFERENCE, BUT IT'S HOW I CONCEIVE
	// THE MESH...
	ofScale(10, 10, -10);

	mesh.draw();

	ofPopStyle();

	camera.end();
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
