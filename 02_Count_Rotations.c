#include <stdio.h>

int countRotations (int arr[], int size)
{
	int start = 0;
	int end = size - 1;
	while (start <= end)
	{
		if (arr[start] <= arr[end])
		{
			return start;
		}
		
		int mid = ( start + end ) / 2;
		int next = ( mid + 1 ) % size;
		int prev = ( mid + size - 1 ) % size;
		
		if ( arr[mid] <= arr[prev] && arr[mid] <= arr[next] )
		{
			return mid;
		} 
		
		if ( arr[mid] >= arr[start] ) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
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
	
	int arr[] = {8,9,10,2,5,6, 7};
	int size = sizeof(arr) / sizeof(arr[1]);
	
	int rot = countRotations(arr, size);
	printf("The array has been rotated %d times anticlockwise.\n", rot);
}
