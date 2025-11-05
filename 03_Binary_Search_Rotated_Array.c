#include <stdio.h>

int searchInRotatedArray (int arr[], int size, int key)
{
	int start = 0;
	int end = size - 1;
	while (start <= end)
	{
		int mid = ( start + end ) / 2;
		
		if ( arr[mid] == key )
			return mid;
		
		if ( arr[mid] >= arr[start] ) {
			if ( key >= arr[start] && key <= arr[mid] ) {
				end = mid - 1;
			} else {
				start = mid + 1; 
			}
		} else {
			if ( key >= arr[mid] && key <= arr[end] ) {
				start = mid + 1;
			} else {
				end = mid - 1; 
			}
		}
	}
	return -1;
}

int main()
{
	/*int arr[10];
	printf("Enter the elements of the SORTED array : \n");
	for (int i = 0 ; i < 5 ; i++)
	{
		printf("Enter the %d element of the array : \n", i);
		scanf("%d", &arr[i]);	
	}*/
	
	int arr[] = {8,9,10,2,5,6};
	int size = sizeof(arr) / sizeof(arr[1]);
	
	int key;
	printf("Enter the key to search : ");
	scanf("%d", &key);
	
	int index = searchInRotatedArray (arr, size, key);
	if (index == -1)
		printf("%d was not found in the array!\n", key);
	else
		printf("The number %d is found at index %d.\n", key, index);
}
