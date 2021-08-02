#include<iostream>
#include<list>
using namespace std;
main()
{
	list<int> mylist;
	char a;
	scanf("%c",&a);
	int i;
	int count=0,val;
	while(a!='x')
	{
//	for(i=0;;i=i+2)
//	{
	//	int count=0;
		if(a=='i')
		{
			scanf("%d",&val);
			mylist.push_back(val);
		//	i=i+2;
			mylist.sort();
		}
		if(a=='n')
		{
			if(count==0)
				count=1;
			else
				count=0;
		}
		if(a=='e')
		{
			if(mylist.empty())
				cout<<-1;
			else
			{
				if(count==0)
				{
					cout << (mylist.front()) << " ";
					mylist.pop_front();
				}
				else
				{
					cout << (mylist.back()) << " ";
					mylist.pop_back();
				}
			}

		}
//		if(a[i]=='x')
//			break;
		scanf("%c",&a);
	}
	cout<<"\n";

}


