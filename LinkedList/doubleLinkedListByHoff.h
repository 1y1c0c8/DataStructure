#ifndef DATASTRUCTURE_DOUBLELINKEDLISTBYHOFF_H
#define DATASTRUCTURE_DOUBLELINKEDLISTBYHOFF_H

#include <stdio.h>
#include <stdlib.h>

struct biDirNode{
    struct biDirNode *preNode ;
    int value ;
    struct biDirNode *nextNode ;
};

struct biDirNode* doubleNodeCreate(int value){
    struct biDirNode *newNode ;
    newNode = malloc(sizeof(struct biDirNode)) ;
    newNode->preNode = NULL ;
    newNode->value = value ;
    newNode->nextNode = NULL ;
    return newNode ;
}

void doubleNodeConnect(struct biDirNode *pre, struct biDirNode *new){
    pre->nextNode = new ;
    new->preNode = pre ;
}

struct biDirNode* doubleNodeDelete(struct biDirNode *head, int target){
    struct biDirNode *duplicateHead = head->nextNode ;

    if(head->value == target){
        duplicateHead->preNode = NULL ;
        head->nextNode = NULL ;
        free(head) ;
        return duplicateHead ;
    }else{
        struct biDirNode *n = head ;

        int k=1 ;
        while(n->value != target){
            n = n->nextNode ;
            k++ ;
        }
        struct biDirNode *beforeT = n->preNode ;
        struct biDirNode *afterT = n->nextNode ;
        doubleNodeConnect(beforeT, afterT) ;
        return head ;
    }
}

void printDoubleLinkedList(struct biDirNode *n, int amount){
    printf("[") ;
    for(int i=0; i<amount; i++){
        printf("%d, ", n->value) ;
        n = n->nextNode ;
    }
    printf("\b\b]") ;
}

void printDoubleLinkedListReverse(struct biDirNode *n, int amount){
    printf("[") ;
    for(int i=amount-1; i>=0; i--){
        printf("%d, ", n->value) ;
        n = n->preNode ;
    }
    printf("\b\b]") ;
}

void printDoubleLinkedListReverseSpecial(struct biDirNode *n, int amount){
    for(int i=amount-1; i>=0; i--){
        printf("%d ", n->value) ;
        n = n->preNode ;
    }
}

void freeDoubleNode(struct biDirNode *head){
    free(head) ;
}

#endif //DATASTRUCTURE_DOUBLELINKEDLISTBYHOFF_H
