1class Solution {
2public:
3    int arrangeCoins(int n) {
4        int k = 1;
5        while(1LL*k * (k + 1) / 2 <= n){
6            k++;
7        }
8        return k-1;
9    }
10};