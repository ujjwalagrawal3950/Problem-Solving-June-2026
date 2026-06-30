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
13    void PreOrder(TreeNode * root , vector<int>&ans){
14        if (root == NULL) {
15            return;
16        }
17        ans.push_back(root->val);
18        PreOrder(root->left , ans);
19        PreOrder(root->right, ans);
20    }
21public:
22    vector<int> preorderTraversal(TreeNode* root) {
23        vector<int>ans;
24        PreOrder(root, ans);
25        return ans;
26    }
27};