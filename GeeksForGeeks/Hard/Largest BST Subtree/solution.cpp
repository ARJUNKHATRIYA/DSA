// /* Structure of a Binary Search Tree node
// class Node {
// public:
//     int data;
//     Node *left, *right;
//     Node(int val) {
//         data = val;
//         left = right = nullptr;
//     }
// };*/

// class Solution {
//   public:
//     int countnodes(Node*  root){
//         if(root==nullptr) return 0;
//         return 1+countnodes(root->left)+countnodes(root->right);
//     }
//     bool validBST(Node* root,Node* minnode,Node* maxnode){
//         if(root==nullptr) return true;
//         if(minnode!=nullptr &&root->data<=minnode->data){
//             return false;
//         }
//         if(maxnode!=nullptr &&root->data>=maxnode->data){
//             return false;
//         }
//         return validBST(root->left,minnode,root) && validBST(root->right,root,maxnode);
        
//     }
   
//     int largestBst(Node *root) {
//         // code here
//         if(root==nullptr) return 0;
//         int maxi =0;
//         stack<Node*>st;
//         st.push(root);
//         while(!st.empty()){
//             Node* curr = st.top();
//             st.pop();
//             if(validBST(curr,nullptr,nullptr)){
//                 int cnt =countnodes(curr);
//                 maxi = max(maxi,cnt);
//             }
//             if(curr->left){
//                 st.push(curr->left);
//             }
//             if(curr->right){
//                 st.push(curr->right);
//             }
//         }
//         return maxi;
        
        
//     }
// };

/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    
   struct Info{
       int size;
       int minval;
       int maxval;
       int largestBST;
       bool isBST;
   };
   Info solve(Node* root){
       if(root==nullptr){
           return{
               0,
               INT_MAX,
               INT_MIN,
               0,
               true
           };
       }
       Info left =solve(root->left);
       Info right =solve(root->right);
       Info curr;
       curr.size =left.size +right.size+1;
       if(left.isBST && right.isBST && left.maxval<root->data && right.minval>root->data){
           curr.isBST =true;
           curr.largestBST =curr.size;
           curr.minval =min(root->data,left.minval);
           curr.maxval =max(root->data,right.maxval);
       }else{
           curr.isBST =false;
           curr.largestBST = max(left.largestBST,right.largestBST);
           curr.minval = INT_MAX;
           curr.maxval = INT_MIN;
       }
       return curr;
   }
    int largestBst(Node *root) {
        // code here
       return solve(root).largestBST;
        
        
        
    }
};