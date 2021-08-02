import java.util.*;
public class t1
{
  public static void main(String[] args)
  {
   int[] a = new int[10];
   String[] b = new String[10];
   int i;
   for(i=0;i<a.length;i++)
   {
    a[i] = a.length -i;
    b[i] = String.valueOf(i);
    System.out.println(a[i] + "             " + b[i]);
  }
  Arrays.sort(a);
  Arrays.sort(b);
  int p = Arrays.binarySearch(a,5);
  System.out.println("it is at location " + p);
  for(i=0;i<a.length;i++)
  {
    System.out.println(a[i] + "             " + b[i]);
  }
 }
}
    

