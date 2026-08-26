1class Solution {
2public:
3    void nextPermutation(vector<int>& nums) {
4        int n = nums.size();
5        int idx = -1;
6        for (int i = n - 2; i >= 0; i--) {
7            if (nums[i] <
8                nums[i + 1]) { // Means we have some element in previous so we
9                               // can make next greater element
10                idx = i;
11                break;
12            }
13        }
14
15        if (idx == -1) {
16            reverse(nums.begin(), nums.end());
17        } else {
18            for (int i = n - 1; i >= idx; i--) {
19                if (nums[i] > nums[idx]) {
20                    swap(nums[i], nums[idx]);
21                    reverse(nums.begin() + idx + 1, nums.end());
22                    break;
23                }
24            }
25        }
26    }
27};