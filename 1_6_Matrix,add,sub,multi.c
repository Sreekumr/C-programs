#include <stdio.h>
int a[5][5], b[5][5];
void add(int r, int c) {
    int i, j, d[5][5];
    for (i = 0; i < r; i++) {
        printf("\n");
        for (j = 0; j < c; j++) {
            d[i][j] = 0;
            d[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\nSUM MATRIX\n");
    for (i = 0; i < r; i++) {
        printf("\n");
        for (j = 0; j < c; j++) {
            printf("%d\t", d[i][j]);
        }
    }
}

void sub(int r,int c)
{
int i,j,d[5][5];
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
d[i][j]=0;
d[i][j]=a[i][j]-b[i][j];
}
}
printf("\nSUBTRACTED MATRIX\n");
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
printf("%d\t",d[i][j]);
}
}
}
void mul(int r,int c)
{
int i,j,k,d[5][5];
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
d[i][j]=0;
for(k=0;k<c;k++)
{
  d[i][j]=d[i][j]+a[i][k]*b[k][j];
}
}
}
printf("\nPRODUCT MATRIX\n");
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
printf("%d\t",d[i][j]);
}
}
}
void transpose(int r,int c)
{
int i,j,d[5][5];
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
d[i][j]=0;
d[i][j]=a[j][i];
}
}
printf("\nTRANSPOSE MATRIX\n");
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
printf("%d\t",d[i][j]);
}
}
}
int main()
{
int i,j,r,c;
printf("Enter the row limit: ");
scanf("%d",&r);
printf("\nEnter the column limit: ");
scanf("%d", &c);
printf("Enter Matrix 1: \n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("\nEnter a[%d][%d]",i,j);
scanf("%d",&a[i][j]);
}
}

printf("Enter Matrix 2: \n");
for(i=0;i<r;i++)
{
for(j=0;j<c;j++)
{
printf("\nEnter b[%d][%d]",i,j);
scanf("%d",&b[i][j]);
}
}
printf("\nMATRIX 1: \n");
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
printf("%d\t",a[i][j]);
}
}
printf("\nMATRIX 2:\n");
for(i=0;i<r;i++)
{
printf("\n");
for(j=0;j<c;j++)
{
printf("%d\t",b[i][j]);
}
}
add(r,c);
sub(r,c);
mul(r,c);
transpose(r,c);
return 0;


}


