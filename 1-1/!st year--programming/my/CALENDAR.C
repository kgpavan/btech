#include<stdio.h>
#include<conio.h>
void calendar(int yy,int mm,int ff,int md)
{
	int i,c,r;
	char *day[]={
				"Mon",
				"Tue",
				"Wed",
				"Thu",
				"Fri",
				"Sat",
				"Sun"
		 };

	char *month[]={
				"JANUARY",
				"FEBRUARY",
				"MARCH",
				"APRIL",
				"MAY",
				"JUNE",
				"JULY",
				"AUGUST",
				"SEPTEMBER",
				"OCTOBER",
				"NOVEMBER",
				"DECEMBER"
			};

	gotoxy(30,10);
	printf("%s   %d",month[mm-1],yy);
	printf("\n");
	i=0;
	for(c=20;c<62;c=c+6)
	{
		gotoxy(c,15);
		printf(day[i]);
		i++;
	}
	r=20;
	c=20+(6*ff);
	for(i=1;i<=md;i++)
	{
		if(c>56)
		{
			c=20;
			r+=5;
		}
		gotoxy(c,r);
		printf("%d",i);
		c=c+6;
	}

}
void main()
{
	int y,i,m,ndays,ldays,mdays=0,fday,month_day,tdays;
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	clrscr();
	printf("Enter the year and month(number)\n");
	scanf("%d %d",&y,&m);


	ndays=(y-1)*365;
	ldays=((y-1)/4)-((y-1)/100)+((y-1)/400);
	tdays=ndays+ldays;   /*number of days till one year before*/


	if(((y%100)==0 && (y%4)==0) || ((y%400)==0 && (y%100)!=0))
		days[1]=29;
	else
		days[1]=28;


	for(i=0;i<m-1;i++)
		mdays=mdays+days[i];       /*calculate days till one month before in current year*/

	tdays=tdays+mdays;

	fday=tdays%7;            /*first day of the given month*/

	month_day=days[m-1];
	printf("\t\t\t\t\t%d  ",fday);
	calendar(y,m,fday,month_day);
}