#include<iostream>
using namespace std;
class heap
{
	int size;
	int *no;
//	node *temp;
	public:
//	no=(int *)malloc(sizeof(int));
	void *insert(int x)
		{
			no=(int *)malloc(sizeof(int));
			
			//node *temp;
		//	temp=(nade *)malloc(sizeof(node));
			if(size==0)
			{
				//temp->size=0;
				no[size]=x;
				size=size+1;
			//	n=temp;
			}
			else
			{
			//	int size=n->size;
				for(int i=++size;no[size] > x;i=i/2)
				{
					no[i]=no[i/2];
				}
				no[size]=x;
				size++;
			//	n=temp;
			}
		}
};
main()
{
	heap h;
	int input;
//	node *n=NULL;
	cout<<"enter the value to be inserted"<<endl;
	for(int i=0;i<3;i++)
	{
		cin>> input;
		h.insert(input);
	}
}



