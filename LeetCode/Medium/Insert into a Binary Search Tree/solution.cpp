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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr =root;
        TreeNode* n=new TreeNode(val);
        if (root == nullptr) {
            return n;
        }
        while(curr!=nullptr){
            if(curr->val>val){
                if(curr->left==nullptr){
                   curr->left=n;
                   break;
                }else{
                    curr=curr->left;
                }
                
            }else{
                if(curr->right==nullptr){
                    curr->right=n;
                    break;
                }else{
                     curr=curr->right;
                }
               
            }
        }
        return root;
    }
};