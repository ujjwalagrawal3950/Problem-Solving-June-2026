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
13    int height(TreeNode* root){
14        if(root == nullptr){return 0;}
15        int left = height(root->left) + 1;
16        int right = height(root->right) +1;
17        return max(left, right);
18    }
19public:
20    int maxDepth(TreeNode* root) {
21        return height(root);
22    }
23};