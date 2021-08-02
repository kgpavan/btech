import java.util.*;

class linkedlist{
public static void main(String st[]){

LinkedList l1 = new LinkedList();

l1.add("f");
l1.add("b");

System.out.println(l1);
l1.addFirst("a");
System.out.println(l1);
l1.addLast("z");
System.out.println(l1);
l1.add(1,"c");
System.out.println(l1);
l1.remove("b");
System.out.println(l1);
l1.remove(1);
System.out.println(l1);
l1.removeFirst();
System.out.println(l1);
l1.removeLast();
System.out.println(l1);
l1.add("f");
l1.add("b");

Object val = l1.get(2);

l1.set(2,(String) val + "set");
System.out.println(l1);
}
}