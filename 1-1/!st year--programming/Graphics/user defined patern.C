#include<graphics.h>
void main()
{
	int gd=DETECT,gm;
	char pattern[][8]={
				{0x00,0x70,0x20,0x27,0x24,0x24,0x07,0x00},
				{0xAA,0x55,0xAA,0x55,0xAA,0x55,0xAA,0x55}
			  };
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setfillpattern(&pattern[0][0],RED);
	bar(420,150,520,250);
	rectangle(420,150,520,250);

	setfillpattern(&pattern[1][0],GREEN);
	bar(250,150,350,250);
	rectangle(250,150,350,250);
}

