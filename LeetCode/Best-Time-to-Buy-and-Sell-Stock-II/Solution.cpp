1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int ans = 0;
5        for(int i = 0; i<prices.size()-1; i++){
6            if(prices[i] < prices[i+1]){
7                ans += prices[i+1]-prices[i];
8            }
9        }
10    return ans;
11    }
12};