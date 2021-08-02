class x {
static final int max=5;
static int count=0;
static int p = 100;

x() {
if(count<max) {
count ++;
System.out.println("current count is:" +count);
}
else {
System.out.println("error can't allocate");
System.exit(1);
}
}
protected void finalize(){
p=count;
count --;
System.out.println("current count is from destructor is:" +count);
}

static void prf(){
System.out.println(p);
}
 
static void f() {
x ob = new x();
}
public static void main(String args[]) {
for(int i=0;i<5;i++)
{
f();
}
System.gc();
{
x p = new x();
p.finalize();
p.prf();
}
System.out.println("current count is:" +count);
}
}