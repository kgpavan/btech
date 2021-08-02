class bitwiseop1
{
  public static void main(String agrs[])
  {
    int i = 10;
    int j = 7;
    int k = i&j;
    System.out.println("Bitwise and of 10 and 7 " + k);

    int l = i|j;
    System.out.println("Bitwise  or of 10 and 7 " + l);
    int m = i^j;
   System.out.println("Bitwise xor of 10 and 7 " + m);

   int o = ~i;
 System.out.println("Not of i is  " + o);

  int p = i<<2;
 System.out.println("Left shift by 2 is  " + p);

 int q = i>>2;
System.out.println("Right shift by 2 is  " + q);

     i = -12;
int r = i>>>2;
System.out.println("Right shift by 2 is  " + r);

}

}

