#include<stdio.h>
main()
{
	int n,k,a,sum,b,l=0,m,i;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		l=0;
		scanf("%d",&n);
		
		for(k=n-200;k<=n;k++)
	{
		b=k;
		sum=0;
		{
			while(b>0)
			{
				a=b%10;
				sum=sum+a;
				b=b/10;
			}
					if(n==k+sum)
			{
				printf("%d %d\n",k,sum);
				l=1;
				break;
			}
					
			
					
			}
		
	}
		if(l==0)
			printf("No Output\n");
	}

}
