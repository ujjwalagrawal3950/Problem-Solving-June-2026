1class Solution {
2public:
3    bool isAlienSorted(vector<string>& words, string order) {
4
5        unordered_map<char, int>priority; int x = 26;
6        for(int i = 0; i<26; i++){
7            priority[order[i]] = x;
8            x--;
9        }
10
11        
12        for(int i = 0; i<words.size()-1; i++){
13            bool different = false;
14            int len = min(words[i].length(), words[i+1].length());
15            for(int j = 0; j<len; j++){
16                if(words[i][j] == words[i+1][j]){continue;}
17                else{
18                    different =  true;
19                    if(priority[words[i][j]] < priority[words[i+1][j]]){ return false;}
20                    break;
21                }
22            }
23            if(!different && (words[i].length() > words[i+1].length())){return false;}
24        }
25        return true;
26    }
27};