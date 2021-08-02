#include<stdio.h>
main()
{
	int a,b,k,num,den,i,n,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d %d %d",&a,&b,&k);
	if(k%5==0)
	{
		num=a;
		den=1;
	}
	else if((k-1)%5==0)
	{
		num=b;
		den=1;
	}
	else if((k-2)%5==0)
	{
		num=1+b;
		den=a;
	}
	else if((k-3)%5==0)
	{
		num=1+a+b;
		den=a*b;
	}
	else if((k-4)%5==0)
	{
		num=1+a;
		den=b;
	}
if(num>den)
{
	for(j=den;j>1;j--)
	{
		if(num%j==0 && den%j==0)
		{
			num=num/j;
			den=den/j;
		}
	}
}
else if(den>num)
{
	for(j=num;j>1;j--)
	{
		if(num%j==0 && den%j==0)
		{
			num=num/j;
			den=den/j;
		}
	}
}
printf("%d/%d\n",num,den);
}
}
