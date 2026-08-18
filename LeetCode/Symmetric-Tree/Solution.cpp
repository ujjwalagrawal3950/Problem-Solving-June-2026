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
14    bool solution(TreeNode*left , TreeNode*right){
15        if(!left && !right){
16            return true;
17        }
18        if(!left || !right){
19            return false;
20        }
21        if(left->val != right->val){
22            return false;
23        }
24        return solution(left->right , right->left)&&solution(left->left , right->right);
25    }
26    bool isSymmetric(TreeNode* root) {
27        return solution(root->left , root->right);
28    }
29};