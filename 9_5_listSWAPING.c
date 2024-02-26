
#include<stdio.h>
#include<malloc.h>
struct node
{
int data;
struct node* next;
};
typedef struct node ll;
ll* insertNode(ll* h,int d)
{
ll* newnode=(ll*)malloc(sizeof(ll));
newnode->data=d;
newnode->next=NULL;
if(h==NULL)
{
h=newnode;
return h;
}
ll* t;
for(t=h;t->next!=NULL;t=t->next);
t->next=newnode;
return h;
}
ll* deleteNode(ll* h,int key)
{
ll* t;
if(h==NULL)
{
printf("\n!List Empty!");
return h;
}
if(h->data==key)
{
t=h;
h=h->next;
free(t);
return h;
}
for(t=h;t!=NULL && t->next->data!=key;t=t->next);
if(t==NULL)
printf("\n!Node Does Not Exist!");
else
{
ll* t1=t->next;
t->next=t->next->next;
free(t1);
}
return h;
}
void display(ll* h)
{
ll* t;
if(h==NULL)
printf("\n!List Empty!");
else
{
printf("\nLinked List :");
for(t=h;t!=NULL;t=t->next)
printf("\n%d",t->data);
}
}
void sortVal(ll* h)
{
ll *t=h,*j;
int temp;
while(t!=NULL)
{
j=t->next;
while(j!=NULL)
{
if(j->data<t->data)
{
temp=t->data;
t->data=j->data;
j->data=temp;
}
j=j->next;
}
t=t->next;
}
display(h);
}
int main()
{
ll* head=NULL;
int data,ch;
printf("\nLINKED LIST :\n1.Insert\n2.Delete\n3.Display\n4.Sort By Value\n5.CANCEL");
do
{
printf("\nEnter Option : ");
scanf("%d",&ch);
switch(ch)
{
case 1 :
printf("\nEnter Data : ");
scanf("%d",&data);
head=insertNode(head,data);
break;
case 2 :
printf("\nEnter Data to be Deleted: ");
scanf("%d",&data);
head=deleteNode(head,data);
break;
case 3 :
display(head);
break;
case 4 :
sortVal(head);
break;
case 5 :
printf("\nCancelled...");
break;
default :
printf("\n!Invalid Option!");
break;
}
}while(ch!=5);
return 0;
}

