// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    struct Node *prev;
    int data;
};
struct Node *insertbeg(struct Node **head,int val)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    if (*head == NULL) {
        newNode->prev = newNode;// Case when the list is empty
        newNode->next = newNode; // Point to itself
        *head = newNode;
    }
    struct Node *ptr=*head;
    while(ptr->next!=*head)
    {
        ptr=ptr->next;
    }
    newNode->next = *head;
    newNode->prev = ptr;
    ptr->next = newNode;
    (*head)->prev = newNode;
    *head = newNode;
}
struct Node* insertend(struct Node **head,int val)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    struct Node *ptr=*head;
    while(ptr->next!=*head)
    {
        ptr=ptr->next;
    }
    newNode->prev=ptr;
    newNode->next=*head;
    ptr->next=newNode;
    (*head)->prev=newNode;
}
void print(struct Node *head)
{
    struct Node *current=head;
     do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}
int main() {
    struct Node *head=NULL;
    int val;
    insertbeg(&head,15);
    insertbeg(&head,14);
    insertbeg(&head,13);
    insertbeg(&head,12);
    insertbeg(&head,11);
    print(head);
    printf("\n");
    printf("\n");
    printf("Enter the value to be entered at the end: ");
    scanf("%d",&val);
    insertend(&head,val);
    print(head);
    return 0;
}