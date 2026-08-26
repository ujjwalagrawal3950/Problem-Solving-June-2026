1class Solution {
2    int solve(vector<int>&nums, int l , int r){
3        if(l == r){
4            return nums[l]; // or can be reurn nums[r]
5        }
6
7        int mid = l + (r-l) / 2;
8        int left  = solve(nums, l, mid);// i assume this will give me max sum in left array
9        int right = solve(nums,  mid+1, r);
10
11        // Merging left and Right subarray
12        int sum = 0, maxLeftSum = INT_MIN;
13        for(int i = mid; i>=l; i--){
14            sum += nums[i];
15            maxLeftSum = max(sum, maxLeftSum);
16        }
17
18        sum = 0; int maxRightSum = INT_MIN;
19        for(int i = mid+1; i<=r; i++){
20            sum += nums[i];
21            maxRightSum =  max(maxRightSum , sum);
22        }
23        // if Crossing middle then 
24        int middleCross = maxLeftSum + maxRightSum;
25        return max({left, right, middleCross});
26    }
27public:
28    int maxSubArray(vector<int>& nums) {
29        int n = nums.size();
30        // Let's Do this with divide and conquer methods
31        return solve(nums, 0, n-1);
32    }
33};