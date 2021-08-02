class X {
       int a;
       float b;
    }
class Y extends X {
        double c;
    }

class r {
     public static void main(String args[])
     {
      X x = new X();
      Y y = new Y();
      Class cal;

      cal = x.getClass();     //gets the class reference
      System.out.println("x is object of type: " + cal.getName());

      cal = y.getClass();  // gets the class reference
      System.out.println("y is object of type: " + cal.getName());

      cal = cal.getSuperclass();
      System.out.println("y's super class is " + cal.getName());

      }
   }




      
