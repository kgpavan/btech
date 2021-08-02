class figure{
double dim1;
double dim2;
figure(double a, double b)
{
System.out.println("");

}
figure()
{
 System.out.println("inside base class");
 }
double area()
{
   System.out.println("Inside area for figure ");
   return(0);
}

}
class rectangle extends figure{
rectangle(double a, double b)
{
  dim1 = a;
  dim2 = b;
}
double area()
{
   System.out.println("Inside area for rectagnle ");
   return(dim1 * dim2);
}
}


class triangle extends figure{
triangle(double a, double b)
{
  dim1 = a;
  dim2 = b;
}
double area()
{
   System.out.println("Inside area for triangle ");
   return( 0.5 * dim1 * dim2);
}
}

class findarea
{
  public static void main(String args[])
  {
     figure f = new figure(1,1);
     rectangle r = new rectangle(5,10);
     triangle t = new triangle(10,5);
     double p;
     p = f.area();
     System.out.println(p);
     p = r.area();
     System.out.println(p);
     p = t.area();
     System.out.println(p);
     figure refer;
     refer = r;
     p = refer.area();
     System.out.println(p);
     refer = t;
     p = refer.area();
     System.out.println(p);
  }
}
