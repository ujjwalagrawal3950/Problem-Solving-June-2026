1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
15        if(!root1 && !root2) return nullptr;
16        if(!root1) return root2;
17        if(!root2) return root1;
18
19        int node1 = (root1 != nullptr) ? root1->val : 0;
20        int node2 = (root2 != nullptr) ? root2->val : 0;
21
22        TreeNode*node = new TreeNode(node1 + node2);
23        node->left = mergeTrees(root1->left, root2->left);
24        node->right= mergeTrees(root1->right, root2->right);
25
26        return node;
27    }
28};