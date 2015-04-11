//============================================================================
// Binary Tree Zigzag Level Order Traversal
// Given a binary tree, return the zigzag level order traversal of its nodes'
// values. (ie, from left to right, then right to left for the next level and
// alternate between).
//
//For example:
// Given binary tree {3,9,20,#,#,15,7},
//    3
//   / \
//  9  20
//    /  \
//   15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]
//============================================================================

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct BinaryTree {
  BinaryTree *left, *right;
  int data;
  BinaryTree(int val) : left(NULL), right(NULL), data(val) { }
};


class Solution {
public:
    //vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    void zigzagLevelOrder(BinaryTree *root) {
       if(!root) return;
       stack<BinaryTree *> currentLevel, nextLevel; 
       currentLevel.push(root);
       int lev = 1; 
       while(!currentLevel.empty()){
           BinaryTree *node = currentLevel.top();
           currentLevel.pop();
           if( lev % 2 == 1) { 
              if(node->left)  nextLevel.push(node->left);
              if(node->right) nextLevel.push(node->right);
           } 
           else{
              if(node->right) nextLevel.push(node->right);
              if(node->left)  nextLevel.push(node->left);
           }
           cout << node->data << ' ';
           if(currentLevel.empty()){
              cout << endl;
              lev++;  
              swap(currentLevel, nextLevel);                
           }
       }
      
    }
};

int main() {

  BinaryTree *root = new BinaryTree(30);
  root->left = new BinaryTree(20);
  root->right = new BinaryTree(40);
  root->left->left = new BinaryTree(10);
  root->left->right = new BinaryTree(25);
  root->right->left = new BinaryTree(35);
  root->right->right = new BinaryTree(50);
  root->left->left->left = new BinaryTree(5);
  root->left->left->right = new BinaryTree(15);
  root->left->right->right = new BinaryTree(28);
  //root->right->right->left = new BinaryTree(41);
  root->right->left->right = new BinaryTree(41);

  Solution sol;

  sol.zigzagLevelOrder(root);
  return 0;
}
