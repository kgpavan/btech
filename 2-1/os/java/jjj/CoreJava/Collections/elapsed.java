import java.io.*;
import java.util.*;
class elapsed
{
  public static void main(String args[])
  {
    DataInputStream in = new DataInputStream(System.in);
    try
    {
    long  start,end;
    long p= 1;
     start = System.currentTimeMillis();
    
    for(int i=0;i<10;i++)
    in.readLine();        
    end =  System.currentTimeMillis();
    System.out.println(end - start);
    }
    catch(Exception e) {  }
    
      
  }
}
