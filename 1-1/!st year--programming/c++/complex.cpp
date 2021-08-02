#include<iostream>
#include<cmath>
using namespace std;
class complexnum
{
	private:
		int re,im;
	public:
		void putvalues(int rp,int ip)
		{
			re=rp;
			im=ip;
		}
		void print()
		{
			cout<<"real part="<<re<<endl<<"imaginary part="<<im<<endl;
		}
		complexnum add(complexnum b)
		{
			complexnum ans;
			ans.re=re+b.re;
			ans.im=im+b.im;
			return ans;
		}
};
main()
{
	complexnum a,b,c;
	a.putvalues(5,2);
	b.putvalues(1,3);
	a.print();
	b.print();
	c=a.add(b);
	c.print();
}


