class FloatArray {

  public static void main(String args[]) {

    // Declare, allocate, initialize
    float myarray[][] = {
      { -56.7f },
      { 500.1f, 70.70f },
      { 100.9f, 0.5f, 20.20f }
    };

    // Display length
    System.out.println("myarray.length = " + 
      myarray.length);

    // Display elements
    System.out.println(myarray[0][0]);
    System.out.println(myarray[1][0]);
    System.out.println(myarray[1][1]);
    System.out.println(myarray[2][0]);
    System.out.println(myarray[2][1]);
    System.out.println(myarray[2][2]);
  }
}