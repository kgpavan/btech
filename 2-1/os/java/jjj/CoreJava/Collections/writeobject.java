import java.io.*;
import java.util.*;
public class writeobject extends Object
{
 public static void main(String args[])
 {
   Hashtable w1 = new Hashtable();
   w1.put("1","one");
  w1.put("2","two");
  w1.put("3","three");
  try
  {
   FileOutputStream fo = new FileOutputStream("object.txt");
   ObjectOutputStream obj = new ObjectOutputStream(fo);
   obj.writeObject(new Date());
   obj.writeObject(w1);
    obj.close();

   }
   catch(Exception e)
   {
   System.out.println("error in writing");
   }
 }
}

