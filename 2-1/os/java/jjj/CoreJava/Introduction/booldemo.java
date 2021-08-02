
class booldemo
{
 public static void main(String args[])
 {
   Boolean boolobject = new Boolean(true);
   if(boolobject.equals(Boolean.TRUE))
   System.out.println("bool object is true");


   boolean boolvalue = true;
   boolvalue = boolobject.booleanValue();

   if(boolvalue == Boolean.TRUE.booleanValue())
   System.out.println("boolean value is true");

   if(boolvalue == true)
   System.out.println("boolean value is true");

   }
}


