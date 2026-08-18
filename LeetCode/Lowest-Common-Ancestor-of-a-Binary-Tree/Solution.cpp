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
11    TreeNode* dfs(TreeNode*root, int x, int y){
12
13        if(!root) return nullptr;
14        if(root->val == x || root->val == y){return root;}
15
16        TreeNode* left = dfs(root->left, x, y);
17        TreeNode*right = dfs(root->right, x, y);
18        
19        if(!left && right){return right;}
20        else if(!right && left) return left;
21        else if(!left && !right) return nullptr;
22        return root;
23    }
24public:
25    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
26        int x = p->val, y = q->val;
27        return dfs(root, x, y);
28    }
29};