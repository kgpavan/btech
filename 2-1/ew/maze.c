/*===========================================================================

Micromouse Maze solver Ver 1.0

For bugs and suggestions for improvement contact:

< sachin dot surendran at gmail.com >

===========================================================================
*/
#include<unistd.h>
#include<X11/Xlib.h>
#include<assert.h>
#include<locale.h>
#include<stdio.h>
#include<unistd.h>
#define NIL (0)
#define DELAY 2000
#define STATE 4
#define X (x*25)+10
#define Y (y*25)+10
#define FALSE 0
#define TRUE 1
#define CRC 1
int mz[16][16];
int dist[16][16];
int x,y,xold,yold,xmem=18,ymem=18;
char Game_win=0,fin_walk=FALSE,color_yellow=FALSE;
int dist_to_cent=255;
int cells_walked=0;//To count how much the mouse had to walk
                            //Useful to design speed
DrawMaze(Display *dis,Window w,GC gc,FILE *fp)//Okay this guy here draws the maz
{					      //from the .maz file
int blackColor = BlackPixel(dis,DefaultScreen(dis));
int whiteColor = WhitePixel(dis,DefaultScreen(dis));
XSetForeground(dis,gc,whiteColor);

for(;;)
        {
        XEvent e;
        XNextEvent(dis,&e);
        if(e.type ==MapNotify)
        break;
        }
//Draw Boundary of maze
XDrawRectangle(dis,w,gc,6,6,408,408);
//XDrawRectangle(dis,w,gc,5,5,415,415);
long unsigned int tmp;
char c;
for(x=0;x<16;x++)
{
for(y=15;y>=0;y--)
{
dist[x][y]=255;
//fputc(c,fp);
tmp=fgetc(fp);
c=tmp;
mz[x][y]=c;
//tmp=15;
printf("c=%x $$ %u\n",c,c);
printf("%d\n",tmp);
if(tmp==0 )
{//Do Nothing
//XDrawLine(dis,w,gc,x,y,x,y+25);
}
if(tmp & 1)//NORTH
{// -- //
XDrawLine(dis,w,gc,X,Y,X+25,Y);
}
if(tmp>>2 & 1)//SOUTH
{
XDrawLine(dis,w,gc,X,Y+25,X+25,Y+25);
}
if(tmp>>1 & 1)//EAST
{//__|
XDrawLine(dis,w,gc,X+25,Y,X+25,Y+25);
}
if(tmp>>3 & 1)//WEST
{// __
XDrawLine(dis,w,gc,X,Y,X,Y+25);  
}
XFlush(dis);
//sleep(1);
}
}
XFlush(dis);
fclose(fp);
}

int Move_to_center(){   
//Direct mouse towards center
//This not the best yet,I need to make
//Lots of Improvements,which will be packed in
// will turn out to make the mouse fastest.....
//Most badly written routine in the whole code :(
//Maybe i got lazy when i reached here	
int distX=7-x,distY=7-y;
char xfl=0,yfl=0;
char dec[4];//decision
if(distX < 0)
{
	distX *=-1;
	xfl=1;
}
if(distY < 0)
{
	distY *=-1;
	yfl=1;
}
if(distX > distY)// need movement in East West Direction
{
	if(xfl==1)//move West
	{	
		dec[0]='w';
		dec[3]='e';
	}
	else{//Move East
		dec[0]='e';
		dec[3]='w';
	}
	if(yfl==1)// Second priority Move North
	{
		dec[1]='n';
		dec[2]='s';
	}
	else{//Second priority move South
		dec[1]='s';
		dec[2]='n';
	}
		
}
else{
	if(yfl==1)//move North 
	{	
		dec[0]='n';
		dec[3]='s';
	}
	else{//Move South 
		dec[0]='s';
		dec[3]='n';
	}
	if(xfl==1)// Second priority Move North
	{
		dec[1]='w';
		dec[2]='e';
	}
	else{//Second priority move South
		dec[1]='e';
		dec[2]='w';
	}
}
		
return ((int ) dec);
}

