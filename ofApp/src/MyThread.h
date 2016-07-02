#include "ofMain.h" 

class MyThread : public ofThread {

	public:

	void MyThread::threadedFunction() {

		while (isThreadRunning()) {

			if (exporting) {
				

				if(t_meshes.size()>0){
					//t_meshes.clear();
					

					for (int i = 0; i < t_meshes.size(); i++) {

						string str3 = "mesh-" + ofGetTimestampString() + ".ply";
						ofMesh m = t_meshes[i];
						m.save(str3);

					}

					std::cout << "t meshes size : " << t_meshes.size() << endl;

					std::cout << "exporting done " << endl; //TODO EDIT STATUS MAIN APPLICATION

					//TO clear mesh
					exporting = false;
					

				}

				
				
				
			}
			/*if (saving) {


			}*/

			/*std::cout << "meshes size : " << meshes.size() << endl;
			exportMeshes();
			saving = false;
			meshes.clear();
			std::cout << "meshes size : " << meshes.size() << endl;*/

		}

	}
	
	boolean exporting;
	vector<ofMesh> t_meshes;
	//ofImage image;
};