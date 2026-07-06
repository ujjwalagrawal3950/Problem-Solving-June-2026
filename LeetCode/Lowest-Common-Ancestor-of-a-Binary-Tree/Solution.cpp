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
11    TreeNode*LCA(TreeNode*root, int p , int q){
12        if(root == nullptr || root->val == p || root->val == q){
13            return root;
14        }
15        TreeNode*left = LCA(root->left, p, q);
16        TreeNode*right= LCA(root->right,p, q);
17
18        if(!left){return right;}
19        else if(!right) {return left;}
20        // if left and right both returning node then return root because root become diverging node;
21        
22        return root;
23    }
24public:
25    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
26        return LCA(root, p->val, q->val); // we need to compare values only
27    }
28};