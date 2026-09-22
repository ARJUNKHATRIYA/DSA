/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// class Solution {
// public:

//     int countNodes(TreeNode* root) {

//         if (root == nullptr)
//             return 0;

//         queue<pair<TreeNode*, long long>> q;

//         q.push({root, 0});

//         long long maxIndex = 0;

//         while (!q.empty()) {

//             auto [node, idx] = q.front();
//             q.pop();

//             maxIndex = max(maxIndex, idx);

//             if (node->left) {
//                 q.push({
//                     node->left,
//                     2 * idx + 1
//                 });
//             }

//             if (node->right) {
//                 q.push({
//                     node->right,
//                     2 * idx + 2
//                 });
//             }
//         }

//         return maxIndex + 1;
//     }
// };


class Solution {
public:

    int leftheight(TreeNode* root){
        
        int count=0;
        while(root!=nullptr){
            count++;
            root=root->left;
        }
        return count;
    }

    int rightheight(TreeNode* root){
        
        int count=0;
        while(root!=nullptr){
            count++;
            root=root->right;
        }
        return count;
    }

    int countNodes(TreeNode* root) {

        if (root == nullptr)
            return 0;
        
        int lh = leftheight(root);
        int rh = rightheight(root);

        if(lh==rh){
            return (1<<lh)-1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);

       
    }
};