/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    // string serialize(TreeNode* root) {
    //     if(root==nullptr){
    //         return "#,";
    //     }
    //     return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
        
    // }

    string serialize(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==nullptr){
            return "";
        }
        string res;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                res+="#,";
                continue;
            }
            res+=to_string(node->val);
            res+=",";
            q.push(node->left);
            q.push(node->right);

        }
        return res;
    }
//     TreeNode* deserialize(string data) {

//     int index = 0;

//     function<TreeNode*()> build = [&]() {

//         // Find next comma
//         int comma = data.find(',', index);

//         string value =
//             data.substr(index, comma - index);

//         index = comma + 1;

//         // NULL
//         if (value == "#")
//             return (TreeNode*)nullptr;

//         TreeNode* root =
//             new TreeNode(stoi(value));

//         root->left = build();
//         root->right = build();

//         return root;
//     };

//     return build();
// }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()){
            return nullptr;
        }
        vector<string>tokens;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            if(!token.empty()){
                tokens.push_back(token);
            }
        }
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (tokens[i] != "#") {

                node->left =
                    new TreeNode(stoi(tokens[i]));

                q.push(node->left);
            }

            i++;

            // Right child
            if (tokens[i] != "#") {

                node->right =
                    new TreeNode(stoi(tokens[i]));

                q.push(node->right);
            }

            i++;
        }

        return root;
    
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));