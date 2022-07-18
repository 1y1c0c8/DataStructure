#include <stdio.h>
#include <stdlib.h>
#include "linkedListByHoff.h"

int main(){
    struct node *n1p = nodeCreate(0) ;
    struct node *n2p = nodeCreate(1) ;
    struct node *n3p = nodeCreate(2) ;

    nodeConnect(n3p, n1p) ;
    nodeConnect(n1p, n2p) ;

    printf("STOP!") ;

    return 0 ;
}