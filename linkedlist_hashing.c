#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
}*newnode, *i, *p, *c;

struct node *a[10];
int n;
void insert(); void delete_h(); void display(); void search(); void empty_hash();

main()
{
	int ch;
	printf("Enter hastable size ");
	scanf("%d", &n);
	do
	{		
		printf("\n\nMENU:\t 1. Insert\t2. Delete\t3. Search hashtable\t4. Display hashtable\t5. Empty hashtable\t 6.Exit ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insert(); break;
			case 2: delete_h();break;
			case 3: search(); break;
			case 4: display(); break;
			case 5: empty_hash(); break;
			case 6: exit(0);
			default: printf("Wrong choice!"); break;
		}
	}while(ch!=6);
}

void insert()
{
	int item, index;
	printf("\nEnter item to be inserted");
	scanf("%d", &item);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=item; newnode->next=NULL;
	
	index=item%n;
	
	if(a[index]==NULL)
	{
		a[index]=newnode; 
	}
	else
	{
		i=a[index];
		while(i->next !=NULL)
			i=i->next;
		i->next=newnode;		
	}
	printf("Element inserted");
}
void display()
{
	int i;
	printf("\n*************************");
	for(i=0; i<n; i++)
	{
		c=a[i];		
		printf("\n INDEX %d", i+1);
		while(c!=NULL)
		{
			printf("\t %d", c->data);
			c=c->next;
		}
	
	}
}
void delete_h()
{
	int item, index, flag=0;
	printf("\nEnter item to be deleted");
	scanf("%d", &item);
	index=item%n;
	p=NULL; c=a[index]; 

	while(c!=NULL)
	{
		if(c->data==item)
		{
			if(p!=NULL)
				p->next=c->next;			
			else
				a[index]=c->next;
			free(c);
			printf("\nSuccessfully deleted!");
			flag++;
			break;
		}
		else
		{
			p=c; c=c->next; 
		}
	}
	if(flag==0)
		printf("\nElement not found!");
	
}
void search()
{
	int item, index, flag=0;
	printf("\nEnter item to be searched");
	scanf("%d", &item);
	index=item%n;
	p=NULL; c=a[index]; 

	while(c!=NULL)
	{
		if(c->data==item)
		{
			printf("\nElement is found at index %d", index+1);
			flag++;
			break;
		}
		else
		{
			p=c; c=c->next; 
		}
	}
	if(flag==0)
		printf("\nElement not found!");
}
void empty_hash()
{
	int i;
	for(i=0; i<n; i++)
	{
		while(a[i]!=NULL)
		{
			c=a[i];
			a[i]=c->next;
			free(c);
		}
	}
	printf("\n Hashtable emptied!");
}
