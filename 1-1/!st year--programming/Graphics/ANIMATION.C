#include<graphics.h>
#include<alloc.h>
void main()
{
	int gd=DETECT,gm,area,x=25,y=25,ch,xdirn=1,ydirn=1;
	int maxx,maxy;
	char *buff;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	setcolor(WHITE);
	setfillstyle(SOLID_FILL,RED);
	circle(50,50,25);
	floodfill(50,50,WHITE);
      //	rectangle(25,25,75,75);

	area=imagesize(25,25,75,75);  /*parameters are top and bottom coordinates of the rectangle enclosing the circle(or the image to be stored)*/
	buff=malloc(area);
	getimage(25,25,75,75,buff);

	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,20,maxx,maxy);
	outtextxy(250,10,"Animation");

	while(1)
	{
		if(kbhit())
		{
			ch=getch();

			/*if ENTER is hit reverse the direction*/

			if(ch=='\r')
			{
				xdirn=xdirn*(-1);
				ydirn=ydirn*(-1);
			}
			else
			{
				if(ch==27)   /*FOR ESCAPE KEY*/
					break;
			}
		}

		putimage(x,y,buff,XOR_PUT);  /*also try OR_PUT and COPY_PUT in place of XOR_PUT*/
		delay(0);
		x=x+(xdirn*5);
		y=y+(ydirn*2);
	     //	x+=xdirn;;
	     //	y+=ydirn;
		putimage(x,y,buff,XOR_PUT);

		/*check if ball touches horizontal boundaries*/

		if(x>maxx-50 || x<0)
		{
			sound(50);
			delay(10);
			nosound();
			xdirn=xdirn*(-1);
		}

		/*check if ball touches vertical boundaries*/

		if(y>maxy-50 || y<0)
		{
			sound(50);
			delay(10);
			nosound();
			ydirn=ydirn*(-1);
		}
	}

	getch();
	closegraph();
	restorecrtmode();
}

