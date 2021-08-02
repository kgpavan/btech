#include<graphics.h>
#include<stdlib.h>
void main()
{
	int gd=DETECT,gm,i,j,x,y,color,startcolor,height,width;
	struct palettetype palette;
	struct viewporttype vp;
	initgraph(&gd,&gm,"c:\\tc\\bgi");

	getpalette(&palette);
	rectangle(0,20,639,479);
	outtextxy(200,10,"Palette demonstration");

	getviewsettings(&vp);
	width=(vp.right-vp.left)/16;
	height=(vp.bottom-vp.top)/16;

	x=0;
	y=20;
	startcolor=0;
	for(j=0;j<=15;j++)
	{
		color=startcolor;
		for(i=0;i<=15;i++)
		{
			setfillstyle(SOLID_FILL,color++);
			bar(x,y,x+width,y+height);
			x=x+width+1;
		}
		startcolor++;
		x=0;
		y=y+height+1;
	}
	getch();

	while(!kbhit())
		setpalette(random(16),random(65));

	setallpalette(&palette);

	getch();
	closegraph();
	restorecrtmode();
}