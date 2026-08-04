1class Solution {
2public:
3    int islandPerimeter(vector<vector<int>>& grid) {
4        int n = grid.size();
5        int m = grid[0].size();
6        int perimeter = 0;
7
8        for(int i = 0; i<n; i++){
9            for(int j = 0; j<m; j++){
10                if(grid[i][j] == 1){
11                    if((j > 0 && grid[i][j-1] == 0) || j == 0){perimeter++;}
12                    if((j+1 < m && grid[i][j+1] == 0) || j == m-1){perimeter++;}
13                    if((i > 0 && grid[i-1][j] == 0) || i == 0){perimeter++;}
14                    if((i+1 < n && grid[i+1][j] == 0 )|| i == n-1){perimeter++;}
15                }
16            }
17        }
18        return perimeter;
19    }
20};