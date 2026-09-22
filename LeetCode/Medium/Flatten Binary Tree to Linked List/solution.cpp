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
    void flatten(TreeNode* root) {

        if (root == nullptr)
            return;

        vector<TreeNode*> ans;

        stack<TreeNode*> st;

        st.push(root);

        // ========================================================
        // PREORDER TRAVERSAL
        // Root -> Left -> Right
        // ========================================================

        while (!st.empty()) {

            TreeNode* curr = st.top();
            st.pop();

            ans.push_back(curr);

            // Push right first
            // so left is processed first
            if (curr->right != nullptr)
                st.push(curr->right);

            if (curr->left != nullptr)
                st.push(curr->left);
        }

        // ========================================================
        // CONNECT NODES
        // ========================================================

        int n = ans.size();

        for (int i = 0; i < n - 1; i++) {

            // No left child
            ans[i]->left = nullptr;

            // Next node in preorder
            ans[i]->right = ans[i + 1];
        }

        // Last node
        ans[n - 1]->left = nullptr;
        ans[n - 1]->right = nullptr;
    }
};