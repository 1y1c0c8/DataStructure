//
// Created by kenny on 2022/7/6.
//

#include <stdio.h>
#include "../stackByHoff.h"
#define MAX_LENGTH 10

int main(){
    printf("Enter the expression:") ;

    //宣告儲存輸入字串的結構
    element elements[MAX_LENGTH] ;
    for(int i=0; i<MAX_LENGTH; i++){
        elements[i].value = ' ' ;
        elements[i].weight = -1 ;
    }
    int target=0 ; //從輸入字串左邊開始讀(順)

    //讀取輸入字元並且加權置入結構
    int index = 0 ;
    do{
        char tempChar = ' ' ;
        scanf("%c", &tempChar) ;
        elements[index].value = tempChar ;

        elements[index].weight = weight(tempChar) ;

        index ++ ;
    }while(elements[index-1].value != '\n') ;

    //計算字元個數
    elementsNum = target+1 ;

    //stack
    element stack[MAX_LENGTH] ;
    int ST ; //ST: stackTop

    //宣告ans
    char ans[MAX_LENGTH] ;
    for(int i=0; i<MAX_LENGTH; i++)
        ans[i] = ' ' ;
    int AT=0 ; //AT: ansTop

    //開始由左至右順向判讀輸入字串
    for(int i=target; i<elementsNum; i++) {
        if (elements[i].weight == 3) {
            ans[AT] = elements[i].value;
            AT++;
        }
        
    }


    return 0 ;
}