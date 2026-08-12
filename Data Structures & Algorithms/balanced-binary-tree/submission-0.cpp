/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {

static constexpr int sentinel = -1;

int height(TreeNode* root){
    if (root == nullptr){
        return 0;
    }
    int left_height = height(root->left);
    int right_height = height(root->right);
    if (left_height == sentinel || right_height == sentinel) {
        return sentinel;
    }
    if (abs(left_height - right_height) > 1){
        return sentinel;
    }
    return 1 + max(left_height, right_height);  
}


public:
    bool isBalanced(TreeNode* root) {
        int tree_height = height(root);
        return (tree_height != sentinel);
    }
};
