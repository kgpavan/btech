import java.io.*;
import static java.lang.Math.*;

class  Cylinder {
public static void main(String args[]) {

float pi=3.1415f;
float radius,height,volume,surfacearea,outerarea;
String radiuss,heights;
radius=height=volume=surfacearea=outerarea=0.0f;

try{

DataInputStream in;
in = new DataInputStream(System.in);


System.out.println("Please Enter the radius");
radiuss = in.readLine();
radius = Float.valueOf(radiuss);

System.out.println("Please Enter the Height");
heights = in.readLine();
height=Float.valueOf(heights);
}
catch(Exception e) {
System.out.println("Input Output Error");
}

volume = pi*(float)pow(radius,2.0f)*height;
surfacearea=2.0f*pi*radius*height;
outerarea=2.0f*pi*(float)pow(radius,2.0f);

System.out.println("\t\t Cylinder");
System.out.println("Radius      " + radius);
System.out.println("Height      " + height);
System.out.println("Volume    " +  volume);
System.out.println("Surface Area" + surfacearea);
System.out.println("Outer Area" + outerarea);
}
}