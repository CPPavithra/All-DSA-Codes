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
  printf("\n");
  sort(&head);
  print(head);
}