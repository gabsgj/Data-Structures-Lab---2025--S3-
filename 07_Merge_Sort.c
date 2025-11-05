#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int sizeleft = mid - left + 1;
    int sizeright = right - mid;
    int leftarr[sizeleft];
    int rightarr[sizeright];

    for (int i = 0; i < sizeleft; i++)
        leftarr[i] = arr[left + i];

    for (int j = 0; j < sizeright; j++)
        rightarr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < sizeleft && j < sizeright) {
        if (leftarr[i] <= rightarr[j])
            arr[k++] = leftarr[i++];
        else
            arr[k++] = rightarr[j++];
    }

    while (i < sizeleft)
        arr[k++] = leftarr[i++];

    while (j < sizeright)
        arr[k++] = rightarr[j++];
}

void mergeSort(int arr[], int left, int right){
	if (left >= right)
		return;
	int mid = (left + right)/2;
	mergeSort(arr, left,mid);
	mergeSort(arr, mid+1, right);
	merge(arr,left,mid,right);
}

int main()
{
	int arr[10];

	for (int i = 0 ; i < 10 ; i++)
	{
		printf("Enter the %d element of the array : ",i);
		scanf("%d", &arr[i]);
	}
	mergeSort(arr, 0, 9);
		
	printf("\nSorted Array : \n\n");
	for (int j = 0 ; j < 10 ; j++)
	{
		printf("%d ",arr[j]);
	}
	printf("\n");
}
