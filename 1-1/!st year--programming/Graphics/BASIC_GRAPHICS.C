#include "graphics.h"
void main()
{
	int gd=DETECT,gm,x,y,tw;
	int array[]={540,220,590,270,570,320,540,220};
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	x=getmaxx();
	y=getmaxy();
	printf("max. x coordinate is %d and max. y coordinate is %d\n",x,y);
	setcolor(BLUE);
	rectangle(x/30,y/20,x/5,y/4);
	outtextxy(x/30+10,y/4+10,"RECTANGLE");
	outtext("ROHIT");
	setcolor(MAGENTA);
	circle(x/3,y/5,60);
	setcolor(MAGENTA);
	outtextxy(x/3-30,y/5+65,"CIRCLE");
	outtext("SETHI");
	outtext("JAIN");
	putpixel(x/3,y/5,WHITE);
	arc(x/3+150,y/5,90,180,80);
	putpixel(x/3+150,y/5,BLUE);
	outtextxy(x/3+100,y/5+50,"ARC");
	setcolor(WHITE);
	line(x/30,y/20,x/5,y/4);
	ellipse(x/2,y/2,0,360,100,50);
	outtextxy(x/2+150,y/2,"ELLIPSE");
	tw=textwidth("ELLIPSE");
	setcolor(7);
	printf("width of ELLIPSE in pixel is %d\n",tw);
	drawpoly(4,array);
	getch();
	closegraph();
	restorecrtmode();
}