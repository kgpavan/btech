#include<stdio.h>
main()
{
	int y,d,i,a[12];
	scanf("%d %d",&y,&d);
	a[0]=a[2]=a[4]=a[6]=a[7]=a[9]=a[11]=31;
	a[3]=a[5]=a[8]=a[10]=30;
	if(y%4==0)
		a[1]=29;
	else
		a[1]=28;
	for(i=0;i<12;i++)
	{
		while(d<=a[i])
		{
			//d=d+7;
			printf("%d ",d);

			d=d+7;
		}
		d=d-a[i];
	}
	printf("\n");
}
