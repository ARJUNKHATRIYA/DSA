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
    void dfs(TreeNode* root,int row,int col,map<int,vector<pair<int,int>>>&mp){
        if(root==nullptr) return;
        mp[col].push_back({row,root->val});
        
        dfs(root->left,row+1,col-1,mp);

        dfs(root->right,row+1,col+1,mp);
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp; 
        vector<vector<int>>ans;
        if(root==nullptr){
            return ans;
        }
        dfs(root,0,0,mp);

        for(auto &[col,nodes]:mp){
            sort(nodes.begin(),nodes.end());
            vector<int>column;

            for(auto &[row,value]:nodes){
                column.push_back(value);

            }
            ans.push_back(column);
        }
        return ans;
       
    }
};