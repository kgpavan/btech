#include<iostream>
#include<deque>
#include<queue>
using namespace std;
main()
{
	int i,j,n;
	scanf("%d",&n);
	queue<int> q;
	int a[100][100],b[n];
	for(i=1;i<=n;i++)
		for(j=0;;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]==-1)
				break;
		}
	int count;
	for(j=1;j<=n;j++)
		b[j]=0;
	for(count=1;count<=n;count++)
		for(i=1;i<=n;i++)
			for(j=0;;j++)
			{
				if(a[i][j]==count)
					b[count]++;
				if(a[i][j]==-1)
					break;
			}
	for(j=1;j<=n;j++)
	{
		if(b[j]==0)
		{
			q.push(j);
			break;
		}
	}
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		printf("%d ",v);
		for(j=0;;j++)
		{
			if(a[v][j]==-1)
				break;
			b[a[v][j]]--;
			if(b[a[v][j]]==0)
				q.push(a[v][j]);
		}
	}
}

			

			
