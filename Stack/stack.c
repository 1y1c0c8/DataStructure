#include <stdio.h>
#include <stdlib.h>
#include "stackByHoff.h"

int main(){
//    stack testS = *stackCreate() ;
//
//    testS = *stackPush(&testS, 'A') ;
//    testS = *stackPush(&testS, 'B') ;
//    testS = *stackPush(&testS, 'C') ;
//    testS = *stackPush(&testS, 'D') ;
//    testS = *stackPush(&testS, 'E') ;
//    testS = *stackPush(&testS, 'F') ;
//
//    printf("Top: %c\n", stackTop(&testS)) ;
//    printf("ElementsNum:%d\n", stackSize(&testS)) ;
//
//    stackPop(&testS) ;
//
//    printf("%c\n", stackTop(&testS)) ;
//    printf("ElementsNum:%d\n", stackSize(&testS)) ;
//
//
//    stackFree(&testS) ;
//    printf("STOP!") ;

    stack* testS = stackCreate() ;

    testS = stackPush(testS, 'A') ;
    testS = stackPush(testS, 'B') ;
    testS = stackPush(testS, 'C') ;
    testS = stackPush(testS, 'D') ;
    testS = stackPush(testS, 'E') ;
    testS = stackPush(testS, 'F') ;

    printf("Top: %c\n", stackTop(testS)) ;
    printf("ElementsNum:%d\n", stackSize(testS)) ;

    stackPop(testS) ;

    printf("%c\n", stackTop(testS)) ;
    printf("ElementsNum:%d\n", stackSize(&testS)) ;

    stackFree(testS) ;
    printf("STOP!") ;

    return 0 ;
}
