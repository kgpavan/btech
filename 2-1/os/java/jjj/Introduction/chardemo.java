import java.io.DataInputStream;
class chardemo
{
  public static void main(String args[])
  {
    DataInputStream in = new DataInputStream(System.in);
    try
    {
   lb1:   {
         double  a = Double.parseDouble(in.readLine());
            {
               if (a == 0) break lb1;
               double  b = Double.parseDouble(in.readLine());

               if (b ==0)   break lb1;
               System.out.println(a/b);
            }
         }
    }
   catch(Exception e) { }
   
 }
 }
