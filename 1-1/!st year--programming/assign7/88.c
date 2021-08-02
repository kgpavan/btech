#include<stdio.h>
#include<math.h>
main()
{
	int x;
	scanf("%d",&x);
	float y=(x*(22.0/7.0))/180.0;
//	int i;
	float a,b,c;
//	while(x>0)
//{
//	 y=(x*(22/7))/180;
	a=sin(y);
	b=cos(y);
	c=tan(y);
	printf("%.4f %.4f %.4f\n",a,b,c);
//	scanf("%d",&x);
//}
}


