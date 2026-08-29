1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& nums) {
4        int n = nums.size();
5        stack<int>st;
6        vector<int>ans(n, 0);
7        for(int i = 0; i<n; i++){
8            while(!st.empty() && nums[st.top()] < nums[i]){
9                ans[st.top()] = i - st.top();
10                st.pop();
11            }
12            st.push(i);
13        }
14        return ans;
15    }
16};