   class breakde {

           public static void main(String args[])
           {
              boolean t = true;
         a:     {
         b:         {
         c:             {

         System.out.println("This executes before break statement");
         if(t)
          break b;
       System.out.println("The statment will not be executed");
       }
       System.out.println("This also will not be executed");

       }
       System.out.println("this statemnet comes after b");
       }
    }
 }


           
