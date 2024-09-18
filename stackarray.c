#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void push(int stack[MAX], int *top, int val) {
    if (*top == MAX - 1) {
        printf("Overflow\n");
    } else {
        (*top)++;
        stack[*top] = val;
        printf("%d pushed into the stack\n", val);
    }
}

void pop(int stack[MAX], int *top) {
    if (*top == -1) {
        printf("Underflow\n");
    } else {
        printf("%d has been popped\n", stack[*top]);
        (*top)--;
    }
}

void peek(int stack[MAX], int *top) {
    if (*top != -1) {
        printf("The top element is %d\n", stack[*top]);
    } else {
        printf("Stack is empty\n");
    }
}

void print(int stack[MAX], int *top) {
    if (*top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i <= *top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, stack[MAX], val;
    int top = -1; // Initialize top to -1 (indicating an empty stack)

    printf("Enter the number of elements to push (max %d): ", MAX);
    scanf("%d", &n);
    if (n > MAX) {
        printf("Cannot push more than %d elements.\n", MAX);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter value to be pushed: ");
        scanf("%d", &val);
        push(stack, &top, val);
    }

    print(stack, &top);
    pop(stack, &top);
    pop(stack, &top);
    print(stack, &top);

    printf("Enter value to be pushed: ");
    scanf("%d", &val);
    push(stack, &top, val);
    peek(stack, &top);

    return 0;
}
