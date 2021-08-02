import java.io.*;
public class pipes2 extends Object
{
public static void writing(Writer r1)
{
 try
  {
   BufferedWriter out = new BufferedWriter(r1);
   String[][] line ={
                    {"java","has","nice","features"},
                    {"pipes","are","interesting"}};

  for(int i=0;i<line.length;i++)
   {
     String[] word = line[i];

     for(int j=0; j<word.length;j++)
     {
       if(j>0)
       out.write("  ");
       out.write(word[j]);
     }
     out.newLine();
   }
   out.flush();
   out.close();
}
catch(IOException x) {}
}

 public static void reading(Reader r2)
 {
  try
   {
     BufferedReader in = new BufferedReader(r2);
     String line;
     while((line = (String)in.readLine()) != null)
     {
     System.out.println("read line" + line);
     }
     System.out.println("completed reading");
   }
   catch(IOException e) {}
}

public static void main(String[] args)
{
 try
  {
     final PipedWriter out = new PipedWriter();
     final PipedReader in = new PipedReader(out);
     Runnable r1 = new Runnable()
     {
      public void run()
      {
        writing(out);
      }
    };
    Thread thr1 = new Thread(r1,"one");
    thr1.start();

     Runnable r2 = new Runnable()
     {
      public void run()
      {
          reading(in);
       }
    };
    Thread th2 = new Thread(r2,"two");
    th2.start();
   } catch(IOException x) {}
 }
 }
