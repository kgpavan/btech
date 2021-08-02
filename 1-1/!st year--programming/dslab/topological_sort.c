#include<stdio.h>
//void topo(int x)
//{
//	int count;
//	for(count=0;;count++)
//	{
//	}
//}

main()
{
	printf("enter the no of rows:");
	int n;
	scanf("%d",&n);
	int arr[1000][1000];
	int b[1000];
	int i,j;
	int count=0;
	for(i=0;i<n;i++)
	{
		for(j=0;;j++)
		{
			scanf("%d",&arr[i][j]);
			b[count]=arr[i][j];
			count++;
			if(arr[i][j]==-1)
			{
				break;
			}
		}
	}
	int indegree[1000];
/*	for(i=0;i<count;i++)
	{
		int flag=0;
		int g=b[i];
		for(i=1;i<count;i++)
		{
			if(b[i]==g)
				flag++;
		}
		printf("indegree of %d is %d\n",g,flag);
		}*/
	int flag,number,k;
	for(flag=1;flag<=7;flag++)
	{
		int number=0;

		for(i=0;i<count;i++)
		{
			//	int number=1;
			if(b[i]==flag)
				number++;
			//	else
			//		continue;
			///	printf("indegree of %d is %d\n",flag,number);
			//flag++;
		}
		indegree[flag]=number;
		printf("indegree of %d is %d\n",flag,number);
//		if(number==0)
//			int k=flag;
	}
	printf("k=%d\n",k);
//	for(i=0;;i++)
//		printf("%d\n",arr[k][i]);
	//		indegree[(arr[k][i])]--;
	//	for(flag=1;flag<=7;flag++)
	//		printf("indegree of %d is %d\n",flag,indegree[flag]);
	//

}














