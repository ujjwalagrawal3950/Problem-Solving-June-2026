1class Solution {
2public:
3    int climbStairs(int n) {
4        vector<int>dp(n+1, 0);
5        dp[1] = 1, dp[0] = 1;
6        for(int i = 2; i<=n; i++){  // bottom to up
7            dp[i] = dp[i-1] + dp[i-2];
8        }
9        return dp[n];
10    }
11};