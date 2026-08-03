1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11    TreeNode * LCA(TreeNode*root, int p, int q){
12        if(root == nullptr){return nullptr;}
13        if(root->val == p || root->val == q){return root;}
14
15        TreeNode*left = LCA(root->left, p, q);
16        TreeNode*right = LCA(root->right, p, q);
17
18        if(left == nullptr){return right;}
19        if(right == nullptr){return left;}
20
21        return root;
22    }
23public:
24    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
25        return LCA(root, p->val, q->val);
26    }
27};