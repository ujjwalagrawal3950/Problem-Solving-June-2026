1class Solution {
2    int high(vector<int>&parent, vector<int>adj[], int x){
3        queue<int>q; q.push(x);
4
5        int depth = 0;
6        while(!q.empty()){ // this can also go for O(n)
7
8            int size = q.size();
9            depth++;
10
11            while(size--){
12                int node = q.front(); q.pop();
13                for(int x : adj[node]){
14                    q.push(x);
15                }
16            }
17        }
18        return depth;
19    }
20
21
22public:
23    long long weightedSum(vector<int>& parent, vector<int>& nums) {
24        int n = parent.size();
25        long long ans = 0;
26        vector<int>adj[n];
27
28        for(int i = 1; i<n; i++){  // children ko uske parent mai push karna
29            adj[parent[i]].push_back(i);
30        }
31
32        int height = high(parent, adj, 0);
33
34
35        queue<int>q; q.push(0);
36        int depth = 1;
37        while(!q.empty()){
38            int size = q.size();
39            while(size--){
40                int node = q.front(); q.pop();
41                ans += 1LL*nums[node] * (height - depth + 1);
42                for(int x : adj[node]){
43                    q.push(x);
44                }
45            }
46            depth++;
47        }
48        return ans;
49    }
50};