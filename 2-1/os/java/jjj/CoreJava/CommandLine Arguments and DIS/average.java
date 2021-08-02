import java.io.*;

 class average
{
  public static void main(String arg[])
  {
   float avg,tot;
   float n1,n2,n3,n4,n5;
   String ns1,ns2,ns3,ns4,ns5;
   Float nf1,nf2,nf3,nf4,nf5;
   nf1 = new Float(0.0f);
   nf2 = new Float(0.0f);
   nf3 = new Float(0.0f);
   nf4 = new Float(0.0f);
   nf5 = new Float(0.0f);
    n1 = 0.0f;
    n2 = 0.0f;
    n3 = 0.0f;
    n4 = 0.0f;
    n5 = 0.0f;

    try
    {
      DataInputStream in;
      in = new DataInputStream(System.in);
      ns1 = in.readLine();
      nf1 = Float.valueOf(ns1);
      n1 = nf1.floatValue();

      ns2 = in.readLine();
      nf2 = Float.valueOf(ns2);
      n2 = nf2.floatValue();

      ns3 = in.readLine();
      nf3 = Float.valueOf(ns3);
      n3 = nf3.floatValue();

      ns4 = in.readLine();
      nf4 = Float.valueOf(ns4);
      n4 = nf4.floatValue();

      ns5 = in.readLine();
      nf5 = Float.valueOf(ns5);
      n5 = nf5.floatValue();
     }
     catch(IOException e)
     {
     System.out.println("io error");
      }
      tot = n1 + n2 + n3 + n4 + n5;
      avg = tot/5.0f;
      System.out.println(tot);
      System.out.println(avg);

      System.out.println(Float.MIN_VALUE);
      System.out.println(Float.MAX_VALUE);
      }
 }
