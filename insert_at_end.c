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

`