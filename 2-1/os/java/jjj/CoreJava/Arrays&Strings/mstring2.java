class mstring2
{
 public static void main(String args[])
 {
  String s1 = "hello";
  String s2 = "hello";
  String s3 = "good-bye";
  String s4 = "HELLO";
  System.out.println(s1 + "equals "  + s2 + s1.equals(s2));
  System.out.println(s1 + "equals "  + s3 + s1.equals(s3));
  System.out.println(s1 + "equals "  +  s1 == s2);
  System.out.println(s1 + "equals "  + s4 + s1.equalsIgnoreCase(s4));
  System.out.println(s1 + "equals "  + s2 + s1.regionMatches(1,s2,2,3));
  System.out.println(s1 + "equals "  + s2 + "ello".regionMatches(1,s2,2,3));
  System.out.println("Foobar".endsWith("bar"));
  System.out.println(s3.endsWith("bye"));
  System.out.println("Foobar".startsWith("Foo"));
  System.out.println(s3.startsWith("good"));

 }
}


