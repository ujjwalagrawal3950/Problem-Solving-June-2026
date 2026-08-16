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
13    int solve(TreeNode*root, int & dia){
14        if(!root){return 0;}
15        int left = solve(root->left, dia);
16        int right= solve(root->right, dia);
17
18        dia = max(left+ right, dia);
19        return max(left , right) + 1;
20    }
21public:
22    int diameterOfBinaryTree(TreeNode* root) {
23        int dia = 0;
24        solve(root, dia);
25        return dia;
26    }
27};