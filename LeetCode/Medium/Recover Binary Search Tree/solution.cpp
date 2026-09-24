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
    void inordertraversal(TreeNode* root,vector<TreeNode*>&inorder){
        if(root==nullptr) return;
    
        inordertraversal(root->left,inorder);
        inorder.push_back(root);
        inordertraversal(root->right,inorder);
    }
    void recoverTree(TreeNode* root) {
        if(root==nullptr) return;
        vector<TreeNode*>inorder;
        inordertraversal(root,inorder);
        TreeNode* first=nullptr;
        TreeNode* second=nullptr;

        for(int i=1;i<inorder.size();i++){
            if(inorder[i-1]->val>inorder[i]->val){
                if(first==nullptr){
                    first =inorder[i-1];
                }
                second = inorder[i];
            }
        }
        swap(first->val,second->val);

        
    }
};