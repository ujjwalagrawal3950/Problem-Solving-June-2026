1class Solution {
2public:
3    string intToRoman(int num) {
4        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
5        vector<string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L", "XL", "X",  "IX", "V",  "IV", "I"};
6        int i = 0;
7        string ans = "";
8        while(num){
9            if(num-values[i] >= 0){ans += symbols[i]; num -= values[i];}
10            else {i++;}
11        }
12        return ans;
13    }
14};