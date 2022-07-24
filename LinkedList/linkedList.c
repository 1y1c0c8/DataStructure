#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedListByHoff.h"

int main(){
    struct node *n1p = singleNodeCreate(0) ;
    struct node *n2p = singleNodeCreate(1) ;
    struct node *n3p = singleNodeCreate(2) ;

    singleNodeConnect(n3p, n1p) ;
    singleNodeConnect(n1p, n2p) ;

    printf("STOP!") ;

    return 0 ;
}