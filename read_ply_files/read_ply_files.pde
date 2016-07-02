String[] params;
PVector[][] meshes;
String line3_start = "element vertex ";


void setup() {
  params = loadStrings("parameters.txt");
  File dir = new File(params[0]);
  String[] children = dir.list();
  if (children != null) processMFolder(children[0]);
}
void processMFolder(String folder){
  println(folder);
  String path = params[0]+"/"+folder;
  File dir = new File(path);
  String[] ply_files = dir.list();
  if (ply_files != null) processPlyFiles(path, ply_files);
}
void processPlyFiles(String path, String[] files){
  
  //println(files.length);
  
  for(int i=0; i<files.length; i++){

    String ply_path = path+"/"+files[i];
    String[] lines = loadStrings(ply_path);
    
    if(i==0){
      String numberOfPoints = lines[2];
      numberOfPoints= numberOfPoints.substring(line3_start.length());
      println(numberOfPoints);
      meshes = new PVector[files.length][parseInt(numberOfPoints)];
      println(meshes.length);
    }
    
  }
  
}
void draw() {
}