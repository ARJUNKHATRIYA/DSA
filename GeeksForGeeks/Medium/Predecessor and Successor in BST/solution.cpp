class Solution {
public:

    vector<Node*> findPreSuc(Node* root, int key) {

        Node* pred = nullptr;
        Node* succ = nullptr;

        Node* curr = root;

        while (curr != nullptr) {

            // =====================================
            // KEY FOUND
            // =====================================

            if (curr->data == key) {

                // ---------------------------------
                // Predecessor
                // Maximum in left subtree
                // ---------------------------------

                if (curr->left != nullptr) {

                    Node* temp = curr->left;

                    while (temp->right != nullptr) {
                        temp = temp->right;
                    }

                    pred = temp;
                }


                // ---------------------------------
                // Successor
                // Minimum in right subtree
                // ---------------------------------

                if (curr->right != nullptr) {

                    Node* temp = curr->right;

                    while (temp->left != nullptr) {
                        temp = temp->left;
                    }

                    succ = temp;
                }

                break;
            }


            // =====================================
            // KEY < CURRENT
            // =====================================

            else if (key < curr->data) {

                // Current node can be successor
                succ = curr;

                curr = curr->left;
            }


            // =====================================
            // KEY > CURRENT
            // =====================================

            else {

                // Current node can be predecessor
                pred = curr;

                curr = curr->right;
            }
        }

        return {pred, succ};
    }
};