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
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        int count =0;
        stack<TreeNode*>st;
        st.push(root);
        TreeNode* curr=root;
        vector<int>ans;
        while(curr!=nullptr ||st.empty()==false){

            while(curr!=nullptr){
                st.push(curr);
                curr=curr->left;
            }
            curr =st.top();
            st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans[k-1];

    }
};