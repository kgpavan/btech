   import java.lang.*;
   import java.util.*;
   public class vec extends Vector
     {
  Class c1,c2;
  public vec()
  {
    super(1,1);
  }
  public void addint( int i)
  {
    addElement(new Integer(i));
  }
  public void addstr(String str)
  {
   addElement(str);
   }
  public void display()
  {
  Object ob;
  String s1 = "software";
  int length = size();
  System.out.println(length);
  for(int i=0;i<length;i++)
  {
    ob = elementAt(i);
    c1 = ob.getClass();
    c2 = s1.getClass();
    if (c1 == c2 ) System.out.println("string values is" + ob.toString());
    else
    System.out.println("Integer values is" + ob.toString());
  }
 }
 public static void main(String args[])
 {
  vec v = new vec();
  int num = 100;
  String  s1 = new String("I Love India");
  v.addint(num);
  v.addstr(s1);
  v.display();
  }
 }

