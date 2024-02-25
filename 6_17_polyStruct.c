#include <stdio.h>

struct polynomial{
	int coefficient;
	int degree;
};

void read(struct polynomial poly[], int n){
	printf("Enter the terms \n");
	int i;
	for( i=n; i>=0; i--){
		
		poly[i].degree=i;
		if(i>0){
		printf("Enter the coeffient of x^%d : ",poly[i].degree);
		scanf("%d",&poly[i].coefficient);
	}
	else if(i==0){
		printf("Enter the constant term : ");
		scanf("%d",&poly[i].coefficient);
	}
	}
}

void disp(struct polynomial poly[], int n){
	printf("THE POLYNOMIAL IS: ");
	int i;
	
	for( i=n; i>=0; i--){
		
		if(i>0){
			printf("%dx^%d + ",poly[i].coefficient, poly[i].degree);
}
else{
		printf(" %d",poly[i].coefficient);
      }
    }
	
}



int main(){
	int n;
	printf("Enter the total number of terms in the polynomial: ");
	scanf("%d",&n);
	struct polynomial poly[n];
	read(poly,n);
	disp(poly,n);
	return 0;
}
