import java.io.*;
import java.util.*;

public class filedemo1 implements FilenameFilter
{
String ext;
public filedemo1(String ex)
{
  ext = "." + ex;
}
public boolean accept(File dir, String name)
{
   return name.endsWith(ext);
}
}


 public static void main(String args[])
 {
   File f1 = new File(args[0]);
   p("Filename is   "+ f1.getName() + "\n");
   p("Path is " +f1.getPath() + "\n");
   p("File last modified " + new Date(f1.lastModified()) + "\n");
   p("File size " + f1.length() + "Bytes");
 }

} 
