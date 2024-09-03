// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Node
{
  int row;
  int col;
  int val;
  struct Node* next;
};
void createnode(struct Node **head,int row,int col,int val)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->val=val;
    newNode->col=col;
    newNode->row=row;
    newNode->next=*head;
    *head=newNode;
}
void print(struct Node *head)
{
    struct Node *current=head;
    int i=1;
    while(current->next!=NULL)
    {
        printf("Non- zero element number %d:  ",i);
        printf("Row: %d\t",current->row);
        printf("Column: %d\t",current->col);
        printf("Value: %d\n",current->val);
        current=current->next;
        i++;
    }
    printf("\nEnd of Matrix. Rest all elements are 0.");
}
int main() {
    int sparseMatric[4][5] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };
    struct Node* head = NULL;
 
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
 {
            if (sparseMatric[i][j] != 0)
            {
                createnode(&head, sparseMatric[i][j], i, j);
            }
 }
    }
    print(head);
    return 0;
}