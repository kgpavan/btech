#include<stdio.h>
main()
{
	int n,m,ns,nl,count=0,i,j,q[10000],b,k,w,h;
	scanf("%d %d",&n,&m);
	int s[10000][2],l[nl][2],v[10000][2],x[10000];
	scanf("%d",&ns);
	for(i=0;i<ns;i++)
		for(j=0;j<2;j++)
			scanf("%d",&s[i][j]);
	scanf("%d",&nl);
	for(i=0;i<nl;i++)
		for(j=0;j<2;j++)
			scanf("%d",&l[i][j]);
	for(i=0;;i++)
	{
		for(j=0;j<2;j++)
			scanf("%d",&v[i][j]);
		x[i]=v[i][0]+v[i][1];
		if(x[i]==0)
			break;
		count++;
	}
	//printf("%d\n",count);
	//for(i=0;i<=count;i++)
	//	printf("%d\n",x[i]);
	//
	for(i=1;i<=m;i++)
		q[i]=0;
	int t=1;int z=0;
	for(i=0;i<count;i++)
	{
		if(t>m)
			t=t-m;
		if(q[t]!=n*n)
		{
			b=n*n-q[t];
			if(x[i]>b)
				t++;
			else
			{
				q[t]=q[t]+x[i];
				if(q[t]==n*n-1)
				{
					q[t]=q[t]-x[i];
					t++;
				}
				else
				{
					for(j=0;j<ns;j++)
					{
						if(q[t]==s[j][0])
						{

							q[t]=s[j][1];
							printf("s %d %d %d %d\n",i+1,t,s[j][0],s[j][1]);
						}
					}
					for(j=0;j<nl;j++)
					{
						if(q[t]==l[j][0])
						{
							q[t]=l[j][1];
							printf("l %d %d %d %d\n",i+1,t,l[j][0],l[j][1]);
						}
					}
					int c=1;
					while(c<=m)
					{
						if((c!=t) && (q[c]!=n*n))
						{
							if(q[t]==q[c])
							{
								printf("k %d %d %d %d\n",i+1,t,c,q[t]);
								q[c]=0;
							}
						}
							c++;
					}
					if(q[t]==n*n)
					{
						printf("w %d %d\n",i+1,t);
					//	z=t;
					}
					t++;
				}
			}
		}
		else
		{
			i--;
			t++;
		}
//		printf("%d %d\n",t-1,q[t-1]);
	}
	t=1;
	while(t<=m)
	{
		printf("%d %d\n",t,q[t]);
		t++;
	}

}
