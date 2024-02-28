#include <stdio.h>

//void disp(int poly)

int main()
{
	int m,n,i,j,k;
	printf("Enter the degree of 1st polynomial: ");
	scanf("%d",&m);
	printf("\nEnter the degree of 2nd polynomial:");
	scanf("%d",&n);
	printf("---ENTER THE TERMS FOR THE FIRST POLYNOMIAL---");
	
	
	int poly1[2][m],poly2[2][n],res[2][m+n];
	for(i=m;i>0;i--)
	 {
//	 	printf("\nEnter the degree of the term %d: ", i);
//		scanf("%d",&poly1[i][0]);
		
		printf("\nEnter the coefficient of the  x^%d: ", i);
		scanf("%d",&poly1[0][i]);
		poly1[1][i]=i;
		
	 }
	 
	 for(i=m;i>0;i--)
	 { 
	 if(i>1)
	   {
	 
	   	printf(" %dx^%d",poly1[0][i],poly1[1][i]);
	   }
	    if(i>1)
	    {
	 	printf(" + ");
	    }
	    else if(i==1)
	      printf("%dx",poly1[0][i]);
	    else if(i==0)
	       printf("%d",poly1[0][i]);
	    
	    
	 	
	 }
	 
	 
	 return 0;
}
