#include<stdio.h>
main()
{
	char a[10000],b;
	int i=0,j,counter=0,counter1=0;
	while((b=getchar())!=EOF)
	{
		a[i]=b;
		i++;
	}
	for(j=0;j<i;j++)
	{
		if(a[j]=='/' && a[j+1]=='*')
		{
			counter++;
		}
		else if (a[j]=='/' && a[j-1]=='*')
		{
			counter1--;
		}
	}
	if((counter+counter1)!=0)
	{
		printf("Error Message\n");
	}
	else
	{
		for(j=0;j<i;j++)
		{
			if(a[j-1]=='/' && a[j]=='*')
			{
				a[j-1]='\0';
				a[j]='\0';
				while(a[j]!='/')
				{
					a[j]='\0';
					j++;
				}
				a[j]='\0';
				j++;
			}

		}
	for(j=0;j<i;j++)
	{
		if(a[j]!='\0')
		{
			printf("%c",a[j]);
		}
	}
	printf("\n");

	}
}

			





