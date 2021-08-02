import java.lang.reflect.*;
import java.util.*;
public class arraygrowtest
{
 public static void main(String[] args)
 {
  int[] a = {1,2,3};
  a= (int[]) goodArrayGrow(a);
  arrayprint(a);
  Date d1[] = { new Date(1990,1,1), new Date(1999,2,2)};
  arrayprint(d1);
  }
  static Object[] badArrayGrow(Object[] a)
  {
    int newlength = a.length + 5;
    Object[] newarray = new Object[newlength];
    System.arraycopy(a,0,newarray,0,a.length);
    return newarray;
   }
   static Object goodArrayGrow(Object a)
   {
    Class c1 = a.getClass();
    if(!c1.isArray()) return null;
    Class componenttype = a.getClass().getComponentType();
    int length = Array.getLength(a);
    int newlength = 20;
    Object newarray = Array.newInstance(componenttype,newlength);
    System.arraycopy(a,0,newarray,0,length);
    return(newarray);
    }
    static void arrayprint(Object a)
    {
     Class c1 = a.getClass();
     if(!c1.isArray()) return;
     Class componenttype = a.getClass().getComponentType();
     int length = Array.getLength(a);
     System.out.println(componenttype.getName());
     for(int i = 0;i<Array.getLength(a);i++)
     System.out.print(Array.get(a,i) + "       ");
   }
   }
