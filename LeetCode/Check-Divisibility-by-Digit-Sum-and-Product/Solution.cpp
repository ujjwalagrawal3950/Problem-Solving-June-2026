1class Solution {
2public:
3    bool checkDivisibility(int n) {
4        long long product = 1;
5        long long sum = 0;
6        int num = n;
7        while(num){
8            int elem = num % 10;
9            num /= 10;
10
11            product *= elem;
12            sum += elem;
13        }
14
15        return (n % (sum + product) == 0) ? true : false;
16    }
17};