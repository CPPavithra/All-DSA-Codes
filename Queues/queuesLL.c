#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int data;
    struct Queue *next;
};

void insert(struct Queue **front, struct Queue **rear, int val) {
    struct Queue *newNode = (struct Queue*)malloc(sizeof(struct Queue));
    newNode->data = val;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void deleteq(struct Queue **front) {
    if (*front == NULL) {
        printf("Underflow\n");
    } else {
        struct Queue *temp = *front;
        *front = (*front)->next;
        free(temp);
    }
}

void display(struct Queue *front) {
    while (front != NULL) {
        printf("%d <- ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct Queue *front = NULL;
    struct Queue *rear = NULL;

    insert(&front, &rear, 10);
    insert(&front, &rear, 20);
    insert(&front, &rear, 30);
    insert(&front, &rear, 40);
    insert(&front, &rear, 50);

    display(front);  // Should display the queue: 10 20 30 40 50

    deleteq(&front); // Deletes 10
    deleteq(&front); // Deletes 20

    display(front);  // Should display the queue: 30 40 50

    return 0;
}
