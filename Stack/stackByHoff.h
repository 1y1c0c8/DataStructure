//
// Created by kenny on 2022/7/7.
//

#ifndef stackByHoff
#define stackByHoff

#include <stdio.h>
#include <stdlib.h>
#define initCap 4 //initCap: initial length
#define space ' '

typedef struct element{
    char value ;
    float weight ;
}element;

typedef struct{
    int top ;
    int capacity ;
    element* arr ;
}stack;

float weight(char element){
    //if(element == ' ') return -1 ;
    if(element == '(') return 0.5 ;
    else if(element == ')') return -0.5 ;
    else if(element == '+' || element == '-') return 1 ;
    else if(element == '*' || element == '/') return 2 ;
    else if(element == '\n') return 4 ;
    else return 3 ;
}

stack* stackCreate(){
    stack* newS = malloc(sizeof(stack)) ;
    element* arr = malloc(sizeof(element) * initCap) ;

    newS->top = 0 ;
    newS->arr = arr ;
    newS->capacity = initCap ;

    for(int i=0; i<newS->capacity; i++){
        newS->arr[i].value = ' ' ;
        newS->arr[i].weight = -1 ;
    }

    return newS ;
}

char stackTop(stack* S){
    return S->arr[S->top].value ;
}

stack* stackDouble(stack* S){
    stack* doubleStack = malloc(sizeof(stack)) ;
    element* arr = malloc(sizeof(element)*S->capacity*2) ;

    doubleStack->top = S->top ;
    doubleStack->capacity = 2*S->capacity ;
    doubleStack->arr = arr ;

    for(int i=0; i<2*S->capacity; i++){
        if(i<S->capacity) {
            doubleStack->arr[i].value = S->arr[i].value ;
            doubleStack->arr[i].weight = weight(doubleStack->arr[i].value) ;
        }else {
            doubleStack->arr[i].value = ' ';
            doubleStack->arr[i].weight = -1 ;
        }
    }

    return doubleStack ;
}

int stackFull(stack S) ;

stack* stackPush(stack *S, char C){
    if(stackFull(*S))
        S = stackDouble(S) ;

    S->arr[S->top].value = C ;
    S->arr[S->top].weight = weight(C) ;
    (S->top) ++ ;

    return S ;
}

void stackPop(stack* S){
    S->arr[(S->top)-1].value = space ;
    S->arr[(S->top)-1].weight = -1 ;
    (S->top) -- ;
}

//回傳元素個數
int stackSize(stack* S){
    return S->top ;
}

int stackEmpty(stack S){
    return S.top == 1 ;
}

int stackFull(stack S){
    return S.top == S.capacity ;
}

void stackFree(stack *S){
    free(S->arr) ;
    free(S) ;
}

#endif //stackByHoff
