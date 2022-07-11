//
// Created by kenny on 2022/7/7.
//

#ifndef newStack
#define newStack

#include <stdlib.h>

typedef struct element {
    char value ;
    float weight ;
}element;

typedef struct {
    int top;
    int capacity;
    element *arr;
} stack;

float weight(char element){
    if(element == '(') return 0.5 ;
    else if(element == ')') return -0.5 ;
    else if(element == '+' || element == '-') return 1 ;
    else if(element == '*' || element == '/') return 2 ;
    else if(element == '\n') return 4 ;
    else return 3 ;
}

stack *createStack(int capacity) {
    stack *st = malloc(sizeof(stack));
    element *arr = malloc(sizeof(element) * capacity);
    st -> top = -1;
    st -> capacity = capacity;
    st -> arr = arr;

    return st;
}

void freeStack(stack *stack) {
    free(stack->arr);
    free(stack);
}

int stackFull(stack *stack) {
    return stack -> top == stack->capacity-1;
}

int stackEmpty(stack *stack){
    return stack -> top == -1;
}

void push(stack *stack, element element) {
    if (!stackFull(stack)) {
        (stack->top)++;
        stack->arr[stack->top] = element;
    }
}

void pop(stack *stack) {
    if (!stackEmpty(stack)) {
        (stack->top)--;
    }
}

element stackTop(stack *stack) {
    return stack->arr[stack->top];
}

#endif //newStack
