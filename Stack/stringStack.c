#include <STDIO.H>
#include <stdlib.h>
#include "stringStackByHoff.h"

int main(){
    vector *V = vecCreate() ;

    STACK *SS = stack_Create() ;

    SS = stack_Push_Char(SS, 'A') ;
    SS = stack_Push_Char(SS, 'B') ;
    SS = stack_Push_Char(SS, 'C') ;
    SS = stack_Push_Char(SS, 'D') ;
    SS = stack_Push_Char(SS, 'E') ;

    int size = stack_Size(SS) ;
    printf("%d", size) ;


    return 0 ;
}