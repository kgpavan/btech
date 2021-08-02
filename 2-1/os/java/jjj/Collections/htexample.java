import java.util.*;

class htexample {
  public static void main(String args[]) {

  Hashtable h = new Hashtable();
  h.put("Naresh",new Integer(90));
  h.put("Sreenu",new Integer(80));
  h.put("Ravi",new Integer(60));
  h.put("Kiran",new Integer(70));

   Enumeration e = h.elements();

   while(e.hasMoreElements()) {
   System.out.println(e.nextElement());
}
}
}

