//find d union of 2 integer array where d elements in an array r not necessarily distinct
//ex 2,1,3,2,4,5,1,2
//   1,3,6,7,1,2,8,6
//output: 2,1,3,4,5,6,7,8
#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int a[n],i,j,b[n];
	for(i=0;i<n;i++)
		scanf("%d".&a[i]);
	for(j=0;j<n;j++)
		scanf("%d".&b[j]);
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
			{
				flag=1;
				break;
			}
			if(flag==0)
				printf("%d",a[i]);
		}
	}
	for(j=0;j<n;j++)
	{
		flag=0;
		for(i=0;i<n;i++)
		{
			if(b[j]==a[i])
			{
				flag=1;
				break;
			}
			if(flag==0)
				printf("%d",b[j]);
		}
	}

}
	
