1class Solution {
2    int dp[1001];
3    bool check(string & s, unordered_set<string>&st, int idx){
4        if(idx == s.length()){return true;}
5        if(idx > s.length()) return false;
6        if(dp[idx] != -1){return dp[idx];}
7        string temp = "";
8        for(int i = idx; i<s.length(); i++){
9            temp += s[i];
10            if(st.find(temp) != st.end()){
11                if(check(s, st, i + 1)) return dp[idx] = true;
12            }
13        }
14        return dp[idx] = false;
15    }
16public:
17    bool wordBreak(string s, vector<string>& wordDict) {
18        memset(dp, -1, sizeof(dp));
19        unordered_set<string>st(wordDict.begin(), wordDict.end());
20        return check(s, st, 0);
21    }
22};