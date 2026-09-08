class Solution {
public:
    Node* connect(Node* root) {
        if (!root || !root->left) return root; // base case: leaf or null

        // Connect the two children of this node
        root->left->next = root->right;

        // Connect right child to the next subtree's left child (if it exists)
        if (root->next) {
            root->right->next = root->next->left;
        }

        // Recurse into both subtrees
        connect(root->left);
        connect(root->right);

        return root;
    }
};