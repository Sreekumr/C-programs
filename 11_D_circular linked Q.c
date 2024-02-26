#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
typedef struct node queue;
queue *front=NULL;
queue *rear=NULL;
void enqueue()
{
queue *t=(queue*)malloc(sizeof(queue));
printf("\nEnter the element to be inserted : ");
scanf("%d",&t->data);
if(front==NULL)
 front=t;
if(rear==NULL)
 rear=t;
else
{
 rear->next=t;
 rear=rear->next;
}
rear->next=front;
}
void dequeue()
{
if(front==NULL)
 printf("\nCircular Linked Queue is Empty");
else
{
printf("\nDequeued element : %d",front->data);
if(front==rear)
 front=rear=NULL;
 else
 {
rear->next=front->next;
front=front->next;
}
}
}
void display()
{
  printf("\n");
  queue *t=front;
  do
 { 
      printf("%d ",t->data);
      t=t->next;
  }
  while(t!=front);
}
int main()
  {
    int ch;
    do
  {
  printf("\n");
  printf("\n*** MENU ***\n");
  printf("\n1. Enqueue");
  printf("\n2. Dequeue");
  printf("\n3. Display");
  printf("\n4. Exit");
  printf("\nEnter your choice (1-4) : ");
  scanf("%d",&ch);
switch(ch)
   {
       case 1 : enqueue();
        break;
       case 2 : dequeue();
       break; 
       case 3 : display();
        break;
        case 4 : break;
        default :
	   printf("\nInvalid Choice\n");
   }
 }
 while(ch!=4);
 return 0;
}


