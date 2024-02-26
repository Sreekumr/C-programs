#include <stdio.h>
#include <malloc.h>
int *mptr,*cptr;
int n,i;
void m_alloc()
{
    printf("Enter number of elements:");
        scanf("%d",&n);
    mptr=(int*)malloc(n*sizeof(int));
    if(mptr==NULL)
    {
        printf("\nmemory was not allocated using malloc:");
    }
    else
    {
        printf("\nmemory allocated using malloc");
        printf("\nenter the elements:");
        for(i=0;i<n;i++)
            scanf("%d",mptr+i);
        printf("\nelements are :\n");
        for(i=0;i<n;i++)
            printf("%d\t",*(mptr+i));
        
    }
}
void c_alloc()
{
    printf("Enter number of elements:");
        scanf("%d",&n);
    cptr=(int*)calloc(n,sizeof(int));
    if(cptr==NULL)
    {
        printf("\nmemory was not allocated using malloc:");
    }
    else
    {
        printf("\nmemory allocated using calloc");
        printf("\nenter the elements:");
        for(i=0;i<n;i++)
            scanf("%d",cptr+i);
        printf("\nelements are :\n");
        for(i=0;i<n;i++)
            printf("%d\t",*(cptr+i));
    }
}
void fr_ee()
{
    if(mptr!=NULL)
    {
        free(mptr);
        printf("\nmemory freed which was allocated dynamically\n");
    }
    else if(cptr!=NULL)
    {
        free(cptr);
        printf("\nmemory freed which was allocated dynamically\n");
    }
    else
        printf("\n nothing to free:");
    
        
    
}
int main()
{
    int ch=0;
    for(;ch!=4;)
    {
        printf("\n1.malloc\n2.calloc\n3.free\n4.exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                m_alloc();
                break;
            case 2:
                c_alloc();
                break;
            case 3:
                fr_ee();
                break;
            case 4:
                break; 
        }
    }
    
    
}

