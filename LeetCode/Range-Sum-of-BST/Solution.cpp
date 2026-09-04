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
13public:
14    int rangeSumBST(TreeNode* root, int low, int high) {
15        if(!root) return 0;
16        if(root->val < low){
17            return rangeSumBST(root->right, low, high);
18        }
19        if(root->val > high){
20            return rangeSumBST(root->left, low, high);
21        }
22
23        return root->val + rangeSumBST(root->left, low, high)
24                + rangeSumBST(root->right, low , high);
25    }
26};