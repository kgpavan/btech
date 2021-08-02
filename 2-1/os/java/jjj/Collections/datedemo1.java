import java.util.*;

class datedemo1
{
 public static void main(String agrs[])
 {
  Date d1 = new Date(99,4,2);
  Date d2 = new Date(99,5,12);
  
  if(d1.compareTo(d2) == 0)
     System.out.println("The date are same");
  else
    System.out.println("The dates are not same");

  System.out.println(" Ths value is " +d1.after(d2));
  System.out.println(" Ths value is " +d1.before(d2));

  System.out.println("   year :" + d1.getYear());
  System.out.println("   Month :" + d1.getMonth());
  System.out.println("   Day :" + d1.getDay());
  System.out.println("   Day :" + d1.getTime());
  System.out.println(d1);
  Date d4 = new Date(500000);
  System.out.println("   year :" + d4.getYear());
  System.out.println("   Month :" + d4.getMonth());
    System.out.println(d4);

  }
}



     
