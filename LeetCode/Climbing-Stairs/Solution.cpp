1class Solution {
2    int fibonaaci(int n, vector<int>&dp){
3        if(n == 0 || n == 1){return 1;}
4        if(n < 0){return 0;}
5        if(dp[n] != -1){return dp[n];}
6
7        return dp[n] = fibonaaci(n-1, dp) + fibonaaci(n-2, dp);
8    }
9public:
10    int climbStairs(int n) {
11        vector<int>dp(n+1, -1);
12        return fibonaaci(n, dp);
13    }
14};