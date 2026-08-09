1class Solution {
2public:
3    double minPrice(vector<int>& prices, vector<int>& discounts) {
4        sort(prices.begin(), prices.end(), greater<int>());
5        sort(discounts.begin(), discounts.end(), greater<int>());
6        int size = min(prices.size(), discounts.size());
7        double final_price = 0;
8        int i = 0;
9        while(i < size){
10            final_price += (prices[i] * (double)(100-discounts[i])/100);
11            i++;
12        }
13
14        while(i < prices.size()){
15            final_price += prices[i];
16            i++;
17        }
18        return final_price;
19    }
20};