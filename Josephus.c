#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *next;
    int id;
};
struct Node* circle(struct Node *head,int person_id)
{
    struct Node *newperson=(struct Node*)malloc(sizeof(struct Node));
    newperson->id=person_id;
    if(head==NULL)
    {
        head=newperson;
        head->next=head;
    }
    else
    {
        struct Node *ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=newperson;
        newperson->next=head;
    }
    return head;
}
void print(struct Node *head)
{
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *current = head;
    do {
        printf("%d -> ", current->id);
        current = current->next;
    } while (current != head);
    printf("Head\n");
}
void josephus(struct Node *head,int k)
{
    struct Node *pptr;
    struct Node *ptr=head;
    while (ptr->next != ptr) {  // More than one node
        for (int i = 0; i < k - 1; i++) {
            pptr = ptr;
            ptr = ptr->next;
        }
        // Remove the kth node
        pptr->next = ptr->next;
        free(ptr);
        ptr=pptr->next;
    }
    int winner=ptr->id;
    free(ptr);
    printf("The winner is: %d",winner);
}
int main()
{
    struct Node *head=NULL;
    int n,k,i;
    printf("Enter the number of people: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        head= circle(head,i);
    }
    printf("The people are: ");
    print(head);
    printf("For josephus: \n");
    printf("Enter the number of people to be skipped: ");
    scanf("%d",&k);
    printf("After killing: \n");
    josephus(head,k);
    return 0;
}