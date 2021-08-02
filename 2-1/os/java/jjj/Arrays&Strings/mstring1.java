class box {
 double width;
 double height;
 box(double p1, double p2)
 {
   width = p1;
   height = p2;
 }
 public String toString() {
  return "dimenstions are " + width + " by " +height;
  } 
}
class mstring1
{
public static void main(String args[])
{
  box b = new box(10,20);
  String s = " box b : " + b;  // calls tostring for conversion from object to string
  //calls toString
  System.out.println(s);



  System.out.println("abcdefgh".length());
  System.out.println(s.charAt(2));
  System.out.println("xyzabc".charAt(2));
  char buf[] = new char[40];
  s.getChars(1,7,buf,0);
  System.out.println(buf);
  buf = s.toCharArray();
  System.out.println(buf);
s = new String(buf);
  System.out.println(s);
  System.out.println(s.valueOf(b)); // conversion from object to string calls toString
 s =  String.valueOf(10);
 System.out.println(s);  
}
}
 
