#include<stdio.h>
struct treenode{
	int item;
	struct treenode *left;
	struct treenode *right;
};
typedef struct treenode *nodeptr;
typedef struct treenode* bst;
nodeptr find (int num,bst t);
nodeptr findmin(bst t);
nodeptr findmax(bst t);
bst insert (int num,bst t);
bst del(int num,bst t);
