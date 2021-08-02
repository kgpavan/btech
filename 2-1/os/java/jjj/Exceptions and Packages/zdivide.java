import java.lang.*;

class zdivide {
public static void main(String args[]) {
     int a=40;
     int b=5;
     int c=5;
     int d;

     try {
      d=a/(b-c);
        }
  
    catch(Exception e) {
    e.printStackTrace();
         }
    finally {
      b++;
     d=a/(b-c);
 System.out.println("the value of d is" + d);
    }

   }
}


       



