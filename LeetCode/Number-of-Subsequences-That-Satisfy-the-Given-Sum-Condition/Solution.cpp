1class Solution {
2public:
3    int numSubseq(vector<int>& nums, int target) {
4        sort(nums.begin(), nums.end());
5        int mod = 1e9 + 7, ans = 0;
6        int n = nums.size();
7        vector<long long>power(n);
8        power[0] = 1; for(int i = 1; i<n; i++){power[i] = (power[i-1]*2)%mod;}
9
10        for(int i = 0; i<n; i++){
11            auto j = upper_bound(nums.begin(), nums.end(),target-nums[i])-nums.begin()-1;
12            if(j>=i){
13                ans = (ans + power[j-i])%mod;
14            }
15        }
16        return ans;
17    }
18};