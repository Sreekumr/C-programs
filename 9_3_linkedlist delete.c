#include<stdio.h>
#include<malloc.h>
struct node 
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head=NULL;
void insert(int e)
{
	if(head==NULL){
	head=(node *)malloc(sizeof(node));
	head->data=e;
	head->next=NULL;
	}
	else{
		node *t;
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(node*)malloc(sizeof(node));
		t->next->data=e;
		t->next->next=NULL;
	}
	
}
void disp()
{
	node *t;
	t=head;
	if(head==NULL){
		printf("\nempty list\n");
	}
	else{
		printf("\n");
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->next;
	}
	printf("\n");
	}
}
void delete1()
{
	if(head==NULL)
	{
		printf("\nlist empty\n");
	}
	else
	{
	head=head->next;
	}
}
void delete2(int e)//case 3 element to be deleted is not head
 {
 	node *t;
	int f=0;
 	t = head;
	if(head==NULL)
	{
		printf("\nlist empty\n");
	}
	else if(head->data==e)
	{
	head=head->next;
	}
	else{
 while(t->next != NULL)
 {
 if(t->next->data == e)
 {
 	t->next=t->next->next; //deleting intermediate or last node
 f = 1;
 return;
 }
 t= t->next;
 }
 if(f == 0) //case 4 element not found
 {
 printf("\nNot Found\n");
 }
 }
}
 
 void delete3()
 {
 		node *t;
	int f=0;
 t = head;
 while(t->next != NULL)
 {
 if(t->next->next == NULL)
 {
 	t->next=t->next->next; //deleting intermediate or last node
 f = 1;
 return;
 }
 t= t->next;
 }
 if(f == 0) //case 4 element not found
 {
 printf("Not Found");
 }
 }
int main()
{
	int ch,n,m,p,s;
	do
	{
		printf("\n1.insert.\n2.delete at begning.\n3.delete from last.\n4.delete a specific element.\n5.display.\n6.quit\n\nenter ur choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nenter the no to be inserted : ");
				scanf("%d",&n);
				insert(n);
				break;
				case 2:
				delete1();
				break;
				case 3:
				delete3();
				break;
				case 4:
				printf("enter specified data element : ");
				scanf("%d",&p);
				delete2(p);
				break;
				case 5:
					disp();
					break;
				case 6:
					break;
		}
	}while(ch!=6);
	return 0;
}

