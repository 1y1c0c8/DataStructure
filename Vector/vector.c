//
// Created by kenny on 2022/7/11.
//

#include <stdio.h>
#include <stdlib.h>
#include "vectorByHoff.h"

int main(){
//    vector testVec = *vecCreate() ;
//    testVec = *vecPushBack(&testVec, 'A') ;
//    testVec = *vecPushBack(&testVec, 'B') ;
//    testVec = *vecPushBack(&testVec, 'C') ;
//    testVec = *vecPushBack(&testVec, 'D') ;
//    testVec = *vecPushBack(&testVec, 'E') ;
//    testVec = *vecPushBack(&testVec, 'F') ;
//
//    testVec = *vecErase(&testVec, 1, 4) ;
//
//
//    char *printP = vecBegin(&testVec) ;
//    for(; printP!=&testVec.arr[testVec.end]; printP++){
//        printf("%c\n", *printP) ;
//    }

    vector *testVec = vecCreate() ;
    testVec = vecPushBack(testVec, 'A') ;
    testVec = vecPushBack(testVec, 'B') ;
    testVec = vecPushBack(testVec, 'C') ;
    testVec = vecPushBack(testVec, 'D') ;
    testVec = vecPushBack(testVec, 'E') ;
    testVec = vecPushBack(testVec, 'F') ;

    vector *S = vecCreate() ;
    S = vecCopy(testVec) ;


    testVec = vecErase(testVec, 1, 4) ;


    char *printP = vecBegin(testVec) ;
    for(; printP!=&(testVec->arr[testVec->end]); printP++){
        printf("%c\n", *printP) ;
    }


    vecFree(testVec) ;

    printf("STOP!") ;
    return 0 ;
}