
class mstring4
{
   public static void main(String args[])
   {
    String s = "now is the time for all to lear java is't it";
    System.out.println(s);
    System.out.println(s.indexOf('i'));
    System.out.println(s.indexOf("io"));
    System.out.println(s.indexOf('i',10));  //starts searching from 10 to last
    System.out.println(s.lastIndexOf('i'));
    System.out.println(s.lastIndexOf('i',50));// starts seaching from 50 to 0
    System.out.println(s.lastIndexOf("is"));
    System.out.println(s.lastIndexOf("is",50));// starts seaching from 50 to 0

   }
}


