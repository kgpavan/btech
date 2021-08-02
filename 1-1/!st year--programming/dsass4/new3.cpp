#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int compare(int a,int b)
{
	if(a>b)
		return 1;
	else
		return 0;
}
int deletemin(int array[],int *index,int k)
{
	int i,x,y,min,last,swaps=0;
		min=array[1];
		last=array[(*index)--];
		for(i=1;(k*(i-1)+2)<=(*index);i=x)
		{
			x=k*(i-1)+2;
			y=x+1;
			while(y<=(*index) && y<=k*i+1)
			if(last > array[x])
			{
				array[i]=array[x];
				swaps++;
			}
		}
}

main()
{
	vector<int> v;
	char c;
	int count=0,value;
	while(1)
	{
		scanf(" %c",&c);
		//printf("c=%c",c);
		if(c=='x')
		{
			cout<<endl;
			break;
		}
		else if(c=='i')
		{
			scanf("%d",&value);
			v.push_back(value);
			if(count==0)
				push_heap(v.begin(),v.end(),compare);
			else
				push_heap(v.begin(),v.end());
			
		}
		else if(c=='e')
		{
			if(v.size()==0)
				cout<< -1 << " ";
			else
			{
			//	printf("%d ",v.front());
				if(count==0)
				{
					
					pop_heap(v.begin(),v.end(),compare);
					cout << v.back() << " ";
				}
				else
				{
					pop_heap(v.begin(),v.end());
					cout << v.back() << " ";
				}
					v.pop_back();
			}
		}
		else if(c=='n')
		{
			if(count==0)
			{
				count=1;
				make_heap(v.begin(),v.end());
			}
			
			else 
			{
				count=0;
				make_heap(v.begin(),v.end(),compare);
			}
		}
	}

}
