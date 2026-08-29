1class Solution {
2public:
3    vector<int> asteroidCollision(vector<int>& nums) {
4        stack<int>st; vector<int>ans;
5        for(int i = 0 ; i<nums.size(); i++){
6            bool alive = true;
7            while(!st.empty() && alive && nums[st.top()] > 0  && nums[i] < 0){
8                if(nums[st.top()] < -nums[i]){
9                    st.pop();
10                }
11                else if(nums[st.top()] == -nums[i]){
12                    st.pop();
13                    alive = false;
14                }
15                else{  
16                    // means +ve direction asteriod are bigger than -ve direction and they both collide and +ve direction is going on
17
18                    alive = false; // this is restrict to add -ve element because here bigger +ve direction planet is win
19                }
20            }
21            if(alive) st.push(i);
22        }
23        while(!st.empty()){
24            ans.push_back(nums[st.top()]);
25            st.pop();
26        }
27        reverse(ans.begin(), ans.end());
28        return ans;
29    }
30};
31
32                                // current element comes
33                                //         ↓
34                                // Can it collide with stack top?
35                                //         ↓
36                                //         YES
37                                //         ↓
38                                //      Compare them
39                                //    ↙        ↓      ↘
40                                // top dies  both die  current dies
41                                //      ↓       ↓       ↓
42                                //    pop      stop     stop
43                                //     ↓
44                                //  check again
45                                //       ↓
46                                // current survived?
47                                //       ↓
48                                //     push