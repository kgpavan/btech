#include<graphics.h>
void main()
{
	int gd=DETECT,gm,x=40,y=40,maxx,maxy,fst;
	char str[40];
	char *pattern[]={
				"EMPTY_FILL",
				"SOLID_FILL",
				"LINE_FILL",
				"LTSLASH_FILL",
				"SLASH_FILL",
				"BKSLASH_FILL",
				"LTBKSLASH_FILL",
				"HATCH_FILL",
				"XHATCH_FILL",
				"INTERLEAVE_FILL",
				"WIDE_DOT_FILL",
				"CLOSE_DOT_FILL",
				"USER_FILL",
			};
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	maxx=getmaxx();
	maxy=getmaxy();
	rectangle(0,10,maxx,maxy);
	setcolor(WHITE);
	outtextxy(175,0,"Pre-defined Fill styles");

	for(fst=0;fst<12;fst++)
	{
		setfillstyle(fst,RED);
		bar(x,y,x+80,y+80);
		rectangle(x,y,x+80,y+80);
		itoa(fst,str,10);
		outtextxy(x,y+100,str);
		outtextxy(x,y+110,pattern[fst]);

		x=x+150;
		if(x>490)
		{
			y=y+150;
			x=40;
		}
	}
	getch();
	closegraph();
	restorecrtmode();
}