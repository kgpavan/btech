import java.lang.*;
class swapdemo {
	public static void main(String[] args)  {

    int a = Integer.parseInt(args[0]);
	int b = Integer.parseInt(args[1]);
	int c;

	System.out.println("****Before Swapping****");
	System.out.println(a  + "   " + b);

	c=a;
	a=b;
	b=c;
	System.out.println("****After Swapping****");
    System.out.println(a  + "   " + b);
	}
}

