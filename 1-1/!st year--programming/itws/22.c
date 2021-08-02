// given an array of int......4 each unique value print d no of times it occurs in d array
//ex.1,3,2,1,4,2,3,5,6,2,8
//1-2
//3-2
//2-3etc
#include<stdio.h>
main()
{
	int n,i,j,count,l,flag;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		flag=0;
		count=0;
		for (l=i-1;l>=0;l--)
		{
			if(a[i]==a[l])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			for(j=i;j<n;j++)
			{
				if(a[i]==a[j])
					count++;
			}
			printf("%d  %d\n",a[i],count);
		}
	}

}


