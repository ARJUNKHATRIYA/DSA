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
public:
    bool issym(TreeNode* a,TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a->val !=b->val) return false;
        return issym(a->left,b->right) && issym(a->right,b->left);
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==nullptr) return true;
        return issym(root->left,root->right);

    }
};