#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTreeByHoff.h"

int main(){
    struct tNode *root = NULL ;
    struct tNode **p = &root ;

    int values[6] = {28, 23, 33, 41, 22, 25} ;

    for(int i=0; i<6; i++){
        bstCreate(p, values[i]) ;
    }

    return 0 ;
}
