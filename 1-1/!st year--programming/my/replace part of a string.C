#include <stdio.h>
#include <conio.h>
void main()
{
char one[50],two[50],last[50];
char *a,*b,*c;
int i,j,flag,n2,n1,pos,k;
clrscr();
printf("enter 1st string\n");
gets(one);
printf("enter d part\n");
gets(two);
printf("enter replacable part\n");
gets(last);
a=one;
b=two;
c=last;
n1=strlen(one);
n2=strlen(two);
for(i=0;i<n1;i++)
{
flag=0;
if(*a==*b)
{
for(j=0;j<n2;j++)
{
if(*a==*b)
{
a++;
b++;
flag++;
}
else
break;
}
}
else
{
a=one;
b=two;
a=a+i+1;
}
if(flag==n2)
{
pos=i;
break;
}
}
a=one;
for(k=0;k<pos;k++)
{
printf("%c",*a);
a++;
}
while(*c!='\0')
{
printf("%c",*c);
c++;
}
a=a+n2;
for(k=pos+n2;k<n1;k++)
{
printf("%c",*a);
a++;
}
}




