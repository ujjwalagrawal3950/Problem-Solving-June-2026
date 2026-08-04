1class Solution {
2    int bfs(vector<vector<int>>&bombs, int i, vector<bool>visited){
3        int ans = 1;
4        int n = bombs.size();
5        queue<int>q;
6        visited[i] = 1;
7        q.push(i);
8        while(!q.empty()){
9            int node = q.front(); q.pop();
10            long long range = bombs[node][2];
11            for(int k = 0; k<n; k++){
12                long long dx = bombs[node][0]-bombs[k][0];
13                long long dy = bombs[node][1]-bombs[k][1];
14
15                if(dx*dx + dy*dy <= 1LL*range*range){
16                    if(!visited[k]){
17                        visited[k] = 1;
18                        q.push(k);
19                        ans++;
20                    }
21                    
22                }
23            }
24        }
25        return ans;
26    }
27public:
28    int maximumDetonation(vector<vector<int>>& bombs) {
29        // this is bfs problem
30        int n = bombs.size();
31        int ans = INT_MIN;
32        vector<bool>visited(n, 0);
33        for(int i = 0; i<n; i++){
34            int x = bfs(bombs, i, visited);
35            ans = max(ans, x);
36        }
37        return ans;
38    }
39};