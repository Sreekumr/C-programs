#include<stdio.h>
void read(int a[],int n)
{
int i;
for(i=0;i<n;i++){
printf("\n Enter the %d array elements:",i+1);
scanf("%d",&a[i]);
}
}
void sort(int a[],int n)
{
int i,j,t;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j]) 
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
}
void disp(int a[],int n)
{
int i;
for(i=0;i<n;i++)
{
printf("\t%d",a[i]);
}
}
int  main()
{
int a[10],n;
printf("\n\t\tSORTING(ASCENDING ORDER)");
printf("\n\t\t------------------------");
printf("\nEnter the array size:");
scanf("%d",&n);
read(a,n);
printf("\n After sorting.....\n");
sort(a,n);


disp(a,n);
return 0;
}

