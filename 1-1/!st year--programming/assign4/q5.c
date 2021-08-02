#include<stdio.h>
main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n][n];
	for(i=1,j=n;i<=n,j<2*n;i++,j++)
	{
		a[i][j]=1;
	}
	for(i=1,j=n;i<=n,j>0;i++,j--)
	{
		a[i][j]=1;
	}
	   for(i=3,j=n;i<=n,j>0;i++,j--)
	   {
		   a[i][j]=a[i-1][j-1]+a[i-1][j+1];
	   }
	   for(i=4,j=n+1;i<=n,j<(2*n);i++,j++)
	   {
		   a[i][j]=a[i-1][j-1]+a[i-1][j+1];
	   }
	   for(i=1;i<=n;i++)
	   {
		   for(j=1;j<=((2*n)-1);j++)
		   {
			   printf("%d ",a[i][j]);
		   }
		   printf("\n");
	   }
}





