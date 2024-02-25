#include <stdio.h>

int insert(int e,int pos,int arr[])
	{
		if(pos+1==5){
		
			printf("Array is Full!!!");
		}
		else{
		    arr[++pos]=e;
			printf("\nElement %d is inserted",arr[pos]);
		}
		return pos;
	}

int delet(int pos,int arr[])
{
    int s,i,j,flag=0;
    printf("\nEnter the element to be deleted: ");
    scanf("%d",&s);

    for (i=0;i<=pos;i++)
    {
        if(arr[i] == s)
         {
         	 flag=1;
         	 printf("\n%d is deleted",arr[i]);
            break;
            
         } 
	}
   if(flag==1)
   {
   	 for(j=i;j<pos;j++)
   	 {
   	 	arr[j]=arr[j+1];
		}
		pos--;
   }
return pos;	
}

void search(int pos,int arr [])
 {
    int s,i,flag=0;
    printf("Enter the element to search for: ");
    scanf("%d",&s);

    for (i=0;i<=pos;i++)
    {
        if(arr[i] == s)
         {
            flag=1;
            break;
         }
    }

    if (flag==1)
    {
        printf("%d found in the array at a[%d]\n",s,i);
    }
    else
    {
        printf("%d not found in the array.\n",s);
    }
}

void disp(int pos,int arr[])
{
	int i;
	printf("\n");
	for(i=0;i<=pos;i++)
	{
		printf("%d\t",arr[i]);
	}
}


void sort(int pos,int arr[])
{
if(pos==-1)
{
    printf("Array cannot sort in ascending order.\n");
}
else
{
    int i,j,temp;
       for(i=0;i<pos;i++)
        {
          for (j=0;j<pos;j++)
          {
             if (arr[j]>arr[j+1])
             {
                temp=arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
             }
          }
        }
    }
}


int menu()
	{
		int ch;
		printf("\n1.Insert\n2.search\n3.delete\n4.sort\n5.Display\n6.Exit\nEnter Your choice: ");
		scanf("%d",&ch);
		return ch;
	}
	
	
	
void process()
{
	
	int pos=-1,arr[5];
	int ch,num;
	for(ch=menu();ch!=6;ch=menu())
	{
		switch (ch)
			{
				case 1: printf("\nEnter your digit :");
						scanf("%d",&num);
						pos=insert(num,pos,arr);
						break;
						
				case 2: search(pos,arr);
				        break;
					
				case 3: pos=delet (pos,arr);
						break;
				       
				 case 4:
                         sort(pos,arr);
                         break;
                         
             case 5:  disp(pos,arr);
                      break;
             	
            default :printf("Wrong choice\n");
                        break;
        
	        }		
	}
}
 int main()
    {
       process();
       return 0;
    }
