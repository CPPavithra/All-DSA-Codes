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
void search(struct Node **head, int num) {
    int nodenum = 0;
    int flag = 0; // Initialize flag to 0
    struct Node *ptr = *head;

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
  printf("Enter the number to be searched: ");
  scanf("%d",&num);
  search(&head,num);
}