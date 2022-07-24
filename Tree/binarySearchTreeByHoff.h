//
// Created by kenny on 2022/7/24.
//

#ifndef DATASTRUCTURE_BINARYTREEBYHOFF_H
#define DATASTRUCTURE_BINARYTREEBYHOFF_H

#include <stdio.h>
#include <stdlib.h>

struct tNode{
    struct tNode *fNode ;
    int value ;
    struct tNode *lChild ;
    struct tNode *rChild ;
};

//put pointer of rChild of root
struct tNode *findRMin(struct tNode *root){
    struct tNode *min = malloc(sizeof(struct tNode)) ;

    while(root->lChild!=NULL){
        min = root->lChild ;
    }
}

struct tNode* dig(struct tNode *root, int value){
    if(root->value > value && root->lChild!=NULL)
        dig(root->lChild, value) ;
    else if(root->value < value && root->rChild!=NULL)
        dig(root->rChild, value) ;
    else if(root->value > value && root->lChild==NULL) {
        return root;
    }
    else if(root->value < value && root->rChild==NULL) {
        return root;
    }
}

void bstCreate(struct tNode **root, int value){
    //struct tNode **copyRoot = root ;

    if((*root) == NULL){
        struct tNode *newTNode = malloc(sizeof(struct tNode)) ;
        newTNode->fNode = NULL ;
        newTNode->value = value ;
        newTNode->lChild = NULL ;
        newTNode->rChild = NULL ;
        *root = newTNode ;
    }
    else if((*root)->lChild == NULL && (*root)->rChild == NULL){
        if((*root)->value > value){
            struct tNode *newLChild = malloc(sizeof(struct tNode)) ;
            newLChild->fNode = *root ;
            newLChild->value = value ;
            newLChild->lChild = NULL ;
            newLChild->rChild = NULL ;
            (*root)->lChild = newLChild ;
        }
        else{
            struct tNode *newRChild = malloc(sizeof(struct tNode)) ;
            newRChild->fNode = *root ;
            newRChild->value = value ;
            newRChild->lChild = NULL ;
            newRChild->rChild = NULL ;
            (*root)->rChild = newRChild ;
        }
    }
    else{
        struct tNode *loadNode = dig(*root, value) ;

        struct tNode *newChild = malloc(sizeof(struct tNode)) ;
        newChild->fNode = NULL ;
        newChild->value = value ;
        newChild->lChild = NULL ;
        newChild->rChild = NULL ;

        if(loadNode->value > value){
            loadNode->lChild = newChild ;
            newChild->fNode = loadNode ;
        }else if(loadNode->value < value){
            loadNode->rChild = newChild ;
            newChild->fNode = loadNode ;
        }
    }
}

// .lChild -> .fNode -> .rChild
void inorderTraversal(struct tNode **root){
    if((*root)->lChild!=NULL)
        inorderTraversal(&(*root)->lChild) ;
    printf("[%2d] ", (*root)->value) ;
    if((*root)->rChild!=NULL)
        inorderTraversal(&(*root)->rChild) ;
}

void preorderTraversal(struct tNode **root){
    printf("[%2d] ", (*root)->value) ;
    if((*root)->lChild!=NULL)
        preorderTraversal(&(*root)->lChild) ;
    if((*root)->rChild!=NULL)
        preorderTraversal(&(*root)->rChild) ;
}

void postorderTraversal(struct tNode **root){
    if((*root)->lChild!=NULL)
        postorderTraversal(&(*root)->lChild) ;
    if((*root)->rChild!=NULL)
        postorderTraversal(&(*root)->rChild) ;
    printf("[%2d] ", (*root)->value) ;
}

struct tNode* bfs(struct tNode *root, int target){

}

struct tNode* dfs(struct tNode *root, int target){

}


//void treeDelete(struct tNode **root, int target){
//}


#endif //DATASTRUCTURE_BINARYTREEBYHOFF_H
