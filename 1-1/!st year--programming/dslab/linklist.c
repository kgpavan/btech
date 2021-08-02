#include<stdio.h>
#include<malloc.h>
struct link
{
	int value;
	struct link *next;
};
void push(int n,int **m)
{
	int *temp,*r;
	r=malloc(sizeof(struct));
	temp=r;
	r->value=n;
	r->next=*m;
	*m=temp;
}
void pop(int n,int **m)
{

}
main()
{
	struct link a1,a2,a3;
	int i;
	a1.value=1;
	a2.value=2;
	a3.value=3;
	a1.next=&a2;
	a2.next=&a3;
	i=a1.next->value;
	printf("%d\n",i);
}

