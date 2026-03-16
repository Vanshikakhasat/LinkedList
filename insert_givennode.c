#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void insertAfter(struct Node* start, int key, int item)
{
    struct Node *ptr, *newNode;

    ptr = start;

    while(ptr != NULL && ptr->info != key){
        ptr = ptr->link;
    }

    if(ptr == NULL){
        printf("Element not found\n");
        return;
    }

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL){
        printf("Overflow\n");
        return;
    }

    newNode->info = item;
    newNode->link = ptr->link;
    ptr->link = newNode;
}

void insertAtEnd(struct Node** start, int item)
{
    struct Node *ptr, *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

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

int main()
{
    struct Node* start = NULL;

    int totalItems, item, key, newItem, i;

    printf("How many elements do you want to create? ");
    scanf("%d",&totalItems);

    for(i=0;i<totalItems;i++){
        printf("Enter value: ");
        scanf("%d",&item);
        insertAtEnd(&start,item);
    }

    printf("\nInitial List:\n");
    printList(start);

    printf("\nAfter which element do you want to insert? ");
    scanf("%d",&key);

    printf("Enter the element to insert: ");
    scanf("%d",&newItem);

    insertAfter(start,key,newItem);

    printf("\nList after insertion:\n");
    printList(start);

    return 0;
}