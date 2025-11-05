#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int x)
{
    struct Node* newNode = ((struct Node*) malloc(sizeof(struct Node)));
    if (newNode == NULL) {
        printf("List Overflow! Memory not available.\n");
        exit(1);
    }
    newNode->data=x;
    newNode->next=NULL;
    return newNode;
}

void addNode(struct Node **head, int x)
{
    struct Node* Node = createNode(x);
    if (*head == NULL)
    {
        *head = Node;
        return;
    }
    struct Node *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = Node;
}

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB){
    struct Node *ta = headA, *tb = headB;
    int m=0,n=0;
    while(ta!=NULL)
    {
        m++;
        ta=ta->next;
    }
    while(tb!=NULL)
    {
        n++;
        tb=tb->next;
    }
    int diff = abs(m-n);
    ta = headA;
    tb = headB;
    if (m>n)
    {
        for (int i = 0; i < diff ; i ++)
        {
            ta=ta->next;
        }
    }else{
        for (int i = 0; i < diff ; i ++)
        {
            tb=tb->next;
        }
    }
    while(ta!=NULL && tb!=NULL)
    {
        if (ta == tb)
            return ta;
        ta = ta->next;
        tb = tb->next;
    }
    return NULL;
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty!");
        return;
    }
    printf("The List: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void createIntersection(struct Node *headA, struct Node *headB, int posA) {
    if (headA == NULL || headB == NULL) {
        printf("Both lists are EMPTY!!.\n");
        return;
    }
    struct Node *ta = headA;
    int count = 1;
    while (ta != NULL && count < posA) {
        ta = ta->next;
        count++;
    }

    if (ta == NULL) {
        printf("Position %d does not exist in List A.\n", posA);
        return;
    }

    struct Node *tb = headB;
    while (tb->next != NULL) {
        tb = tb->next;
    }

    tb->next = ta;
    printf("Intersection created at node with value %d (position %d in List A).\n", ta->data, posA);
}




int main()
{
    int on = 1;
    int choice;
    struct Node *headA = NULL, *headB = NULL;
    int num;
    while(on)
    {
        printf("\nEnter choice:\n1.Add element to A\n2.Add element to B\n3.Display List A\n4.Display List B\n5.Find INTERSECTION\n6.Create Intersection\n7.Quit\nChoice = ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter number to add to list A: ");
            scanf("%d", &num);
            addNode(&headA, num);
            break;
        case 2:
            printf("Enter number to add to list B: ");
            scanf("%d", &num);
            addNode(&headB, num);
            break;
        case 3:
            display(headA);
            break;
        case 4:
            display(headB);
            break;
        case 5:
            struct Node *intersection = getIntersectionNode(headA, headB);
            if (intersection == NULL)
            {
                printf("NO INTERSECTION POINT RETURNED!!!\n");
                break;
            }
            printf("INTERSECTION POINT = Node with value %d\n", intersection->data);
            break;
        case 6:
            int pos;
            printf("Enter position in List A to create intersection: ");
            scanf("%d", &pos);
            createIntersection(headA, headB, pos);
            break;
        case 7:
            on = 0;
            break;
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    while(headA!=NULL){
        struct Node* temp = headA;
        headA = temp->next;
        free(temp);
    }
    while(headB!=NULL){
        struct Node* temp = headB;
        headB = temp->next;
        free(temp);
    }
}
