#ifndef DATASTRUCTURE_SINGLELINKEDLISTBYHOFF_H
#define DATASTRUCTURE_SINGLELINKEDLISTBYHOFF_H

#include <stdio.h>
#include <stdlib.h>

struct node{
    int value ;
    struct node *nextNode ;
};

struct node* singleNodeCreate(int value){
    struct node *newNode = malloc(sizeof(struct node)) ;
    newNode->value = value ;
    newNode->nextNode = NULL ;
    return newNode ;
}

void singleNodeConnect(struct node *pre, struct node *new){
    pre->nextNode = new ;
}

struct node* singleNodeDelete(struct node *head, int target){
    struct node *returnHead = head ;
    struct node *tail = head ;

    if(head->value==target) {
        returnHead = head->nextNode ;
        free(head) ;
        return returnHead ;
    }
    else{
        struct node *traversal = tail->nextNode ;

        while(traversal->value!=target){
            traversal = traversal->nextNode ;
            tail = tail->nextNode ;
        }

        tail->nextNode = traversal->nextNode ;
        free(traversal) ;
        return returnHead ;
    }
}

void printSingleLinkedList(struct node *n, int amount){
    printf("[") ;
    for(int i=0; i<amount; i++){
        printf("%d, ", n->value) ;
        n = n->nextNode ;
    }
    printf("\b\b]") ;
}

void printSingleLinkedListSpecial(struct node *n, int amount){
    for(int i=0; i<amount; i++){
        printf("%d ", n->value) ;
        n = n->nextNode ;
    }
    printf("\b") ;
}


#endif //DATASTRUCTURE_SINGLELINKEDLISTBYHOFF_H
