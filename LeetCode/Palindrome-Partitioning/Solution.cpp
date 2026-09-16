1class Solution {
2    bool checkPalindrome(string x, int start, int end){
3        while(start < end){
4            if(x[start] != x[end]) return false;
5            start++; end--;
6        }
7        return true;
8    }
9
10    void MakeCuts(string s, vector<string>&temp, vector<vector<string>>&ans, int idx){
11        if(idx == s.length()){
12            ans.push_back(temp);
13            return;
14        }
15        for(int i = idx; i<s.length(); i++){
16            if(checkPalindrome(s, idx, i)){
17                temp.push_back(s.substr(idx, i-idx+1));
18                MakeCuts(s, temp, ans, i+1);
19                temp.pop_back();
20            }
21        }
22    }
23public:
24    vector<vector<string>> partition(string s) {
25
26        vector<string>temp;
27        vector<vector<string>>ans;
28
29        MakeCuts(s, temp, ans, 0);
30
31        return ans;
32    }
33};