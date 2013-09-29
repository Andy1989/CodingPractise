/**
 * Balanced Binary Tree
 * 
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree 
 * in which the depth of the two subtrees of every node never differ by more than 1.
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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left, right;
        if(root == NULL) {
            return true;
        } else if(root->left == NULL && root->right == NULL) {
            return true;
        } else if(root->left == NULL) {
            return (depth(root->right) == 1);
        } else if(root->right == NULL) {
            return (depth(root->left) == 1);
        } else {
            left = depth(root->left);
            right = depth(root->right);
            if(left == -1 || right == -1 || abs(left - right) > 1) {
                return false;
            } else 
                return true;
        }
    }
    
    int depth(TreeNode *root){
        int left,right;
        if(root == NULL) {
            return 0;
        } else if(root->left == NULL && root->right == NULL) {
            return 1;
        } else if(root->left == NULL) {
            right = depth(root->right);
            if(right == -1 || right > 1) {
                return -1;
            } else
                return 1 + right;
        } else if(root->right == NULL) {
            left = depth(root->left);
            if(left == -1 || left > 1)
                return -1;
            else
                return 1 + left;
        } else {
            left = depth(root->left);
            right = depth(root->right);
            if(left == -1 || right == -1 || abs(left - right) > 1) {
                return -1;
            } else 
                return left >= right ? (1 + left) : (1 + right);
        }
    }
};
