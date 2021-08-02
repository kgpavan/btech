#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class dual
{
	public:
		int vertex;
		int value;

};
void dijkstra(int a[][3],int n,vector <vector <dual> > graph)
{
	int min,k,i,x;
	for(x=0;x<n;x++)
	{
		min=9999;
		for(i=0;i<n;i++)
		{
			if((min>a[i][1])&&(a[i][0]==0))
			{
				min=a[i][1];
				k=i;
			}
		}
		a[k][0]=1;
		for(i=0;i<graph[k].size();i++)
		{
			if(a[graph[k][i].vertex][0]==1)
				continue;
			else if((a[k][1]+graph[k][i].value)<a[graph[k][i].vertex][1])
			{
				a[graph[k][i].vertex][1]=a[k][1]+graph[k][i].value;
				a[graph[k][i].vertex][0]=0;
				a[graph[k][i].vertex][2]=k;
			}
		}
	}
	return;
}
int main()
{
	vector <vector <dual> > graph;
	vector <dual> temp;
	dual temp1;
	int n,d,val,home,i,v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		while(5)
		{
			cin>>v;
			if(v==-1)
				break;
			cin>>val;
			temp1.vertex=v-1;
			temp1.value=val;
			temp.push_back(temp1);
		}
		graph.push_back(temp);
	}
	int a[n][3];
	for(i=0;i<n;i++)
	{
		a[i][0]=0;
		a[i][1]=327856;
	}
	cin>>home;
	a[home-1][1]=0;
	dijkstra(a,n,graph);
	for(i=0;i<n;i++)
		cout<<i+1<<"\t"<<a[i][0]<<"\t"<<a[i][1]<<"\t"<<a[i][2]+1<<endl;
}
