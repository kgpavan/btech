import java.lang.*;

class ClassA {
 protected int a;
 public void put(int j) {
a=j;
  }
}
class ClassB extends ClassA {
  private int b;
  public void set(int x){
 put(x);
 b=a+10;
  }
  public void display() {
  System.out.println("The value of a is" + a);
  System.out.println("The value of b is" + b);
   }
}
class SingleInherit1 {
  public static void main(String args[]) {
    ClassB cb = new ClassB();
    cb.set(100);
    cb.display();
 }
}