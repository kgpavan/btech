#include<stdio.h>
long long int fact(int a)
{
	long long int f=1;
	int i;
	for(i=a;i>=1;i--)
		f=f*i;
	return f;
}
main()
{
	int n,k,i;
	scanf("%d %d",&n,&k);
	int a[k],pro=1;
	long long int num,den;
	for(i=1;i<=k;i++)
	scanf("%d",&a[i]);
	num=fact(n);
	for(i=1;i<=k;i++)
	{
		den=fact(a[i]);
		pro=pro*den;
	}
	printf("%d",num/pro);
}


