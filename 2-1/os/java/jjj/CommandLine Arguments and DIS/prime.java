import java.io.DataInputStream;
class prime
{
  public static void main(String args[])
  {
    DataInputStream  in = new DataInputStream(System.in);
    int p,i,s1;
    char ch1;
    boolean f1;
           try
    {
      f1 = true;
     p = Integer.parseInt(in.readLine());
     for(i=2;i<p;i++)
     {
        s1= p % i;
        if (s1 == 0)
          f1 = false;
      }
      if (f1)
        System.out.println("prime");
      else
       System.out.println("not prime");
    }
   catch(Exception e) { }
   }
}


