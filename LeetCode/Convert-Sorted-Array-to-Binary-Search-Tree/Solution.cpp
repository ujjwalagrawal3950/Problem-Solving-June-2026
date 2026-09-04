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
13    TreeNode * BST(vector<int>&nums, int left, int right){
14        if(left > right){return nullptr;}
15        int mid = left + (right - left)/2;
16        TreeNode * node = new TreeNode(nums[mid]);
17        node->left = BST(nums, left, mid-1);
18        node->right = BST(nums, mid + 1, right);
19
20        return node;
21
22    }
23public:
24    TreeNode* sortedArrayToBST(vector<int>& nums) {
25        return BST(nums, 0, nums.size()-1);
26    }
27};