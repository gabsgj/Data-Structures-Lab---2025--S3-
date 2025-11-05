#include <stdio.h>

void insertionSort(int arr[], int size)
{
	int i,j,key;
	for (i = 1 ; i < size ; i ++)
	{
		key = arr[i];
		j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

int main()
{
	int arr[10];
	for (int i = 0 ; i < 10 ; i++)
	{
		printf("Enter the %d element of the array : ",i);
		scanf("%d", &arr[i]);
	}

	insertionSort(arr, 10);
		
	printf("\nSorted Array : \n\n");
	for (int j = 0 ; j < 10 ; j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");
}
