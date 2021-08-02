import java.io.*;
import java.lang.*;

class tempconv {
public static void main(String args[]){

float farenheit,centigrade;
String fs,cs;

farenheit = centigrade= 0.0f;

try{
DataInputStream  dis = new DataInputStream(System.in);

System.out.println("Enter the Farenheit temparature");
fs =  dis.readLine();
farenheit = Float.valueOf(fs);
}
catch(Exception e){
System.out.println("Input Output Error");
}
centigrade = (farenheit-32) * 5.0f/9.0f;

System.out.println("Farenheit is :" + farenheit);
System.out.println("Centigrade is:" + centigrade);
}
}