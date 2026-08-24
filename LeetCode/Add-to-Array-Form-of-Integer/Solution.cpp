1class Solution {
2public:
3    vector<int> addToArrayForm(vector<int>& num, int k) {
4        vector<int> ans;
5
6        int j = num.size() - 1;
7        int carry = 0;
8
9        while (j >= 0 || k > 0 || carry) {
10            int digit = k % 10;
11            k /= 10;
12
13            int n = (j >= 0) ? num[j] : 0;
14
15            int sum = n + digit + carry;
16
17            ans.push_back(sum % 10);
18            carry = sum / 10;
19
20            j--;
21        }
22
23        reverse(ans.begin(), ans.end());
24
25        return ans;
26    }
27};