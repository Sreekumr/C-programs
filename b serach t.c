#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node tree;

struct stack {
	tree * r;
	struct node * next;
};

typedef struct stack stack; 

tree * root=NULL;
tree *p,*x;
stack * top=NULL;

void insert(int e)
{
	if(root==NULL)
	{
		root=(tree *)malloc(sizeof(tree));
		root->data=e;
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
			{
				p=p->right;
			}
			else
			{
				p=p->left;
			}
	}
			if(e<x->data)
			{
				x->left=(tree *)malloc(sizeof(tree));
				x->left->data=e;
				x->left->left=NULL;
				x->left->right=NULL;
			}	
			else
				{
				x->right=(tree *)malloc(sizeof(tree));
				x->right->data=e;
				x->right->right=NULL;
				x->right->left=NULL;
			    }	
	}
}

//void inorder(tree *r)
//{
//	if(r!=NULL)
//	{
//		inorder(r->left);
//		printf("%d\t",r->data);
//		inorder(r->right);
//	}
//}

void push(tree *t )
{
	stack *temp=(stack *)malloc(sizeof(stack));
	temp->r=t;
	temp->next=top;
	top=temp;
}

tree * pop()
{
	tree *t=NULL;
	if(top!=NULL)
	{
		t=top->r;
		top=top->next;
	}
	return t;
}

void inorder2(tree * root)
{
	tree *t;
	for(t=root;t!=NULL;t=t->left)
	   push(t);
	t=pop();
	while(t!=NULL)
	{
		printf("%d ",t->data);
		for(t=t->right;t!=NULL;t=t->left)
		  push(t);
		t=pop();

	}
}


int main()
{
	insert(10);
	insert(50);
	insert(60);
	insert(100);
	insert(30);
	insert(40);
	insert(150);
	inorder2(root);
	return 0;
}
