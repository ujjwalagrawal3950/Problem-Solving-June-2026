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
13    int dfs(TreeNode * root, int & ans){
14        if(!root){ return 0; }
15        int left = max(0 , dfs(root->left, ans));
16        int right= max(0, dfs(root->right,ans));
17        ans = max(ans, left+ right + root->val);
18        return root->val + max(left , right);
19    }
20public:
21    int maxPathSum(TreeNode* root) {
22        if(root->left == nullptr && root->right == nullptr){
23            return root->val;
24        }
25        int ans = INT_MIN;
26        dfs(root, ans);
27        return ans;
28    }
29};