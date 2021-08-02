import java.io.DataInputStream;

class reading
{

public static void main(String args[])
{
DataInputStream in = new DataInputStream(System.in);
int intnumber =0;
float floatnumber = 0.0f;
try
{
intnumber =Integer.parseInt(in.readLine());
floatnumber = Float.parseFloat(in.readLine());
System.out.println(" The integet value is " + intnumber);
System.out.println(floatnumber);

 }
 catch(Exception e) {  System.out.println("err"); }
 }
 }
