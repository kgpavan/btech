class DeCls
{
    private int i,j,k;
	/*private void getdata(int a,int b)
	{
		i=a;
		j=b;
	   k=i+j;
	}
	private void display()
	{
		 System.out.println(k);
	}*/
	public static void main(String[] args) 
	{
	  DeCls dc= new DeCls();
	  dc.i=90;
	  dc.j=80;
	  dc.k=dc.i+dc.j;

	  //dc.getdata(10,20);
	  //dc.display();
	  System.out.println(dc.k);
	}
}
