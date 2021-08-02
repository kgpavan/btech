import java.io.*;
class floatpr
{
public static void main(String args[])
{
try
{
 DataInputStream in = new DataInputStream(System.in);
 float a,b,c;
 a = Float.parseFloat(in.readLine());
 b = Float.parseFloat(in.readLine());
 c = a/b;
 System.out.println(c);
 if(c == Float.POSITIVE_INFINITY)
   System.out.println("It is infinity");
}
catch(Exception e)
{
 System.out.println("error");
 }
}
}
