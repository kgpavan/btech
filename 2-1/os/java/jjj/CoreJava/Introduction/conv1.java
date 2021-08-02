import java.io.DataInputStream;
class conv1
{
  public static void main(String args[])
  {
  byte  b = 5;
  int i = 257;
  double d = 323.142;
  boolean flag;
//  flag = (boolean) i;
  System.out.println("conversion of int to byte" + b);
  b = (byte) i;
  i = b;
  System.out.println("conversion of byte to int" + b);
  System.out.println("conversion of byte to int" + i);
  i = (int) d;
  System.out.println("conversion from double to int" + i  + "     " + d);
  }

    
}

