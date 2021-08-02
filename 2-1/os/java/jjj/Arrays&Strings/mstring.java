class mstring
{
 public static void main(String args[])
 {
   char c[] = {'j','a','v','a'};
   String s1 = new String(c);
   String s2 = new String(s1);
   String s3 = "abcdef";
   System.out.println(s1);
   System.out.println(s2);
   System.out.println(s2.length());
String s4 = s1 + " concatenated with " + s3 + "" + s2;
   System.out.println(s4);
 }
}
