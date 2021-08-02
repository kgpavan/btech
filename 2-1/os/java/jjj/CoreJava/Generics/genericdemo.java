//a simple generic class
class Gen<T> {
T ob;  //declare an object of type T
  //pass the constructor a reference
  //to an object of type T
Gen(T o) {
ob=o;
  }
     //return ob
 T getob() {
  return ob;
      }
 //show type of T
void showType() {
System.out.println("Type of T is" + ob.getClass().getName());
  }
}
class genericdemo {
 public static void main(String args[]) {
  // create a gen reference for integers

  Gen<Integer> iob;
  iob = new Gen<Integer>(88);
  iob.showType();

   int v=iob.getob();    
   System.out.println("Value is" + v);
   

Gen<String> strob = new Gen<String>("Generics Test");
strob.showType();
String str = strob.getob();
System.out.println("Value" + str);
}
}