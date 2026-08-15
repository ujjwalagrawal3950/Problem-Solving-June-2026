1class Solution {
2public:
3    int longestSubsequence(vector<int>& nums) {
4        int xi = 0, n = nums.size();
5        bool everyZero = true;
6        for(int i = 0; i<nums.size(); i++){
7            if(everyZero && nums[i] != 0){everyZero = false;}
8            xi ^= nums[i];
9        }
10        if(everyZero) {return 0;}
11        if(xi != 0){return n;}
12        return n-1;     
13    }
14};