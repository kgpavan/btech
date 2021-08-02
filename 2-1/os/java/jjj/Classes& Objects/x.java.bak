class x {
static final int max = 5;
static int count = 0;

x() {
if(count<max) {
count++;
System.out.println("current count is :" + count);
}
else{
 System.out.println("error cannot allocate");
 System.exit(1);
}
}
protected void finalize() {
count--;
System.out.println("current count is :" + count);
}
static void f() {
x ob = new x();
ob.finalize();
}
public static void main(String args[]) {
  int i;
for(i=0;i<5;i++)  {
 f();
 }
 //System.gc();
 System.out.println("current count is " + count);
}
}