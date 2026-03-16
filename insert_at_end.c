#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void insertAtEnd(struct Node** start, int item)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    struct Node* ptr;

    if(newNode == NULL){
        printf("Overflow\n");
        return;
    }

    newNode->info = item;
    newNode->link = NULL;

    if(*start == NULL){
        *start = newNode;
        return;
    }

    ptr = *start;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    ptr->link = newNode;
}

void printList(struct Node* node)
{
    printf("Current List: ");
    while(node != NULL){
        printf("%d -> ", node->info);
        node = node->link;
    }
    printf("NULL\n");
}

int main() {
    struct Node* start = NULL;
    int totalItems, item, i, newItem;

    printf("How many elements do you want to create? ");
    scanf("%d", &totalItems);

    // Creating initial list
    for(i = 0; i < totalItems; i++) {
        printf("Enter value: ");
        scanf("%d", &item);
        insertAtEnd(&start, item);
    }

    printf("\nInitial List:\n");
    printList(start);

    // Asking which element to insert at end
    printf("\nEnter the element you want to insert at the end: ");
    scanf("%d", &newItem);

    insertAtEnd(&start, newItem);

    printf("\nList after inserting at end:\n");
    printList(start);

    return 0;
}