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

struct node* nodeDelete(struct node *start, int target){
    int choice=0 ;
    struct node *newStart = start->nextNode ;

    if(start->value == target){
        newStart->preNode = NULL ;
        free(start) ;
        choice = 1 ;
    }else{
        struct node *n = start ;

        while(n->value != target){
            //printf("%d\n", n->value) ;
            n = n->nextNode ;
        }
        struct node *beforeT = n->preNode ;
        struct node *afterT = n->nextNode ;
        nodeConnect(beforeT, afterT) ;

        choice = 2 ;
    }
    if(choice == 1) return newStart ;
    else return start;
}

void freeNode(struct node *start){
    free(start) ;
}


#endif //DATASTRUCTURE_LINKEDLISTBYHOFF_H
