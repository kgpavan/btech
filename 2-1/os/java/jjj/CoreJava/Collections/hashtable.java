import java.util.*;

class hashtable {
public static void main(String args[]){
Hashtable hm = new Hashtable();
hm.put("1", new Double(45.5555));
hm.put("2", new Double(55.6667));
Set set = hm.keySet();
Iterator it = set.iterator();
while(it.hasNext()){
String m1 = (String)it.next();
System.out.println(m1 + "       " + hm.get(m1));
}
double bal = ((Double) hm.get("1")).doubleValue();
hm.put("1",new Double(bal + 1000));
System.out.println("new balance is " + hm.get("1"));
}
}

