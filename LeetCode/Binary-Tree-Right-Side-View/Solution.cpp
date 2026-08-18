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
14    vector<int> rightSideView(TreeNode* root) {
15        // apply bfs because in each step we are going down
16        vector<int>ans;
17        if(!root) return ans;  // edge case
18
19        queue<TreeNode*>q;  // Treenode and maximum depth
20        q.push(root);
21
22        while(!q.empty()){
23            int size = q.size();
24            while(size--){
25                TreeNode*node =  q.front(); q.pop();
26                if(size == 0)  {ans.push_back(node->val);}
27                if(node->left)  q.push(node->left);
28                if(node->right) q.push(node->right);
29            }
30        }
31        return ans;
32    }
33};