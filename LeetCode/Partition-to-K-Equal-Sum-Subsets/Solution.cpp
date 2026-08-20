1class Solution {
2    bool visited[17];
3    bool solve(vector<int>&nums, int k , int target, int idx, int SubSum){
4        if(k == 0){
5            return true;
6        }
7
8        if(SubSum == target){return solve(nums, k-1, target, 0, 0);}
9
10        for(int i = idx; i<nums.size(); i++){
11
12            if(visited[i]) continue;
13            if(SubSum + nums[i] > target) continue;
14
15            visited[i] = true;
16
17            if(solve(nums, k, target, i, SubSum + nums[i])) return true;
18            
19            visited[i] = false;
20        }
21
22        return false;
23    }
24public:
25    bool canPartitionKSubsets(vector<int>& nums, int k) {
26        memset(visited, false, sizeof(visited));
27        int sum = accumulate(nums.begin(), nums.end(), 0);
28        if(sum % k != 0) {return false;}
29        return solve(nums, k , sum/k, 0, 0);
30    }
31};