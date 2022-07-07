//
// Created by kenny on 2022/7/7.
//

#ifndef DATASTRUCTURE_PUSH_H
#define DATASTRUCTURE_PUSH_H

typedef struct element{
    char value ;
    float weight ;
}element;

//Remember to update the value of elementsNum
int elementsNum ;

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
        //該加括號就加括號
        (*top)++ ;
        (stack+ *top) ->value = element ;
        (stack+ *top) ->weight = weight(element) ;
    }
}

void pop(element* stack, int* top){
    if(!stackEmpty(top)){
        (stack+ *top) ->value = ' ' ;
        (stack+ *top) ->weight = -1 ;
        (*top)-- ;
    }
}

#endif //DATASTRUCTURE_PUSH_H
