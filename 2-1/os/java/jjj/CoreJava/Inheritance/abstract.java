
     abstract class a
     {
        abstract void cm();

        void cmt()
        {
          System.out.println("This is a concrete method");
        }
      }

      class b extends a
      {
        void cm()
        {
      System.out.println("The implementation of the function");
        }
     }

     class abstractdemo
     {
        public static void main(String args[])
        {
          b b1 = new b();

          b1.cm();
          b1.cmt();
        }
     }




