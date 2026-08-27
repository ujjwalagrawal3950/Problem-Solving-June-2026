1class Solution {
2    int originalWidth;
3    int dp[1001][1001];
4    int solve(vector<vector<int>>&books, int width , int idx, int height){
5        if(idx == books.size()){
6            return height;
7        }
8        if(dp[idx][width] != -1){return dp[idx][width];}
9        int bookWidth  = books[idx][0];
10        int bookHeight = books[idx][1];
11
12        int x = INT_MAX, y = INT_MAX;
13        if(bookWidth <= width){
14            x = solve(books, width - bookWidth , idx + 1, max(height, bookHeight));
15        }
16        y = solve(books, originalWidth-bookWidth, idx + 1, bookHeight) + height;
17
18        return dp[idx][width] = min(x, y);
19    }
20public:
21    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
22        originalWidth = shelfWidth;
23        memset(dp, -1, sizeof(dp));
24        return solve(books, shelfWidth , 0, 0);
25    }
26};