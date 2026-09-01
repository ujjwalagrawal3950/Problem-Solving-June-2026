1class Solution {
2public:
3    long long subArrayRanges(vector<int>& nums) {
4        long long ans = 0;
5        for(int i = 0; i<nums.size(); i++){
6            int maxi = INT_MIN, mini = INT_MAX;
7            for(int j = i; j<nums.size(); j++){
8                maxi = max(maxi,  nums[j]);
9                mini = min(mini , nums[j]);
10                ans += (maxi - mini);
11            }
12        }
13        return ans;
14    }
15};