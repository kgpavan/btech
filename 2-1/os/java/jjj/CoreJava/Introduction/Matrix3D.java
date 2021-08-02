class Matrix3D {
  public static void main(String args[]) {
    byte array[][][] = {
      { { 4, 5, 6 }, { 1, 2, 3 }, { 5, 7, 8 } },
      { { 2, 0, 5 }, { 9, 8, 7 }, { 4, 4, 3 } },
      { { 0, 0, 0 }, { 1, 1, 1 }, { 2, 2, 2 } }
    };

    System.out.print(array[0][0][0] + ", ");
    System.out.print(array[0][0][1] + ", ");
    System.out.print(array[0][0][2] + ", ");
    System.out.print(array[0][1][0] + ", ");
    System.out.print(array[0][1][1] + ", ");
    System.out.print(array[0][1][2] + ", ");
    System.out.print(array[0][2][0] + ", ");
    System.out.print(array[0][2][1] + ", ");
    System.out.println(array[0][2][2] + ", ");

    System.out.print(array[1][0][0] + ", ");
    System.out.print(array[1][0][1] + ", ");
    System.out.print(array[1][0][2] + ", ");
    System.out.print(array[1][1][0] + ", ");
    System.out.print(array[1][1][1] + ", ");
    System.out.print(array[1][1][2] + ", ");
    System.out.print(array[1][2][0] + ", ");
    System.out.print(array[1][2][1] + ", ");
    System.out.println(array[1][2][2] + ", ");

    System.out.print(array[2][0][0] + ", ");
    System.out.print(array[2][0][1] + ", ");
    System.out.print(array[2][0][2] + ", ");
    System.out.print(array[2][1][0] + ", ");
    System.out.print(array[2][1][1] + ", ");
    System.out.print(array[2][1][2] + ", ");
    System.out.print(array[2][2][0] + ", ");
    System.out.print(array[2][2][1] + ", ");
    System.out.print(array[2][2][2] + ", ");
  }
}