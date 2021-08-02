import java.io.*;
import static java.lang.Float.*;
import static java.lang.Math.*;

class circle{
public static void main(String args[]) {
float pi = 3.14157f;
float radius;
float diameter,area,circumference;

String s;

radius=diameter=area=circumference=0.0f;

try {
DataInputStream in = new DataInputStream(System.in);

System.out.println("Please Enter the Radius");
s = in.readLine();
radius = valueOf(s);
 }
catch(Exception e) {
System.out.println("error");
 }

area = pi*(float)pow(radius,2.0f);
diameter = 2.0f * radius;
circumference=2.0f*pi*radius;

System.out.println("Radius : " + radius);
System.out.println("Diameter : " +    diameter);
System.out.println("Area : " + area);
System.out.println("Circumference : " +   circumference);
 }
}