1class Solution {
2public:
3    string mergeAlternately(string word1, string word2) {
4        string ans = "";
5        int i = 0, j = 0;
6        while(i < word1.length() || j < word2.length()){
7            if(i < word1.length()) ans += word1[i];
8            if(j < word2.length()) ans += word2[j];
9            i++; j++;
10        }
11        return ans;
12    }
13};