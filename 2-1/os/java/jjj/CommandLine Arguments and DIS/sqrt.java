import java.io.DataInputStream;

public class sqrt
{
  public static void main(String args[])
  {
    DataInputStream  in = new DataInputStream(System.in);
    double doublenumber = 0.0f,d1 = 0.0f;
    int i = 0;

       try
    {
      doublenumber = Double.parseDouble(in.readLine());
      System.out.println("the number is" + doublenumber);
      d1 = Math.sqrt(doublenumber);

      System.out.println(d1);
       i = (int) d1;
       System.out.println(i);
  }
   catch(Exception e) { }
   }
}


