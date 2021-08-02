#include<stdio.h>
main()
{
	int n,k,a,sum,b,l=0;
	scanf("%d",&n);
	k=1;
		while(k<n)
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
				printf("%d %d",k,sum);
				l=1;
				
			}
					
			
					
			}
		k++;
	}
		if(l==0)
			printf("No Output");

		}
