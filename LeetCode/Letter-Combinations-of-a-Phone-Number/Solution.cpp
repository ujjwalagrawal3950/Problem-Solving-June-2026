1class Solution {
2    void MakeCombinations(string digits, vector<string>&mp , vector<string>&ans, string & temp, int idx, int n){
3
4        if(idx >= n){
5            cout<<temp<<endl;
6            ans.push_back(temp);
7            return;
8        }
9
10        string x = mp[digits[idx]-'0'];
11
12        for(int i = 0; i<x.length(); i++){
13            temp += x[i];
14            MakeCombinations(digits, mp, ans, temp, idx + 1, n);
15            temp.pop_back();
16        }
17    }
18public:
19    vector<string> letterCombinations(string digits) {
20        vector<string>mp = 
21        {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
22
23        vector<string>ans;
24        int n = digits.length();
25        string temp = "";
26        MakeCombinations(digits, mp, ans, temp, 0, n);
27        return ans;
28    }
29};