char getOpening()//Heart of the micromouse algo,Got my algo optimize tweak
{                //Takes decision as to where to move next
char tmp=mz[x][y],count=0,*dec;
dec=(char *)Move_to_center();

if( dist[x][y] >= dist_to_cent )
return 0;

decision:

switch(dec[count]){
case 'n':
{goto North;}
case 's':
{goto South;}
case 'e':
{goto East;}
case 'w':
{goto West;}
default:
{printf("Error!!\n");}
}

//Below is a circluar linked code which breaks out after it goes thro circle once
North:
count++;
if( !(tmp & 1) )//NORTH
{// -- //
	if(y!=0)//North
	{ 
	if( dist[x][y-1] > dist[x][y]+1 )
        	{
			//Remove this code,only for debug
			if(dist[x][y-1] != 255 && !color_yellow)
			{
				color_yellow=TRUE;
				xmem=x;ymem=y;
			}

		if(x==4 && y==1)
		printf("\nmz[4][1]=%x\n",mz[4][1]);
		yold=y--;
		xold=x;
		return 1;
		}
	}
}
if(count==4)
return 0;
else
  goto decision;

South:
count++;//This takes care of breaking out once visited the circle completely
if( !(tmp>>2 & 1) )//SOUTH
{
        if(y!=15)//south
        {
	if( dist[x][y+1] > dist[x][y]+1 )
		{
			//Remove this code,only for debug
			if(dist[x][y+1] != 255 && !color_yellow)
			{
				color_yellow=TRUE;
				xmem=x;ymem=y;
			}

		yold=y++;
		xold=x;
		return 2;
		}
	}
}
if(count==4)
return 0;
else
  goto decision;

East:
count++;
if( !(tmp>>1 & 1) )//EAST
{//__|
 	if(x!=15)//East
	{
	if( dist[x+1][y] > dist[x][y]+1 )
		{
			//Remove this code,only for debug
			if(dist[x+1][y] != 255 && !color_yellow)
			{
				color_yellow=TRUE;
				xmem=x;ymem=y;
			}
		xold=x++;
		yold=y;
		return 3;
		}
	}
}
if(count==4)
return 0;
else
  goto decision;


West:
count++;
if( !(tmp>>3 & 1) )//WEST
{// __
	if(x!=0)//West
	{
	if( dist[x-1][y] > dist[x][y]+1 )
		{
			//Remove this code,only for debug
			if(dist[x-1][y] != 255 && !color_yellow)
			{
				color_yellow=TRUE;
				xmem=x;ymem=y;
			}
		xold=x--;       
		yold=y;
		return 4;
		}
	}
}
if(count==4)
return 0;
else
  goto decision;
}

backtrack()//I have hit a dead end,lets go back
{
int tmp;
int sqr;
tmp=dist[x][y];
sqr=mz[x][y];

	if(y!=0)//North
	{ 
	if(dist[x][y-1]==tmp-1 && !(sqr & 1) )
        	{
		yold=y--;
		xold=x;
		return 1;
		}
	}

        if(y!=15)//south
        {
	if(dist[x][y+1]==tmp-1 && !(sqr>>2 & 1) )
		{
		yold=y++;
		xold=x;
		return 2;
		}
	}
	 		
 	if(x!=15)//East
	{
	if(dist[x+1][y]==tmp-1 && !(sqr>>1 & 1) )
		{
		xold=x++;
		yold=y;
		return 3;
		}
	}

	if(x!=0)//West
	{
	if(dist[x-1][y]==tmp-1 && !(sqr>>3 & 1) )
		{
		xold=x--;       
		yold=y;
		return 4;
		}
	}
return 0;
}
print_maze()//solely for debugging,dumps the whole maze
{
char x,y;
	for(y=0;y<16;y++)
	{
		for(x=0;x<16;x++)
		{
		if(dist[x][y]<10)
		printf("00%d   ",dist[x][y]);
		else
		if(dist[x][y]<100)
		printf("0%d   ",dist[x][y]);
		else
		printf("%d   ",dist[x][y]);

		}
	printf("\n");
	}
}

