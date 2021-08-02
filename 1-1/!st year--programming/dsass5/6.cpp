#include<iostream>
#include<deque>
#include<queue>
using namespace std;
main()
{
	int i,j,n,d,m;
	char ch;
	scanf("%d",&m);
	for(d=0;d<m;d++)
	{
		int flag=0;
		scanf("%d",&n);
		queue<int> q;
		int a[n+1][n+1],b[100000]={0};
		char c[n+1][n+1];
		int count;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				scanf(" %c",&c[i][j]);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(c[i][j]=='Y' && c[j][i]=='Y')

				{
					c[i][j]='N';
					c[j][i]='N';
				}
				else if(c[i][j]=='Y')
					b[j]++;
			}
		}

		for(i=1;i<=n;i++)
		{
			int counter=0;
			for(j=1;j<=n;j++)
			{
			//	scanf(" %c",&c[i][j]);
				if(c[i][j]=='Y')
				{
					a[i][counter]=j;
					counter++;
				}
			}
			a[i][counter]=-1;
		}
		for(j=1;j<=n;j++)
		{
			if(b[j]==0)
			{
				q.push(j);
			}
		}
		if(q.empty())
		{
			printf("NO\n");
			continue;
		}
		while(!q.empty())
		{
			int v=q.front();
			q.pop();
			flag++;
			for(j=0;;j++)
			{
				if(a[v][j]==-1)
					break;
				b[a[v][j]]--;
				if(b[a[v][j]]==0)
					q.push(a[v][j]);
			}
		}
		if(flag==n)
			printf("YES\n");
		else
			printf("NO\n");
		ch=getchar();
	}
}
