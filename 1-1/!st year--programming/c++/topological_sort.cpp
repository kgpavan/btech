#include<iostream>
using namespace std;
int main()
{
	int arr[100][100]={0};
	int indeg[100]={0};
	int n,x=1,t=1,f=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		while(x!=-1)
		{
			cin>>x;
			if(x==-1)
			{
				x=1;
				arr[t][f]=-1;
				break;
			}
			else
			{
				arr[t][f]=x;
			}
			f++;
		}
		f=1;
		t++;
	}
	for(int i=1;i<=n;i++)
	{
			cout<<"elements of " <<i<<" are ";
		for(int j=1;arr[i][j]!=-1;j++)
			cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;arr[i][j]!=-1;j++)
			{
				if(arr[i][j]==k)
					indeg[k]++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(indeg[i]>=0)
		{
			cout<<"indegree of "<<i<<" is "<<indeg[i]<<"\n";
			continue;
		}
	}
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(arr[i][0]!=-1)
			{
				if(indeg[i]==0)
				{
					cout<<i<<" ";
					int x=1;
					arr[i][0]=-1;
					while(x<=n)
					{
						if(arr[i][x]!=-1)
							indeg[arr[i][x]]--;
						else 
							break;
						x++;
					}
					break;
				}
			}

		}
	}
	cout<<"\n";
	return 0;	
}
