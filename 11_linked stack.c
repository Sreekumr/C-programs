
#include<stdio.h>
#include<stdlib.h>
struct stack
{
int data;
struct stack *next;
};
typedef struct stack stack;
stack *top=NULL;
void push()
{
stack *t;
t=(stack*)malloc(sizeof(stack));
printf("\nEnter the element to be inserted : ");
scanf("%d",&t->data);
t->next=top;
top=t;
}
void pop()
{
if(top==NULL)
printf("\nEmpty Stack\n");
else
{
printf("%d is deleted\n",top->data);
top=top->next;
}
}
void peep()
{
if(top==NULL)
printf("\nEmpty Stack\n");
else
printf("\nThe top element is : %d\n",top->data);
}
int main()
{
int ch;
do
{
printf("\n*** MENU ***\n");
printf("\n1. Push (Insertion)");
printf("\n2. Pop (Deletion)");
printf("\n3. Peep (Displaying the top element)");
printf("\n4. Exit");
printf("\nEnter your choice (1-4) : ");
scanf("%d",&ch);
switch(ch)
{
case 1 : push();
break;
case 2 : pop();
break;
case 3 : peep();
break;
case 4 : break;
default : printf("\nInvalid Choice\n");
}
} 
while(ch!=4);
return 0;
}





