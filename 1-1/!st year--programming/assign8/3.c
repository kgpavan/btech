#include<stdio.h>
#include<math.h>
main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		
		if(n==0)
			printf("0\n");
		else if(n==1)
			printf("1\n");
		else if(n==2)
			printf("3\n");
		else if(n==3)
			printf("5\n");
		else
		{
			int i=3,a=5,flag=0,y,s;
			for(s=2; ; s++)
			{
				for(y=0;y<=s;y++)
				{
					a=a+pow(2,s);
					i++;
					if(i==n)
					{
						printf("%d\n",a);
						flag=1;
						break;
					}
				}
			if(flag==1)
				break;
			}
		}
	}
}
