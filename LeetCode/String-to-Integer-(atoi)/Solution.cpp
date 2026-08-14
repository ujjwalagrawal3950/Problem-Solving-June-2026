1class Solution {
2public:
3    int myAtoi(string s) {
4        // firstly remove tailing space or zeros
5        string ans = "";
6        int n = s.length(), i = 0;
7        bool negative = false;
8        while(i < n && s[i] == ' '){i++;}
9        if(i < n && (s[i] == '-' || s[i] == '+')){negative = (s[i] == '-'); i++;}
10        while(i < n && s[i] == '0'){i++;}
11
12        while(i < n){
13            int val = s[i] - '0';
14            if(val >= 0 && val <= 9){ // we got number
15                ans += s[i];
16            }
17            else{
18                break;
19            }
20            i++;
21        }
22        long long res = 0;
23        n = ans.length();
24        for(int i = 0; i<n; i++){
25            int val = ans[i]-'0';
26            res = res * 10 + val;
27
28            if(negative && -res < INT_MIN){return INT_MIN;}
29            if(!negative && res > INT_MAX){return INT_MAX;}
30
31        }    
32        return (negative) ? res * -1 : res;
33    }
34};