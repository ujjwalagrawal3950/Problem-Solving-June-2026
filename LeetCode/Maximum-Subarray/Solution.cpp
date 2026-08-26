1class Solution {
2    public int maxSubArray(int[] nums) {
3        int maxSum = nums[0];
4        int currentSum = nums[0];
5
6        for (int i = 1; i < nums.length; i++) {
7            currentSum = Math.max(nums[i], currentSum + nums[i]);
8            maxSum = Math.max(maxSum, currentSum);
9        }
10
11        return maxSum;
12    }
13}