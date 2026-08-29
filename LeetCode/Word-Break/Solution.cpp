1class Solution {
2    bool solution(string&s, vector<string>&word, unordered_set<string>&mp, int st, vector<int>&dp){
3        if(dp[st] != -1){return dp[st];}
4        int n = s.length();
5        string temp = "";
6        for(int i = st; i<n; i++){
7            temp += s[i];
8            if(mp.find(temp) != mp.end()){
9                if(i == n-1) return true;
10                if(i != n-1 && solution(s, word, mp, i+1, dp)) return dp[st] = true;
11            }
12        }
13        return dp[st] = false;
14    }
15public:
16    bool wordBreak(string s, vector<string>& wordDict) {
17
18        // here gready approch will fail because if we found wrong substring in the map and if we take it then this will give wrong answer 
19
20        // example s = 'leetcode' wordDict = {'leet', 'lee', 'code'} then firstly you choose lee and then further no words will available and you will give wrong answer. therefore use dyanmic programing here instead of gready approch
21        int n = s.length();
22        vector<int>dp(n, -1);
23        unordered_set<string>mp(wordDict.begin(), wordDict.end());
24        return solution(s, wordDict, mp, 0, dp);
25
26    }
27};