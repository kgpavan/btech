#include<stdio.h>
//int fac(int x)
//{
//	if(x==1)
//		return 1;
//	else
//		return x*fac(x-1);
//}
main()
{
	int a;
	scanf("%d",&a);
	long double c=1.0,b=1;
	int i;
	for(i=2;i<=a;i++)
	{
		c=c*((a+i));
	}
	for(i=2;i<=a;i++)
		b=b*i;

	printf("%.0llf\n",c/b);
//	long long double c=((fac(2*a)/(fac(a)*fac(a)*(a+1))));
//	printf("%lld\n",c);
}
