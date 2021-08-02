#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int find_min(int arr[],int l)
{
	int i,k;
	int min=999999;
	for(i=0;i<l;i++)
	{
		if(arr[i]<min)
			min=arr[i];
	}
	return min;
}
main()
{
	int i,j,n;
	scanf("%d",&n);
	queue<int> q;
	int a[n][n],b[n];
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	int cost[n],known[n],path[n];
	for(i=1;i<=n;i++)
	{
		cost[i]=INT_MAX;
		known[i]=0;
		path[i]=0;
	}
	cost[1]=0;
	q.push(1);
	int count=0;
	int g,l;
	while(!q.empty())
	{
		for(int k=0;k<count;k++)
			b[k]=0;
		count=0;
		int v=q.front();
//		printf("%d",v);
		q.pop();
		//		cout << "size of the queeu : "<< q.size()<< endl;
		known[v]=1;
		for(j=1;j<=n;j++)
		{
			if(known[j]!=1)
			{
				if(a[v][j]!=0)
				{
					b[count]=a[v][j];
					count++;
				}
			}
		}
		if(count!=0)
		{

			int g=find_min(b,count);
		}
		printf("g=%dtttttttt\n",g);
		for(i=1;i<=n;i++)
		{
			if(a[v][i]==g)
			{
				int l=i;
				break;
			}
		}
		printf("l is %d\n",l);
		q.push(l);
		cout << "size of the queeu : "<< q.size()<< endl;
		for(j=1;j<=n;j++)
		{
			if(known[j]!=1)
			{
				if(a[v][j]!=0)
				{
					if(cost[j]>a[v][j])
					{
						cost[j]=a[v][j];
						path[j]=v;
					}
				}
			}
		}
//		break;
	}
//	for(i=1;i<=n;i++)
//
//		printf("%d     %d",i,path[i]);
}






