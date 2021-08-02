//A generic class with two parameters
class  TwoGen<T,V>{
   T ob1;       //int ob1;
   V ob2;     //String ob2
   //pass the constructor reference to an object T
   // and object V
   TwoGen(T o1, V o2) {
        ob1=o1;
		ob2=o2;
	}
	// show types of T and V
	 void showTypes() {
	   System.out.println("Type of T is" + ob1.getClass().getName());
	   System.out.println("Type of V is" + ob2.getClass().getName());
	   }

	   T getob1() {
	      return ob1;
		  }
		V getob2() {
		   return ob2;
		 }
	} // end of class

	class GenericSimple 	{
         public static void main(String args[]) {
		  TwoGen<Integer,String> tgobj =  new TwoGen<Integer,String>(88,"Generics");
		  tgobj.showTypes();

		  int v= tgobj.getob1();
		  System.out.println("Value" + v);

		  String str = tgobj.getob2();
		  System.out.println("value is" +  str);
	} //end of main
	} //end of class