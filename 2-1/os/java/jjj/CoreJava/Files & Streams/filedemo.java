import java.io.*;
import java.util.*;

class filedemo
{
 static void p(String s)
 {
 System.out.println(s);
 }
 public static void main(String args[]){
   File f1 = new File(args[0]);
   if(f1.exists()) {
   p("Filename is"+ f1.getName() + "\n");
   p("Path is " +f1.getPath() + "\n");
   p("File last modified " + new Date(f1.lastModified()) + "\n");
   p("File size " + f1.length() + "Bytes");
   p("File is readable" + f1.canRead());
   p("File is writeable" + f1.canWrite());
   }
   else
   p("file not exists");
 }
}