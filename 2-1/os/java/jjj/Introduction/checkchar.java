import java.io.DataInputStream;
public class checkchar
{
  public static void main(String args[])
  {
    DataInputStream  in = new DataInputStream(System.in);
    char ch1;
           try
    {
     ch1 = (char)in.read();
      System.out.println("the character is " + ch1);
      if (Character.isLetter(ch1))
        System.out.println("It is character");
      else
        if(Character.isDigit(ch1))
        System.out.println("It is digit");
     }
   catch(Exception e) { }
   }
}


