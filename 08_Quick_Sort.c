#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i,j;
	i = low;
	
	for (j=low+1;j<=high;j++)
	{
		if (arr[j] <= pivot)
		{
			swap(&arr[i+1],&arr[j]);
			i++;
		}
	}
	swap(&arr[low], &arr[i]);
	return i;
}

void quickSort(int arr[], int low, int high)
{
	if (low>=high)
		return;
	int mid = partition(arr,low,high);
	quickSort(arr,low,mid-1);
	quickSort(arr, mid+1, high);
}

int main()
{
	int arr[10];

	for (int i = 0 ; i < 10 ; i++)
	{
		printf("Enter the %d element of the array : ",i);
		scanf("%d", &arr[i]);
	}

	quickSort(arr, 0, 9);
		
	printf("\nSorted Array : \n\n");
	for (int j = 0 ; j < 10 ; j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");
}
