1class Solution {
2    void MakePermutations(vector<int>& nums, vector<bool>& visited,
3                          vector<vector<int>>& ans, int idx,
4                          vector<int>& temp) {
5
6        if (idx == nums.size()) {
7            ans.push_back(temp);
8            return;
9        }
10
11        for (int i = 0; i < nums.size(); i++) {
12            if (!visited[i]) {
13                temp.push_back(nums[i]);
14                visited[i] = true;
15
16                MakePermutations(nums, visited, ans, idx + 1, temp);
17
18                visited[i] = false;
19                temp.pop_back();
20            }
21        }
22    }
23
24public:
25    vector<vector<int>> permute(vector<int>& nums) {
26        int n = nums.size();
27        vector<bool> visited(n, false);
28        vector<int> temp;
29        vector<vector<int>> ans;
30
31        MakePermutations(nums, visited, ans, 0, temp);
32        return ans;
33    }
34};