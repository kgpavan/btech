class usestatic{
  static int a=3;
  static int b;

 static void m1() {
 System.out.println(a);
 System.out.println(b);
  }
 static  {
 System.out.println("Static block");
 b=a*5;
  }
  public static void main(String args[])  {
 usestatic.m1();
  }
}