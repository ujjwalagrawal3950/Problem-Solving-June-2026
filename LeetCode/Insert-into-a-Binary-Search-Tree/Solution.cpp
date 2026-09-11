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
13    TreeNode*insert(TreeNode*root, int value){
14        
15        if(!root) return new TreeNode(value);
16
17        if(root->val > value)
18        {root->left   = insert(root->left, value);}
19
20        if(root->val < value)
21        {root->right = insert(root->right, value);}
22
23        return root;
24    }
25public:
26    TreeNode* insertIntoBST(TreeNode* root, int val) {
27        return insert(root, val);
28    }
29};