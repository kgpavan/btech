#include<graphics.h>
#include<stdio.h>
void cross(int x,int y)
{
	line(x-20,y,x+20,y);
	line(x,y-20,x,y+20);
}
void main()
{
	int gd=DETECT,gm;
	int midx,midy,i,j;
	char msg[80]="Hello,Good Morning";
	char msg1[80],msg2[80];
	char *horizontal[]={
				"LEFT_TEXT",
				"CENTER_TEXT",
				"RIGHT_TEXT"
			};
	char *vertical[]={
				"BOTTOM_TEXT",
				"CENTER_TEXT",
				"TOP_TEXT"
			};
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	midx=getmaxx()/2;
	midy=getmaxy()/2;

	/*loop through text justifications*/

	for(i=LEFT_TEXT;i<=RIGHT_TEXT;i++)
	{
		for(j=BOTTOM_TEXT;j<=TOP_TEXT;j++)
		{
			cleardevice();
			cross(midx,midy);  /*create cross hairs on screen*/
			settextjustify(i,j);
			outtextxy(midx,midy,msg);
			settextjustify(LEFT_TEXT,TOP_TEXT);
			outtextxy(100,350,"HORIZONTAL JUSTIFICATION=");
			sprintf(msg1,"%s",horizontal[i]);
			outtextxy(320,350,msg1);
			outtextxy(100,400,"VERTICAL JUSTIFICATION=");
			sprintf(msg2,"%s",vertical[j]);
			outtextxy(320,400,msg2);

			getch();
		}
	}

	closegraph();
	restorecrtmode();
}
