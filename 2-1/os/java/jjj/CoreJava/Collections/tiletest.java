import java.awt.*;
import java.util.*;
public class tiletest
{
  public static void main(String[] args)
  {
    tile[] a = new tile[10];
    int i;
    for(i=0;i<a.length;i++)
    {
      a[i] = new tile(i,i,10,20,(int)(100 * Math.random()));
      System.out.println(a[i]);
   }
   Arrays.sort(a);

   for(i=0;i<a.length;i++)
   {
    System.out.println(a[i]);
   }
 }
}
class tile extends Rectangle implements Comparable
{
  public int compareTo(Object ob)
  {
    tile tb = (tile) ob;
    return (z - tb.z)  ;
  }
  public tile(int x1, int y1, int x2, int y2, int zz)
  {
    super(x1,y1,x2,y2);
    z = zz;
  }
  private int z;
  public String toString()
  {
    return  " z = " + z;
  }
}

