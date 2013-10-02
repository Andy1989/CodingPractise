/**
 * Symmetric Tree
 * 
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * 
 * For example, this binary tree is symmetric:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
 * 
 * But the following is not:
 *     1
 *    / \
 *   2   2
 *   \   \
 *   3    3
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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return true;
        } else if(root->left == NULL && root->right == NULL) {
            return true;
        } else if(root->left == NULL) {
            return false;
        } else if(root->right == NULL) {
            return false;
        } else {
            return isEqual(root->left, root->right);
        }
    }
    
    bool isEqual(TreeNode *left, TreeNode *right) {
        if(left->val != right->val) {
            return false;
        } else if(left->left == NULL && right->right == NULL && left->right == NULL && right->left == NULL) {
            return true;
        } else if(left->left != NULL && right->right != NULL && left->right == NULL && right->left == NULL) {
            return isEqual(left->left, right->right);
        } else if(left->left == NULL && right->right == NULL && left->right != NULL && right->left != NULL) {
            return isEqual(left->right, right->left);
        } else if(left->left != NULL && right->right != NULL && left->right != NULL && right->left != NULL) {
            return isEqual(left->left, right->right) && isEqual(left->right, right->left);
        } else {
            return false;
        }
    }
};
