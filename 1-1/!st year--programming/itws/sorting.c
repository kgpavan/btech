// arrange d array in ascending order
#include<stdio.h>
main()
{
	int n,i,j,x,temp,min;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[n]);
	for(i=0;i<n;i++)
	{
		min=a[i];
		for(j=i;j<n;j++)
		{
			if(a[j]>a[j+1])
			{
				min=a[j+1];
				x=j+1;
			}
		}
		temp=a[i];
		a[j]=a[x];
		a[x]=temp;
	}
	for(i=0;i<n;i++)
		printf("%d",&a[i]);
}
