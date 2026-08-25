1class Solution {
2public:
3    vector<vector<int>> generate(int numRows) {
4        vector<vector<int>>ans;
5        for(int i = 0; i<numRows; i++){
6            vector<int>temp(i+1, 0);
7            int k = 0;
8            for(int j = 0; j<i+1; j++){
9
10                if(j == 0 || j==i){
11                    temp[j] = 1;
12                }
13                else{
14                    int size = ans[i-1].size();
15                    temp[j] = ans[i-1][k] + ans[i-1][k+1];
16                    k++;
17                }
18            }
19            ans.push_back(temp);
20        }
21        return ans;
22    }
23};