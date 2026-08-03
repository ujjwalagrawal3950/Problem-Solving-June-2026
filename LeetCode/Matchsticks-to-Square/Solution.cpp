1class Solution {
2    bool solution(vector<int>&matchsticks , int index , vector<int>&temp , int size){
3        if(index < 0){
4            for(int i = 0; i<3; i++){
5                if(temp[i] != temp[i+1]){
6                    return false;
7                }
8            }
9            return true;
10        }
11
12        for(int i = 0; i<4; i++){
13            if(temp[i] + matchsticks[index] > size){
14                continue;  // skip that element
15            }
16            if(i > 0 && temp[i] == temp[i-1]) continue; // optimization
17            temp[i] += matchsticks[index];
18            if(solution(matchsticks , index-1 , temp, size)) return true; // end tak aake agar square ban gaya toh bapash upar jane ki jarurat nahi hai islye return true kar do
19            temp[i] -= matchsticks[index];
20        }
21        return false;
22    }
23public:
24    bool makesquare(vector<int>& matchsticks) {
25        int n = matchsticks.size();
26        int sum = accumulate(matchsticks.begin() , matchsticks.end(), 0);
27        if(sum %2 != 0){return false;}
28        int stick_size = sum/4;
29        sort(matchsticks.begin() , matchsticks.end());
30        vector<int>temp(4 , 0);
31        return solution(matchsticks , n-1, temp , stick_size);
32    }
33};