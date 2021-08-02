class StringToInt2 {
  public static void main(String args[]) {
    String s = "125";
    int i = Integer.valueOf(s).intValue();
    i += 10;
    System.out.println(i);
  }
}