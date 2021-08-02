class bit_op
{
  public static void main(String args[])
  {
    int i = 1;
    c1 : for(i=0;i<5;i++)
         {
            System.out.println("outer");
             
     c2 :  {
               if (i < 2)
               {
                 i++;
                continue c1;
              }
               System.out.println("inner");
           }
        }
   }
}



