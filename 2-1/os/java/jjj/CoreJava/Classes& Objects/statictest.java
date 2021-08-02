public class statictest {
 public static void main(String[] args) {
   double[] d = new double[20];

   for(int i=0;i<d.length;i++)   {
     d[i] = 100 * Math.random();
     System.out.println(d[i]);
   }
    arrayalg.pair p = arrayalg.minmax(d);
//   arrayalg.pair p = new arrayalg.pair(5,5);

   System.out.println("min = " + p.getfirst());
   System.out.println("max = " + p.getsecond());
   }
}
class arrayalg
{
 public static class pair
 {
   public pair(double f, double s)
   {
     first = f;
     second = s;
   }
   public double getfirst()
   {
     return(first);
   }
   public double getsecond()
   {
     return(second);

    }
   private double first;
   private double second;

 }
 //   public  pair minmax(double[] d)
   public static pair minmax(double[] d)
   {
    if(d.length == 0)
     return new pair(0,0);
    double min = d[0];
    double max = d[0];
    for(int i = 1;i<d.length;i++)
    {
     if(min >d[i]) min = d[i];
     if(max<d[i]) max = d[i];
    }
    return new pair(min,max);
  }
 }