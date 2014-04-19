#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Stack {
    Node *base;
    Node *top;
}Stack;

void InitStack(struct Stack *S) {
    S->base = (struct Node *)malloc(sizeof(struct Node));
    if (S->base == NULL) {
        printf("malloc failed!!!\n");
        exit(0);
    }
    S->top = S->base;
    S->base->next = NULL;
    return;
}

void push(struct Stack *S, int num) {
    Node *pNew = (struct Node *)malloc(sizeof(struct Node));
    if (pNew == NULL) {
        printf("relloc failed!!!\n");
        exit(1);
    }
    pNew->data = num;
    pNew->next = S->top;
    S->top = pNew;
    return;
}

int pop(struct Stack *S) {
    if (S->top == S->base) {
        printf("There is not a number in the Stack");
        exit(2);
    }
    Node *node = S->top;
    int num = node->data;
    S->top = node->next;
    node = NULL;
    free(node);
    return num;
}

int isEmpty(struct Stack *S) {
    if (S->top == S->base)
        return 0;
    else
        return 1;
}

//十进制到八进制的转换
void conversion(int num) {
    struct Stack *S = malloc(sizeof(Stack));
    if (S != NULL) {
        S->base = NULL;
        S->top  = S->base;
    }
    InitStack(S);
    while(num) {
        push(S, num%8);
        num = num / 8;
    }
    while(isEmpty(S)) {
        printf("%d", pop(S));
    }
    printf("\n");
    
}

int main() {
    int num;
    printf("print input a number:\n");
    scanf("%d", &num);
    conversion(num);
}
