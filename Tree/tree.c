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

    printf("inorder:\n") ;
    inorderTraversal(p) ;
    printf("\n") ;

    printf("preorder:\n") ;
    preorderTraversal(p) ;
    printf("\n") ;

    printf("postorder:\n") ;
    postorderTraversal(p) ;
    
    return 0 ;
}
