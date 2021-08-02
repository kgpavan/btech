class test {
int a;
test(int i){
a=i;
}
//returning an object
test incrbyten() {
test temp = new test(a+10);
return temp;
  }
 }
class retob  {
public static void main(String args[])    {
test ob1 = new test(2);
test ob2;
ob2 = ob1.incrbyten();

System.out.println("ob1.a:" + ob1.a);
System.out.println("ob2.a:" + ob2.a);

ob2 = ob2.incrbyten();
System.out.println("ob2.a after the second increse" + ob2.a);
 }
}