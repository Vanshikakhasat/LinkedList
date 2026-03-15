#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void insert_after_node(struct Node** start, struct Node* LOC, int item)
{
    struct Node* newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Overflow: No memory available.\n");
        return;
    }

    newNode->info = item;

    if (LOC == NULL){
        newNode->link = *start;
        *start = newNode;
    }
    else{
        newNode->link = LOC->link;
        LOC->link = newNode;
    }
}

void printList(struct Node* node)
{
    while (node != NULL){
        printf("%d -> ", node->info);
        node = node->link;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* start = NULL;

    int totalItems, item, i;

    printf("How many Elements do you want to insert? ");
    scanf("%d", &totalItems);

    for(i = 0; i < totalItems; i++)
    {
        printf("Enter the value: ");
        scanf("%d", &item);

        insert_after_node(&start, NULL, item);

        printList(start);
    }

    printf("\nFinal Result: ");
    printList(start);

    return 0;
}