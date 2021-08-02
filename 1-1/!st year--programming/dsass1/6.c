#include<stdio.h>
main()
{
	int a[1000],k,e,j,i;
	char f[100];
//	for(i=0;i<50;i++)
//		a[i]=0;
	scanf("%d\n",&k);
	
	for(i=0;i<100;i++)
	{
		a[i]=0;
	}
	int flag=0;
	i=0;
	while(i<k)
	{

		gets(f);
		j=0;
		while(f[j]=='\t')
		{
			printf("\t");
			j++;
		}
		a[j]++;
		for(e=j+1;e<100;e++)
			a[e]=0;
		printf("%d ",a[j]);
		e=0;
		while(f[e]!='\0')
		{
			if(f[e]!='\t')
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
			if(flag==1)
			{
				printf("%c",f[e]);
			}
			e++;
		}
		printf("\n");
		i++;
	}
}


