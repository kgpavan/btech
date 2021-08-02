#include<stdio.h>
int max=0;
int r,c,n,x,b;
char a[1000][1000];
void find(int q,int w,int count)
{
	a[q][w]='@';
	int go=0;
	if((q-1)>=0 && a[q-1][w]=='.')
	{
		//a[q-1][w]='@';
		go=1;
		find(q-1,w,count+1);
	}
	if((q+1)<r && a[q+1][w]=='.')
	{
		//a[q+1][w]='@';
		go=1;
		find(q+1,w,count+1);
	}
	if((w-1)>=0 && a[q][w-1]=='.')
	{
		//a[q][w-1]='@';
		go=1;
		find(q,w-1,count+1);
	}
	if((w+1)<c && a[q][w+1]=='.')
	{
		//a[q][w+1]='@';
		go=1;
		find(q,w+1,count+1);
		
	}
	if(go==0)
	{
		if(count>max)
		{
			max=count;
			 x=q;
		 	b=w;
		}
	}
//	return max;
}



main()
{
	int j,i,v;
	scanf("%d",&v);
	getchar();
	int gh;
	for(gh=0;gh<v;gh++)
	{
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				scanf(" %c",&a[i][j]);

		int flag=0;
		for(i=0;i<r;i++)
		{	
			int flag1=0;
			for(j=0;j<c;j++)
			{	if(a[i][j]=='.')
				{
					flag1=1;
					find(i,j,flag);
					break;
				}
			}
			if(flag1==1)
				break;

		}
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(a[i][j]=='@')
					a[i][j]='.';

		find(x,b,flag);
		printf("%d\n",max);
		max=0;
	}
}




		

			

