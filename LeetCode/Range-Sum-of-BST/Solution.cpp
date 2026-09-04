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
13    void Summation(TreeNode*root, int low , int high, int & x){
14        if(!root) return ;
15        if(root->val >= low  && root->val <= high){
16            x += root->val;
17        }
18        Summation(root->left , low, high, x);
19        Summation(root->right, low, high, x);
20    }
21public:
22    int rangeSumBST(TreeNode* root, int low, int high) {
23        int sum = 0;
24        Summation(root, low , high, sum);
25        return sum;
26    }
27};