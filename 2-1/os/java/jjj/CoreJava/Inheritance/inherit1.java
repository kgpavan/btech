class a {
  int i;
  a() {
   System.out.println("Inside super class");
     }
     a(int k) {
       i=k;
     }
     }
  class b extends a {
      int i;
       b(int a, int b) {
      super(a);
       i=b;
          }
 void show() {
 System.out.println("I in Super Class " + super.i);
 System.out.println("I in Sub Class " + i);
  }
}
  class inherit1 {
     public static void main(String args[]) {
          b subob = new b(100,200);
           subob.show();
               }
         }


