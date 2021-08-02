# include <iostream>
using namespace std;
int wt=0;
int check(int n,int mark[])
{
	if (mark[n]==0)
		return 0;
	if (mark[n]==n)
		return n;
	return(check(mark[n],mark));
}

void func(int n1,int n2,int mark[],int base,int add)
{
	int p1,p2,p;
	p1=check(n1,mark);
	p2=check(n2,mark);
	if (p1==0 && p2==0)
		p=1;
	else if (p1==p2)
		p=0;
	else p=1;
	if (p==1)
		wt=wt+add;
	else return;
	if (mark[n1]==0 && mark[n2]==0)
	{
		if (n1==base || n2==base)
		{
			mark[n1]=base;
			mark[n2]=base;
		}
		else 
		{
			mark[n1]=n1;
			mark[n2]=n1;
		}
		return;
	}
	
	if (mark[n2]==base)
	{
		p1=check(n1,mark);
		mark[p1]=n2;
	}
	else 
	{
		p2=check(n2,mark);
		mark[p2]=n1;
		
	}
	return;
}

int main()
{
	int no,i,temp,k;
	scanf("%d",&no);
	int j,mark[no+1],arr[no+1][3];
	for(i=0;i<=no;i++)
		mark[i]=i;
	for(i=1;i<=no;i++)
		for(j=0;j<3;j++)
			cin>>arr[i][j];
	for(i=1;i<no;i++)
	{
		for(j=i+1;j<=no;j++)
		{
			if (arr[i][2]>arr[j][2])
			{
				for(k=0;k<3;k++)
				{
					temp=arr[i][k];
					arr[i][k]=arr[j][k];
					arr[j][k]=temp;
				}
			}
		}
	}
/*	for(i=1;i<=no;i++)
		cout<<endl<<arr[i][0]<<"  "<<arr[i][1]<<"  "<<arr[i][2];
	cout<<endl;
	for(i=1;i<=no;i++)
		cout<<i<<" ";
	cout<<endl;*/
	for(i=1;i<=no;i++)
	{
		func(arr[i][0],arr[i][1],mark,arr[1][0],arr[i][2]);
		for(j=1;j<=no;j++)
			printf("%d ",mark[j]);
		printf("\n");
	}
	cout<<endl;
	
	cout<<"\n Min wt="<<wt<<endl;
	return 0;
}
