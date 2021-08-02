/* minimum spannning tree ....using prims algorithm*/
# include<iostream>
# include<vector>
# include<queue>
# define infinity 20000
using namespace std;
int compare (int a,int b)
{
	if (a>b)
		return 1;
	else
		return 0;
}
int min(int dist[],int vertex,int mark[])
{
	int i,minimum=infinity,x;
	for (i=1;i<=vertex;i++)
		if (dist[i]<minimum && mark[i]==0)
		{
			minimum=dist[i];
			x=i;
		}
	return x;
}
int main()
{
	int vertex,edges,i;
	cin>>vertex;
	cin>>edges;
	vector <int> a[vertex+1];
	int wt[vertex+1][vertex+1];
	
	int mark[vertex+1];
	int dist[vertex+1];
	int pre_ver[vertex+1];
	for (i=0;i<=vertex;i++)
		dist[i]=infinity;
	for (i=1;i<=vertex;i++)
		mark[i]=0;
	for ( i=0;i<edges;i++)
	{
		int t1,t2,t3;
		cin>>t1;
		cin>>t2;
		cin>>t3;
		a[t1].push_back(t2);
		a[t2].push_back(t1);
		wt[t1][t2]=t3;
		wt[t2][t1]=t3;
		
	}
	int neg=0;
	for(i=1;i<=vertex;i++)
		if(a[i].size()==0)
			neg++;
	int p,count=0,temp=-1;
	
	cin>>p;
//	p=1;
	
	dist[p]=0;
	pre_ver[p]=-1;
	
	while (1)
	{
		int t1=min(dist,vertex,mark);
		mark[t1]=1;
		for (i=0;i<a[t1].size();i++)
		{
			if(dist[a[t1][i]]>wt[t1][a[t1][i]] && mark[a[t1][i]]==0)
			{
				
				dist[a[t1][i]]=wt[t1][a[t1][i]];
				pre_ver[a[t1][i]]=t1;
				
			}
		}
		count++;
		if (count==(vertex-neg))
			break;

	}
	int flag=0;
	for (i=1;i<=vertex;i++)
	{
		if(pre_ver[i]==-1)
			flag++;
		if (flag==2)
			break;
	}

	if (flag==1)
	{

		int cost=0;
		for (i=1;i<=vertex;i++)
		{
			if (pre_ver[i]!=-1 && a[i].size()!=0)
			{
				cout<<pre_ver[i]<<" "<<i<<endl;
				cost+=wt[pre_ver[i]][i];
			}
		}

		//cout<<"cost= "<<cost<<endl;
	}
	else
		cout<<"Impossible to print mst"<<endl;
	return 0;
}
