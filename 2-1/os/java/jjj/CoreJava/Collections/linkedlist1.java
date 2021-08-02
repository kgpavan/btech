import java.util.*;
class linkedlist1
{
public static void main(String st[])
{
LinkedList l1 = new LinkedList();
l1.add("f");
l1.add("b");
l1.add("c");
l1.add("a");
Comparator r = Collections.reverseOrder();
Collections.sort(l1,r);
Iterator ir = l1.iterator();
while(ir.hasNext())
System.out.println(ir.next() + "   ");
Collections.shuffle(l1);
ir = l1.iterator();
while(ir.hasNext())
System.out.println(ir.next() + "   ");
}
}





