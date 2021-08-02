class exe1
{
 public static void main(String args[])
 {
   Runtime r = Runtime.getRuntime();
   Process p = null;
   try
   {
     p = r.exec("notepad t.txt");
     p.waitFor();
     }
     catch(Exception e)
     {
       System.out.println("error");
       }
       System.out.println(p.exitValue());
    }
 }
