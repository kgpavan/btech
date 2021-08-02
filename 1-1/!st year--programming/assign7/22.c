#include<stdio.h>
#include<string.h>
main()
{
	int a[1000],flag,max,pos,my;
	scanf("%s",a);
	int count,i;
	count=strlen(a);
	int j;
	max=0;
	pos=0;
	for(i=0;i<count;i++)
	{
		flag=0,my=0;
		if(a[i]=='(')
		{
			for(j=i;j<count;j++)
			{
				if(a[j]=='(')
					flag++;
				else
					flag--;
				my++;
				if(flag==0)
					break;
				
			if(my>max)
			{
				max=my;
				pos=i;
			}
			printf("%d",max);
		}
	}
	for(j=pos;j<pos+max;j++)
		printf("%c",a[j]);	
	if(max==0)
		printf("empty");
	printf("\n");
}








