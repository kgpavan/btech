
class tool
{
 double width;
 double height;
 double depth;
}

class tooldemo
{
public static void main(String args[])
{
 tool t1 = new tool();

 double vol;

 t1.width=10;
 t1.height=20;
 t1.depth=30;

 vol = t1.width*t1.height*t1.depth;

 System.out.println("Volume is" + vol);

 }
}



