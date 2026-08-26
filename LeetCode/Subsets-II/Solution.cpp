1class Solution {
2    void solve(vector<int>&nums, vector<vector<int>>&ans, int idx, vector<int>&temp){
3        if(idx == nums.size()){
4            ans.push_back(temp);
5            return;
6        }
7        // Here I got a problem that i have duplicate numbers so i have to manage that
8        // Each element have two options first take and another is notTake
9        // Take 
10        temp.push_back(nums[idx]);
11        solve(nums, ans, idx + 1, temp);
12        while(idx < nums.size()-1 && nums[idx] == nums[idx + 1]){
13            idx++;
14        }
15        temp.pop_back();
16        solve(nums, ans, idx + 1, temp);
17    }
18public:
19    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
20        sort(nums.begin(), nums.end());
21        vector<vector<int>>ans;
22        vector<int>temp;
23        solve(nums, ans, 0, temp);
24        return ans;
25    }
26};