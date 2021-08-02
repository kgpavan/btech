class EightTypes {

  public static void main(String args[]) {

    Boolean bool = Boolean.valueOf(args[0]);
    Character c = new Character(args[1].charAt(0));
    Byte b = Byte.valueOf(args[2]);
    Short s = Short.valueOf(args[3]);
    Integer i = Integer.valueOf(args[4]);
    Long l = Long.valueOf(args[5]);
    Float f = Float.valueOf(args[6]);
    Double d = Double.valueOf(args[7]);

    System.out.println(bool);
    System.out.println(c);
    System.out.println(b);
    System.out.println(s);
    System.out.println(i);
    System.out.println(l);
    System.out.println(f);
    System.out.println(d);
  }
}