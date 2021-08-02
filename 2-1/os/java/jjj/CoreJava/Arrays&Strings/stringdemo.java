import java.lang.*;

class stringdemo {
   public static void main(String args[]) {
      String str="       seofeteoware      ";
      String str1="SOFTWARE";
      String str2="solutions";

System.out.println("The character at a specified location" + str.charAt(4));
System.out.println("Index of character" + str.indexOf('o'));
System.out.println("Index of character at a given location" + str.indexOf('o',2)); 
System.out.println("Last index of the character" + str.lastIndexOf('e'));
System.out.println("The trim of the function"  + str.trim());
System.out.println("string is" + str.equals(str1));
System.out.println("Ignore Case" + str.equalsIgnoreCase(str1));
System.out.println("Substring of the given string is" + str.substring(3,4));
}
}