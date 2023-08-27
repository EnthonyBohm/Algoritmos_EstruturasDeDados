// Enthony Gabriel Rodrigues Bohm
// M1
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
  int               val;
  struct TreeNode*  right;
  struct TreeNode*  left ;
};
typedef struct TreeNode TreeNode;

int                 findSmallest (TreeNode* node, int rootValue, int* secondSmallestValue);
int                 findSecondMinimumValue(struct TreeNode* root);
TreeNode*           newNode(int value);

int main(){
  TreeNode*         root;
  int               answer;

  root = (TreeNode*) malloc (sizeof(TreeNode));

  //Test Case 1     || Expected : 5
    // root->val = 2;
    // root->left = newNode (2);
    // root->right = newNode (5);
    // root->right->left = newNode (5);
    // root->right->right = newNode (7);

  //Test Case 2     || Expected : 2
    // root->val = 2;
    // root->left = newNode(2);
    // root->right = newNode(2);

  //Test Case 3     ||  Expected : 4
    root->val = 2;
    root->left = newNode(2);
    root->right = newNode(4);

  answer = findSecondMinimumValue(root);
  printf ( "Result: %d", answer ) ;
}


/*
===============================================================================
    findSecondMinimumValue
    receive a root from a tree and return the second Minimum value of it
===============================================================================
*/
int findSecondMinimumValue(struct TreeNode* root){
  int*                secondSmallestValue = (int*) malloc (sizeof(int));
  int                 answer;

  *secondSmallestValue = -1;
  *secondSmallestValue = findSmallest(root, root->val, secondSmallestValue);

  answer = *secondSmallestValue;
  
  free(secondSmallestValue);

  return answer;
}

/*
===============================================================================
    findSmallesta
    receive a tree node, the value of the tree and look for the second smallest
    vallue from the tree
===============================================================================
*/
int findSmallest ( TreeNode* node, int rootValue, int* secondSmallestValue ){

  if ( !node )
    return *secondSmallestValue;

  
  if ( node->val != *secondSmallestValue && node->val != rootValue ){
    
    if ( *secondSmallestValue == -1 || node->val < *secondSmallestValue )
      *secondSmallestValue = node->val;
  }
  
  
  findSmallest( node->left , rootValue, secondSmallestValue ) ;
  findSmallest( node->right, rootValue, secondSmallestValue ) ;

  return *secondSmallestValue;
}

TreeNode* newNode(int value){
  TreeNode* newNode = (TreeNode*) malloc(sizeof(TreeNode));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->val = value;

  return newNode;
}