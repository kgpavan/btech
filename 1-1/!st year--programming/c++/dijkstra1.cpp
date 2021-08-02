#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int find_min(int d[],int l)
{
	if(l==1)
		return 1;
	int i,t=l,min=INT_MAX;
	for(i=2;i<=n;i++)
	{
		if(d[i]<min && d[i]>0)
		{
			min=d[i];
			t=i;
		}
	}
	return t;
}
int main()
{
	int i,j,t;
	cin>>n;
	int d[n+n],D[n+n],wt[n+n][n+n],p[n+n];
	for(i=1;i<=n;i++)
		p[i]=0;	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>wt[i][j];
			if(wt[i][j]>0 && p[j]==0 && j!=1)
				p[j]=i;
		}
		d[i]=wt[i][1];
		if(d[i]==0 && i!=1)
			d[i]=INT_MAX;
//		cout<<p[i]<<endl;
	}
//	sort(d,d+n);
	for(i=1;i<=n;i++)
	{
		t=find_min(d,i);
//		cout<<t<<"******"<<endl;
		D[t]=d[t];
	//	cout<<d[5]<<" 5 "<<endl;//<<D[t]<<endl;
		for(j=1;j<=n;j++)
		{
			if(wt[t][j]>0 && j!=t && d[j]!=INT_MIN)
			{
				if((wt[t][j]+D[t])<d[j])
				{
					d[j]=wt[t][j]+D[t];
					p[j]=t;
				}
		//		if(t==3 && j==6)
		//			cout<<d[j]<<" "<<p[j]<<endl;
			}
		}
		d[t]=INT_MIN;
	}
	for(i=1;i<=n;i++)
		cout<<D[i]<<" "<<p[i]<<endl;
	return 0;
}

