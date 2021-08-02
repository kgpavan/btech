import java.io.*;

public class pipes1 extends Object
{
public static void writing(OutputStream r1,int[] data)
{
 try
  {
    DataOutputStream out = new DataOutputStream( new BufferedOutputStream(r1));
  //  int[] data = {10,11,12,13,14,15,16,17,18,19,20};
    for(int i=0;i<10;i++)
    {
      out.writeInt(data[i]);
      System.out.println("written data " + data[i]);
    }
   out.flush();
//    out.close();
  }
  catch(IOException e)
  {
    System.out.println(e);
  }
}
public static void reading(InputStream r2)
{
 try
  {
   DataInputStream in = new DataInputStream(new BufferedInputStream(r2));
   boolean eof = false;
   while(!eof)
   {
     try
      {
       int i = in.readInt();
       System.out.println("just read" + i);
      }
      catch(IOException e)
      {
        eof = true;
      }
   } //while
  }
  catch(Exception e)
  {
   System.out.println("Exception " +e);
  }
}
public static void main(String args[])
{
 try
   {
     final PipedOutputStream out = new PipedOutputStream();
     final PipedInputStream in = new PipedInputStream(out);
     Runnable run1 = new Runnable() 
     {
     public void run()
       {
       try
       {
        int i = 0;
        int p[] = new int[10];
       while(i<10)
       {
        for( int j = 0;j<10;j++)
          p[j] = i+j;
       writing(out,p);
       Thread.sleep(1000);
       i++;
       }
      }
      catch(InterruptedException e) {}
       }
     };
  Thread th1 = new Thread(run1,"one");
  th1.start();
     Runnable run2 = new Runnable() 
     {
         
     public void run()
     {
      try
      {
        int i = 0;
       while(i<10)
       {
         reading(in);
         Thread.sleep(500);
         i++;
       }
      }
      catch(InterruptedException e) {}
     }
     };
     Thread th2 = new Thread(run2,"two");
     th2.start();
   }
   catch(IOException e)
   {
    System.out.println(e);
   }
 }
}


