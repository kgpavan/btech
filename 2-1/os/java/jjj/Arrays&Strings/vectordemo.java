import java.util.Vector;

class vectordemo{
public static void main(String args[]){
//initial size of the vector
Vector v = new Vector(3,2);

System.out.println("Intial Size of the Vector " + v.size());

System.out.println("Initial Capacity is" + v.capacity());

v.addElement(new Integer(1));
v.addElement(new Integer(2));
v.addElement(new Integer(3));
v.addElement(new Integer(4));

System.out.println("Capacity after four additions " + v.capacity());

v.addElement(new Double(5.45));

System.out.println("Current Capacity " + v.capacity());

v.addElement(new Double(6.08));
v.addElement(new Integer(8));

System.out.println("Current Capacity " + v.capacity());

v.addElement(new Float(9.4));
v.addElement(new Integer(10));

System.out.println("Current capacity:" + v.capacity());

v.addElement(new Integer(11));
v.addElement(new Double(12.34));

System.out.println("First Element value" + (Integer)v.firstElement());
System.out.println("Last Element value" + (Double)v.lastElement());

if(v.contains(new Integer(32)))
System.out.println("Vector contains 32");
       }
    }