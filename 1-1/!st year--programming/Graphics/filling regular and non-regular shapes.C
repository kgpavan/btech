#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	int array[]={350,180,400,80,450,180,350,180};
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	/*to fill an ellipse*/

	setcolor(BLUE);
	ellipse(150,125,0,360,100,50);
	setfillstyle(8,RED);
	fillellipse(150,125,100,50);
      //	floodfill(150,125,BLUE);  /*this also works*/

      /*to fill a polygon*/

      drawpoly(4,array);
      setfillstyle(3,GREEN);
      fillpoly(4,array);

      /*to fill an inersection area between an overlapping circle and triangle*/

      circle(280,320,70);
      line(190,350,370,350);
      moveto(190,350);
      linerel(100,-120);
      linerel(80,120);
      outtextxy(210,410,"user defined figure");
      setfillstyle(4,BROWN);
      floodfill(280,320,BLUE);

      setfillstyle(6,GREEN);
      floodfill(192,349,BLUE);
      floodfill(368,349,BLUE);
      floodfill(290,231,BLUE);

      setfillstyle(8,DARKGRAY);
      floodfill(240,289,BLUE);
      floodfill(330,289,BLUE);
      floodfill(280,351,BLUE);


}
