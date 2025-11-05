#include <stdio.h>

int findFirstOccurrence (int arr[], int size, int key)
{
	int start = 0;
	int end = size - 1;
	int result = -1;
	while (start <= end)
	{
		int mid = ( start + end ) / 2;
		
		if ( arr[mid] == key ) {
			result = mid;
			end = mid - 1;
		}
		
		if ( arr[mid] > key ) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return result;
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
	
	int arr[] = {1,2,2,4,4,4,4,5};
	int size = sizeof(arr) / sizeof(arr[1]);
	
	int key;
	printf("Enter the key to search : ");
	scanf("%d", &key);
	
	int index = findFirstOccurrence (arr, size, key);
	if (index == -1)
		printf("%d was not found in the array!\n", key);
	else
		printf("Index of first occurrence : %d\n", index);
}
