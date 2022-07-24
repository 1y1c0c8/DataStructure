//
// Created by kenny on 2022/7/11.
//

#ifndef DATASTRUCTURE_STRINGSTACK_H
#define DATASTRUCTURE_STRINGSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../Vector/vectorByHoff.h"
#define initStringCap 1
#define Before S->ARR
#define newV newS->ARR

typedef struct{
    int TOP ;
    int CAP ;
    vector* ARR ;
}STACK;

STACK* stack_Create(){
    STACK* newS = malloc(sizeof(STACK)) ;
    vector* ARR = malloc(sizeof(vector)*initCap) ;

    newS->TOP = 0 ;
    newS->ARR = ARR ;
    newS->CAP = initCap ;

    for(int i=0; i<newS->CAP; i++){
        newS->ARR[i] = *vecPushBack(&(newS->ARR[i]), ' ') ;
    }

    return newS ;
}

vector* stack_Top(STACK *S){
    return (S->ARR) + (S->TOP) ;
}

int stack_Full(STACK S) ;

//STACK* stack_Double(STACK *S){
//    STACK *doubleSTACK = malloc(sizeof(STACK)) ;
//    vector* newARR = malloc(2* sizeof(vector)* S->CAP) ;
//
//    doubleSTACK->ARR = newARR ;
//    doubleSTACK->CAP = S->CAP* 2 ;
//    doubleSTACK->TOP = S->TOP ;
//
//    for(int i=0; i<2*S->CAP; i++){
//        if(i<S->CAP)
//            doubleSTACK->ARR[i] = S->ARR[i] ;
//        else{
//
//        }
//    }
//
//}

STACK* stack_Double(STACK *S){
    STACK *doubleSTACK = malloc(sizeof(STACK)) ;

    //
    //
    //do something
    //
    //

    return doubleSTACK ;
}

//
//STACK* stack_Copy(STACK *S){
//    STACK *newS = stack_Create() ;
//
//    for(int i=0; i<){
//
//    }
//
//    return newS ;
//}

int stack_Size(STACK *S) ;

STACK* stack_Push_Char(STACK *S, char C){
//    if(stack_Full(*S))
//         S = stack_Double(S) ;

    S->ARR[S->TOP] = *vecPushBack(&(S->ARR[S->TOP]), C) ;
    (S->TOP) ++ ;

    return S ;
}

//STACK* stack_Push_Vec(STACK *S, vector* V){
//    STACK *newS = stack_Create() ;
//
//    newS =
//
//    for(int i=0; i<){
//
//    }
//
//
//    return newS ;
//}

void stack_Pop(STACK *S) ;

STACK* stack_mergeInOne(STACK *S, int mode, char opr /*operator*/){
    //prefix->infix:  1
    //postfix->infix: 2

    STACK *newS = stack_Create() ;


    switch(mode){

        //
        // X
        //┌----------------
        //| [Aa] [Bb]         STACK Before
        //└----------------
        // ▼
        //[( [Bb] X [Aa] )]   vector_Temp
        // ▼
        //┌----------------
        //| ( [Bb] X [Aa] )   STACK After
        //└----------------
        case 1:{
            //STACK_Before中topVec的pointer
            char *beginP = vecBegin(&Before[(S->TOP)-1]) ; //指向STACK_Before中B的pointer
            char *constBegin = vecBegin(&Before[(S->TOP)-1]) ;
            char *endP = vecEnd(&Before[(S->TOP)-1]) ; //指向STACK_Before中b的pointer
            char *constEnd = vecEnd(&Before[(S->TOP)-1]) ;

            //1)
            newV = vecPushBack(newV, '(') ;
            //2)
            for(;beginP!=constEnd ; beginP++){
                newV = vecPushBack(newV, *beginP) ;
                Before[(S->TOP)-1].end -- ;
            }
            (S->TOP) -- ;

            //UPDATE
            beginP = vecBegin(&Before[(S->TOP)-1]) ; //指向STACK_Before中B的pointer
            constBegin = vecBegin(&Before[(S->TOP)-1]) ;
            endP = vecEnd(&Before[(S->TOP)-1]) ; //指向STACK_Before中b的pointer
            constEnd = vecEnd(&Before[(S->TOP)-1]) ;

            //3)
            newV = vecPushBack(newV, opr) ;
            //4)
            for(;beginP!=constEnd ;beginP++){
                newV = vecPushBack(newV, *beginP) ;
                Before[(S->TOP)-1].end -- ;
            }
            (S->TOP) -- ;
            //5)
            newV = vecPushBack(newV, ')') ;

            break ;
        }

        //(X)
        //┌----------------
        //| [Aa] [Bb]         STACK_Before
        //└----------------
        // ▼
        //[( [Aa] X [Bb] )]   vector_Temp
        // ▼
        //┌----------------
        //| ( [Aa] X [Bb] )   SATCK_After
        //└----------------
        case 2:{
            //STACK_Before中topVec的pointer
            char *beginP = vecBegin(&Before[(S->TOP)-1]) ; //指向STACK_Before中B的pointer
            char *constBegin = vecBegin(&Before[(S->TOP)-1]) ;
            char *endP = vecEnd(&Before[(S->TOP)-1]) ; //指向STACK_Before中b的pointer
            char *constEnd = vecEnd(&Before[(S->TOP)-1]) ;

            vector *tempVec1 = vecCopy(&Before[(S->TOP)-1]) ;
            stack_Pop(S) ;
            vector *tempVec2 = vecCopy(&Before[(S->TOP)-1]) ;
            stack_Pop(S) ;

            vector *newVec = vecCreate() ;

            newV = vecPushBack(newV, '(') ;
            newV = vecPushVec(newV, tempVec1) ;
            newV = vecPushBack(newV, opr) ;
            newV = vecPushVec(newV, tempVec2) ;
            newV = vecPushBack(newV, ')') ;



            break ;
        }
    }

    return newS ;
}

void stack_Pop(STACK *S){
    vecClear(&S->ARR[(S->TOP)-1]) ;
}

//回傳元素個數
int stack_Size(STACK *S){
    return S->TOP ;
}

int stack_empty(STACK S){
    return S.TOP == 0 ;
}

int stack_Full(STACK S){
    return S.TOP == S.CAP ;
}

void stack_Free(STACK *S){
    free(S->ARR) ;
    free(S) ;
}

#endif //DATASTRUCTURE_STRINGSTACK_H
