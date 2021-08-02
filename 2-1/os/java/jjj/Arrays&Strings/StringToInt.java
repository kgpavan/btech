class StringToInt {
public static void main(String args[]) {
    String s = "125";
    Integer obj = Integer.valueOf(s);
    int i = obj.intValue();
    i += 10;
    System.out.println(i);
  }
}