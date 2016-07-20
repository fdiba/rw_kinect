import java.util.Date;
import peasy.*;

PeasyCam cam;

String[] params;

//meshes of the selected folder
PShape[] meshes;
int shapeId;
//need to match recording speed
int speed;

String line3_start = "element vertex ";
int[] pointers = {9, 217096};
int coef = 100;

float rotX = radians(180);

boolean pause;

void setup() {

  size(640, 480, P3D);

  background(0);

  speed = 10;

  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(0);
  cam.setMaximumDistance(500);

  params = loadStrings("parameters.txt");
  File dir = new File(params[0]);
  //number of meshes animations
  String[] children = dir.list();
  if (children != null) processMFolder(children[0]);
}
void processMFolder(String folder) {
  //println(folder);
  String path = params[0]+"/"+folder;
  File dir = new File(path);
  String[] fileNames = dir.list();
  //println(fileNames.length);
  if (fileNames != null) processPlyFiles(path, fileNames);
}
void processPlyFiles(String path, String[] files) {

  //create all meshes
  for (int i=0; i<files.length; i++) {

    String ply_path = path+"/"+files[i];
    String[] lines = loadStrings(ply_path);

    //initiate array
    if (i==0) {
      String numberOfPoints = lines[2];
      numberOfPoints= numberOfPoints.substring(line3_start.length());
      //println(numberOfPoints);
      meshes = new PShape[files.length];
    }

    meshes[i] = createShape();
    meshes[i].beginShape(POINTS);
    meshes[i].stroke(255);

    for (int j=pointers[0]; j<=pointers[1]; j++) {
      String[] pos = split(lines[j], ' ');
      if (!pos[0].equals("-inf")) meshes[i].vertex(parseFloat(pos[0])*coef, parseFloat(pos[1])*coef, parseFloat(pos[2])*coef);
    }

    meshes[i].endShape();
  }

  println("all meshes processed");
  
}
void draw() {
  background(0);

  rotateX(rotX);

  if (frameCount%speed==0)editShapeId();

  if (meshes.length>0) shape(meshes[shapeId], 0, 0);
}
void editShapeId() {
  if(!pause)shapeId++;
  if (shapeId>=meshes.length)shapeId=0;
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
  } else if (key == 'p') {
    pause = !pause;
    println("pause:", pause);
  }
}