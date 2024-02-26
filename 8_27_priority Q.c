#include <stdio.h>
void heapify(int arr[], int n, int i)
{
 int largest = i,t; 
 int l = 2*i + 1; 
 int r = 2*i + 2; 
 if (l < n && arr[l] > arr[largest])
 largest = l;
 if (r < n && arr[r] > arr[largest])
 largest = r;
 if (largest != i)
 {
 t = arr[i];
 arr[i] = arr[largest];
 arr[largest] = t;
 heapify(arr, n, largest);
 }
}
void heapSort(int arr[], int n)
{
 int t,i;
 for (i = n / 2 - 1; i >= 0; i--)
 heapify(arr, n, i);
 for (i=n-1; i>0; i--)
 {
 t = arr[0];
 arr[0] = arr[i];
 arr[i] = t;
 heapify(arr, i, 0);
 }
}
void printArray(int arr[], int n)
{
	int i;
 for (i=0; i<n; ++i)
 printf("%d ",arr[i]);
 printf("\n");
}
int main()
{
 int arr[10],n,i;
 printf("\nEnter the number of elements of the array: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 	printf("\nEnter arr[%d]: ",i+1);
 	scanf("%d",&arr[i]);
 }
 heapSort(arr, n);

 printf("\nElements in the priority queue are: ");
 printArray(arr, n);
}

