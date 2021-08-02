class wood {
String type="teak";
String finish = "coarse";

void showdets() {
System.out.println("type of the wood" + type);
System.out.println("Finish is" + finish);
   }
}
class wtable1 extends wood {
int legs=4;

void show() {
System.out.println("woodtype" + type);
System.out.println("finish" + finish);
System.out.println("Legs" + legs);
}
public static void main(String args[]) {
wtable1 w = new wtable1();
w.show();
w.showdets();
 }
}