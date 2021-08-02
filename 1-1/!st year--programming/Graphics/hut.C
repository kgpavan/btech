#include<graphics.h>
void main()
{
	int gd=DETECT,gm,x,y;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	x=getmaxx();
	y=getmaxy();
	setcolor(GREEN);
	outtextxy(175,0,"Scene of a village");
	rectangle(0,10,x,y);
	setcolor(BROWN);
	line(x/30,y/4,x/7,y/10);
	line(x/7,y/10,x/4,y/4);
	line(x/4,y/4,x/2.5,y/10);
	line(x/2.5,y/10,x/1.7,y/4);
	line(x/1.7,y/4,x/1.3,y/10);
	line(x/1.3,y/10,x/1.1,y/4);
	setcolor(RED);
	line(x/2,y/2,x/1.7,y/2.5);
	line(x/1.7,y/2.5,x/1.4,y/2);
	line(x/2,y/2,x/1.4,y/2);
	line(x/2,y/2,x/2,y/1.3);
	line(x/1.4,y/2,x/1.4,y/1.3);
	line(x/2,y/1.3,x/1.4,y/1.3);
	setcolor(BLUE);
	line(x/1.7,y/1.5,x/1.7,y/1.3);
	line(x/1.7,y/1.5,x/1.55,y/1.5);
	line(x/1.55,y/1.5,x/1.55,y/1.3);
	setcolor(YELLOW);
	arc(x/1.7,y/4,35,145,50);
}