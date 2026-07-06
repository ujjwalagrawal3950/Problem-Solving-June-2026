1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Solution {
12    TreeNode*find_LCA(TreeNode*root, int p, int q){
13        if(root == nullptr) {return root;}
14
15        if(p == root->val || q == root->val){return root;}
16
17        TreeNode*left =  find_LCA(root->left, p, q);
18        TreeNode*right = find_LCA(root->right, p, q);
19
20        if(!left){return right;}
21        else if(!right){return left;}
22
23        return root;
24    }
25public:
26    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
27        return find_LCA(root, p->val, q->val);
28    }
29};