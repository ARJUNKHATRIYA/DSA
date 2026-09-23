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
    bool valid(TreeNode* root,TreeNode* minnode,TreeNode* maxnode){
        if(root==nullptr) return true;
        

        if( minnode!=nullptr && root->val<=minnode->val){
            return false;
        }
        if( maxnode!=nullptr && root->val>=maxnode->val){
            return false;
        }
        return valid(root->left,minnode,root) && valid(root->right,root,maxnode);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,nullptr,nullptr);
    }
};