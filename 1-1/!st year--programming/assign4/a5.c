#include<stdio.h>
main()
{
	int n,i,j,k,count;
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++)
	{
		for(j=n;j>i;j--)
		{
			printf(" ");
                } 		
		if(i==0)
		{
			a[i][i]=1;
			printf("1");
		}
		else if(i==1)
                {
			a[i][0]=1;
			a[i][i]=1;
			printf("1 1");
		}
		else if(i>=2 && i<n) 
		{
			a[i][0]=1;
			a[i][i]=1;
			for(k=1;k<i;k++)
			{
				a[i][k]=a[i-1][k-1]+a[i-1][k];
			}
		
		for(count=0;count<=i;count++)
		{
			printf("%d ",a[i][count]);
		}
		}
		printf("\n");
	}	
}


