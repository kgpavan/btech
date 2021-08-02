class tool {
 double width;
 double height;
 double depth;

 tool(int w,int h,int d) {
   width=w;
   height=h;
   depth=d;
  }
double volume() {
return width*height*depth;
}
}
class tooldemo {
public static void main(String args[]){
 tool t1 = new tool(10,20,30);
 tool t2 = new tool(5,6,7);

 double vol;
 vol= t1.volume();
 System.out.println("The volume is" + vol);

 vol=t2.volume();
 System.out.println("The volume is" + vol);
 }
}