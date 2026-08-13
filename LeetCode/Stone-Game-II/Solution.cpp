1class Solution {
2    int dp[2][101][101];
3    int solve(vector<int>&piles, int idx, int m, int person){
4        int n = piles.size();
5        if(idx >= n){return 0;}
6        if(dp[person][idx][m] != -1){return dp[person][idx][m];}
7        int stones = (person == 1)?-1:INT_MAX;
8        int take = 0, x = min(2*m, n-idx);
9
10        for(int i = 1; i<=x; i++){  // Alice turn to play
11            take += piles[idx+i-1];
12            if(person){
13                stones = max(stones, take + solve(piles, idx+i, max(m, i), 0));
14            }
15            else{
16                stones = min(stones, solve(piles, idx+i, max(m, i), 1));
17            } 
18        }
19        return dp[person][idx][m] =  stones;
20    }
21public:
22    int stoneGameII(vector<int>& piles) {
23        memset(dp, -1 , sizeof(dp));
24        int sum = accumulate(piles.begin(), piles.end(), 0);
25        int alice_score = solve(piles, 0, 1, 1);
26        return alice_score;
27    }
28};