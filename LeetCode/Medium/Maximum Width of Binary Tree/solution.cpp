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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxwidth =0;
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        
        while(!q.empty()){
            int n = q.size();
             long long firstIndex = q.front().second;

            long long leftmost = 0;
            long long rightmost = 0;
            for(int i=0;i<n;i++){
                auto [node,idx] = q.front();
                q.pop();
                idx =idx-firstIndex;
                
                // First node of current level
                if (i == 0)
                    leftmost = idx;

                // Last node of current level
                if (i == n - 1)
                    rightmost = idx;
                 if(node->left!=nullptr){
                    q.push({node->left,2*idx+1});
                }
                if(node->right!=nullptr){
                    q.push({node->right,2*idx+2});
                }
                maxwidth = max(maxwidth,rightmost-leftmost+1);

               

            }
        }
        return maxwidth;
    }
};