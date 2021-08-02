#include<iostream>

using namespace std;

void getwt(int wt[][100],int j,char c[])
{
	int i,k,l,wgt;
	for(i=0,k=0,wgt=0;c[i]!='\0';i++)
	{
		while(c[i]!=' ')	
		{
			k=k*10 + c[i]-'0';
			i++;
		}
		i++;
		while(c[i]!=' '&&c[i]!='\0'&&c[i]!='\n')
		{
			wgt=wgt*10 + c[i]-'0';
			i++;
		}
		wt[j][k]=wgt;
	}
}



main()
{
	int nodes,i,j,k,min;
	char c[10000],a;
	cin>>nodes;
	int n[nodes],wt[nodes][nodes],mark[nodes],last[nodes],dist[nodes];
	for(i=0;i<nodes;i++)
	{
		scanf("%d",&j);
		n[j]=j;
		mark[j]=0;
		last[j]=0;
		dist[j]=10000000;
		for(k=0;k<nodes;k++)
			wt[i][k]=-100;
		a=getchar();
		gets(c);
		getwt(wt,j,c);
	}
	
	dist[0]=0;
	int pos;
	for(i=0;i<nodes;i++)
	{
		min=100000;
		for(j=0;j<nodes;j++)
		{
			if(dist[j]<min && mark[j]==0)
			{
				min=dist[j];
				pos=j;
			}
		}
		mark[pos]=1;

		for(j=0;j<nodes;j++)
		{
			if(wt[pos][j]!=-100)
			{
				if(min+wt[pos][j]<dist[j])
					dist[j]=wt[pos][j]+min;
				last[j]=pos;
			}
		}
	}
	for(i=0;i<nodes;i++)
	{
		cout<<mark[i]<<"\t"<<dist[i]<<"\t"<<last[i]<<"\n";
	}
}

