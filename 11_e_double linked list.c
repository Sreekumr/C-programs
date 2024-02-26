#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node *next,*prev;
};
typedef struct node dll;
dll *head=NULL;
void insertion()
{
dll *t;
if(head==NULL)
{
  head=(dll*)malloc(sizeof(dll));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&head->data);
  head->next=NULL;
  head->prev=NULL;
}
else
{
  for(t=head; t->next!=NULL; t=t->next);
  t->next=(dll*)malloc(sizeof(dll));
  printf("\nEnter the element to be inserted : ");
  scanf("%d",&t->next->data);
  t->next->next=NULL;
  t->next->prev=t;
 }
}
void deletion()
{
int ele;
dll *t;
printf("\nEnter the element to be deleted : ");
scanf("%d",&ele);
if(head==NULL)
printf("\nDoubly Linked List is Empty");
else if(head->data==ele)
{
if(head->next==NULL)
head=NULL;
else
{
  head=head->next; 
  head->prev=NULL;
 }
}
else
{
for(t=head; t!=NULL && t->data!=ele; t=t->next);
if(t==NULL)
printf("\nElement not found");
else if(t->next==NULL)
t->prev->next=NULL;
else
{
  t->next->prev=t->prev;
  t->prev->next=t->next;
  }
 }
}
void display()
{
printf("\n");
dll *t;
for(t=head; t!=NULL; t=t->next)
 {
   printf("%d ",t->data);
  }
}
int main()
{
int ch;
do
{
   printf("\n");
   printf("\n*** MENU ***\n");
   printf("\n1. Insertion");
   printf("\n2. Deletion");
   printf("\n3. Display");
   printf("\n4. Exit");
   printf("\nEnter your choice : ");
   scanf("%d",&ch);
   switch(ch)
{
  case 1 :insertion();
  break;
 case 2 : deletion();
         break;
case 3 : display();
         break;
case 4 :break;
 default :printf("\nInvalid Choice\n");
 }
 }
while(ch!=4);
return 0;
}

