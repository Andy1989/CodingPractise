/**
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL) {
            return 0;
        }
        if(root->left == NULL && root->right == NULL) {
            return 1;
        } else if(root->left == NULL) {
            return 1 + maxDepth(root->right);
        } else if(root->right == NULL ){
            return 1 + maxDepth(root->left);
        } else{
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
        }
    }
};
