//this keyword demo
class point1 {
int x,y;
void init(int x,int y) {
this.x=x;
this.y=y;
}
void display() {
System.out.println("X value is" + x);
System.out.println("Y value is" + y);
   }
}
class Point {
public static void main(String args[]) {
  point1 p1 = new point1();
  p1.init(3,5);
  p1.display();
}
}