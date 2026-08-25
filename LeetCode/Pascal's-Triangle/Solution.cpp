1class Solution {
2public:
3    vector<vector<int>> generate(int numRows) {
4        vector<vector<int>>ans;
5        int k = 0;
6        for(int i = 0; i<numRows; i++){
7            vector<int>temp;
8            for(int j = 0; j<i+1; j++){
9                if(j == 0 || j == i){
10                    temp.push_back(1);
11                }
12                else{
13                    if(i > 0){int sum = ans[i-1][j] + ans[i-1][j-1]; temp.push_back(sum);}
14                }
15            }
16            ans.push_back(temp);
17        }
18        return ans;
19    }
20};