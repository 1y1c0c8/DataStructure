//
// Created by kenny on 2022/7/11.
// reference: https://mropengate.blogspot.com/2015/07/cc-vector-stl.html

#ifndef DATASTRUCTURE_VECTORBYHOFF_H
#define DATASTRUCTURE_VECTORBYHOFF_H
#include <stdio.h>
#include <stdlib.h>
#define initCap 4


typedef struct{
    int capacity ;
    int end ;
    char *arr ;
}vector;

vector* vecCreate(){
    vector* newVec = malloc(sizeof(vector)) ;
    char* arr = malloc(sizeof(char)*initCap) ;

    newVec->arr = arr ;
    newVec->capacity = initCap ;
    newVec->end = 0 ;
    for(int i=0; i<initCap; i++){
        newVec->arr[i] = ' ' ;
    }

    return newVec ;
}

int vecEmpty(vector V){
    return V.end-1 == 0 ;
}

int vecFull(vector V){
    return V.end == V.capacity ;
}

char vecAt(vector V, int index){
    return V.arr[index] ;
}

char vecFront(vector V){
    return V.arr[0] ;
}

char vecBack(vector V){
    return V.arr[V.end-1] ;
}

vector* vecDouble(vector* V) ;

vector* vecPushBack(vector* V, char E){
    if(vecFull(*V)){
        V = vecDouble(V) ;
    }
    V->arr[V->end] = E ;
    (V->end) ++ ;

    return V ;
}

void vecPop(vector *V){
    V->arr[V->end-1] = ' ' ;
    (V->end)-- ;
}

vector* vecInsert(vector *V, int insertIndex, char E){
    if(V->end == V->capacity)
        V = vecDouble(V) ;

    int shiftNum = (V->end)-insertIndex ;
    char tempChar[shiftNum] ;

    for(int i=0, j=insertIndex; i<shiftNum; i++, j++){
        tempChar[i] = V->arr[j] ;
        V->arr[j] = ' ', V->end -- ;
    }

    V->arr[insertIndex] = E, V->end ++ ;

    for(int i=insertIndex+1, j=0; j<shiftNum; i++, j++){
        V->arr[i] = tempChar[j], V->end ++ ;
    }
    return V ;
}

//beforeShift: insertIndex~(end-1)    end = 6
// 0 1 2 3 4 5 6 7 8 9
// A B C D E F _ _ _ _
// vecInsert(3, 'X') ;

//afterShift: (insertIndex+1)~end     end = 7
// 0 1 2 3 4 5 6 7 8 9
// A B C X D E F _ _ _

vector* vecErase(vector *V, int beginIndex, int endIndex){
    if(endIndex == V->end){
        for(int i=beginIndex; i<endIndex; i++){
            V->arr[i] = ' ' ;
        }
    }else{
        int clearNum = endIndex - beginIndex ;
        char tempChar[clearNum] ;

        for(int i=0; i<clearNum; i++){
            tempChar[i] = V->arr[i+endIndex] ;
        }

        int endValue = V->end ;
        for(int i=beginIndex; i<endValue; i++){
            vecPop(V) ;
        }

        for(int i=0; i<clearNum; i++){
//            V->arr[i+beginIndex] = tempChar[i] ;
            vecPushBack(V, tempChar[i]) ;
        }
    }
    return V ;
}

//移除[3]~[5]共三個元素
// 0 1 2 3 4 5 6 7 8 9
// A B C D E F _ _ _ _
//vecErase(&testVec, 1, 4) ;
//beginIndex = 3, endIndex = 6, testVec.end = 6

// 0 1 2 3 4 5 6 7 8 9
// A E F _ _ _ _ _ _ _


void vecClear(vector *V){
    for(int i=0; i<V->end; i++)
        V->arr[i] = ' ' ;
}

//現有元素個數
int vecSize(vector *V){
    return V->end ;
}

//int vecResize(){
//
//}

int vecCapacity(vector *V){
    return V->capacity ;
}

vector* vecDouble(vector* V){
    vector* doubleVec = malloc(sizeof(vector)) ;
    char *arr = malloc(2*sizeof(char)*V->capacity) ;

    doubleVec->arr = arr ;
    doubleVec->end = V->end ;
    doubleVec->capacity = 2*V->capacity ;

    for(int i=0; i<2*V->capacity; i++){
        if(i<V->capacity)
            doubleVec->arr[i] = V->arr[i] ;
        else
            doubleVec->arr[i] = ' ' ;
    }

    return doubleVec ;
}

//void vecDouble(vector* V){
//    vector* doubleVec = malloc(sizeof(vector)) ;
//    char* arr = malloc(2*sizeof(char)*V->capacity) ;
//
//    doubleVec->arr = arr ;
//    doubleVec->end = V->end ;
//    doubleVec->capacity = 2* V->capacity ;
//
//    for(int i=0; i<2*V->capacity; i++){
//        if(i<V->capacity)
//            doubleVec->arr[i] = V->arr[i] ;
//        else
//            doubleVec->arr[i] = ' ' ;
//    }
//    V = doubleVec;
//    int temp = V->capacity;
//    printf("%d",temp);
//}

char* vecBegin(vector *V){
    return V->arr ;
}

char* vecEnd(vector *V){
    return (V->arr + (V->end-1)) ;
}

void vecFree(vector *V){
    free(V->arr) ;
    free(V) ;
}


#endif //DATASTRUCTURE_VECTORBYHOFF_H
