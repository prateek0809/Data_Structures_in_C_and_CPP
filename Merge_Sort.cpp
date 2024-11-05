#include<stdio.h>
#include<stdlib.h>
#define infinity 100000
void merge_sort(int ar,int beg,int end);
void merge(int ar,int f,int m,int l);

void merge(int ar[],int f,int m,int l)
{
	int i = f, j = m+1, k=0, a[100];
	while(i <= m && j<=l)
	{
		if(ar[i] < ar[j])       //copying the elements
		a[k++] = ar[i++];
		else
		a[k++] = ar[j++];
	}
	while(i <= m)
	{
		a[k++] = ar[i++];
	}
	while(j <= l)
	{
		a[k++] = ar[j++];
	}
	for(i=f,k=0; i<=l; i++, k++)
	{
		ar[i] = a[k];
	}
}


void merge_sort(int ar[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid = (beg + end) / 2;
		merge_sort(ar, beg, mid);
		merge_sort(ar, mid+1, end);
		merge(ar, beg, mid, end);
	}
}

int main()
{
	int arr[100], i, size;
	printf("Enter the size of list:\n");
	scanf("%d",&size);
	printf("Initalize the elements in the list:\n");
	for(i=0; i<size; i++)
	{
		scanf("%d",&arr[i]);
	}
	merge_sort(arr, 0, size-1);
	printf("The list after Merge Sort:\n");
	for(i=0; i<size; i++)
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
