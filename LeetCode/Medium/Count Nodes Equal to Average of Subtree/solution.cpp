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
    int countnodes(TreeNode* root){
        if(root==nullptr) return 0;
        return countnodes(root->left)+countnodes(root->right)+1;
    }
    int sumnodes(TreeNode* root){
        if(root==nullptr) return 0;
        return sumnodes(root->left)+sumnodes(root->right)+root->val;
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr) return 0;
        int ans =0;
        ans+=averageOfSubtree(root->left);
        ans+=averageOfSubtree(root->right);
        int sum = sumnodes(root);
        int cnt = countnodes(root);
        int avg = sum/cnt;

        if(root->val==avg) {
            ans++;
        } 
        return ans;

    }
};