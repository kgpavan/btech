import java.io.*;

class filedemo3
{
public static void main(String args[])
{
for(int i=0;i<args.length;i++)
{
    File f = new File("c:\\java",args[i]);
    File f1 = new File("c:\\java\renfile");
   
  if(f.exists())
   {
    System.out.println( f + "exists");
   System.out.println("Its size is" + f.length() + "bytes");
f.renameTo(f1);
System.out.println("Renamed to" + f1);
 System.out.println("deleting the file" + f);
f.delete();
 }
else
System.out.println(f + "does not exists");
}
}
}
