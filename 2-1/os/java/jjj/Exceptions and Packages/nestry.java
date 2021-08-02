class nestry
{
  public static void main(String args[])
  {
    try
    {
      int a = args.length;

      int b = 42/a;

      System.out.println("a = " + a);

    try
    {
    if(a==1) a = a/(a-a);
    if(a==2)
    {
      int c[] = {1};
      c[5] = 99;
    }
   }  //end of second try
   catch(ArrayIndexOutOfBoundsException e)
   {
     System.out.println("Array Index Out of bounds");
   }
    System.out.println("in outer block");
 }  // end of first try


 catch(ArithmeticException e)
 {
  System.out.println("Divide by 0: " + e);
 }
}
}

