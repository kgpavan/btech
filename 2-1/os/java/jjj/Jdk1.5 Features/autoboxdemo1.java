//autoboxing/unboxing occurs inside expressions

class autoboxdemo1 {
   public static void main(String args[]) {
    Integer iob,iob2;
    int i;

    iob=100;
 System.out.println("Original value of iob" + iob);
   ++iob;
   System.out.println("After increment" + iob);
   iob2 = iob + (iob/3);
  System.out.println("iob2 after expression" + iob2);

i=iob+(iob/3);
System.out.println("i after expression" + i);
}
}
