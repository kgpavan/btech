  class arr {
    int i;
    int da[] = {10,20,30,40,50};
 void disp()  {
System.out.println("Displaying the Array Details");
  for(i=0;i<=4;i++) {
   System.out.println(da[i]);
   }
}
 public static void main(String args[]){
 arr a = new arr();
 a.disp();
 }
}