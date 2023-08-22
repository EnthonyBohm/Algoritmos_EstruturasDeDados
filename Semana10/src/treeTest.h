#ifndef TREETEST_H
#define TREETEST_h

struct node{
    int content;
    struct node *leftSon, *rightSon;
};
typedef struct node Node;

Node** RESET(int content);
int    PUSH(Node** root, int content);
void    insertInPlace (Node* position, Node* newNode);
int     height(Node* rootNode);
int     balancingFactor (Node* rootNode);
void    rightRotation (Node** pivot);
void    leftRotation (Node** pivot);
int     balancing (Node** pivot);
int     rBalancing (Node** pivot);
int     lBalancing (Node** pivot);
#endif