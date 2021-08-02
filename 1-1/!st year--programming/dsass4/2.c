#include<stdio.h>
#include<string.h>
main()
{
	int n,score,i,j,k;
	scanf("%d",&n);
	char c[10];
	char s[100];
	int count=0;
	char d[n][100];
	int b[100];
	for(i=0;i<n;i++)
	{
		scanf("%s",c);
		if(c[0]=='I')
		{
			int fly=0;
			scanf("%s",s);
		//	strcpy(v[counter],s);
			scanf("%d",&score);
		//	b[count]=score;
		//	counter++;
		//	//printf("1\n");
			for(j=0;j<count;j++)
			{
				if(strcmp(s,d[j])==0)
				{
				//	printf("0\n");
					fly=1;
					break;
				}
				else
				{
					fly=0;
				}

				//	printf("1\n");
			}
			if(fly==0)
			{
				printf("1\n");
				strcpy(d[count],s);
				b[count]=score;

				count++;
			}
			else
				printf("0\n");

		}
		else if(c[0]=='D')
		{
			scanf("%s",s);
			int go=0;
			for(j=0;j<count;j++)
			{
				if(strcmp(s,d[j])==0)
				{
					printf("1\n");
					go=1;
					strcpy(d[j],d[count-1]);
					b[j]=b[count-1];
					count--;
					break;
				}
			}
			if(go==0)
				printf("0\n");
		}
		else if(c[0]=='M')
		{
			if(count==0)
				printf("NONE\n");
			else
			{
				//		printf("fdsaffas");
				int max=-10000;
				int k;
				for(j=0;j<count;j++)
				{
					if(b[j]>max)
					{
						max=b[j];
						k=j;
					}
				}
				printf("%s\n",d[k]);
			}
		}
		else if(c[0]=='S')
		{
			int flag=0;
			scanf("%s",s);
			for(j=0;j<count;j++)
			{
				if(strcmp(s,d[j])==0)
				{
					printf("1\n");
					flag=1;
					break;
				}
			}
			if(flag==0)
				printf("0\n");
		}
	}
}




