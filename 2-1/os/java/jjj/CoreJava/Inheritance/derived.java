//overriding demo

interface myinter {
      void getdata();
      void putdata();
    }

   class myclass {
       int x,y;
      void getdata(int a,int b) {
        x=a;
        y=b;
      }
     void getdata() {
      System.out.println("From the class");
      }

      void display() {
  System.out.println("The value of x and y are" + x + "  "+ y);
        }
   }

class abcclass extends myclass implements myinter {

     public void getdata(){
   System.out.println("From interface");
    }

    public void putdata() {
  System.out.println("From the interface");
    }
}

class Derived {
  public static void main(String args[]) {
    abcclass ab = new abcclass();
    ab.getdata();
    ab.putdata();
    ab.getdata(10,20);
    ab.display();
   }
}     

