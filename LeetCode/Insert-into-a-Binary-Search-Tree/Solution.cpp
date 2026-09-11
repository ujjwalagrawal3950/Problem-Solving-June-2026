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
14    TreeNode* insertIntoBST(TreeNode* root, int value) {
15
16        // Can we Do this with iterative method
17        if(!root) return new TreeNode(value);
18        
19        TreeNode*temp = root;
20        while(temp != nullptr){
21            if(temp->val > value && temp->left)      {temp = temp->left;}
22            else if(temp->val < value && temp->right) {temp = temp->right;}
23            else break;
24        }
25        if(temp->val > value){temp->left = new TreeNode(value);}
26        else temp->right = new TreeNode(value);
27
28        return root;
29    }
30};