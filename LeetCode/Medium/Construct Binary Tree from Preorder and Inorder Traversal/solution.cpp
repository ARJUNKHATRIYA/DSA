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
    unordered_map<int,int>mp;
    int preidx=0;
    TreeNode* build(vector<int>& preorder,int si,int li){
        if(si>li){
            return nullptr;
        }
        int rootval = preorder[preidx++];
        TreeNode* root =new TreeNode(rootval);

        int pos = mp[rootval];

        root->left = build(preorder,si,pos-1);
        root->right = build(preorder,pos+1,li);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int n  = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,0,n-1);

    }
};