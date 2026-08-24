1class Solution {
2public:
3    string addBinary(string a, string b) {
4        string ans = "";
5        int carry = 0;
6        int i = a.length()-1, j = b.length()-1;
7
8        while(i >= 0 && j >= 0){
9            int first = a[i]-'0', second = b[j]-'0';
10            ans += to_string((carry ^ first ^ second));
11            carry = (first & second) | (first & carry) | (second & carry);
12            i--; j--;
13        }
14
15        while(i >= 0){
16            int digit = a[i] - '0';
17            ans += to_string((carry ^ digit));
18            carry = carry & digit;
19            i--;
20        }
21
22        while(j >= 0){
23            int digit  = b[j] - '0';
24            ans += to_string((carry ^ digit));
25            carry = carry & digit;
26            j--;
27        }
28        ans = (carry == 1) ? ans + '1' : ans;
29        reverse(ans.begin(), ans.end());
30        return ans;
31    }
32};