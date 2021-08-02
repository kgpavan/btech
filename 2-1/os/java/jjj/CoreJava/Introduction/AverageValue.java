class AverageValue {
  public static void main(String args[]) {
    double da[] = new double[4];
    da[0] = 1E307;
    da[1] = 1.1E307;
    da[2] = 1.2E307;
    da[3] = 1.3E307;
    double total = da[0];
    total += da[1];
    total += da[2];
    total += da[3];
    System.out.println("Average = " + total/4);
  }
}