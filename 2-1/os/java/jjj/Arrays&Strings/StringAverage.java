class StringAverage {
public static void main(String args[]) {
 String array[] = new String[5];
 array[0] = "Short string";
 array[1] = "A much longer string";
 array[2] = "This is a complete sentence!";
 array[3] = "Token";
 array[4] = "This is the longest " +
      "element in the array";

 int total = array[0].length();
 total += array[1].length();
 total += array[2].length();
 total += array[3].length();
 total += array[4].length();
 System.out.println("The average string " +
   "size is " + total/5);
  }
}