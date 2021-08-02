
import java.util.*;

class hashmap {

public static void main(String args[])
{
HashMap hm = new HashMap();
hm.put("1", new Double(45.5555));
hm.put("2", new Double(55.6667));

Set set = hm.entrySet();
Iterator it = set.iterator();

while(it.hasNext())
{
Map.Entry m1 = (Map.Entry)it.next();
System.out.println(m1.getKey());
System.out.println(m1.getValue());
}

double bal = ((Double) hm.get("1")).doubleValue();
hm.put("1",new Double(bal + 1000));
System.out.println("new balance is " + hm.get("1"));
}
}

