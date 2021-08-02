class StringBufferDemo {
  public static void main(String args[]) {
    StringBuffer sb1 = new StringBuffer();
    StringBuffer sb2 = new StringBuffer(30);
    StringBuffer sb3 = new StringBuffer("abcde");

    System.out.println("sb1.capacity = " + 
      sb1.capacity());
    System.out.println("sb1.length = " + 
      sb1.length());
    
	System.out.println("sb2.capacity = " + 
      sb2.capacity());
    System.out.println("sb2.length = " + 
      sb2.length());
    
	System.out.println("sb3.capacity = " + 
      sb3.capacity());
    System.out.println("sb3.length = " + 
      sb3.length());
  }
}