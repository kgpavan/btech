#include<iostream>
using namespace std;
struct node
{
	int value;
        node *nxt;        // Pointer to next node
};

node *start_ptr = NULL;
void insert(int val)
{
	node *temp;
	node *temp1;
	temp=new node;
	temp->value=val;
	temp->next=NULL:
	if(start_ptr==NULL)
	{
		start_ptr=temp;
	}
	else
	{
		temp1=start_ptr;
		while(temp1!=NULL)
		{
			temp1=temp1_next;
		}
		temp1->next=temp;
	}
}
main()




