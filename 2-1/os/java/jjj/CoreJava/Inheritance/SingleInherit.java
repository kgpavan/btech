import java.lang.*;

class ClassA {
    protected int a;
    public void setA(int x) {
      a=x;
     }
};

class ClassB extends ClassA {

  protected int b;
   public void  cal() {
      b=a+10;
    }
  public void print() {
  System.out.println("The value of a is" + a);
  System.out.println("The value of b is" + b);
   }
}

class SingleInherit {
 public static void main(String args[]) {

   ClassB cb = new ClassB();
   cb.setA(100);
   cb.cal();
   cb.print();
}
}
