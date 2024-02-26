#include <stdio.h>
#define N 5
int q[N],f=-1,r=-1;
void enqueue(int e)
  {
		if(r+1==N)
		 {
 			printf("\nQueue : Full");
 		}
else
	{
		if(f==-1)
		{
			f=0;
			}
		r=r+1;
		q[r]=e;
		}
	}
void dequeue()
{
	if(r==-1)
		{
		printf("\nQueue : Empty");
		}	
else
{
		printf("\n%d is deleted",q[f]);
		if(f==r)
	{
		f=r=-1;
	}
 else
  {
		f=f+1;
		}
	}
}

int main()
{
int ch=0;
int num;
for(;ch!=4;)
{
printf("\n1. Enqueue\n2.Dequeue\n3.Exit\nEnter your choice:");
scanf("%d",&ch);
switch(ch)
{
	case 1:
		printf("\nEnter the element to be inserted:");
		scanf("%d",&num);
		enqueue(num);
		break;

	case 2:
		dequeue();
		break;
	case 3:
		break;
}
}
return 0;
}

