#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    int data;
};
struct Node *insertbeg(struct Node **head, int val)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=*head;
    *head=newNode;
}
struct Node *insertend(struct Node **head,int val)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    struct Node *ptr=*head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->next=NULL;
}
void print(struct Node *head)
{
   struct Node *current=head;
   while(current!=NULL)
   {
    printf("%d -> ",current->data);
    current=current->next;
   }
   printf("NULL");
}
int main()
{
  struct Node *head=NULL;
  int n,i,val;
  printf("Insert Number of elements in the linked list: ");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the %d node data: ",(n-i));
    scanf("%d",&val);
    insertbeg(&head,val);
  }
  print(head);
  printf("\n");
  printf("Enter the number to be entered at the end: ");
  scanf("%d",&val);
  insertend(&head,val);
  printf("After Insertion: ");
  print(head);
}