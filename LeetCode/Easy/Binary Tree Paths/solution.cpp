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
    void rec(TreeNode* root,vector<string> &ans,string &temp){
        if(root==nullptr) return;
            temp+=to_string(root->val);
            if(root->left==nullptr && root->right==nullptr) {
                ans.push_back(temp);
                temp.resize(temp.size()-to_string(root->val).size());
                return;
            }
            
            
            temp+="->";
            rec(root->left,ans,temp);
            rec(root->right,ans,temp);
            temp.resize(temp.size() - 2 - to_string(root->val).size());

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string temp;
        rec(root,ans,temp);
        return ans;

    }
};