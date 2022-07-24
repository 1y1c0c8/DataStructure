#ifndef DATASTRUCTURE_CHARDOUBLELINKEDLISTBYHOFF_H
#define DATASTRUCTURE_CHARDOUBLELINKEDLISTBYHOFF_H

#include <stdio.h>
#include <stdlib.h>

struct biDirCharNode{
    struct biDirCharNode *preNode ;
    char value ;
    struct biDirCharNode *nextNode ;
};

struct biDirCharNode* nodeCreate(char value){
    struct biDirCharNode *newNode ;
    newNode = malloc(sizeof(struct biDirCharNode)) ;
    newNode->preNode = NULL ;
    newNode->value = value ;
    newNode->nextNode = NULL ;
    return newNode ;
}

void nodeConnect(struct biDirCharNode *pre, struct biDirCharNode *new){
    pre->nextNode = new ;
    new->preNode = pre ;
}

struct biDirCharNode* nodeDelete(struct biDirCharNode *head, char target){
    struct biDirCharNode *duplicateHead = head->nextNode ;

    if(head->value == target){
        duplicateHead->preNode = NULL ;
        head->nextNode = NULL ;
        free(head) ;
        return duplicateHead ;
    }else{
        struct biDirCharNode *n = head ;

        int k=1 ;
        while(n->value != target){
            n = n->nextNode ;
            k++ ;
        }
        struct biDirCharNode *beforeT = n->preNode ;
        struct biDirCharNode *afterT = n->nextNode ;
        nodeConnect(beforeT, afterT) ;
        return head ;
    }
}

void printLinkedList(struct biDirCharNode *n, int amount){
    printf("[") ;
    for(int i=0; i<amount; i++){
        printf("%c, ", n->value) ;
        n = n->nextNode ;
    }
    printf("\b\b]") ;
}

void printLinkedListReverse(struct biDirCharNode *n, int amount){
    printf("[") ;
    for(int i=amount-1; i>=0; i--){
        printf("%d, ", n->value) ;
        n = n->preNode ;
    }
    printf("\b\b]") ;
}

void freeNode(struct biDirCharNode *head){
    free(head) ;
}

#endif //DATASTRUCTURE_CHARDOUBLELINKEDLISTBYHOFF_H
