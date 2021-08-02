#include<stdio.h>
void sort_even(int a[],int n)
{
	int i,j;
	//for(i=0;i<n;i=i+2)
	//	 b[i/2]=a[i];
	for(i=0;i<n;i+=2)
	{
		for(j=0;j<n-i-2;j+=2)
		{
			if(a[j]>a[j+2])
			{
				int temp=a[j];
				a[j]=a[j+2];
				a[j+2]=temp;
			}
		}
	}
	for(j=0;j<n;j+=2)
	printf("%d ",a[j]);
}
main()
{
	int n,i;
	scanf("%d",&n);
	int a[n],b[2*n];
	for(i=0;i<n;i=i++)
		scanf("%d",&a[i]);
	int j=0;
	for(i=0;i<2*n;i+=2)
	{
		b[i]=a[j];
		j++;
	}
	sort_even(b,2*n);
	printf("\n");	
}

