// inner class demo
import java.lang.*;

class outer {
private int outer_x = 100;
//test is an outer class method
void test() {
System.out.println("Outer Class Method");
Inner in = new Inner();
in.display();
 } //end of test()
         class Inner {
            int y=10;
           //inner class method
           void display() {
 System.out.println("Inner Class method");
  System.out.println("display : outer_x " + outer_x);
          } //end of display()
     } // end of inner class
  //declaration of an object for inner class (global)
  Inner p = new Inner();
   //outer class method
   void showy() {
   System.out.println("sample");
      } //end of the method
 } //end of the outer class

class innerdemo {
public static void main(String args[])  {
outer o = new outer();
o.test();
//to access inner class method
o.p.display();

  }
}