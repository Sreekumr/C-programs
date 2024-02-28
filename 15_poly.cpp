#include <stdio.h>

int main()
{
	int n,i;
	printf("Enter the no.of terms :");
	scanf("%d",&n);
    
	int poly[n][2];
	for (i=0; i<=n; i++)
	{
		if(i!=n)
		{
		
		printf("Enter the degree of the term %d: ", i+1);
		scanf("%d",&poly[i][0]);
		
		printf("Enter the coefficient of the term %d: ", i+1);
		scanf("%d",&poly[i][1]);
	   }
	   else if(i==n)
	   {
	   	printf("Enter the constant  term %d: ", i+1);
		scanf("%d",&poly[i][1]);
	   }
	}
	

		printf("\nPolynomial: ");
	for(i=0; i<=n; i++)
	{
	
		if(i < n-1)
		{
			printf("%dx^%d",poly[i][1],poly[i][0]);
		  	printf(" + ");
		  }
		
		else if(i==n-1)
		    {
		
		    printf("%dx",poly[i][1]);
		
	       }
	    else if(i==n)
	    {
	    	printf(" + %d",poly[i][1]);
		}
	
//	printf("\n");
}

	return 0;

}
