#include<stdio.h>
#include<math.h>
int swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
main()
{
	int i,j,no_of_input;
	scanf("%d",&no_of_input);
	for(i=0;i<no_of_input;i++)
	{
		int cx,cy,sx,sy,step=0;
		scanf("%d %d %d %d",&cx,&cy,&sx,&sy);
		if(cx==cy)
		{
			if(cx!=0 && cy!=0)
			{
				if(sx>sy)
				{
					swap(&sx,&sy);
				}
				if(sx<sy)
				{
					step+=(abs(cx-sx)-1)+abs(cy-sy);
					step+=(4+(6*(cx-1)));
				}
				if(sx==sy)
				{
					step+=(abs((cx-1)-sx))+abs(cy-sy);
					step+=(4+(6*(cx-1)));
				}

			}
			if(cx==0 && cy==0)
				step+=0;
		}
		if(cx!=cy)
		{
			if(cx>cy)
			{
				swap(&cx,&cy);
				swap(&sx,&sy);
			}
			if(cx<cy)
			{
				int d=abs(cx-sx)+abs(cy-sy);
				if(sy<cy)
				{
					step+=(d-1);
				}
				if(sy>cy && sx==cx)
				{
				//	if(sx!=cx)
				//		step+=(d+1);
//
//					if(sx==cx)
						step+=(d+3);
				}
				if(sy>=cy && sx!=cx)
				{
					step+=(d+1);
				}
			}

			step+=6*cx;
			step+=(1+5*(abs(cx-cy)-1));
		}

		printf("%d\n",step);
	}
}











