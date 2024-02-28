/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};


typedef struct node tree;

struct stack
{
    tree *r;
    struct stack *next;
};

typedef struct stack stack;

tree *root = NULL;
stack *top = NULL;

void push(tree *t)
{
    stack *temp = (stack *)malloc(sizeof(stack));
    temp->r = t;
    temp->next = top;
    top = temp;
}

tree  *pop()
{
    tree *t = NULL;
    if(top != NULL)
    {
        t = top->r;
        top = top->next;
    }
    return t;
}

void insert(int e)
{
    tree *p,*x;
    if(root==NULL)
    {
        root = (tree *) malloc(sizeof(tree));
        root->data = e;
        root->left=NULL;
        root->right=NULL;
    }
    else
    {
        p=root;
        while(p!=NULL)
        {
            x=p;
            if(e>p->data)
                p=p->right;
            else if(e<p->data)
                p=p->left;
            else
            {
                printf("\nDuplicates value not allowed\n");
                return;
            }
        }
        tree *t = (tree *) malloc(sizeof(tree));
        t->data = e;
        t->left = NULL;
        t->right = NULL;
        if(e>x->data)
            x->right = t;
        else
            x->left = t;
    }
}

void inorder2(tree *root)
{
    tree *t;
    for(t=root;t!=NULL;t=t->left)
    {
	 push(t);
     }
    t = pop();
    while(t!=NULL)
    {
        printf("%d\t ",t->data);
        for(t=t->right;t!=NULL;t=t->left)
		{
            push(t);
        }
        t=pop();
    }
}

void preorder2(tree *root)
{
    tree *t;
    for(t=root;t!=NULL;t=t->left)
    {
	 printf("%d\t ",t->data);  
    push(t); 
	
    }
    t=pop();
    while(t!=NULL)
    {
        
        for(t=t->right;t!=NULL;t=t->left)
        {
            printf("%d\t ",t->data);
            push(t); 
			 
        }
        t=pop();
    }
}
int main()
{
    insert(10);
     insert(30);
    insert(20);
    insert(40);
    insert(50);
    insert(60);
    //insert(10);
    // insert(200);
    printf("\n");
     printf("Inorder without using recursion:");
    inorder2(root);
    printf("\n");
    printf("Preorder without using recusrion:");
    preorder2(root);
    return 0;
}

