/**
 * Same Tree 
 * 
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 * 
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(p == NULL && q == NULL) {
            return true;
        } else if((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
            return false;
        }
        if(p->left == NULL && p->right == NULL && q->left == NULL && q->right == NULL && p->val == q->val) {
            return true;
        } else if(p->left == NULL && p->right != NULL && q->left == NULL && q->right != NULL && p->val == q->val) {
            return isSameTree(p->right, q->right);
        } else if(p->left != NULL && p->right == NULL && q->left != NULL && q->right == NULL && p->val == q->val) {
            return isSameTree(p->left, q->left);
        } else if(p->left != NULL && p->right != NULL && q->left != NULL && q->right != NULL && p->val == q->val) {
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        } else {
            return false;
        }
        
    }
};
