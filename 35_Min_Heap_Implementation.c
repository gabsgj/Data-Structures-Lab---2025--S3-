#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}

void insert(int heap[], int *size, int node) {
    heap[*size] = node;
    int current = (*size)++;

    while (current > 0 && heap[current] < heap[(current - 1) / 2]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

int extractMin(int heap[], int *size) {
    if (*size == 0)
        return -1;  // Or handle empty heap case

    int minNode = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return minNode;
}

int maxActivityPoints(int A[], int n, int k) {
    if (k <= 0) return 0;
    if (k > n) k = n;

    int heap[k];  
    int size = 0;

    for (int i = 0; i < n; i++) {
        if (size < k) {
            insert(heap, &size, A[i]);
        } else {
            if (A[i] > heap[0]) {
                extractMin(heap, &size);
                insert(heap, &size, A[i]);
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += heap[i];
    }
    return sum;
}

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    int result = maxActivityPoints(A, n, k);
    printf("Sum of top %d activity points = %d\n", k, result);

    return 0;
}

