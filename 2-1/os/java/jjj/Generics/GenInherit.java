//A generic class that supports inheritance
class  Gen<T> {
 T ob;  // declare an object of type T
 //pass the constructor a reference to an object
 Gen(T o) {
   ob=o;
   }
  T getob() {
  return ob;
  }
  }
  // a sub class of Gen that defines a second type of parameter called V
  class Gen2<T,V> extends Gen<T>  {
     V ob2;

	 Gen2(T o, V o2) {
	   super(o);
	   ob2=o2;
	   }
  V getob2() { 
    return ob2;
  }
  }
  // create an object 
  class GenInherit  {
   public static void main(String args[]) {
   Gen2<String,Integer> x = new Gen2<String,Integer>("Value is",99);
   System.out.println(x.getob());
   System.out.println(x.getob2());
  } // end of main
}
