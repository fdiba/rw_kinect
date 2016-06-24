#pragma once

#include "ofMain.h"
#include "ofxKinectForWindows2.h"
#include "MyThread.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void exit();
		void displayPoC();

		MyThread thread;

		ofxKFW2::Device kinect;

		ofEasyCam			camera;

		ofMesh				mesh;

		void drawJoints3D();

		ofImage     img;

		//vector<ofMesh*> meshPointers;
		vector<ofMesh> meshes;

		boolean recording;
		boolean saving;

		ofTrueTypeFont myfont;

		int framesMax;
};
