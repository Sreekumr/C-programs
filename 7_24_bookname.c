#include<stdio.h>
#include <malloc.h>
struct book
{
	char bookname[50];
	char authorname[30];
};
struct book *a;
void read_book(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\nEnter details of Book%d",i+1);
		printf("\n");
		fflush(stdin);
		printf("\nEnter book name:");
		gets(a[i].bookname);
		fflush(stdin);
		printf("\nEnter author name:");
		gets(a[i].authorname);
	}
}
void disp_book(int n)
{
	int i;
	printf("\n The Books  are: ");
	for(i=0;i<n;i++)
	{
		printf("\n\nBook%d",i+1);
		printf("\n**********************");
		printf("\nBook Name: %s",a[i].bookname);
		printf("\nAuthor Name: %s",a[i].authorname);
	}
}
int main()
{
	int n;
	printf("Enter the number of books: ");
	scanf("%d",&n);
	a=(struct book *)calloc(n,sizeof(struct book));
	read_book(n);
	printf("\n");
	disp_book(n);
	return 0;
}

