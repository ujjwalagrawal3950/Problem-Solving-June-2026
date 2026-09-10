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
13    void MakeParentNode(TreeNode*root, unordered_map<int, TreeNode*>&ParentMap, TreeNode*&starting, int start){
14        if(!root) return;
15
16        if(root->left)  ParentMap[root->left->val] = root;
17        if(root->right) ParentMap[root->right->val] = root;
18
19        if(root->val == start){starting = root;}
20
21        MakeParentNode(root->left, ParentMap, starting, start);
22        MakeParentNode(root->right, ParentMap,starting ,start);
23        
24    }
25    
26    int time(TreeNode*root, unordered_map<int, TreeNode*>&ParentMap, unordered_map<TreeNode*, bool>&visited, int start){
27
28        queue<TreeNode*>q;
29        q.push(root);
30        visited[root] = true;
31
32        int time = 0;
33
34        while(!q.empty()){
35            int size = q.size();
36            while(size--){
37                TreeNode*node = q.front(); q.pop();
38                if(node->left && !visited[node->left])  
39                {q.push(node->left); visited[node->left] = true;}
40
41                if(node->right && !visited[node->right]) 
42                {q.push(node->right); visited[node->right] = true;}
43                
44                if(ParentMap.count(node->val) && !visited[ParentMap[node->val]]) 
45                {q.push(ParentMap[node->val]); visited[ParentMap[node->val]] = true;}
46            }
47            time++;
48        }
49        return time-1;
50    }
51public:
52    int amountOfTime(TreeNode* root, int start) {
53    
54        unordered_map<int, TreeNode*>ParentMap;
55        unordered_map<TreeNode*, bool>visited;
56        TreeNode*starting = nullptr;
57        MakeParentNode(root, ParentMap, starting, start);
58        
59        return time(starting, ParentMap, visited, start);
60    }
61};