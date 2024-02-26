#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j,*a, sum = 0, n, *b, k = 0, c = 1, max = 0, mode;
    printf("\nEnter the limit\n");
    scanf("%d", &n);
    a=(int *)calloc(n,sizeof(int));
    b=(int *)calloc(n,sizeof(int));
    printf("Enter the set of numbers\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", a+i);
    }
    for (i = 0; i < n - 1; i++)
    {
        mode = 0;
        for (j = i + 1; j < n; j++)
        {
            if (*(a+i) == *(a+j)) {
                mode++;
            }
        }
        if ((mode > max) && (mode != 0)) {
            k = 0;
            max = mode;
            *(b+k) = *(a+i);
            k++;
        }
        else if (mode == max) {
            *(b+k) = *(a+i) ;
            k++;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (*(a+i) == *(b+i)) 
            c++;
        }
        if (c == n)
            printf("\nThere is no mode");
        else
        {
            printf("\nMode\t= ");
            for (i = 0; i < k; i++)
                printf("%d ",*(b+i));
        }
        printf("\n");
        return 0;
    }


