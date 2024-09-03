// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};
void insertbeg(struct node **head,int val)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    newNode->next=*head;
    *head=newNode;
}
void print(struct node *head)
{
    struct node *current=head;
    while(current!=NULL)
    {
        printf("%d-> ",current->data);
        current=current->next;
    }
    printf("NULL");
}
void insertafter(struct node **head,int val,int num)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
        struct node *ptr=*head;
    newNode->data=val;
    while(ptr->data!=num)
    {
        ptr=ptr->next;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;
}
void insertbefore(struct node **head,int val,int num)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    struct node *ptr=*head;
    struct node *pptr;
    while(ptr->data!=num)
    {
        pptr=ptr;
        ptr=ptr->next;
    }
    newNode->next=ptr;
    pptr->next=newNode;
}
void insertend(struct node **head,int val)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=val;
    struct node *ptr=*head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    newNode->next=NULL;
    ptr->next=newNode;
}
void deletebeg(struct node **head)
{
    struct node* ptr=*head;
    *head=(*head)->next;
    free(ptr);
}
void deleteend(struct node **head)
{
    struct node* ptr=*head;
    struct node* pptr;
    while(ptr->next!=NULL)
    {
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=NULL;
    free(ptr);
}
void deleteafter(struct node **head,int num)
{
   struct node* ptr=*head;
   struct node* aptr;
   while(ptr->data!=num)
   {
       ptr=ptr->next;
       aptr=ptr->next;
   }
   ptr->next=aptr->next;
   free(aptr);
}
void deletebefore(struct node **head,int num)
{
    struct node* ptr=*head;
    struct node *pptr1;
    struct node *pptr2;
    while(ptr->data!=num)
    {
        pptr1=ptr;
        pptr2=pptr1;
        ptr=ptr->next;
        pptr1=ptr;
        ptr=ptr->next;
        
    }
    pptr2->next=ptr;
    free(pptr1);
    
}
void search(struct node **head, int num) {
    int nodenum = 0;
    int flag = 0; // Initialize flag to 0
    struct node *ptr = *head;

    while (ptr != NULL) {
        if (ptr->data == num) {
            flag = 1; // Set flag to 1 when the number is found
            printf("The Search was Successful\n");
            printf("The position of the node from beginning is: %d\n", nodenum + 1);
            break; // Exit the loop as we found the number
        }
        ptr = ptr->next;
        nodenum++;
    }

    if (flag == 0) {
        printf("The number does not exist in the list\n");
    }
}
void sort(struct Node **head) {
    
    int temp;
    int swapped;
    do{
        swapped=1;
        struct Node *ptr=*head;
    while(ptr->next!=NULL)
    {
        if(ptr->next->data<ptr->data)
        {
            temp=ptr->data;
            ptr->data=ptr->next->data;
            ptr->next->data=temp;
            swapped=1;
        }
        ptr=ptr->next;
    }
    }while(swapped);
}



int main() {
    struct node *head=NULL;
    int val,num;
    insertbeg(&head,40);
    insertbeg(&head,30);
    insertbeg(&head,20);
    insertbeg(&head,10);
    print(head);
    printf("\n");
    printf("TO INSERT AFTER A GIVEN NODE\n");
    printf("Enter value to be entered: ");
    scanf("%d",&val);
    printf("Enter node after which to be entered: ");
    scanf("%d",&num);
    insertafter(&head,val,num);
    printf("New List: ");
    print(head);
    printf("\n");
    printf("TO INSERT BEFORE A GIVEN NODE\n");
    printf("Enter value to be entered: ");
    scanf("%d",&val);
    printf("Enter node before which to be entered: ");
    scanf("%d",&num);
    insertbefore(&head,val,num);
    printf("New List: ");
    print(head);
    printf("\n");
    printf("TO INSERT AT END\n");
    printf("Enter the value to be entered: ");
    scanf("%d",&val);
    insertend(&head,val);
    print(head);
    printf("\n");
    printf("Deleting first node: ");
    deletebeg(&head);
    print(head);
    printf("\n");
    printf("Deleting last node: ");
    deleteend(&head);
    print(head);
    printf("\n");
    printf("Enter the node after the value: ");
    scanf("%d",&val);
    deleteafter(&head,val);
    print(head);
    printf("\n");
    printf("Enter the node before the value: ");
    scanf("%d",&val);
    deletebefore(&head,val);
    print(head);
    printf("\n");
    printf("Enter the number to be searched: ");
    scanf("%d",&num);
    search(&head,num);
    printf("\n");
    sort(&head);
    printf("After Sorting: ");
    print(head);
    return 0;


}
