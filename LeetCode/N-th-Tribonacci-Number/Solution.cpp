1class Solution {
2    int solution(int n , vector<int>&dp){
3        if(n == 0){return 0;}
4        if(n == 1){return 1;}
5        if(n == 2){return 1;}
6        if(dp[n] != -1){return dp[n];}
7        return dp[n] = solution(n-1,dp) + solution(n-2, dp) + solution(n-3, dp);
8    }
9public:
10    int tribonacci(int n) {
11        vector<int>dp(n+1, -1);
12        return solution(n, dp);
13    }
14};