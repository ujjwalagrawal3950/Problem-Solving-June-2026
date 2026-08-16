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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        if(!root){return {};}
16        vector<vector<int>>ans;
17        queue<TreeNode*>q;
18        q.push(root);
19        int level = 0;
20        while(!q.empty()){
21            vector<int>temp;
22            int s = q.size();
23            while(s--){
24                TreeNode*node = q.front(); q.pop();
25                if(node->left)   q.push(node->left);
26                if(node->right)  q.push(node->right);
27                temp.push_back(node->val);
28            }
29            if(level % 2 != 0){
30                reverse(temp.begin(), temp.end());
31            }
32            ans.push_back(temp);
33            level++;
34        }
35        return ans;
36    }
37};