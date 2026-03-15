#include <stdio.h>
#include <stdlib.h>

// Structure for the Node
struct Node {
    int info;
    struct Node* link;
};

// Insert at end
void insertAtEnd(struct Node** start, int item)
{
    struct Node *newnode, *temp;

    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->info = item;
    newnode->link = NULL;

    if (*start == NULL) {
        *start = newnode;
        return;
    }

    temp = *start;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    temp->link = newnode;
}

// Print list
void printList(struct Node* start)
{
    struct Node* temp = start;

    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

// Delete given node
void delete_givennode(struct Node** start, int ITEM)
{
    struct Node *LOC, *LOCP;

    if (*start == NULL) {
        printf("Underflow: List is empty\n");
        return;
    }

    LOC = *start;
    LOCP = NULL;

    while (LOC != NULL && LOC->info != ITEM) {
        LOCP = LOC;
        LOC = LOC->link;
    }

    if (LOC == NULL) {
        printf("Item not found\n");
        return;
    }

    if (LOCP == NULL)
        *start = LOC->link;
    else
        LOCP->link = LOC->link;

    printf("Deleted item: %d\n", LOC->info);
    free(LOC);
}

int main()
{
    struct Node* start = NULL;
    int n, i, item, del;

    printf("How many nodes do you want to create? ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter value: ");
        scanf("%d", &item);
        insertAtEnd(&start, item);
    }

    printf("Initial List: ");
    printList(start);

    printf("Enter value to delete: ");
    scanf("%d", &del);

    delete_givennode(&start, del);

    printf("Updated List: ");
    printList(start);

    return 0;
}