#include<stdio.h>
#include<string.h>
main()
{
	int flag,max,pos,my;
        char a[1000];
	scanf("%s",a);
	int count,i;
	count=strlen(a);
	int j;
	max=0;
	pos=0;
//	printf("count=%d\n",count);
//	printf("%s\n",a);
//	for(i=0;i<count;i++)
//		printf("a[%d]=%c\n",i,a[i]);
	for(i=0;i<count;i++)
	{
		flag=0,my=0;
		if(a[i]==40)
		{
		//	printf("i=%d\n",i);
			for(j=i;j<count;j++)
			{
				if(a[j]==40)
					flag++;
				else
					flag--;
                                        
//				printf("flag=%d\n",flag);
					my++;
				if(flag==0)
				{	
//					printf("%d %d %d\n",my,i,j);			
			     if(my>max)
			     {
				max=my;
				pos=i;
			      }
				break;
				}
		//	printf("%d",max);
		}
	}}
	for(j=pos;j<pos+max;j++)
		printf("%c",a[j]);	
	if(max==0)
		printf("empty");
	printf("\n");
}








