/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root==nullptr)  return true;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int sum =0;
            Node* node =q.front();
            q.pop();
             if(node->left!=nullptr){
                 q.push(node->left);
             }
            
             if(node->right!=nullptr){
                 q.push(node->right);
             }
             
             if(node->left==nullptr && node->right==nullptr){
                 continue;
             }
             if(node->left!=nullptr){
                 sum+=node->left->data;
             }
             if(node->right!=nullptr){
                 sum+=node->right->data;
             }
             if(sum!=node->data){
                 return false;
             }
            
        }
        return true;
    }
};