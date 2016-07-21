import java.util.Date;
import peasy.*;

PeasyCam cam;

String[] params;

//meshes of the selected folder
PShape[] meshes;
int shapeId;
//need to match recording speed
int speed;
float depthThreshold;

String line3_start = "element vertex ";
int[] pointers = {9, 217096};
int coef = 100;

float rotX = radians(180);

boolean pause;

PVector[] vectors;

void setup() {

  size(640, 480, P3D);

  background(0);

  speed = 10;
  depthThreshold =.9;

  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(-100);
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

    //initiate meshes array
    if (i==0) {
      String numberOfPoints = lines[2];

      numberOfPoints = numberOfPoints.substring(line3_start.length());

      //initiate vectors array
      vectors = new PVector[parseInt(numberOfPoints)];
      for (int k=0; k<vectors.length; k++) {
        vectors[k] = new PVector(random(-800, 800), random(-800, 800), random(-800, 800));
      }
      //println(vectors.length);

      meshes = new PShape[files.length];
    }

    meshes[i] = createShape();
    meshes[i].beginShape(POINTS);
    meshes[i].stroke(255);

    for (int j=pointers[0]; j<=pointers[1]; j++) {
      String[] pos = split(lines[j], ' ');

      //add depth threshold and remove -inf 
      if (!pos[0].equals("-inf") && parseFloat(pos[2])<depthThreshold) {
        meshes[i].vertex(parseFloat(pos[0])*coef, parseFloat(pos[1])*coef, parseFloat(pos[2])*coef);
      }
    }

    meshes[i].endShape();
  }

  println("all meshes processed");
}
void draw() {
  background(0);

  rotateX(rotX);

  animateAndDisplayVectorsBasedOn(meshes[shapeId]);
  
}
void animateAndDisplayVectorsBasedOn(PShape shape) {

  //---------- update
  for (int i=0; i<shape.getVertexCount(); i++) {

    PVector v = shape.getVertex(i);

    PVector dist = PVector.sub(v, vectors[i]);
    dist.mult(.3);

    vectors[i].add(dist);
  }

  //------- display
  stroke(255);

  beginShape(POINTS);
  for (int j=0; j<shape.getVertexCount(); j++) {
    vertex(vectors[j].x, vectors[j].y, vectors[j].z);
  }
  endShape();
}
void editShapeId() {
  if (!pause)shapeId++;
  if (shapeId>=meshes.length)shapeId=0;
}
void saveIMG() {
  Date date = new Date();
  String name = "data/img/pbm-" + date.getTime() + ".jpg";
  save(name);
}
//------------------------- keyboard -------------------------//
void mousePressed() {
  //if (meshes.length>0)println(meshes[0].getVertexCount());
}
//------------------------- keyboard -------------------------//
void keyPressed() {

  if (key == 's') {
    saveIMG();
  } else if (key == 't') {
    editShapeId();
    println("shapeId:", shapeId);
  } else if (key == ' ') {
    pause = !pause;
    println("pause:", pause);
  }
}