#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void swap(struct Node** a, struct Node** b) {
    struct Node* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Node* heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left]->data < heap[smallest]->data)
        smallest = left;

    if (right < size && heap[right]->data < heap[smallest]->data)
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapify(heap, size, smallest);
    }
}


void insert(struct Node* heap[], int *size, struct Node* node) {
    heap[*size] = node;
    int current = (*size)++;
    
    while (current > 0 && heap[current]->data < heap[(current - 1) / 2]->data) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}


struct Node* extractMin(struct Node* heap[], int *size) {
    if (*size == 0)
        return NULL;

    struct Node* minNode = heap[0];
    heap[0] = heap[--(*size)];
    heapify(heap, *size, 0);
    return minNode;
}

struct Node* mergeKSortedLists(struct Node* lists[], int K) {
    if (K == 0)
        return NULL;
        
    struct Node* heap[K];
    int heapSize = 0;

    // Insert the first node of each list into the min-heap
    for (int i = 0; i < K; i++) {
        if (lists[i] != NULL) {
            insert(heap, &heapSize, lists[i]);
        }
    }

    struct Node* head = NULL; // Head of merged list
    struct Node* tail = NULL; // Tail of merged list

    while (heapSize > 0) {

        struct Node* minNode = extractMin(heap, &heapSize);

        if (head == NULL) {
            head = minNode;
            tail = minNode;
        } else {
            tail->next = minNode;
            tail = tail->next;
        }
        
        if (minNode->next != NULL) {
            insert(heap, &heapSize, minNode->next);
        }
    }

    if (tail != NULL)
        tail->next = NULL;

    return head;
}



void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int K;
    printf("Enter Number of Arrays (K): ");
    scanf("%d", &K);
    
    struct Node* lists[K];

    for (int i = 0; i < K; i++) {
        printf("\nARRAY %d\n", i + 1);
        int length;
        printf("Enter size of list: ");
        scanf("%d", &length);

        struct Node* head = NULL;
        struct Node* tail = NULL;

        printf("Enter elements in sorted order:\n");
        for (int j = 0; j < length; j++) {
            int val;
            scanf("%d", &val);

            struct Node* new_node = newNode(val);
            if (head == NULL) {
                head = tail = new_node;
            } else {
                tail->next = new_node;
                tail = tail->next;
            }
        }

        lists[i] = head;
    }

    struct Node* merged = mergeKSortedLists(lists, K);

    printf("\nMerged List:\n");
    printList(merged);

}



