class Cone 
{
  final double pi=3.1415;
  double radius,height,slheight,volume,area;

  double sqrt(double y)  {
    double z;
	z=Math.pow(y,0.5);
	return z;
	}
	Cone(double r,double h)
	{
	  radius = r;
	  height=h;
	  slheight= sqrt(r*r + h*h);
	  volume = (pi*r*r*h)/3;
	  area= pi*r*sqrt(r*r + h*h);
	  }
  void  display()
  {
    System.out.println("\nHeight =" + height + "\nRadius=" + radius + "\nSlant Height=" + slheight + "\nVolume=" + volume + "\nArea=" + area);
	}

	public static void main(String args[]) {

	  Cone x;
	  x = new Cone(5.0,12.0);
	  x.display();
}
}