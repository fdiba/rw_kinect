import java.util.Date;
import peasy.*;

PeasyCam cam;

String[] params;
PVector[][] meshes;
String line3_start = "element vertex ";
int[] pointers = {9, 217096};
int coef = 100;

void setup() {
  
  size(640, 480, OPENGL);
  
  background(0);
  
  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(50);
  cam.setMaximumDistance(500);
  
  params = loadStrings("parameters.txt");
  File dir = new File(params[0]);
  String[] children = dir.list();
  if (children != null) processMFolder(children[0]);
}
void processMFolder(String folder) {
  println(folder);
  String path = params[0]+"/"+folder;
  File dir = new File(path);
  String[] ply_files = dir.list();
  if (ply_files != null) processPlyFiles(path, ply_files);
}
void processPlyFiles(String path, String[] files) {

  //println(files.length);

  for (int i=0; i<files.length; i++) {

    String ply_path = path+"/"+files[i];
    String[] lines = loadStrings(ply_path);

    if (i==0) {
      String numberOfPoints = lines[2];
      numberOfPoints= numberOfPoints.substring(line3_start.length());
      println(numberOfPoints);
      meshes = new PVector[files.length][parseInt(numberOfPoints)];
      println(meshes.length);
    }

    for (int j=pointers[0]; j<=pointers[1]; j++) {

      String[] pos = split(lines[j], ' ');
      if (!pos[0].equals("-inf")) {
        meshes[i][j-pointers[0]] = new PVector(parseFloat(pos[0])*coef, parseFloat(pos[1])*coef, parseFloat(pos[2])*coef);
      }
    }
  }

  println("done");
}
void draw() {
  
  background(0);
  fill(255);
  stroke(255);
  
  if (meshes.length>0) {

    for (PVector v : meshes[0]) {

      if (v!=null) {
        //println(v.x);
        
        pushMatrix();
        translate(v.x, v.y, v.z);
        point(0, 0);
        //ellipse(0, 0, 1, 1);
        
        popMatrix();
        
      }
    }
  }
}

void saveIMG() {
  Date date = new Date();
  String name = "data/img/ply_render-" + date.getTime() + ".jpg";
  save(name);
}

//------------------------- keyboard -------------------------//
void keyPressed() {
  
  if (key == 's') {
    saveIMG();
  } 
  
}