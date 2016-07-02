import java.util.Date;
import peasy.*;

PeasyCam cam;

String[] params;

PShape[] shapes;

String line3_start = "element vertex ";
int[] pointers = {9, 217096};
int coef = 100;

float rotX = radians(180);

void setup() {

  size(640, 480, P3D);

  background(0);

  cam = new PeasyCam(this, 100);
  cam.setMinimumDistance(0);
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

  for (int i=0; i<files.length; i++) {

    String ply_path = path+"/"+files[i];
    String[] lines = loadStrings(ply_path);

    if (i==0) {
      String numberOfPoints = lines[2];
      numberOfPoints= numberOfPoints.substring(line3_start.length());
      println(numberOfPoints);

      shapes = new PShape[files.length];
    }

    shapes[i] = createShape();
    shapes[i].beginShape(POINTS);
    shapes[i].stroke(255);

    for (int j=pointers[0]; j<=pointers[1]; j++) {

      String[] pos = split(lines[j], ' ');
      if (!pos[0].equals("-inf")) {

        shapes[i].vertex(parseFloat(pos[0])*coef, parseFloat(pos[1])*coef, parseFloat(pos[2])*coef);
      }
    }

    shapes[i].endShape();
  }

  println("done");
}
void draw() {
  background(0);
  
  rotateX(rotX);
  
  if (shapes.length>0) shape(shapes[0], 0, 0);
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