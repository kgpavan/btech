import java.lang.*;

class p {
   //nested class
  class contents {
             private int i=16;
             private int value(){
             return i;
          } //end of the method
    } // end of contents
 //an other nested class
class destination {
    private String label;
  destination(String whereto) {
     label = whereto;
        }  //end of constructor
     String readlabel() {
        return label;
        } //end of method
    } //end of destination class

   //class -p method
	public void ship (String dest) {
     contents c = new contents();
    destination d = new destination(dest);
   System.out.println("Shipped " + c.value() + "item to" + dest);
   }
   public static void main(String args[])   {
       p p1 = new p();
       p1.ship("Cargo");
  }
 }