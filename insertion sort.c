#include <stdio.h>

int main()
{
	int a[10],i,j,min;
	
	for(i=0;i<5;i++)
	{
		printf("Enter the value for a[%d]",i);
		scanf("%d",&a[i]);
	}
	
     for(i=1;i<5;i++)
     {
     	min=a[i];
     	j=i-1;
     	while(j>=0 && min<a[j])
     	{
     		a[j+1]=a[j];
     		j=j-1;
		 }
		 a[j+1]=min;
	 }
	 for(i=0;i<5;i++)
	 {
	 	printf("%d ",a[i]);
	 }
	 return 0;
}
