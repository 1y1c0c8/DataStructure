//
// Created by kenny on 2022/7/5.
// Reference:
//     https://mypaper.pchome.com.tw/zerojudge/post/1323260629
//     https://opensourcedoc.com/c-programming/struct/

#include <stdio.h>
#include "../stackByHoff.h"
#define MAX_LENGTH 20
#define T target
#define ST stackTop
#define PAT preAnsTop

int main(){
    printf("Enter the expression:") ;

    //宣告儲存輸入字串的結構
    element elements[MAX_LENGTH] ;
    for(int i=0; i<MAX_LENGTH; i++){
        elements[i].value = ' ' ;
        elements[i].weight = -1 ;
    }
    int target=0 ;

    //讀取輸入字元並且加權置入結構
    int index = 0 ;
    do{
        char tempChar = ' ' ;
        scanf("%c", &tempChar) ;
        elements[index].value = tempChar ;

        elements[index].weight = weight(tempChar) ;

        index ++ ;
    }while(elements[index-1].value != '\n') ;

    //從右讀至左(逆)
    target = index-2 ;
    //計算有幾個字元(含括號)
    //elementsNum = target+1 ;
    elementsNum = index-1 ;

    //stack
    element stack[elementsNum] ;
    int stackTop = -1 ;

    //宣告preAns，儲存尚未反轉之前的已處理字串
    char preAns[MAX_LENGTH] ;
    for(int i=0; i<MAX_LENGTH; i++){
        preAns[i] = ' ' ;
    }
    int preAnsTop=0 ;

    //開始由右至左逆向判讀輸入字串
    for(int i=target; i>=0; i--){
        if(elements[i].weight == 3){
            preAns[PAT] = elements[i].value ;
            PAT++ ;
        }
        else{
            if(elements[i].weight == -0.5)

                //太多top了 直接混在一起==

                push(&stack[0], &ST, elements[i].value) ;
            else if(elements[i].weight == 0.5){
                do{
                    preAns[PAT] = stack[ST].value ;
                    //
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

    printf("Prefix format: ") ;
    for(int i=PAT-1; i>=0; i--){
        printf("%c", preAns[i]) ;
    }

    return 0 ;
}