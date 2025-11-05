#include <stdio.h>

int getMax(int A[], int n)
{
    int max = A[0];
    for(int i = 0; i < n ; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void CountSort(int A[], int n, int pos)
{
    int Count[10] = {0};
    int i;
    int B[n];
    for (i = 0; i < n; i++)
        ++Count[(A[i] / pos) % 10];

    for (i = 1; i < 10; i++)
        Count[i] = Count[i] + Count[i-1];

    for (i = n-1; i >= 0; i--)
        B[ --Count[(A[i] / pos) % 10] ] = A[i];

    for (i = 0; i < n; i++)
        A[i] = B[i];
}

void radixSort(int A[], int n)
{
    int max = getMax(A, n);
    for (int pos = 1; max/pos > 0; pos *= 10)
    {
        CountSort(A, n, pos);
    }
}

int main() {
    int num;
    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int arr[num];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);

    radixSort(arr, num);

    printf("\nSorted Array: ");
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
}
