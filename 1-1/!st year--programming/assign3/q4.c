#include<stdio.h>
main()
{
long double n,z,k,i;
scanf("%llf",&n);
k=n/2;
for(i=1;0<k*k-n;i++)
	k=(k+(n/k))/2;
printf("%.0llf\n",k);
}





