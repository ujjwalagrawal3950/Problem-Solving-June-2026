1class Solution {
2    int next(int n) {
3        int sum = 0;
4        while (n) {
5            int elem = n % 10;
6            n /= 10;
7            sum += elem * elem;
8        }
9        return sum;
10    }
11
12public:
13    bool isHappy(int n) {
14        int slow = n, fast = n;
15
16        do {
17            slow = next(slow);
18            fast = next(next(fast));
19        } while (slow != fast);
20
21        return slow == 1;
22    }
23};