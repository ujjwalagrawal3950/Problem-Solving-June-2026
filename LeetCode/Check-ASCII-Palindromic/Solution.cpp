1class Solution {
2    bool checkPalindrome(string s) {
3        int n = s.length();
4        int i = 0, j = n - 1;
5
6        while(i <= j) {
7            if(s[i] == s[j]) {
8                i++;
9                j--;
10            }
11            else {
12                return false;
13            }
14        }
15
16        return true;
17    }
18
19    string intToBinary(int num) {
20        string ans = "";
21
22        // Exactly 8 bits, including leading zeros
23        for(int i = 7; i >= 0; i--) {
24            char bit = ((num >> i) & 1) + '0';
25            ans += bit;
26        }
27
28        return ans;
29    }
30
31public:
32    bool isPalindromic(string s) {
33
34        string binary = "";
35
36        // Convert every character to 8-bit ASCII binary
37        for(char ch : s) {
38            binary += intToBinary((int)ch);
39        }
40
41        // Check the complete binary string
42        return checkPalindrome(binary);
43    }
44};