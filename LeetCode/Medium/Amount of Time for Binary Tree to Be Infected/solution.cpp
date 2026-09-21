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

    TreeNode* findStartBFS(
        TreeNode* root,
        int start
    ) {

        if (root == nullptr)
            return nullptr;

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {

            TreeNode* curr = q.front();
            q.pop();

            if (curr->val == start)
                return curr;

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        return nullptr;
    }
    void par_track(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent;
        par_track(root,parent);
        unordered_map<TreeNode*,bool>vis;
        queue<TreeNode*>q;
        TreeNode* startNode = findStartBFS(root,start);
        q.push(startNode);
        vis[startNode] =true;
        int level=0;
        while(!q.empty()){
            int s = q.size();
            bool infected =false;
            for(int i=0;i<s;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    vis[curr->left]=true;
                    q.push(curr->left);
                    infected=true;
                }
                if(curr->right && !vis[curr->right]){
                    vis[curr->right]=true;
                    q.push(curr->right);
                    infected=true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    vis[parent[curr]]=true;
                    q.push(parent[curr]);
                    infected=true;
                }
            }
            if(infected)
            level++;

        }
        return level;
        
    }
};