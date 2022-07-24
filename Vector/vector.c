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


    int test = vecIndex(testVec, &testVec->arr[3]) ;
    printf("test:%d\n", test) ;

    vector *temp1 = vecCreate() ;
    temp1 = vecPushBack(temp1, 'A') ;
    temp1 = vecPushBack(temp1, 'a') ;

    vector *temp2 = vecCreate() ;
    temp2 = vecPushBack(temp2, 'B') ;
    temp2 = vecPushBack(temp2, 'C') ;
    temp2 = vecPushBack(temp2, 'D') ;

    temp1 = vecPushVec(temp1, temp2) ;

    vecPrint(temp1) ;

    vecFree(testVec) ;

    printf("STOP!") ;
    return 0 ;
}