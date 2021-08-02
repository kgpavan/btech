#include<iostream>
using namespace std;
class linklist
{
	private:
	int val;
	linklist *next;
	public:
	void  insert(int v)
	{
		linklist *k,*temp;
		k=NULL;
		temp=this;
		while(temp->next)
			temp=temp->next;
		k = (linklist*) malloc(sizeof(linklist));
		k->val=v;
		temp->next=k;
	}
	void print(int k)
	{
		linklist *temp;
		temp=this;
		while(temp->next)
		{
			temp=temp->next;
			printf("%d\n",temp->val);
		}
			printf("%d\n",temp->val);
	}

};
int main()
{
	linklist* l;
	l=new (linklist);
	l->insert(10);
	l->insert(20);
	l->print(2);
}

/*	linklist *l;
	linklist *k;
	l =new( linklist);
	int  a,b,c;
	printf("enter no . to insert \n");
	scanf("%d",&a);
	l->val=a;
	l->next=NULL;
	
	scanf("%d",&a);
	l->insert(a);
	printf("%d\n",k->val);

	scanf("%d",&b);
	scanf("%d",&c);
	l->insert(b);
	printf("%d\n",k->val);
	l->insert(c);
	printf("%d\n",k->val);
	return 0;*/


	

