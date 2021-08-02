import java.util.*;
class treemap{
public static void main(String args[])
{
   TreeMap t = new TreeMap();
   t.put("one",new Integer(90));
   t.put("two", new Integer(100));
   Set s = t.entrySet();
   Iterator it = s.iterator();
while(it.hasNext())
{
Map.Entry m1 = (Map.Entry)it.next();
System.out.println(m1.getKey());
System.out.println(m1.getValue());
}

}
}

