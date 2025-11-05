#include <stdio.h>

int maxarr(int arr[], int n){
    int i, max = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countingSort(int arr[], int n) {

    int max = maxarr(arr, n);
    int i;
    int count[max + 1];
    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[arr[i]]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];
    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int num;
    printf("Enter the number of elements : ");
    scanf("%d", &num);
    int arr[num];
	printf("Enter the elements  array : \n");
	for (int i = 0 ; i < num ; i++)
	{
		printf("Enter the %d element of the array : \n", i);
		scanf("%d", &arr[i]);	
    }

    printf("Original Array: ");
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);

    countingSort(arr, num);

    printf("\nSorted Array: ");
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
