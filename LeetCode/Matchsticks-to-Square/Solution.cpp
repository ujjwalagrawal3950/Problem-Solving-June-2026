1class Solution {
2    bool dfs(vector<int>& matchsticks, vector<int>& temp, int index, int n, int target) {
3        if (index >= n) {
4            return (temp[0] == target && temp[1] == target &&
5                    temp[2] == target && temp[3] == target);
6        }
7
8        for (int i = 0; i < 4; i++) {
9            if (temp[i] + matchsticks[index] > target) continue; // prune
10            temp[i] += matchsticks[index];
11            if (dfs(matchsticks, temp, index + 1, n, target)) return true;
12            temp[i] -= matchsticks[index];
13        }
14        return false;
15    }
16
17public:
18    bool makesquare(vector<int>& matchsticks) {
19        int sum = 0;
20        for (int x : matchsticks) sum += x;
21        if (sum % 4 != 0) return false;
22
23        int target = sum / 4;
24        sort(matchsticks.rbegin(), matchsticks.rend()); // descending
25
26        vector<int> temp(4, 0);
27        return dfs(matchsticks, temp, 0, matchsticks.size(), target);
28    }
29};
30