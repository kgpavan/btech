#include<stdio.h>
#include<math.h>
main()
{
	int n,sex=0,k=0,i,b,c,d,e,j,fuck;
	 scanf("%d",&n);
	int a[n];
	for(i=2;i<n;i++)
	{
		int flag=0;
		fuck=sqrt(i);
		j=2;
		while(j<=fuck)
		{
	//	for(j=2;j<=fuck;j++)
	//	{
			if(i%j==0)
			{
				flag=1;
				break;
			}
			j++;
		}
		if(flag==0)
		{
			a[k]=i;
			k++;
		}
	}
	for(b=0;b<k;b++)
	{
		for(c=0;c<k;c++)
		{
			for(d=0;d<k;d++)
			{
				for(e=0;e<k;e++)
				{
					if(a[b]+a[c]+a[d]+a[e]==n)
					{
						printf("%d %d %d %d",a[b],a[c],a[d],a[e]);
						sex=1;
						break;
					}
			//		if(sex==1)
			//			break;
				}
				if(sex==1)
					break;
			}
			if(sex==1)
				break;
		}
		if(sex==1)
			break;
	}
if(sex==0)
	printf("impossible");
}