drawMouse(Display *dis,Window w,GC gc) // He Draws the new position of the mouse
{					//and erases the old mouse position
Status rc;				//Some little Graphics	
XColor red,blue,yellow,brown,green;
Colormap screen_colormap;
int blackColor = BlackPixel(dis,DefaultScreen(dis));

screen_colormap=DefaultColormap(dis,DefaultScreen(dis));
rc=XAllocNamedColor(dis,screen_colormap,"red",&red,&red);
rc=XAllocNamedColor(dis,screen_colormap,"yellow",&yellow,&yellow);
rc=XAllocNamedColor(dis,screen_colormap,"brown",&brown,&brown);
rc=XAllocNamedColor(dis,screen_colormap,"green",&green,&green);

if(fin_walk)//Mark the shortest path yellow
{
if(x==7 && y==7)//For marking Center as yellow,ie when i walk the last Mile
	{       //Last walk is marked in yellow,see executable!!
	XSetForeground(dis,gc,yellow.pixel);
	XDrawRectangle(dis,w,gc,(x*25)+12,(y*25)+12,20,20);
	XFlush(dis);
	usleep(5000);
	return;
	}
XSetForeground(dis,gc,green.pixel);
//XSetFillStyle(dis,gc,FillSolid);
if(CRC)
	XDrawArc(dis,w,gc,(x*25)+15,(y*25)+15,15,15,0,23040);
	else
	XDrawRectangle(dis,w,gc,(x*25)+12,(y*25)+12,20,20);

usleep(5000);
return;
}


XSetForeground(dis,gc,blackColor);

if(CRC)
	XDrawArc(dis,w,gc,(xold*25)+15,(yold*25)+15,15,15,0,23040);
	else
	XDrawRectangle(dis,w,gc,(xold*25)+12,(yold*25)+12,20,20);
	
XFlush(dis);
if(x==7 && y==7)//For marking Center as yellow
{
	XSetForeground(dis,gc,yellow.pixel);
	XDrawRectangle(dis,w,gc,(x*25)+12,(y*25)+12,20,20);
	XFlush(dis);
	usleep(5000);
}
//Comment line below to undisplay thinking process
XSetForeground(dis,gc,yellow.pixel);
if(!color_yellow)
{
	XSetForeground(dis,gc,red.pixel);//Draw mouse in red , its a normal
	cells_walked++;
}
if(x==xmem && y==ymem)
{
	color_yellow=FALSE;
}

if(CRC)
	XDrawArc(dis,w,gc,(x*25)+15,(y*25)+15,15,15,0,23040);
	else
	XDrawRectangle(dis,w,gc,(x*25)+12,(y*25)+12,20,20);
	
XFlush(dis);
//sleep(1);
//if(x==14||x==15)
usleep(DELAY);
}
char getbacktrack(int xi,int yi)//Finds me the next cell to move to
{				//Used in Mark_Last_walk
char sel=0;
unsigned int tmp =500;
if(!(mz[xi][yi] & 1))//NORTH
	{
	tmp=dist[xi][yi-1];
	sel=1;
	}
if(!(mz[xi][yi]>>2 & 1))//SOUTH
	{
	if(dist[xi][yi+1]<tmp)
		{
		tmp=dist[xi][yi+1];
		sel=2;	
		}
	}
if(!(mz[xi][yi]>>1 & 1))//EAST
	{
 	if(dist[xi+1][yi]<tmp)
		{
		tmp=dist[xi+1][yi];
		sel=3;
		}
	}
if(!(mz[xi][yi]>>3 & 1))//WEST
	{
	if(dist[xi-1][yi]<tmp)
		{
		tmp=dist[xi-1][yi];
		sel=4;
		}	
	}
return sel;
}			


	
Mark_Last_walk()//Marks the shortest path from center, & makes center = 999
{               // and decrements till we reach mz[0][0]
int xi;
int yi,tmp;
char sel;
xi=7;
yi=7;
tmp=dist[xi][yi]=999;
while( yi || xi )
{
sel=getbacktrack(xi,yi);//Get me the smallest dist value from present cell
if(sel==1)//OK its North
yi--;
if(sel==2)//No, then its South
yi++;
if(sel==3)//No, then its East
xi++;
if(sel==4)//Yeah i knew it, its West
xi--;
dist[xi][yi]=--tmp; 
//printf("%d, %d\n",xi,yi);
}

}
FinalWalk(Display *dis,Window w,GC gc)//Read Mark_Last_walk to make sense 
{
char tmp;
int store=dist[0][0];//Store the path next dist
store++;
fin_walk=TRUE;//Dont know why im using this

while(!(x==7 && y==7))
{
tmp=mz[x][y];

if( !(tmp & 1) )//NORTH
{// -- //
	if(y!=0)//North
	{ 
	if(dist[x][y-1]==store)
        	{
		yold=y--;
		xold=x;
		goto DrawMouse;
		}
	}
}
if( !(tmp>>2 & 1) )//SOUTH
{
        if(y!=15)//south
        {
	if(dist[x][y+1]==store)
		{
		yold=y++;
		xold=x;
		goto DrawMouse;
		}
	}
}
if( !(tmp>>1 & 1) )//EAST
{//__|
 	if(x!=15)//East
	{
	if(dist[x+1][y]==store)
		{
		xold=x++;
		yold=y;
		goto DrawMouse;
		}
	}
}
if( !(tmp>>3 & 1) )//WEST
{// __
	if(x!=0)//West
	{
	if(dist[x-1][y]==store)
		{
		xold=x--;       
		yold=y;
		goto DrawMouse;
		}
	}
}
DrawMouse:
//printf("\nx=%d y=%d store=%d",x,y,store);
store++;
drawMouse(dis,w,gc);
}
drawMouse(dis,w,gc);
}

