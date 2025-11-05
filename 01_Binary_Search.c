#include <stdio.h>

int binarySearch (int arr[], int low, int high, int key)
{
	while (low <= high)
	{
		int mid = ( low + high ) / 2;
		
		if (arr[mid] == key)
		{
			return mid;
		} else if ( arr[mid] > key ) {
			return binarySearch(arr,low,mid-1,key);
		} else {
			return binarySearch(arr,mid+1,high,key);
		}
	}
	return -1;
}

int main()
{
	int arr[10];
	printf("Enter the elements of the SORTED array : \n");
	for (int i = 0 ; i < 5 ; i++)
	{
		printf("Enter the %d element of the array : \n", i);
		scanf("%d", &arr[i]);	
	}
	
	int key;
	printf("Enter the key to search : ");
	scanf("%d", &key);
	
	int index = binarySearch(arr, 0, 9, key);
	if (index == -1)
		printf("%d was not found in the array!\n", key);
	else
		printf("The number %d is found at index %d.\n", key, index);
}
