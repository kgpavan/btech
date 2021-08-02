
import java.util.*;

class treesetoper
{
  public static void main(String args[])
  {
 TreeSet t = new TreeSet();

  t.add("2");
  t.add("1");
  t.add("4");
  t.add("3");

  System.out.println("The tree set is as follows");

  System.out.println(t + "\n");

  t.remove("3");

  System.out.println("The tree set after removing the element 3 is as follows");

  System.out.println(t + "\n");

  t.add("5");
  t.add("4");
  t.add("7");

  System.out.println("The tree set after adding more elements is as follows");

  System.out.println(t + "\n");

  System.out.println("The part of the tree set upto the element '4' is as follows");

  System.out.println(t.headSet("4"));

  }
  }




