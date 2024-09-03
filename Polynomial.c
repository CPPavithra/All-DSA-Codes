#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};
typedef struct Node Node;

void polynomial(Node **poly, int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        Node* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    Node* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coeff, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }
    printf("\n");
}

//Function to add these
Node *add(Node *poly1,Node *poly2)
{
    Node *result=NULL;
    while(poly1!=NULL && poly2!=NULL)
    {
        if(poly1->exp==poly2->exp)
        {
            polynomial(&result,poly1->coeff+poly2->coeff,poly1->exp);
            poly1=poly1->next;
            poly2=poly2->next;
        }
        else if(poly1->exp>poly2->exp)
        {
            polynomial(&result,poly1->coeff,poly1->exp);
            poly1=poly1->next;
        }
        else
        {
            polynomial(&result,poly2->coeff,poly2->exp);
            poly2=poly2->next;
        }
        while (poly1 != NULL) {
        polynomial(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    
    while (poly2 != NULL) {
        polynomial(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    
    return result;
    }
}

int main() {
    Node* poly1 = NULL;
    polynomial(&poly1, 5, 4);
    polynomial(&poly1, 3, 2);
    polynomial(&poly1, 1, 0);
    
    Node* poly2 = NULL;
    polynomial(&poly2, 4, 4);
    polynomial(&poly2, 2, 2);
    polynomial(&poly2, 1, 1);
    
    printf("First polynomial: ");
    print(poly1);
    printf("Second polynomial: ");
    print(poly2);
    Node* result = add(poly1, poly2);
    printf("Result: ");
    print(result);


    return 0;
}
