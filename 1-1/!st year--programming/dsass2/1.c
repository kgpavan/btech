#include<stdio.h>
main()
{
	int input,y,j;
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
			arr2[i]=0;
			i++;
		}
		arr2[i+1]=0;
		int flag=1,p=0;
		i=0;
		while(i<n)
		{
			flag=1;
			for(j=0;j<p;j++)
			{
				if(arr[i]>arr2[j])
				{
					
					arr2[j]=arr[i];
			//		printf("%d\n",arr2[j]);
					flag=0;
					break;
				}
			}
			if(flag==1)
			{
				arr2[p]=arr[i];
				p++;
			}
			i++;			
		}
		
	printf("%d\n",p);
	}
}


