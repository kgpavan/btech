class comm_agr
{
  public static void main(String[] arg)
  {
   if(arg.length<1)

    System.out.println( "number should be given with file");

   else
    {
      int intvalue = Integer.parseInt(arg[0]);
      System.out.println("default = " + Integer.toString(intvalue));
      System.out.println(" hex = " + Integer.toHexString(intvalue));
      System.out.println("oct = " + Integer.toOctalString(intvalue));
      System.out.println("binary = " + Integer.toBinaryString(intvalue));
      System.out.println("32 bit format" + Integer.toString(intvalue,32));
   }

  }
}
