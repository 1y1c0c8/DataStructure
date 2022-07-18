#ifndef DATASTRUCTURE_LINKEDLISTBYHOFF_H
#define DATASTRUCTURE_LINKEDLISTBYHOFF_H

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *preNode ;
    int value ;
    struct node *nextNode ;
};

struct node* nodeCreate(int value){
    struct node *newNode ;
    newNode = malloc(sizeof(struct node)) ;
    newNode->preNode = NULL ;
    newNode->value = value ;
    newNode->nextNode = NULL ;
    return newNode ;
}

void nodeConnect(struct node *pre, struct node *new){
    pre->nextNode = new ;
    new->preNode = pre ;
}

struct node* nodeDelete(struct node *head, int target){
    int choice=0 ;
    struct node *duplicateHead = head->nextNode ;

    if(head->value == target){
        duplicateHead->preNode = NULL ;
        head->nextNode = NULL ;
        free(head) ;
        return duplicateHead ;
    }else{
//        struct node *n = start ;
//
//        printf("Start traversal till the value of curNode is target:\n") ;
//        int k=1 ;
//        while(n->value != target){
//            printf("The no.%d cycle, the value of curNode is %d.\n", k, n->value) ;
//            n = n->nextNode ;
//            k++ ;
//        }
//        struct node *beforeT = n->preNode ;
//        struct node *afterT = n->nextNode ;
//        nodeConnect(beforeT, afterT) ;
//
//        choice = 2 ;
        printf("TEST POINT!") ;
    }
}

void freeNode(struct node *start){
    free(start) ;
}


#endif //DATASTRUCTURE_LINKEDLISTBYHOFF_H
