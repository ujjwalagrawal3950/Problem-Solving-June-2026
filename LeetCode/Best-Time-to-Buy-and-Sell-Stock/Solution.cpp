1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int mini = INT_MAX, ans = 0;
5        for(int i = 0; i<prices.size(); i++){
6            mini = min(mini, prices[i]);
7            ans = max(ans, prices[i]-mini);
8        }
9        return ans;
10    }
11};