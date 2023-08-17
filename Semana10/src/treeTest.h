#ifndef TREETEST_H
#define TREETEST_h

struct node{
    int content;
    struct node *leftSon, *rightSon;
};
typedef struct node Node;

Node** RESET(int content);
void    PUSH(Node* root, int content);
void    insertInPlace (Node* position, Node* newNode);
int     height(Node* rootNode);
int     balancingFactor (Node* rootNode);
void    SRR (Node** pivot);
void    RLR (Node** pivot);
#endif