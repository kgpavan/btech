class ArrayReference {

public static void main(String args[]) {

// Declare and allocate space for array1
float array1[] = new float[3];

    // Initialize array1
    array1[0] = -3.45f;
    array1[1] = 7.7f;
    array1[2] = 101.56f;

// Declare and allocate space for array2
float array2[] = new float[3];

// Copy array1 to array2
 array2 = array1;

// Display the elements of array2
 System.out.println("array2:");
 System.out.println(array2[0]);
 System.out.println(array2[1]);
 System.out.println(array2[2]);

    // Change an element
    array2[1] = 100;

    // Display the elements of array1
    System.out.println("array1:");
    System.out.println(array1[0]);
    System.out.println(array1[1]);
    System.out.println(array1[2]);

    // Display the elements of array2
    System.out.println("array2:");
    System.out.println(array2[0]);
    System.out.println(array2[1]);
    System.out.println(array2[2]);
  }
}
