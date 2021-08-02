import java.io.*;
import java.util.*;
public class readobject extends Object
{
public static void main(String args[])
{
try
{
  FileInputStream fi =  new FileInputStream("object.txt");
  ObjectInputStream obj = new ObjectInputStream(fi);
  Object ob1 = obj.readObject();
  System.out.println(ob1);
  ob1 = obj.readObject();
  System.out.println(ob1);
  obj.close();
  }
  catch(Exception e)
  {
    System.out.println("error");
  }
}
}


