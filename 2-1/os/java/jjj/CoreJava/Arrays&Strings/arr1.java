class arr1 {

 int i;
 int arr[] = new int[10];

  void add() {
  int j=100;

 for(i=0;i<arr.length;i++) {
  arr[i] =j;
  j++;
     }
   }
void show(){
for(i=0;i<arr.length;i++){
System.out.println("The" + i + "array element is" + arr[i]);
   }
   }

public static void main(String args[])
   {
    arr1  n = new arr1();
    n.add();
    n.show();
   }
 }