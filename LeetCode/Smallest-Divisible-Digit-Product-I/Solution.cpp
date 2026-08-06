1class Solution {
2public:
3    int smallestNumber(int n, int t) {
4        int x = n, ans = 0;
5        n += 10;
6        while(x <= n){
7            int num = x, product = 1;
8            while(num){
9                product *= (num%10);
10                num /= 10;
11            }
12            if(product % t == 0){
13                ans = x;
14                break;
15            }
16            x++;
17        }
18        return ans;
19    }
20};