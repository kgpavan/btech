import java.util.*;
class arraylist
{
public static void main(String args[])
{
 ArrayList a1 = new ArrayList();
 System.out.println(a1.size());
 a1.add(new Integer(1));
 a1.add(new Integer(1));
 a1.add(new Integer(2));
 a1.add(new Integer(3));
 a1.add(new Integer(4));
 a1.add(new Double(5.0));
 a1.add("sample");
 System.out.println(a1.get(6));
  Iterator itr = a1.iterator();
  while(itr.hasNext())
  {
    Object element = itr.next();
    System.out.println(element);
  }
  ListIterator ltr = a1.listIterator();
  while(ltr.hasNext())
  {
    Object element = ltr.next();
    System.out.println(element);
  }
 while(ltr.hasPrevious())
 {
    Object element = ltr.previous();
   System.out.println(element);
  }
 }
 }

 
