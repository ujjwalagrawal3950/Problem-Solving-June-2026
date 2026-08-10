1class Solution {
2
3    bool MaxArea(vector<vector<int>>& mat,
4                 int k,
5                 vector<vector<int>>& prefix) {
6
7        int n = mat.size();
8        int m = mat[0].size();
9
10        int R = n - k + 1;
11        int C = m - k + 1;
12
13        // valid[r][c] = whether a k x k square starts at (r,c)
14        vector<vector<bool>> valid(R, vector<bool>(C, false));
15
16        for (int r = 0; r < R; r++) {
17            for (int c = 0; c < C; c++) {
18
19                int sum = prefix[r + k][c + k]
20                        - prefix[r][c + k]
21                        - prefix[r + k][c]
22                        + prefix[r][c];
23
24                if (sum == k * k) {
25                    valid[r][c] = true;
26                }
27            }
28        }
29
30        // rowHas[r] = is there any valid square starting in row r?
31        vector<bool> rowHas(R, false);
32
33        // colHas[c] = is there any valid square starting in column c?
34        vector<bool> colHas(C, false);
35
36        for (int r = 0; r < R; r++) {
37            for (int c = 0; c < C; c++) {
38                if (valid[r][c]) {
39                    rowHas[r] = true;
40                    colHas[c] = true;
41                }
42            }
43        }
44
45        // Prefix count of rows containing a valid square
46        vector<int> rowPrefix(R + 1, 0);
47
48        for (int r = 0; r < R; r++) {
49            rowPrefix[r + 1] = rowPrefix[r] + rowHas[r];
50        }
51
52        // Prefix count of columns containing a valid square
53        vector<int> colPrefix(C + 1, 0);
54
55        for (int c = 0; c < C; c++) {
56            colPrefix[c + 1] = colPrefix[c] + colHas[c];
57        }
58
59        // Check every valid square
60        for (int r = 0; r < R; r++) {
61            for (int c = 0; c < C; c++) {
62
63                if (!valid[r][c])
64                    continue;
65
66                // Is there a valid square at least k rows ABOVE?
67                // Its starting row must be <= r-k.
68                if (r - k >= 0) {
69                    if (rowPrefix[r - k + 1] > 0)
70                        return true;
71                }
72
73                // Is there a valid square at least k rows BELOW?
74                // Its starting row must be >= r+k.
75                if (r + k < R) {
76                    if (rowPrefix[R] - rowPrefix[r + k] > 0)
77                        return true;
78                }
79
80                // Is there a valid square at least k columns LEFT?
81                if (c - k >= 0) {
82                    if (colPrefix[c - k + 1] > 0)
83                        return true;
84                }
85
86                // Is there a valid square at least k columns RIGHT?
87                if (c + k < C) {
88                    if (colPrefix[C] - colPrefix[c + k] > 0)
89                        return true;
90                }
91            }
92        }
93
94        return false;
95    }
96
97public:
98
99    int maxArea(vector<vector<int>>& mat) {
100
101        int n = mat.size();
102        int m = mat[0].size();
103
104        // Build 2D prefix sum
105        vector<vector<int>> prefix(
106            n + 1,
107            vector<int>(m + 1, 0)
108        );
109
110        for (int i = 1; i <= n; i++) {
111            for (int j = 1; j <= m; j++) {
112
113                prefix[i][j] =
114                    mat[i - 1][j - 1]
115                    + prefix[i - 1][j]
116                    + prefix[i][j - 1]
117                    - prefix[i - 1][j - 1];
118            }
119        }
120
121        // Binary search on side length k
122        int start = 1;
123        int end = min(n, m);
124        int ans = 0;
125
126        while (start <= end) {
127
128            int mid = start + (end - start) / 2;
129
130            if (MaxArea(mat, mid, prefix)) {
131                ans = mid;
132                start = mid + 1;
133            }
134            else {
135                end = mid - 1;
136            }
137        }
138
139        return ans * ans;
140    }
141};