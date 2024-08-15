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
void deleteend(struct Node **head)
{
    struct Node* ptr=*head;
    struct Node* pptr;
    while(ptr->next!=NULL)
    {
        pptr=ptr;
        ptr=ptr->next;
    }
    pptr->next=NULL;
    free(ptr);
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
  int n,i,val,num;
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
  printf("After Deletion from End: ");
  deleteend(&head);
  print(head);
}