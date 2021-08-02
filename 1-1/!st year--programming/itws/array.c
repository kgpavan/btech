// given 2 array wid distinct value
//print d integer that r common 2 both array
#include<stdio.h>
main()
{
	int n,i,j;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n;i++)
	{
         	for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
				printf("%d\n",a[i]);
		}
	}
}

	
