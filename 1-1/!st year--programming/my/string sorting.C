#include <stdio.h>
#include <conio.h>
void main()
{
int i,j,k,v,n,l,flag1,flag2;
char t;
char name[4][50];
clrscr();
//printf("how many names sony.....\n");
//scanf("%d",&n);
for(i=0;i<=3;i++)
{
	printf("enter d string\n");
	gets(&name[i][0]);
}
printf("u entered...\n");
for(i=0;i<=3;i++)
{
	puts(&name[i][0]);
}
for(i=0;i<3;i++)
{
for(l=i+1;l<4;l++)
{
	for(j=0;j<50;j++)
	{
		flag1=0;
		flag2=0;
	  if(name[i][j]<91 && name[i][j]>65)
	  {
		 name[i][j]=name[i][j]+32;
		 flag1=1;
	  }
	  if(name[l][j]<91 && name[l][j]>65)
	  {
		 name[l][j]=name[l][j]+32;
		 flag2=2;
	  }


	v=name[i][j]-name[l][j];
	if(flag1==1)
		name[i][j]=name[i][j]-32;
	if(flag2==2)
		name[l][j]-=32;

		if(v>0)
		{
			for(k=0;k<50;k++)
			{
				t=name[i][k];
				name[i][k]=name[l][k];
				name[l][k]=t;
			}
			break;
		}
		else if(v<0)
		{
			break;
		}
	}
	}
}

printf("after sorting.........\n");
for(i=0;i<4;i++)

{
	puts(&name[i][0]);
	printf("\n");
}

}


































































































































