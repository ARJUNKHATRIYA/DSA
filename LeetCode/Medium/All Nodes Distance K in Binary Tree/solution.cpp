/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void par(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(root==nullptr) return ans;
        unordered_map<TreeNode*,TreeNode*>parent;
        par(root,target,parent);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(target);
        vis[target] =true;
        int dist=0;
        while(!q.empty()){
            int s = q.size();
            if(dist++ ==k){
                break;
            }
            
            for(int i=0;i<s;i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
           
        }
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
        

    }
};