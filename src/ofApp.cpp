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

	//mesh.disableTextures();
	//mesh.disableNormals();

	myfont.loadFont("arial.ttf", 12);

	framesMax = 10;

}

//--------------------------------------------------------------
void ofApp::update(){
	
	kinect.update();

	/*mesh = kinect.getDepthSource()->getMesh(false,
		ofxKinectForWindows2::Source::Depth::PointCloudOptions::TextureCoordinates::ColorCamera);*/

	mesh = kinect.getDepthSource()->getMesh(false,
		ofxKinectForWindows2::Source::Depth::PointCloudOptions::ColorCamera);

	if (kinect.isFrameNew() && recording) {

		if(ofGetFrameNum() % 10 == 0){
			std::cout << "meshes size : " << meshes.size() << endl;
			if (meshes.size()<framesMax) meshes.push_back(mesh);
			else if (meshes.size() >= framesMax)recording = false;
		
		}
	}

	/*if (kinect.isFrameNew()) {

		//auto depth = kinect.getDepthSource();

	}*/

	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);

	//ofSetColor(0);
	//ofDrawRectangle(0, 0, previewWidth, previewHeight);


	if (recording) {
		ofSetColor(255, 0, 0);
		myfont.drawString("recording", 10, 20);
		displayPoC();
	}
	else if (saving) {

		ofSetColor(255, 0, 0);
		myfont.drawString("saving", 10, 20);
		
		std::cout << "meshes size : " << meshes.size() << endl;
		exportMeshes();
		saving = false;
		meshes.clear();
		std::cout << "meshes size : " << meshes.size() << endl;

	}
	else {
		displayPoC();
	}
	
	//kinect.getDepthSource()->draw(0, 0, previewWidth, previewHeight);
	//kinect.getColorSource()->draw(previewWidth, 0, previewWidth, previewHeight);
	//kinect.getInfraredSource()->draw(0, 0, previewWidth, previewHeight);

	//kinect.getColorSource()->draw(0, 0, 320, 180);

}
void ofApp::displayPoC() {

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
void ofApp::exportMeshes() {

	for (int i = 0; i < meshes.size(); i++) {

		string str3 = "mesh-" + ofGetTimestampString() + ".ply";
		ofMesh m = meshes[i];
		m.save(str3);

	}

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == 's') {

		string str2 = "rw_kinect" + ofGetTimestampString() + ".jpg";

		img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());

		img.save(str2);
	}
	else if (key == 'x') { //export meshes
		saving = true;
	} 
	else if (key == 'r') {

		recording = !recording;

		//meshes.push_back(mesh);

		//std::cout << "meshPointers size : " << meshes.size() << endl;

	} else if (key == 'm') {

		int id = 10000;
		vector<ofPoint> v = mesh.getVertices();

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
	
	//auto v = mesh.getVertices();

	//mesh.clearTexCoords();

	

	//ofFile newFile(ofToDataPath("temp.txt")); //file doesn't exist yet
	//newFile.create(); // now file doesn't exist 

	

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
