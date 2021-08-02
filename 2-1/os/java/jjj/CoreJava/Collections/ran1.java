import java.util.*;
class ran1
{
public static void main(String args[])
{
 Random r = new Random();
 double val;
 double sum = 0;
 System.out.println("according to Gaussian" + r.nextGaussian());
  System.out.println("according to Gaussian" + r.nextGaussian());
 for(int i=0;i<10;i++)
 System.out.println(r.nextInt(40));
  System.out.println(r.nextFloat());
 }
}
