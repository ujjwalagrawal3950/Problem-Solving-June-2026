1class Solution {
2    int dp[101][101];
3    int mod = 1e9 + 7;
4public:
5    int sumOfPower(vector<int>& nums, int k) {
6        int n = nums.size();
7        memset(dp, 0, sizeof(dp));
8        dp[0][0] = 1;
9        for(int i = 0; i<n; i++){  // Each element has two option pick or not pick
10            for(int len = i+1; len >= 1; len--){
11                for(int sum = k; sum >= nums[i]; sum--){
12                    dp[len][sum] = (dp[len][sum]+ dp[len-1][sum-nums[i]]) % mod;
13                }
14            }
15        }
16
17
18        // Now we have all the subsequence with sum = k and now we can use them again
19
20        int ans = 0;
21
22        vector<long long>power(n+1, 1);
23        power[0] = 1; for(int i = 1; i<=n; i++){power[i] = (power[i-1] * 2) % mod;}
24
25        for(int len = 1; len <= n; len++){ // len = 0 ko koi sense nahi hai
26            ans = (ans + dp[len][k] * power[n-len]) % mod;
27        }
28        return ans;
29    }
30};