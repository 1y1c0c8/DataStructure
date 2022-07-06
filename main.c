#include <stdio.h>
#define MAX_LENGTH 20
#define T target
#define ST stackTop
#define PAT preAnsTop
typedef struct element{
    char value ;
    float weight ;
}element;
int elementsNum = 0;
float weight(char element){
    if(element == '(') return 0.5 ;
    else if(element == ')') return -0.5 ;
    else if(element == '+' || element == '-') return 1 ;
    else if(element == '*' || element == '/') return 2 ;
    else if(element == '\n') return 4 ;
    else return 3 ;
}
int stackFull(int top){
    if(top == elementsNum-1)
        return 1 ;
    else return 0 ;
}
int stackEmpty(int top){
    if(top == -1)
        return 1 ;
    else return 0 ;
}
void push(element* stack, int* top, char element){
    if(!stackFull(top)){
        (*top)++ ;
        (stack+*top)->value = element ;
        (stack+*top)->weight = weight(element) ;
    }
}
void pop(element* stack, int* top){
    if(!stackEmpty(top)){
        (stack+*top)->value = ' ' ;
        (stack+*top)->weight = -1 ;
        (*top)-- ;
    }
}
int main(){
    element elements[MAX_LENGTH] ;
    for(int i=0; i<MAX_LENGTH; i++){
        elements[i].value = ' ' ;
        elements[i].weight = -1 ;
    }
    int target=0 ;
    printf("Enter the expression:") ;
    int index = 0 ;
    do{
        char tempChar = ' ' ;
        scanf("%c", &tempChar) ;
        elements[index].value = tempChar ;
        elements[index].weight = weight(tempChar) ;
        index ++ ;
    }while(elements[index-1].value != '\n') ;
    target = index-2 ;
    elementsNum = target+1 ;
    element stack[elementsNum] ;
    int stackTop = -1 ;
    char preAns[MAX_LENGTH] ;
    for(int i=0; i<MAX_LENGTH; i++)
        preAns[i] = ' ' ;
    int preAnsTop=0 ;
    for(int i=target; i>=0; i--){
        if(elements[i].weight == 3){
            preAns[PAT] = elements[i].value ;
            PAT++ ;
        }
        else{
            if(elements[i].weight == -0.5)
                push(&stack[0], &ST, elements[i].value) ;
            else if(elements[i].weight == 0.5){
                do{
                    preAns[PAT] = stack[ST].value ;
                    pop(&stack[0], &ST) ;
                    PAT++ ;
                }while(stack[ST].weight != -0.5) ;
                stack[ST].value = ' ' ;
                stack[ST].weight = -1 ;
                ST-- ;
            }
            else if(elements[i].weight > stack[ST].weight)
                push(&stack[0], &ST, elements[i].value) ;
            else if(elements[i].weight <= stack[ST].weight){
                preAns[PAT] = stack[ST].value ;
                pop(&stack[0], &ST) ;
                push(&stack[0], &ST, elements[i].value) ;
            }
        }
    }
    if(!stackEmpty(ST)){
        do{
            preAns[PAT] = stack[ST].value ;
            PAT++ ;
            pop(&stack[0], &ST) ;
        }while(!stackEmpty(ST)) ;
    }
    for(int i=PAT-1; i>=0; i--){
        printf("%c", preAns[i]) ;
    }
    return 0 ;
}