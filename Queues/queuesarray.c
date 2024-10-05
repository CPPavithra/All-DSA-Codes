#include <stdio.h>
#define MAX 10

void insertq(int *queue, int *front, int *rear, int val) {
    if (*rear == MAX - 1) {
        printf("Overflow\n");
    } else if (*front == -1 && *rear == -1) {
        *front = 0;
        *rear = 0;
        queue[*rear] = val;
    } else {
        (*rear)++;
        queue[*rear] = val;
    }
}

void deleteq(int *queue, int *front, int *rear) {
    if (*front == -1) {
        printf("Underflow\n");
    } else {
        int val = queue[*front];
        printf("Deleted: %d\n", val);
        if (*front == *rear) { // If the queue becomes empty after deletion
            *front = -1;
            *rear = -1;
        } else {
            (*front)++;
        }
    }
}

void printq(int *queue, int front, int rear) {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d <- ", queue[i]);
    }
    printf("END");
    printf("\n");
}

int main() {
    int queue[MAX];
    int front = -1, rear = -1;

    insertq(queue, &front, &rear, 10);
    insertq(queue, &front, &rear, 20);
    insertq(queue, &front, &rear, 30);
    insertq(queue, &front, &rear, 40);
    insertq(queue, &front, &rear, 50);
    insertq(queue, &front, &rear, 60);

    printq(queue, front, rear);

    deleteq(queue, &front, &rear);
    deleteq(queue, &front, &rear);

    printq(queue, front, rear);

    return 0;
}
