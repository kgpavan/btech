#include <graphics.h>
void main()
{
	int gd=DETECT,gm,x,y,style;
	char str[50];
	struct linesettingstype ls;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	y=getmaxy();
	setcolor(4);
	outtextxy(10,20,"Normal Width");
	x=20;
	for(style=0;style<=4;style++)
	{
		setlinestyle(style,0,1);
		if(style==0)
			getlinesettings(&ls);   /*save line setting*/
		if(style==4)
		{
			setlinestyle(4,15,1);
		      //	setlinestyle(4,1,1);
		//	line(x,50,x,y-50);
		      //	getlinesettings(&ls);
		}
	      //	else
			line(x,50,x,y-50);
		itoa(style,str,10);
	      //	itoa(22,str,10);
		outtextxy(x,y-20,str);
		x=x+50;
	}

	setcolor(9);
	outtextxy(375,20,"Thick Width");
	x=375;
	for(style=0;style<=4;style++)
	{
		setlinestyle(style,0,3);
		if(style==4)
		{
			setlinestyle(4,15,3);
			line(x,50,x,y-50);
		}
		else
			line(x,50,x,y-50);
		itoa(style,str,10);
		outtextxy(x,y-20,str);
		x=x+50;
	}
    //	line(20,300,40,500);

	/*restore line settings*/
	setlinestyle(ls.linestyle,ls.upattern,ls.thickness);
      //	line(40,500,300,50);
}









































