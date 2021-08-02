#include<stdio.h>
main()
{
	int input,y;
	scanf("%d",&input);
	for(y=0;y<input;y++)
	{
		int n;
		scanf("%d",&n);
		int arr[1000000],arr2[1000000];
		int i=0;
		while(i<n)
		{
			scanf("%d",&arr[i]);
			arr2[i]=-1;
			i++;
		}
		int flag=0;
		i=n-1;
		while(i>=0)
		{

			if(flag==0)
			{
				arr2[flag]=arr[i];
				flag++;
			}
			else if( arr[i]>arr2[flag-1] )
			{
				arr2[flag]=arr[i];
				flag++;
			}
			else if( arr[i]<arr2[flag-1] )
			{
				arr2[flag-1]=arr[i];
			}
			i--;
		}
		flag=0;
		while(arr2[flag]!=-1 && flag<n)
			flag++;
		printf("%d\n",flag);
	}
}


