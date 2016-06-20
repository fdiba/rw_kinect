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

	ofSetWindowShape(previewWidth, previewHeight);
	//ofSetWindowShape(1920, 1080);
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

	ofBackground(0);

	//ofSetColor(255);
	//kinect.getColorSource()->draw(0, 0, 320, 180);

	//3D view
	camera.begin();

	ofPushStyle();

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

	//printf("test");
	//ofLog("test2 \n");
	int id = 10000;
	//auto v = mesh.getVertices();
	vector<ofPoint> v = mesh.getVertices();

	//ofFile newFile(ofToDataPath("temp.txt")); //file doesn't exist yet
	//newFile.create(); // now file doesn't exist 

	string str = ofToString(v[id][0]);
	
	
	
	for (int i = 1; i < 5; i++) {
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
