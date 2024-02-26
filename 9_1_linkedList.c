#include <stdio.h>
#include <malloc.h>
struct node
{
int data;
struct node *next;
};
typedef struct node node;
node *head = NULL;
void insert(int e)
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
void display()
{
	node *t = head;
	if(t == NULL)
	{
		printf("List is Empty\n");
		}
	while (t != NULL)
	{
		printf("%d\t",t->data);
		t = t->next;
		}
	printf("\n\n");
}
void main(){
	int ch,e;
	do{
		printf("\n 1.Insert\n 2.Display\n 3.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\nEnter value to be inserted:");
					scanf("%d",&e);
					insert(e);
					break;
			case 2: display();
			     	break;		
			case 3: exit(1);     	
		}
	}while(1);
}


