#include<graphics.h>
#include<dos.h>

union REGS i,o;
void main()
{
	int gd=DETECT,gm,maxx,maxy,x,y,button;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	maxx=getmaxx();
	maxy=getmaxy();

	rectangle(0,56,maxx,maxy);
	setviewport(1,57,maxx-1,maxy-1,1);

	gotoxy(26,1);
	printf("Mouse Demonstration Program");

	if(initmouse()==0)
	{
		closegraph();
		restorecrtmode();
		printf("\n Mouse diver not loaded");
		exit(1);
	}

	restrictmouseptr(1,57,maxx-1,maxy-1);
	showmouseptr();
	gotoxy(1,2);
	printf("Left Button");
	gotoxy(15,2);
	printf("Right Button");
	gotoxy(55,3);
	printf("Press any key to exit...");

	while(!kbhit())
	{
		getmousepos(&button,&x,&y);

		gotoxy(5,3);
		if((button & 1)==1)
			printf("DOWN");
		else
			printf("UP");

		gotoxy(20,3);
		if((button & 2)==2)
			printf("DOWN");
		else
			printf("UP");

		gotoxy(65,2);
		printf("X=%03d Y=%03d",x,y);
	}
}

/*initialises mouse */
initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

/*displays mouse pointer*/
showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}

/*restricts mouse movement*/
restrictmouseptr(int x1,int y1,int x2,int y2)
{
	i.x.ax=7;
	i.x.cx=x1;
	i.x.dx=x2;
	int86(0x33,&i,&o);

	i.x.ax=8;
	i.x.cx=y1;
	i.x.dx=y2;
	int86(0x33,&i,&o);
}

/*gets mouse coordinates and button status*/
getmousepos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}

