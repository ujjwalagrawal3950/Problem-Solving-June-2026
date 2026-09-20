1class Solution {
2public:
3    int reverseDegree(string s) {
4        long long ans = 0;
5        for(int i = 0; i<s.length(); i++){
6            ans = ans + 1LL*(26-(s[i]-'a')) * (i + 1);
7        }
8        return (int)ans;
9    }
10};