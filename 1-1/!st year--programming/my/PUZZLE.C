#include<stdio.h>
#include<conio.h>
#include<dos.h>
getkey()
{
	union REGS i,o;
	while(!kbhit())
		;
	i.h.ah=0;
	int86(22,&i,&o);
	return(o.h.ah);
}

void box()
{
	int c,r;
	for(r=20;r<=32;r=r+3)
	{
		for(c=30;c<=46;c++)
		{
			gotoxy(c,r);
			printf("%c",196);
		}
	}
	for(c=30;c<=46;c=c+4)
	{
		for(r=20;r<=32;r++)
		{
			gotoxy(c,r);
			printf("%c",179);
		}
	}
	for(c=34;c<=42;c=c+4)
	{
		for(r=23;r<=29;r=r+3)
		{
			gotoxy(c,r);
			printf("%c",197);
		}
	}
	for(r=23;r<=29;r=r+3)
	{
		gotoxy(30,r);
		printf("%c",195);
		gotoxy(46,r);
		printf("%c",180);
	}
	for(c=34;c<=42;c=c+4)
	{
		gotoxy(c,20);
		printf("%c",194);
		gotoxy(c,32);
		printf("%c",193);
	}
	gotoxy(30,20);
	printf("%c",218);
	gotoxy(46,20);
	printf("%c",191);
	gotoxy(30,32);
	printf("%c",192);
	gotoxy(46,32);
	printf("%c",217);
}
void display(int a[][4])
{
	int c,r,i=0,j=0;
	for(r=22;r<32;r=r+3)
	{
		for(c=32;c<46;c=c+4)
		{
			gotoxy(c,r);
			if(a[i][j]==0)
				printf(" ");
			else
				printf("%d",a[i][j]);
			j++;
		}
		i++;
		j=0;
	}
}
void main()
{
	int a[4][4] = {
			1,4,15,7,
			8,10,2,11,
			14,3,6,13,
			12,9,5,0
		      };
	char name[50];
	int ch,ch1,row=3,col=3,t,count=0,k,i,j,flag=0;
	clrscr();
	printf("ENTER THE NAME OF PLAYER\n");
	gets(name);
	box();
	display(a);
	while(1)
	{
		ch=getkey();
		if(ch==72)     /*for up arrow key*/
		{
			if(row==3)
				continue;
			else
			{
				t=a[row][col];
				a[row][col]=a[row+1][col];
				a[row+1][col]=t;
				row++;
				count++;
				clrscr();
				box();
				display(a);
			}
		}
		else if(ch==80)  /*for down arrow key*/
		{
			if(row==0)
				continue;
			else
			{
				t=a[row][col];
				a[row][col]=a[row-1][col];
				a[row-1][col]=t;
				row--;
				count++;
				clrscr();
				box();
				display(a);
			}
		}
		else if(ch==75)   /*for right arrow key*/
		{
			if(col==3)
				continue;
			else
			{
				t=a[row][col];
				a[row][col]=a[row][col+1];
				a[row][col+1]=t;
				col++;
				count++;
				clrscr();
				box();
				display(a);
			}
		}
		else if(ch==77)   /*for right arrow key*/
		{
			if(col==0)
				continue;
			else
			{
				t=a[row][col];
				a[row][col]=a[row][col-1];
				a[row][col-1]=t;
				col--;
				count++;
				clrscr();
				box();
				display(a);
			}
		}
		else if(ch==1)  /*for escape key*/
		{
			printf("\n");
			printf("\n\n\t\t DO YOU WANT TO QUIT THE GAME");
			printf("\n");
			printf("\n\n\t PRESS y FOR YES AND n FOR NO");
			ch1=getch();
			if(ch1=='y' || ch1=='Y')
				break;
			else

				continue;
		}

		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\t\tTOTAL NUMBER OF MOVES=%d\n",count);

		/*to check puzzle is solved*/
		k=1;
		for(i=0;i<4;i++)
		{
			for(j=1;j<4;j++)
			{
				if(a[i][j]==k)
				{
					if(k==15)
					{
						flag=1;
						break;
					}
					k++;
					continue;
				}
				else
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				break;
		}
		if(k==15)
		{
			printf("\n\n\n\t\tBRAVO! YOU WON");
			break;
		}
	}

}
