#include<stdio.h>
#include<string.h>
main()
{
	int n,m,i,k,j;
	scanf("%d%d", &n,&m);
	char a[10000][1000];
	int b[10000];
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
		b[i]=0;
	}
	char s[1000];
	int max;
	char temp[100];
	for(i=0;i<m;i++)
	{
		scanf("%s",s);
		//printf("%s\n",s);
		if(strcmp(s,"PRINT")==0)
		{

			max=-10000;
			for(j=0;j<n;j++)
			{
				if(b[j]>max)
				{
					max=b[j];
					k=j;
				}
			}
			printf("%s\n",a[k]);
		}
		else if(strcmp(s,"Withdraw")==0)
		{
			char z[10000];
			scanf("%s",z);
			for(j=0;j<n;j++)
			{
				if(strcmp(z,a[j])==0)
				{
					//temp=a[j];
				//	a[j]=a[n-1];
				//	a[n-1]=temp;
					strcpy(a[j],a[n-1]);
					b[j]=b[n-1];
					n=n-1;
				}
			}
		}
		else
		{
			int val;
			char g;
			
			scanf("%d",&val);
			
//			printf("=========%d\n",val);
			scanf(" %c",&g);
			
			for(j=0;j<n;j++)
			{
				if(strcmp(s,a[j])==0)
				{
					//int val;
				//	ch//ar g;
				///	scanf("%d",&val);
				//	scanf("%c",&g);
					if(g=='A')
						b[j]=b[j]+val;
					else if(g=='R')
						b[j]=b[j]-val;
				}
			}
		}
	}
}
