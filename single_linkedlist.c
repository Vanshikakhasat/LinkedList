#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

int main() {
   
    struct node *start = malloc(sizeof(struct node));
    start->data = 90;
    start->link = NULL;

   
    struct node *second = malloc(sizeof(struct node));
    second->data = 780;
    second->link = NULL;
    start->link = second; 

    struct node *third = malloc(sizeof(struct node));
    third->data = 7;
    third->link = NULL;
    second->link = third;  

    return 0;
    
}