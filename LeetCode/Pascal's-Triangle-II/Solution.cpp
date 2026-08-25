1class Solution {
2public:
3    vector<int> getRow(int rowIndex) {
4        vector<int>prev;
5        for(int i = 0; i<=rowIndex; i++){
6            vector<int>curr;
7            for(int j = 0; j<i+1; j++){
8                if(j == 0 ||  j == i){
9                    curr.push_back(1);
10                }
11                else{
12                    if(i > 0){
13                        int sum = prev[j] + prev[j-1];
14                        curr.push_back(sum);
15                    }
16                }
17            }
18            prev = curr;
19        }
20        return prev;
21    }
22};