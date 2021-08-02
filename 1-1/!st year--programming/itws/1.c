// given 2 array wid distinct value
//print d integer that r  not common 2 both array
#include<stdio.h>
main()
{
	int n,i,j,x,flag=0;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(j=0;j<n;j++)
		scanf("%d",&b[j]);
	for(i=0;i<n;i++)
	{
         	for(j=0;j<n;j++)
		{
			if(a[i]==b[j])
				flag=1;
				break;
		}
		if(flag==0)
			printf("%d\n",a[i]);
	}
	for(j=0;j<n;j++)
	{
         	for(i=0;i<n;i++)
		{
			if(b[j]==a[i])
				flag=1;
				break;
		}
		if(flag==0)
			printf("%d\n",b[j]);
	}
}

      
			
		
	

	



	
