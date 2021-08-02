#include<stdio.h>
main()
{
int n,i,c=0,j;
char a[i];
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%c",&a[i]);
}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		if(a[i]==a[j])
		{
			c++;
		}
	}
}
printf("%d",c);
}
