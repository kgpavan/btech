#include<stdio.h>
#include<math.h>
main()
{
	int n,count1,count,y,x,a,i,k;
	scanf("%d",&k);
	while(k--)
	{
		count1=0;
		int b[32]={0};
	scanf("%d",&n);
	a=n;
	while(a>0)
	{
		a=a/10;
		count1++;
	}
//	printf("count%d\n",count1);
for(i=0;i<32;i++)
	b[i]=pow(2,i);
 for(i=0;i<32;i++)
 {
	 count=0;
	 y=b[i];
	 while(y>0)
	 {
		 y=y/10;
		 count++;//printf("%d",count);
		 if(y==n&&count>count1)
		 {
			 x=i;
			 break;
		 }
	 }
	 if(y==n)
		 break;
 }
// printf("x=%d\n",x);
 if(count>count1)
	 printf("%d\n",b[x]);
 else
	 printf("no power of 2\n");
	}
}

