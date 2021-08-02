class UnevenTwoDimensionArrayInitializer {

  public static void main(String args[]) {

    // Declare, allocate, initialize
    int myarray[][] = {
      { 33, 71 },
      { -16, 45, 50, -7 },
      { 99 }
    };

    // Display lengths of the array and its elements
    System.out.println("myarray.length = " + myarray.length);
    System.out.println("myarray[0].length = " + myarray[0].length);
    System.out.println("myarray[1].length = " + myarray[1].length);
    System.out.println("myarray[2].length = " + myarray[2].length);

    // Display elements
    System.out.println(myarray[0][0]);
    System.out.println(myarray[0][1]);
    System.out.println(myarray[1][0]);
    System.out.println(myarray[1][1]);
    System.out.println(myarray[1][2]);
    System.out.println(myarray[1][3]);
    System.out.println(myarray[2][0]);
  }
}