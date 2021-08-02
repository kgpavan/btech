import java.io.*;
class  checkfile
{
public static void main(String args[])
{
    File f1 = new File("c:\\java","abc.txt");
    if(f1.canRead())
   System.out.println("We can read from this file");
    else
    System.out.println("Cannot read from the file");
    if(f1.canWrite())
      System.out.println("We can write from the file");
      else
      System.out.println("Cannot write to the file");
   System.out.println("The file was last modified at" + f1.lastModified());
  }
}
