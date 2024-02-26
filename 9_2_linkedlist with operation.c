#include <stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head = NULL;
void insert_end(int e)
{
	if(head == NULL) 
	{
	head = (node *)malloc(sizeof(node));
	head->data = e; 
	head->next = NULL; 
	}
	else 
	{
		node *t = head;
		while(t->next != NULL) 
		{ 
			t = t->next;
		}
		t->next = (node *)malloc(sizeof(node)); 
		t->next->data = e; 
		t->next->next = NULL; 
	}
}
void insert_begin(int e)
{
	node *newnode;
	if(head == NULL) 
	{
	head = (node *)malloc(sizeof(node));
	head->data = e; 
	head->next = NULL; 
	}
	else 
	{
		newnode=(node *)malloc(sizeof(node));
		newnode->data=e;
		newnode->next=head;
		head=newnode;
	}
}
void insert_elem(int e,int elem)
{
	node *newnode,*t=head;
	newnode=(node *)malloc(sizeof(node));
	newnode->data=e;
	while(t!=NULL)
	{
		if(t->data==elem)
			break;
		t=t->next;
	}
	if(t==NULL)
	{
		printf("\n%d not found in the list\n",elem);
	}
	else
	{
		newnode->next=t->next;
		t->next=newnode;
	}
}
void display()
{
	node *t = head;
	if(t == NULL)
	{
		printf("List is Empty\n");
		return;
	}
	printf("\nElements in the linked list are: ");
	while (t != NULL)
	{
		printf("%d\t",t->data);
		t = t->next;
	}
	printf("\n\n");
}
int main()
{
	int ch,e,item;
	do
	{
		printf("\nLinked list\n****************\n1.Insertion at the beginning\n2.Insertion at the end\n3.Insertion after a specified element in the list\n4.Display\n5.Exit\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					printf("\nEnter the element to insert: ");
					scanf("%d",&e);
					insert_begin(e);
					break;
			case 2:
					printf("\nEnter the element to insert: ");
					scanf("%d",&e);
					insert_end(e);
					break;
			case 3:
					printf("\nEnter the element to insert: ");
					scanf("%d",&e);
					printf("\nEnter the element after which insertion should be done: ");
					scanf("%d",&item);
					insert_elem(e,item);
					break;
			case 4:
					display();
					break;
			case 5:
					printf("\nExiting.......\n");
					break;
			default:
					printf("\nEnter a valid choice!!!!!\n");
					break;
		}
	}while(ch!=5);
	return 0;
}



