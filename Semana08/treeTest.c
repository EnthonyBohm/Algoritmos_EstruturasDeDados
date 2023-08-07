#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int content;
    struct node* leftSon;
    struct node* rightSon;
};
typedef struct node Node;

typedef struct{
    struct node* root;
    int lenght;
} RootNode;

RootNode* RESET(int content);
void PUSH(Node* root, int content);
void insertInPlace (Node* position, Node* newNode);
//void printTree(Node* root);
int main(){
    RootNode* treeRoot = NULL;

    treeRoot = RESET(100);

    PUSH(treeRoot -> root, 2);
    PUSH(treeRoot -> root, 10);
    PUSH(treeRoot -> root, 1002);
    PUSH(treeRoot -> root, 102);
    PUSH(treeRoot -> root, 122);
    PUSH(treeRoot -> root, 32);
    PUSH(treeRoot -> root, 55);
    PUSH(treeRoot -> root, 88);

}

/*Start a tree and return the positon of the Root Node*/
RootNode* RESET(int content){
    RootNode* treeRoot = NULL;
    Node* fatherNode;

    fatherNode = (Node *) malloc(sizeof(fatherNode));
    fatherNode -> content  = content;
    fatherNode -> leftSon  = NULL;
    fatherNode -> rightSon = NULL;

    treeRoot = (RootNode*) malloc(sizeof(RootNode));
    treeRoot -> lenght  = 0;
    treeRoot -> root    = fatherNode;

    return treeRoot;
}

/*Creates a New Node with the content and put it on the right spot*/
void PUSH(Node* root, int content){
    Node* newNode = NULL;

    newNode = (Node*) malloc(sizeof(Node));

    newNode -> content  = content;
    newNode -> leftSon  = NULL;
    newNode -> rightSon = NULL;

    insertInPlace(root, newNode);

}

/*Find a Place to insert the New Node and Insert it*/
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

/*Print the Binary tree
void printTree(Node* root){
    
}


                 A
            B          C
          D   E      F   G
        H  I   L    M      N
        
        A
            B
                D
                    H
                    I
                E
                    L
            C
                F
                    M
                G
                    N
*/