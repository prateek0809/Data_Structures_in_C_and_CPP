#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void quick_sort(int ar[],int l,int h);
int divide(int a[],int l,int h);

int divide(int a[],int l,int h)
{
	int pivot = a[l], i = l+1, j = h, temp;
	do
	{
		while(a[i]<=pivot)               // it finds element index greater than pivot
		{
			i++;
		}
		while(a[j]>pivot)                // it finds element index lesser than pivot
		{
			j--;
		}
		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];                 // it swap the elements
			a[j] = temp;
		}
	}while(i < j);
	temp = a[l];                         // swapping the pivot with the a[j]
	a[l] = a[j];
	a[j] = temp;
	return j;                            // return the index of pivot
}

void quick_sort(int a[],int l,int h)
{
	int piv_val;
	if(l>=h)
	{
		return;
	}
	piv_val = divide(a, l, h);
	quick_sort(a, l, piv_val);
	quick_sort(a, piv_val+1, h);
}
int main()
{
	int arr[100],i,n;
	printf("\nEnter the size of the list\n");
	scanf("%d",&n);
	printf("\nEnter the elements in the list:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(arr,0,n);
	printf("The list after the quick sort implementation:\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
