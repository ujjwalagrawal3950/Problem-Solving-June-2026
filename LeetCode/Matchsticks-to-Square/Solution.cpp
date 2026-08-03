1class Solution {
2    bool solution(vector<int>&matchsticks, int idx, int target, vector<int>&side){
3        int n = matchsticks.size();
4        if(idx >= n){
5            if(side[0] == side[1] && side[1] == side[2] && side[2] == side[3]) return true;
6        }
7
8        for(int i = 0; i<4; i++){ // Each sticks have to option to add in any of four side
9            if(side[i] + matchsticks[idx] > target){continue;} // ek side badi ho gayi toh add hi nahi karna
10            if(i > 0 && side[i] == side[i-1]) continue; // if side are same then add the matchsticks to one of them because if you add matchsticks in both then in the end they will generate same side array so just add in any one of them
11            side[i] += matchsticks[idx];
12            if(solution(matchsticks, idx+1, target, side)) return true;
13            side[i] -= matchsticks[idx];
14        }
15        return false;
16    }
17public:
18    bool makesquare(vector<int>& matchsticks) {
19        int n = matchsticks.size();
20        int sum = accumulate(matchsticks.begin(), matchsticks.end(),0);
21        if(sum % 2 != 0){return false;}
22        sort(matchsticks.begin(), matchsticks.end());
23        vector<int>sides(4, 0);
24        return solution(matchsticks, 0, sum/4, sides);
25    }
26};