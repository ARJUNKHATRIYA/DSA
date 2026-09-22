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
    unordered_map<int ,int>mp;
    
    TreeNode* build(vector<int>& postorder,int si,int li,int& rootidx){
        if(si>li){
            return nullptr;
        }
        int rootval = postorder[rootidx--];
        int pos = mp[rootval];
        TreeNode* root = new TreeNode(rootval);
        root->right = build(postorder,pos+1,li,rootidx);
        root->left = build(postorder,si,pos-1,rootidx);
        
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n =inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]] =i;
        }
        int rootidx = n - 1;
        return build(postorder,0,n-1,rootidx);
        
    }
};