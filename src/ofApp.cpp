#include "ofApp.h"

int previewWidth = 1024;
int previewHeight = 768;

ofImage image;

//--------------------------------------------------------------
void ofApp::setup(){

	kinect.open();

	kinect.initDepthSource();
	kinect.initColorSource();
	kinect.initBodySource();

	//kinect.initInfraredSource();

	camera.setDistance(10);

	ofSetWindowShape(previewWidth, previewHeight);
	//ofSetWindowShape(1920, 1080);
	//ofSetWindowShape(previewWidth * 2, previewHeight * 2);

	//mesh.disableTextures();
	//mesh.disableNormals();

}

//--------------------------------------------------------------
void ofApp::update(){
	
	kinect.update();

	/*mesh = kinect.getDepthSource()->getMesh(false,
		ofxKinectForWindows2::Source::Depth::PointCloudOptions::TextureCoordinates::ColorCamera);*/

	mesh = kinect.getDepthSource()->getMesh(false,
		ofxKinectForWindows2::Source::Depth::PointCloudOptions::ColorCamera);

	/*if (kinect.isFrameNew()) {

		//auto depth = kinect.getDepthSource();

	}*/

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//kinect.getDepthSource()->draw(0, 0, previewWidth, previewHeight);
	//kinect.getColorSource()->draw(previewWidth, 0, previewWidth, previewHeight);
	//kinect.getInfraredSource()->draw(0, 0, previewWidth, previewHeight);

	ofBackground(0);

	ofSetColor(0);
	ofDrawRectangle(0, 0, previewWidth, previewHeight);
	//kinect.getColorSource()->draw(0, 0, 320, 180);

	ofSetColor(255);

	//3D view
	
	camera.begin();

	ofPushStyle();

	ofScale(10, 10, -10);

	mesh.draw();

	drawJoints3D();

	ofPopStyle();

	camera.end();

	

}
void ofApp::drawJoints3D(){

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 's') {
		
		//img.clear();

		string str2 = "rw_kinect" + ofGetTimestampString() + ".jpg";

		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		
		img.save(str2);
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

	//mesh.save("mesh.ply");

	//printf("test");
	//ofLog("test2 \n");
	int id = 10000;
	//auto v = mesh.getVertices();

	//mesh.clearTexCoords();

	vector<ofPoint> v = mesh.getVertices();

	//ofFile newFile(ofToDataPath("temp.txt")); //file doesn't exist yet
	//newFile.create(); // now file doesn't exist 

	string str = ofToString(v[id][0]);
	
	
	
	for (int i = 1; i < 5; i++) { //TODO SAVE MESH TO VECTOR MESH
		str = str + ", " + ofToString(v[id][0]);

	}

	ofBuffer msg(str.c_str(), str.length());
	ofBufferToFile("out.txt", msg);
	
	std::cout << 640 * 480 << " v size: " << v.size() << endl;

	//mesh.removeTexCoord();

	std::cout << 640 * 480 << " getVertex: " << mesh.getVertex(id) << endl;
	
	
	std::cout << 640 * 480 << " getNumColors: " << mesh.getNumColors() << endl;
	std::cout << 640 * 480 << " getNumIndices: " << mesh.getNumIndices() << endl;

	std::cout << 640 * 480 << " getNumNormals: " << mesh.getNumNormals() << endl;

	std::cout << 640 * 480 << " getNumTexCoords: " << mesh.getNumTexCoords() << endl; //307200 217088

	std::cout << 640 * 480 << " getNumVertices: " << mesh.getNumVertices() << endl; //307200 217088

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
