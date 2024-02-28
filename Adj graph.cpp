#include <stdio.h>

int adj[20][20];
int n;

void create_grahp()
{
	int i,max_edge,origin,destin;
	printf("\nEnter the number of vertices(nodes):");
	scanf("%d",&n);
	max_edge=n*(n-1);
	for(i=1;i<=max_edge;i++)
	{
		printf("Enter edge %d :\n",i);
		scanf("%d%d",&origin,&destin);
		if((origin==0) && (destin==0))
		{
			break;
		}
		if(origin>n || destin>n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!!!\n");
			i--;
		}
		else
		{
			adj[origin][destin]=1;
		}
	}
}
	
	void disp()
	{
	 int i,j;
	printf("\n---Adjacency matrix---\n");
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	
}

int main()
{
create_grahp();
disp();
	return 0;
}
