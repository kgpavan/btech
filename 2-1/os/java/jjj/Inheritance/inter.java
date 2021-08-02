import java.lang.*;

interface area {
int v1=20;
float compute(float x,float y);
}

class rectangle implements area {
public float compute(float x,float y) {
return(x*y);
}
public void test(){
System.out.println("the value is" + v1);
 } 
 }

class circle implements area {
public float compute(float x,float y) {
float pi=3.1415f;
return(pi*x*x);
}
}


class inter {
float p;
public static void main(String args[]){

rectangle ob = new rectangle();
System.out.println("The area of rectangle is" + ob.compute(5,2));
ob.test();

circle cr = new circle();
System.out.println("The area of circle is" + cr.compute(5,0));

area a = new rectangle();
System.out.println("The area is" + a.compute(5,1));

((rectangle) a).test();

  }
 }