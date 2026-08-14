1class Solution {
2public:
3    int romanToInt(string s) {
4        int ans = 0;
5        int i = 0;
6        while (i <= s.length() - 1) {
7            if (s[i] == 'I') {
8                if (s[i + 1] == 'V') {
9                    ans += 4;
10                    i += 2;
11                } else if (s[i + 1] == 'X') {
12                    ans += 9;
13                    i += 2;
14                } else {
15                    ans += 1;
16                    i++;
17                }
18            }
19            if (s[i] == 'X') {
20                if (s[i + 1] == 'L') {
21                    ans +=40 ;
22                    i += 2;
23                } else if (s[i + 1] == 'C') {
24                    ans += 90;
25                    i += 2;
26                } else {
27                    ans += 10;
28                    i++;
29                }
30            }
31            if (s[i] == 'C') {
32                if (s[i + 1] == 'D') {
33                    ans +=400 ;
34                    i += 2;
35                } else if (s[i + 1] == 'M') {
36                    ans += 900;
37                    i += 2;
38                } else {
39                    ans += 100;
40                    i++;
41                }
42            }
43            if(s[i] =='V'){
44                ans+=5;
45                i++;
46            }
47            else if(s[i] == 'L'){
48                ans += 50;
49                i++;
50            }
51            else if(s[i] =='D' ){
52                ans+=500;
53                i++;
54            }
55            else if(s[i] == 'M'){
56                ans+=1000;
57                i++;
58            }
59        }
60        return ans;
61    }
62};