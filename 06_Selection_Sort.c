#include <stdio.h>

void selectionSort(int arr[], int size) 
{
	int i,j,key;
	for (int i = 0 ; i < size - 1 ; i ++)
	{
		key = i;
		for (j = i+1;j < size;j++)
		{
			if (arr[j] < arr[key])
			{
				key = j;
			}
		}
		if (key != i)
		{
			int temp = arr[i];
			arr[i] = arr[key];
			arr[key] = temp;
		}
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

	selectionSort(arr, 10);
		
	printf("\nSorted Array : \n\n");
	for (int j = 0 ; j < 10 ; j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");
}
