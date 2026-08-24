1class Solution {
2public:
3    string addBinary(string a, string b) {
4        int i = a.length()-1, j = b.length()-1;
5        string ans = "";
6        int carry = 0;
7        while(i >= 0 || j >= 0 || carry){
8            int first  =  (i >= 0)  ?  a[i--]-'0' : 0;
9            int second =  (j >= 0)  ?  b[j--]-'0' : 0;
10            
11            char digit = (first + second + carry) % 2 + '0';
12            carry = (first + second + carry) / 2;
13
14            ans += digit;
15
16        }
17        reverse(ans.begin(), ans.end());
18        return ans;
19    }
20};