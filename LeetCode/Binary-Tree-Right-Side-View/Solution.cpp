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
22        int level = 0;
23        int maxDepth = -1;
24        while(!q.empty()){
25            int size = q.size();
26            while(size--){
27                TreeNode*node =  q.front(); q.pop();
28                if(level > maxDepth){ans.push_back(node->val);  maxDepth = level;}
29                if(node->right) q.push(node->right);
30                if(node->left)  q.push(node->left);
31            }
32            level++;
33        }
34        return ans;
35    }
36};