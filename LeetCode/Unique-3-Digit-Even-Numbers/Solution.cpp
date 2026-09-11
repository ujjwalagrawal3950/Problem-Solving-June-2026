1class Solution {
2public:
3    int totalNumbers(vector<int>& digits) {
4        int n = digits.size();
5        unordered_set<int> s;
6
7        for (int i = 0; i < n; i++) {
8            if (digits[i] == 0) continue; 
9
10            for (int j = 0; j < n; j++) {
11                if (j == i) continue;
12
13                for (int k = 0; k < n; k++) {
14                    if (k == i || k == j) continue;
15
16                    if (digits[k] % 2 == 0) {
17                        int num = digits[i] * 100
18                                + digits[j] * 10
19                                + digits[k];
20
21                        s.insert(num);
22                    }
23                }
24            }
25        }
26
27        return s.size();
28    }
29};