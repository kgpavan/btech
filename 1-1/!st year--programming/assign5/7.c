#include<stdio.h>
main()
{
	int n,i,input,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&input);
		int se[input+2];
		se[1]=1;
               for(j=1;j<input;j++)
	       {
		       se[j+1]=se[1]+se[j+1-se[se[j]]];
		       k=se[j+1];
	       }
	       printf("%d\n",k);
	}
}
