     
#include <stdio.h>
#include <stdlib.h>
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


void rev(node* head){
    if (head == NULL)
       return;
    rev(head->next);
    printf("%d  ", head->data);
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
		printf("\nMENU\n====\n 1.Insert\n 2.Display\n 3.Reverse display \n 4.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("\n Enter value to be inserted:");
					scanf("%d",&e);
					insert(e);
					break;
			case 2: printf("\n Elements are:");
					display();
			     	break;


			case 3:printf("\n Elements in reverse order :");
				   rev(head);
			       break;		 		
			case 4: exit(1);     	
		}
	}while(1);
}

