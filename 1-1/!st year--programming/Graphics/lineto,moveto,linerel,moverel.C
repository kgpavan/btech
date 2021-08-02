#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	outtextxy(100,0,"Demonstration of Moveto,Lineto,Moverel,Linerel");
	rectangle(0,10,639,479);
	line(100,50,100,350);
	moveto(300,50);  /*moves the C.P.*/
	lineto(300,350);  /*draws a line upto that point*/
	moverel(200,-300);    /*moves the CP by relative distance from its current position*/
	linerel(0,300);
	lineto(100,50);
       //	lineto(500,50);
       //	linerel(400,0);

	outtextxy(104,50,"(100,50)");
	outtextxy(104,350,"(100,350)");
	outtextxy(90,375,"line");

	outtextxy(304,50,"(300,50)");
	outtextxy(304,350,"(300,350)");
	outtextxy(280,375,"Moveto,Lineto");

	outtextxy(504,50,"(500,50)");
	outtextxy(504,350,"(500,350)");
	outtextxy(480,375,"Moverel,Linerel");

	getch();
	closegraph();
	restorecrtmode();
}