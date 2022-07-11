//
// Created by kenny on 2022/7/7.
//

#include <stdio.h>
#define MAX_LENGTH 20
#include "../stackByHoff.h"

int main(){
    element elements[MAX_LENGTH] ;

    int index=0 ;
    do{
        char tempChar = ' ' ;
        scanf("%c", &tempChar) ;
        elements[index].value = tempChar ;
        elements[index].weight = weight(tempChar) ;
        index++ ;
    }while(elements[index].weight != 4);

    stringElement stack[MAX_LENGTH] ;
    int ST=-1 ;

    char ans[MAX_LENGTH] ;
    int AT=0 ; //AT: ansTop

    for(int i=0; i<=index-1; i++){
        if(elements[i].weight == 3)
            push(&stack[0], &ST, elements[i].value) ;
        else if(elements[i].weight == 1 || elements[i].weight == 2){
                ans[AT] = '(' ;
                AT++ ;
                ans[AT] = stackTop(&stack[0], &ST) ->value ;
                AT++ ;
                ans[AT] = elements[i].value ;
                AT++ ;
                ans[AT] = stackTop(&stack[0], &ST) ->value ;
                AT++ ;

        }
    }

    return 0 ;
}