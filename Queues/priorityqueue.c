#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    int priority;
    struct Queue *next;
};

void insertq(struct Queue **front, int val, int p) {
    struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = val;
    newNode->priority = p;
    newNode->next = NULL;

    if (*front == NULL || (*front)->priority > newNode->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Queue *ptr = *front;

        while (ptr->next != NULL && ptr->next->priority <= newNode->priority) {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
}

void printq(struct Queue *front) {
    while (front != NULL) {
        printf("%d , %d -> ", front->data, front->priority);
        front = front->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue *front = NULL;

    insertq(&front, 10, 1);
    insertq(&front, 20, 6);
    insertq(&front, 30, 5);
    insertq(&front, 40, 8);
    insertq(&front, 50, 2);
    insertq(&front, 60, 3);

    printq(front);

    return 0;
}
