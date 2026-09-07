1class Solution {
2public:
3    int buyChoco(vector<int>& prices, int money) {
4        sort(prices.begin(), prices.end());
5        return (prices[0] + prices[1] <= money) ? money - prices[0] - prices[1] : money;
6    }
7};