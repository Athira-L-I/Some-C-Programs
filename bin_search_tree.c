#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *lchild;
	struct node *rchild;
};
struct node *root=NULL, *parent=NULL, *newnode=NULL, *current=NULL, *c=NULL;


void insert()
{
	int item;
	newnode=(struct node *) malloc(sizeof(struct node));
	printf("Enter the element ");
	scanf("%d", &item);
	newnode->data=item;
	newnode->lchild=newnode->rchild=NULL;
	
	if(root==NULL) 
	{	root=newnode; 	current=root; 	}
	else
{
	parent=root;
	while(parent!=NULL)
  {
	if(item<parent->data)
	{
		current=parent->lchild;
		if(current==NULL)
			{parent->lchild=newnode; return; }
		else
			parent=current; 
	}
	if(item>parent->data)
	  {
		current=parent->rchild;
		if(current==NULL)
			{parent->rchild=newnode; return; }
		else
			parent=current;
	  }
   }
}
	printf("Element inserted!\n");
}

void search()
{
	int item;
	printf("Enter item to search");
	scanf("%d", &item);
	if(root==NULL)
	{	printf("Binary tree is empty!"); return;	}
	c=root;
	while(c!=NULL)
	{
		if(item==c->data)
		{	printf("Element found!"); return;	}
		else if(item<c->data)
			c=c->lchild;
		else
			c=c->rchild;
	}
	if(c==NULL)
		printf("Element not present in binary tree");
}
void infix(struct node *root)
{
	if(root!=NULL)
	{
		infix(root->lchild);
		printf("%d  ", root->data);
		infix(root->rchild);
	}
}	
void postfix(struct node *root)
{
	if(root!=NULL)
	{
		postfix(root->lchild);
		postfix(root->rchild);
		printf("%d  ",root->data); 
	}
}
void prefix(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d  ", root->data);
		prefix(root->lchild);
		prefix(root->rchild);
	}
}
void traversal()
{
	printf("\n Inorder: "); infix(root);
	printf("\n Preorder: "); prefix(root);
	printf("\n Postorder: "); postfix(root);
}

int deletemin(struct node *a)
{
	int min;
	if(a->lchild==NULL)
	{
		min=a->data; a=a->rchild;		
	}	
	else
	{
		min=deletemin(a->lchild);
	}
}
struct node *deletenode(int x, struct node *a)
{
	if(a!=NULL)
	{
		if(x<a->data)	a=deletenode(x, a->lchild);
		else if(x>a->data)	a=deletenode(x, a->rchild);
		else if((a->lchild==NULL)&&(a->rchild==NULL))
			a=NULL;
		else if(a->lchild==NULL)	return a->rchild;
		else if(a->rchild==NULL)	return a->lchild;
		else
			{	a->data=deletemin(a->rchild); return a;}
	}
}
main()
{
	int ch, item;
	do
	   {	
	printf("\nMENU: 1. Insert\t2. Delete\t3. Search\t4. Traversal\t 5. Exit");
	scanf("%d", &ch);
	switch(ch)
	{
		case 1: insert(); break;
		case 2: printf("Enter item to be deleted");
				scanf("%d", &item);
				root=deletenode(item, root); break;
		case 3: search(); break;
		case 4: traversal(); break;
	}
	   }while(ch!=5);
}
			
