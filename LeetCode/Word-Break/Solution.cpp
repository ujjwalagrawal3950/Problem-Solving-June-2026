1class Solution {
2public:
3    bool wordBreak(string s, vector<string>& wordDict) {
4        int n = s.length();
5        vector<bool>dp(n+1, false); // i = 0 means empty substr so we choose dp.size = n
6        dp[0] = true;
7
8        for(int i = 1; i<=n; i++){
9            for(string x : wordDict){
10                int start = i - x.length();
11                if(start >= 0 && dp[start] && s.substr(start, x.length()) == x){
12                    dp[i] = true;
13                    break;
14                }
15            }
16        }
17        return dp[n];
18    }
19};