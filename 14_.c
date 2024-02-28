#include <stdio.h>
void disp();
struct employee {
 int	empno;
 char name[20];
 int salary;
 int dno;
 };
 
 void read(struct employee e[],int n){
 	int i;
 	for(i=0;i<n;i++)
 	{
 		printf("\nenter employee no:");
 		scanf("%d",&e[i].empno);
 		printf("\n Enter the name:");
 		scanf("%s",&e[i].name);
 		printf("\n Enter the salary:");
 		scanf("%d",&e[i].salary);
 		printf("\n Enter the department No:");
 		scanf("%d",&e[i].dno);
	 }
}


void disp(struct employee e[],int n)
{
	int i;
	printf("ENo.\tEName\tSalary\tDeptNo.");
	
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s\t%d\t%d",e[i].empno,e[i].name,e[i].salary,e[i].dno);
	}
	printf("\n");
}

void sortsal(struct employee e[],int n)
{
	struct employee t;
	int i,j;
	for (i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(e[i].salary<e[j].salary)
			{
			
	        	t=e[i];
		    	e[i]=e[j];
		    	e[j]=t;
		    }
		}
	}
}


void sortname(struct employee e[],int n)
{
	struct employee t;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i;j<n;j++)
		{
			if(strcmp(e[i].name,e[j].name)>0)
			   {
			   	 t=e[i];
			   	 e[i]=e[j];
			   	 e[j]=t;
			   }
		}
	}
	
}

void search(struct employee e[],int n)
{
	int i,s;
	printf("Enter the Employee no:");
	scanf("%d",&s);
	for(i=0;i<n;i++)
    {
    	if(s==e[i].empno)
    	  {
    	  	printf("\nEmployee is found\n\nEmployee name:%s\nEmployee no:%d",e[i].name,e[i].empno);
    	  	break;
    	  }
    }
    	
	if(s!=e[i].empno)
	  {
			printf("\nEmployee is NOT FOUND!!!");
      }
}

int delet(struct employee e[],int n)
{
	int i,j;
	int s;
	printf("Enter the Employee no:");
	scanf("%d",&s);
	for(i=0;i<n;i++)
    {
   	if(e[i].empno==s)
    	{
    	for(j=i;j<n-1;j++)
    	 {
    	 	e[j]=e[j+1];
		 }
		 --n;
		 printf("Employee no %d is deleted",s);
		 return n;
        }
      }
printf("%d IS NOT FOUND!\n",s);
return n;
}


int menu()
{
	int ch ;
	printf("\nEnter your choice:\n");
	printf("1-Display\n2-Sort by salary\n3-Sort by name\n4-Search\n5-Delete\n");
	scanf("%d",&ch);
	return ch;
}
 
 int main()
 {
 	struct employee e[20];
 	int n;
 	printf("enter the no.of employees:");
 	scanf("%d",&n);
 	read (e,n);
 	
 	int ch;
 	for(ch=menu();ch!=6;ch=menu())
 	{
 	  switch(ch)
 	  {
 	  	case 1:	disp(e,n);
 	  	         break;
 	  	
 	  	case 2: sortsal(e,n);
 	  	        disp(e,n);
 	  	        break;
 	  	         
 	  	case 3: sortname(e,n);
 	  	        disp(e,n);
 	  	        break;
 	  	        
 	  	case 4: search(e,n);
 	  	       break;
 	  	       
 	  	case 5: n=delet(e,n);
 	  	        break;
 	    
 	  	
 	    default :printf( "Wrong choice ");
 	             break;
	   }
	 }
 
 	
 	return 0;
 }
