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
    void insert(TreeNode* root,TreeNode* node){
        int val = node->val;
        TreeNode* curr = root;
        while(curr!=nullptr){
            if(curr->val>val){
                if(curr->left==nullptr){
                   curr->left=node;
                   break;
                }else{
                    curr=curr->left;
                }
                
            }else{
                if(curr->right==nullptr){
                    curr->right=node;
                    break;
                }else{
                     curr=curr->right;
                }
               
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int n = preorder.size();
        for(int i=1;i<n;i++){
            TreeNode* node = new TreeNode(preorder[i]);
            insert(root,node);
        }
        return root;
    }
};