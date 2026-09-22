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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

private:
    // void inorder(TreeNode* root, vector<int>& ans) {
    //     if (!root) return;
    //     inorder(root->left, ans);       // Traverse left subtree
    //     ans.push_back(root->val);       // Visit root
    //     inorder(root->right, ans);      // Traverse right subtree
    // }
    void inorder(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root;
        while(curr!=nullptr){
           
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                 TreeNode* prev = curr->left;
                while(prev->right!=nullptr && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right =curr;
                    curr=curr->left;
                }else{
                    prev->right =nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        
        
    }

};