main(int argc,char *argv[])
{
int z,i;
Display *dis = XOpenDisplay(NIL);
// Initalise Color
int blackColor = BlackPixel(dis,DefaultScreen(dis));
int whiteColor = WhitePixel(dis,DefaultScreen(dis));
char c,b;
int count=0,iter=0;

if(argc!=2)
{
	printf("\nError : No argument !!!\nUsage: maze <filename.maz>\n");
	return;
}
FILE *fp;
fp=fopen(argv[1],"r");
Window w = XCreateSimpleWindow(dis,DefaultRootWindow(dis),0,0,500,500,0,blackColor,blackColor);
XSelectInput(dis,w,StructureNotifyMask);
XMapWindow(dis,w);
GC gc=XCreateGC(dis,w,0,NIL);
XSetForeground(dis,gc,whiteColor);
DrawMaze(dis,w,gc,fp);//Draws the maze loaded from file
XFlush(dis);
x=0;
xold=0;
y=0;
yold=0;
while(1)
{
iter++;//No of iterations
dist[x][y]=count;//Mark the dist matrix with distance

if(x==7 && y==7)
{
	if( count < dist_to_cent )//We maintain shortest distance from centere
	dist_to_cent=count;//If we have a new shortest distance update it
}

c=getOpening();//Get an way out of present Cell
printf("\nMove:%d",c);
if(!c)
	{
	b=backtrack();//We have reached an end or already visited area
	if(b)         //Lets go back 
	count--;
	printf("\nBacktrack:%d",b);
	}
else
	count++;
printf("\nx=%d,y=%d,xold=%d,yold=%d,  count=%d\ndist[x][y]=%d,dist[xold][yold]=%d",x,y,xold,yold,count,dist[x][y],dist[xold][yold]);//Debugging purpose
drawMouse(dis,w,gc);//Draw the new position of the mouse 

if(c==0 && b==0 && x==0 && y==0)
break;
}
printf("\nGame Over!!\n\n");
print_maze();//Prints the matrix
Mark_Last_walk();//Mark the best way from center to maze
printf("\n\n");
print_maze();//Prints the matrix
FinalWalk(dis,w,gc);//Walk the last mile of glory :)
printf("Cells Walked by mousee: %d ",cells_walked);
printf("\n\nIterations=%d\nDist to Center=%d\n",iter,dist_to_cent);
while(1);
}
