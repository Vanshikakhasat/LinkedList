#include <stdlib.h>
#include <stdio.h>
struct node{
    int data;
    struct node *link;
};
int main(){
    struct node *start =NULL;
    start=(struct node*)malloc(sizeof(struct node));
    start->data=90;
    start->link=NULL;
    printf("%d",start->data);
    return 0;

}