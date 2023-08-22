#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "treeTest.h"


int main(){
    Node** RootNode = NULL;

    RootNode = RESET(10);

    PUSH(RootNode, 100);
    PUSH(RootNode, 1002);
    PUSH(RootNode, 102);
    PUSH(RootNode, 122);
    PUSH(RootNode, 32);
    PUSH(RootNode, 55);
    PUSH(RootNode, 88);

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
int PUSH(Node** root, int content){
    if(*root == NULL)
    {
        *root = (Node*) malloc (sizeof(Node));
        (*root)->content    = content;
        (*root)->leftSon    = NULL;
        (*root)->rightSon   = NULL;
        return 1;
    } else if (content < (*root)->content){
        if ( PUSH( &(*root)->leftSon, content))
        {
            if(balancing(root))
                return 0;
            else
                return 1;
        }
    } else if (content > (*root)->content) {
        if ( PUSH ( &(*root)->rightSon, content)){
            if (balancing (root))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
    return 0;
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
    rightRotation
    Do a simple Right Rotation
=========================================================
*/
void rightRotation (Node** pivot){
    Node* auxNode;

    auxNode = (*pivot)->leftSon;
    if (auxNode->rightSon == NULL)
        (*pivot)->leftSon = NULL;
    else
        (*pivot)->leftSon = auxNode->rightSon;
    auxNode->rightSon = (*pivot);
    (*pivot) = auxNode;
}

/*
=========================================================
    leftRotation
    Do a simple left Rotation
=========================================================
*/
void leftRotation (Node** pivot){
    Node* auxNode;

    auxNode = (*pivot)->rightSon;
    if ( auxNode->leftSon != NULL)
        (*pivot)->rightSon = auxNode->leftSon;
    else
        (*pivot)->rightSon = NULL;
    auxNode->leftSon = (*pivot);
    (*pivot) = auxNode;
}

/*
=========================================================
    lBalancing
    Balance a Disbalanced Tree, by either
    doing a simple rotation or a double rotation
=========================================================
*/
int lBalancing (Node** pivot)
{
    int lBF = balancingFactor((*pivot)->leftSon);
    if(lBF > 0)
    {  /*Simple Right Rotation*/
        rightRotation(pivot);
        return 1;
    } else if ( lBF < 0)
    { /*Double Right Rotation*/
        leftRotation( &((*pivot)->leftSon) );
        rightRotation(pivot);
        return 1;
    }
    return 0;
}
/*
=========================================================
    rBalancing
    Balance a Disbalanced Tree, by either
    doing a simple rotation or a double rotation
=========================================================
*/
int rBalancing (Node** pivot)
{
    int rBF = balancingFactor((*pivot)->rightSon);
    if(rBF > 0){ /*Simple left Rotation*/
        leftRotation(pivot);
        return 1;
    }
    else if(rBF < 0){ /*Double Rotation */
        rightRotation( &((*pivot)->rightSon) );
        leftRotation(pivot);
        return 1;
    }
    return 0;
}

/*
=========================================================
    balancing
    Check if a Tree is balanced, if it is, return's 0
    if it isn't aply'es the correction and return 1
=========================================================*/
int balancing (Node** pivot)
{
    int BF = balancingFactor(*pivot);

    if(BF > 1)
    {
        return lBalancing(pivot);
    } else if (BF < -1){
        return rBalancing(pivot);
    }
    
    return 0;
}