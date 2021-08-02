class StringBufferReverse {
public static void main(String args[]) {
StringBuffer sb1 = new StringBuffer("abcde");
sb1.append("abcdefghij");
StringBuffer sb2 = sb1.reverse();
System.out.println(sb1);
System.out.println(sb2);
  }
}