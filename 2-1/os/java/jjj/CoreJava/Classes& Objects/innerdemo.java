class outer {
int outer_x = 100;
void test(){
int s;
Inner in = new Inner();
in.display();
}
class Inner{
int y=10;
void display(){
System.out.println("display : outer_x " + outer_x);
  }
}
Inner p = new Inner();
void showy(){
System.out.println("sample");
 }
}
class innerdemo{
 public static void main(String args[])  {
 outer o = new outer();
// Inner ins1 = new Inner();
 //ins1.display();
 //ins1.showy();
 o.test();
 o.p.display();
  }
}