// Enthony Gabriel Rodrigues Bohm
// M1

typedef struct TreeNode TreeNode;
int findSmallest (TreeNode* node, int rootValue, int* secondSmallestValue);

int findSecondMinimumValue(struct TreeNode* root){
  int                 *secondSmallestValue = (int*) malloc (sizeof(int));
  *secondSmallestValue = -1;

  return findSmallest(root, root->val, secondSmallestValue);

}

int findSmallest (TreeNode* node, int rootValue, int* secondSmallestValue){

  if (!node)
    return *secondSmallestValue;

  
  if ( node->val != *secondSmallestValue && node->val != rootValue ){
    
    if (*secondSmallestValue == -1 || node->val < *secondSmallestValue)
      *secondSmallestValue = node->val;
  }
  
  
  findSmallest(node->left , rootValue, secondSmallestValue);
  findSmallest(node->right, rootValue, secondSmallestValue);

  return *secondSmallestValue;
}