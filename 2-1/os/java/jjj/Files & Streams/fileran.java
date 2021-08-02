
import java.io.*;

class fileran
{
public static void main(String args[])
{
DataInputStream  in = new DataInputStream(System.in);

try
{
RandomAccessFile f2 = new RandomAccessFile("file1.dat","rw");

String s;
s = in.readLine();
f2.writeChars(s);
f2.close();


RandomAccessFile f1 = new RandomAccessFile("file1.dat","r");
s = f1.readLine();
System.out.println(s);
}
catch (Exception e)
{
System.out.println("error");
}
}
}



