1class Solution {
2public:
3    string reverseStr(string s, int k) {
4        int i = 0, n = s.length();
5        while(i < s.length()){
6           if(i + k < s.length()) reverse(s.begin()+i, s.begin() + k + i);
7           if(n-i-1 < k) reverse(s.begin()+ i , s.end());
8            i += 2*k;
9        }
10        return s;
11    }
12};