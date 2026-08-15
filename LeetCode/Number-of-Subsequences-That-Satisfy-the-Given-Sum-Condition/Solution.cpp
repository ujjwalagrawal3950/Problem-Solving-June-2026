1class Solution {
2public:
3    int numSubseq(vector<int>& nums, int target) {
4        sort(nums.begin(), nums.end());
5        int n = nums.size(), mod = 1e9 + 7;
6        vector<int>power(n);
7        power[0] = 1; for(int i = 1; i<n; i++){power[i] = (power[i-1]*2)  % mod;}
8
9        int i = 0, j = n-1, ans = 0;
10        while(i <= j){
11            if(nums[i] + nums[j] <= target){
12                ans = (ans + power[j-i]) % mod;
13                i++; // valid subsequence must always in positive direction
14            }
15            else j--;
16        }
17        return ans;
18    }
19};