#include <stdio.h>
#include <malloc.h>

int main()
{
	char ch;
	char *p,i=0;
	printf("Enter the string");
	p=(char *)malloc(1*sizeof(char));
	do
	{
		scanf("%c",&ch);
		*(p+i)=ch;
		i++;
	p=(char *)realloc(p,i*sizeof(char));
	}while(ch!='\n');
	p(p+i)='\n';
	printf("\nThe string is\n %s",p);
}
