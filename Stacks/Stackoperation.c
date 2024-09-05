#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
//SIMILAR TO INSERTION AND DELETION AT BEGINNING
void push(struct Node**top,int val)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=*top;
    *top=newNode;
}
void pop(struct Node**top)
{
    if(*top==NULL)
    {
        printf("Underflow: No nodes found");
    }
    else
    {
        struct Node *temp=*top;
        (*top)=(*top)->next;
        free(temp);
    }
}
void peek(struct Node**top)
{
    printf("The foremost Node is: %d",(*top)->data);
}
void print(struct Node*top)
{
    struct Node *current=top;
    while(current->next!=NULL)
    {
        printf("%d \n",current->data);
        current=current->next;
    }
    printf("\n");
}
int main() {
     struct Node*top=NULL;
     push(&top,10);
     push(&top,20);
     push(&top,30);
     push(&top,40);
     push(&top,50);
     push(&top,60);
     print(top);
     printf("After popping 1: \n");
     pop(&top);
     print(top);
     printf("After popping 2: \n");
     pop(&top);
     print(top);
     printf("Peeking: \n");
     peek(&top);
    return 0;
}