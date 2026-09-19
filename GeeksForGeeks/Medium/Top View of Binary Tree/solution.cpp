/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    
    
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        if(root==nullptr) return ans;
        
        queue<pair<Node*,int>>q;
        
        map<int,int>mp;
         q.push({root,0});
         while(!q.empty()){
             auto &[node,hd] = q.front();
             q.pop();
             
             if(mp.find(hd)==mp.end()){
                 mp[hd]=node->data;
             }
             
             if(node->left!=nullptr){
                 q.push({node->left,hd-1});
             }
             if(node->right!=nullptr){
                 q.push({node->right,hd+1});
             }
             
         }
         for( auto &[hd,val]:mp){
             ans.push_back(val);
         }
         return ans;
        
    }
};