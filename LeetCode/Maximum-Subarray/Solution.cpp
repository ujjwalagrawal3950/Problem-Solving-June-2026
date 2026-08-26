1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        if(nums.size() == 1){return nums[0];}
5        int maxSum = INT_MIN, n  = nums.size();
6        int i = 0, j = 0, currSum = 0;
7        while(i < n && j < n){
8            currSum += nums[j];
9            if(maxSum <= currSum){
10                maxSum = currSum;
11            }
12            if(currSum < 0){currSum = 0; i = j+1;}
13            j++;
14        }
15        return maxSum;
16    }
17};