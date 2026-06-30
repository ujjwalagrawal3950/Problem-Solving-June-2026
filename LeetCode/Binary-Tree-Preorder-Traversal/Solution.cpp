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
14    vector<int> preorderTraversal(TreeNode* root) {
15        stack<TreeNode*>st;
16        vector<int>ans;
17        st.push(root);
18        while(!st.empty()){
19            TreeNode*node = st.top(); st.pop();
20            if(node != NULL){
21                ans.push_back(node->val);
22                if(node->right) st.push(node->right);
23                if(node->left)  st.push(node->left);
24            }
25        }
26        return ans;
27    }
28};