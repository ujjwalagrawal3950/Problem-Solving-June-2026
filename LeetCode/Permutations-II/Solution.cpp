1class Solution {
2    void solution(vector<int>nums , vector<vector<int>>&ans , int index){
3        if(index == nums.size()){
4            ans.push_back(nums);
5            return;
6        }
7        vector<bool>track(21 , false);
8        for(int i = index; i<nums.size() ; i++){
9            if(track[nums[i]+10] == false){
10                track[nums[i]+10] = true;
11                // Means element is unvisited so swap element with index element 
12                swap(nums[i] , nums[index]);
13                //After swapping again call the function 
14                solution(nums , ans , index+1);
15
16                
17                // Now mark the sign by making nums[i]+10 =1 that you visited your element and you never use it again because  by using this element again some cases would be repeated 
18                
19            }
20        }
21    }
22public:
23    vector<vector<int>> permuteUnique(vector<int>& nums) {
24        //               -------------------IMPORTANT----------------------
25        // In this question limit also present the range of nums[i] will affect our space complexity because for tracking of our element we will have to make a array of size = range of nums[i];
26        vector<vector<int>>ans;
27        
28        int index = 0;
29        solution(nums , ans , index);
30        return ans;
31    }
32};