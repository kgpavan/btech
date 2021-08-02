#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int fac(int x)
{
	if(x==1)
		return 1;
	else
		return (x*fac(x-1));
}
void main()
{
	char a[50];
	int l,i,num,den=1,b[26],t;
	char temp;
	//clrscr();
	scanf("%s",a);
	l=strlen(a);
	for(i=0;i<26;i++)
		b[i]=0;
	i=0;
	while(i<l)
	{
		t=a[i]-97;
		b[t]++;
		i++;
	}
	for(i=0;i<26;i++)
	{
		if(b[i]!=0)
		{
			den=den*fac(b[i]);
		}
	}
	num=fac(l);
	printf("%d",num/den);
}
