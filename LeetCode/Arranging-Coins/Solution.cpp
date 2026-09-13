1class Solution {
2public:
3    int arrangeCoins(int n) {
4        int left = 1, right = n;
5        while(left <= right){
6            int mid = left + (right-left)/2;
7            
8            long long coins = 1LL * mid * (mid + 1) / 2;
9            if(coins == n) return mid;
10            else if(coins < n) left = mid + 1;
11            else right = mid -1;
12        }
13        return right;
14    }
15};