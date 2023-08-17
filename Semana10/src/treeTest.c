#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treeTest.h"


int main(){
    Node** RootNode = NULL;

    *RootNode = RESET(100);

    PUSH((*RootNode), 10);
    PUSH((*RootNode), 10);
    PUSH((*RootNode), 1002);
    PUSH((*RootNode), 102);
    PUSH((*RootNode), 122);
    PUSH((*RootNode), 32);
    PUSH((*RootNode), 55);
    PUSH((*RootNode), 88);

}

/*
=========================================================
    RESET
    Start a tree and return the positon of the Root Node
=========================================================
*/
Node** RESET(int content)
{
    Node** treeRoot = (Node **) malloc(sizeof(Node*));
    (*treeRoot) = (Node *) malloc ( sizeof (Node) );
    (*treeRoot)->content   = content;
    (*treeRoot)->leftSon   = NULL;
    (*treeRoot)->rightSon  = NULL;

    return treeRoot;
}

/*
=========================================================
    PUSH
    Creates a New Node with the content
    and put it on the right spot
=========================================================
*/
void PUSH(Node* root, int content){
    Node* newNode = NULL;

    newNode = (Node*) malloc(sizeof(Node));

    newNode -> content  = content;
    newNode -> leftSon  = NULL;
    newNode -> rightSon = NULL;

    insertInPlace(root, newNode);

}

/*
=========================================================
    insertInPlace
    Find a Place to insert the New Node and Insert it
=========================================================
*/
void insertInPlace (Node* position, Node* newNode){
    if((newNode -> content) < (position ->content) ){
        if (position -> leftSon == NULL)
            position -> leftSon = newNode;
        else
            insertInPlace(position -> leftSon, newNode);
    }

    else{
        if (position -> rightSon == NULL)
            position -> rightSon = newNode;
        else
            insertInPlace(position -> rightSon, newNode);
    }
}


/*
=========================================================
    height
    Return the Height of a rootNode
=========================================================
*/
int height(Node* rootNode)
{
    int rHeight, lHeight;

    if (rootNode == NULL)
        return 0;
    
    rHeight = height(rootNode->rightSon);
    lHeight = height(rootNode->leftSon);

    if(rHeight > lHeight)
        return rHeight+1;
    else
        return lHeight+1;
}

/*
=========================================================
    balancingFactor
    returns the balancing Factor of a rootNode
    using the height of that node's sons
=========================================================
*/
int balancingFactor (Node* rootNode)
{
    if (rootNode == NULL)
        return 0;
    
    return height(rootNode->leftSon) - height(rootNode->rightSon);
}

/*
=========================================================
    RSR
    Do a right Simple Rotation
=========================================================
*/
void SRR (Node** pivot){
    Node* auxNode;

    auxNode = (*pivot)->rightSon;
    (*pivot)->rightSon = auxNode->leftSon;
    auxNode->leftSon = (*pivot);
    (*pivot) = auxNode;
}

void SLR (Node** pivot){
    Node* auxNode;

    auxNode = (*pivot)->leftSon;
    (*pivot)->leftSon = auxNode->rightSon;
    auxNode->rightSon = (*pivot);
    (*pivot) = auxNode;
}

int lBalancing (Node** pivot){
    int lBF = balancingFactor((*pivot)->leftSon);
    if(lBF > 0)
    {  /*Simple Right Rotation*/
        SRR(pivot);
        return 1;
    } else if ( lBF < 0)
    { /*Double Right Rotation*/
        SLR( &((*pivot)->leftSon) );
        SRR(pivot);
    }
}