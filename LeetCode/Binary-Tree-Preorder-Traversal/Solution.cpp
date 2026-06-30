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
15        vector<int>ans;
16        stack<TreeNode*>s;
17        s.push(root);
18        if(root== NULL){
19            return ans;
20        }
21        while(!s.empty()){
22            TreeNode*temp = s.top();
23            s.pop();
24            if(temp->right){
25                s.push(temp->right);
26            }
27            if(temp->left){
28                s.push(temp->left);
29            }
30            ans.push_back(temp->val);
31        }
32        return ans;
33    }
34};