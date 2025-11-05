#include <stdio.h>
#include <string.h>

struct Customer{
	char name[100];
	int priority;
};

struct PriorityQueue{
	struct Customer customer[100];
	int size;
};

void swap(struct Customer *a, struct Customer *b){
	struct Customer temp = *a;
	*a = *b;
	*b =temp;
}

void heapify(struct PriorityQueue* pq, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->customer[left].priority < pq->customer[smallest].priority) {
        smallest = left;
    }
    if (right < pq->size && pq->customer[right].priority < pq->customer[smallest].priority) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&pq->customer[index], &pq->customer[smallest]);
        heapify(pq, smallest);
    }
}

void enqueue(struct PriorityQueue* pq, char* name, int category){
    (pq->size)++;
	struct Customer temp;
	strcpy(temp.name, name);
	temp.priority=category;
	pq->customer[pq->size - 1] = temp;
	int current = pq->size - 1;
	while(current > 0 && (pq->customer[current]).priority < (pq->customer[(current-1) / 2]).priority)
	{
		swap(&(pq->customer[current]), &(pq->customer[(current-1) / 2]));
		current = current / 2;
	}
}


void dequeue(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty. No customer to serve.\n");
        return;
    }
    printf("Serving Customer: %s (Priority: %d)\n", pq->customer[0].name, pq->customer[0].priority);

    swap(&pq->customer[0], &pq->customer[pq->size - 1]);
    pq->size--;

    heapify(pq, 0);
}


void display(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Customers in queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Name: %s, Priority: %d\n", pq->customer[i].name, pq->customer[i].priority);
    }
    printf("\n");
}



int main() {
    struct PriorityQueue pq;
    pq.size = 0;

    int choice;
    char name[100];
    int category;

    printf("Post Office Priority Queue\n");
    do {
        printf("\nMenu:\n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter customer name: ");
                scanf(" %[^\n]", name);
                
                printf("Select category by number:\n");
                printf("1. Differently Abled (Highest Priority)\n");
                printf("2. Senior Citizen\n");
                printf("3. Defence Personnel\n");
                printf("4. Ordinary Person (Lowest Priority)\n");
                printf("Enter category number: ");
                scanf("%d", &category);

                if (category < 1 || category > 4) {
                    printf("Invalid category number! Try again.\n");
                } else {
                    enqueue(&pq, name, category);
                    printf("Customer added successfully.\n");
                }
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 4);

    return 0;
}


