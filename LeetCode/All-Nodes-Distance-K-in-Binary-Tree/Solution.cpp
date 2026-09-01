1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11    void buildParent(TreeNode*root, unordered_map<TreeNode*, TreeNode*>&parentMap){
12        if(!root) return;
13        if(root->left)  parentMap[root->left] = root;
14        if(root->right) parentMap[root->right] = root;
15        buildParent(root->left, parentMap);
16        buildParent(root->right, parentMap);
17    }
18public:
19    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
20        unordered_map<TreeNode*, TreeNode*>parentMap;
21        vector<int>ans;
22        buildParent(root, parentMap);
23
24        // Firstly Reach to Target but here target node is already is given
25        queue<TreeNode*>q;
26        set<TreeNode*>visited;
27        q.push(target);
28        int level = 0;
29        while(level != k){
30            int size = q.size();
31            while(size--){
32                TreeNode* node = q.front(); q.pop();
33                visited.insert(node);
34                // I have three option/direction to go
35                if(node->left && visited.find(node->left) == visited.end())q.push(node->left);
36                if(node->right && visited.find(node->right) == visited.end()) q.push(node->right);
37                if(parentMap[node] && visited.find(parentMap[node]) == visited.end()) q.push(parentMap[node]);
38            }
39            level++;
40        }
41
42        while(!q.empty()){
43            TreeNode*node = q.front(); q.pop();
44            ans.push_back(node->val);
45        }
46        return ans;
47    }
48};